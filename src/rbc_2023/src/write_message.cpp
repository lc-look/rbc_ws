#include <string.h>
#include "Message.h"
#include "rbc_2023/recive.h"
#include <stdlib.h>
#include "ros/ros.h"
#include "serial/serial.h"
#include "iostream" 
#include "fstream"
#include "sensor_msgs/Joy.h"
#include "std_msgs/Int32.h"
#include "rbc_2023/UI2node.h"
#include "rbc_2023/node2UI.h"
#include "std_msgs/String.h"
using namespace std;


// Declare variables and functions
serial::Serial ser;//Create Serial object
serial::Serial ser_imu;
Message *msg = new Message();
sensor_msgs::Joy controller; // The object of joy message

int open_serial();
int open_serial_imu();
void doJoy(const sensor_msgs::Joy::ConstPtr& data);
void doMsgFromUI(const rbc_2023::UI2node::ConstPtr& data);

/*!
    @brief According to the message source to decide Mode an write message to stm32

*/
int main(int argc,char** argv)
{
    setlocale(LC_ALL, "");
    ros::init(argc,argv,"write_message");


// open serial port
    int open_serial_flag = open_serial();
    if(open_serial_flag == -1)
    {
        ROS_ERROR("Failed to open serial port");
        msg->showPresentSerial();
        return -1;
    }
    int open_serial_flag_imu = open_serial_imu();
    if(open_serial_flag_imu == -1)
    {
        ROS_ERROR("Failed to open serial port /dev/ttyUSB1");
        msg->showPresentSerial();
        return -1;
    }

// serial port part

    //create node handle
    ros::NodeHandle nh;

    //create publisher
    ros::Publisher pub = nh.advertise<rbc_2023::node2UI>("node_UI",100);
    msg->setPubNode2UI(pub);

    //set the frequency of writing to stm32
    ros::Subscriber sub_Joy = nh.subscribe<sensor_msgs::Joy>("joy",10,doJoy);
    ros::Subscriber sub_sendType = nh.subscribe<rbc_2023::UI2node>("UI_writeMsg",100,doMsgFromUI);
    ros::Rate rate(20);
    //

    //设置msg的串口
    msg->ser =&ser;
    msg->ser_IMU = &ser_imu;

    while(ros::ok())
    {
        bool isImuPortOK = true;
        try//在mode10下获取底盘数据
        {
            msg->writeMsg(10);

        }
        catch(int m_error)
        {
            ROS_WARN("模式%d出现错误",m_error);
            try
            {
                if(open_serial())
                {
                }   
            }
            catch(...)
            {
                ROS_ERROR("Unknown error occurred while trying to open ttyUSB0");
            }
        }
        catch(...)
        {
            ROS_WARN("模式10出现错误。进行忽略处理-建议立即处理");
        }

        if(open_serial_flag_imu)
        {
            try
            {
                msg->writeMsg(11);//imu对应的mode

            }
            catch(...)
            {
                ROS_ERROR("[main-msg-write]与IMU通信未知错误发生!");
            }
        }
            
        // msg->print2UI("Hello! This is a test message");   
        ros::spinOnce();
        rate.sleep();
    }

    //write parameters to the stm32

    return 0;
}


// When receive message ,the class will update state
// then write message to stm32
void doJoy(const sensor_msgs::Joy::ConstPtr& data)
{
    // msg.update_state(data);
    ros::Rate r(15);
    msg->ser = &ser;
    msg->changeMode(1);
    msg->controller.setMsg(data);
    uint8_t* backMsg;
    msg->addLaunchSpeedStatus(msg->controller.getSpeedStatue());
    msg->writeMsgController();
    // backMsg = msg->readMsgINControllerMode(14);
    msg->showID();
    msg->showMode();
    msg->controller.showMsg();
    msg->showLaunchSpeedStatus();
    // while(backMsg[0] != msg->getID())
    // {
    //     msg->writeMsgController();
    // }
    r.sleep();
    msg->addID();
}
    // msg.writeMessage(ptr_ser);W
/*!
    Get message from UI
    \param data Data is rendered from controlUI interface. The data contains single that contains some info.   
*/
void doMsgFromUI(const rbc_2023::UI2node::ConstPtr& Msg)
{
    msg->showWrite(Msg->isCheckShowWrite);
    cout <<"收到来自UI的mode:" <<Msg->mode << endl;
    // cout << to_string(Msg->mode) <<endl;
    msg->changeMode(Msg->mode);// Change mode to 0, which means automatically motion
    msg->print2UI("[doMsgFromUI]mode:"+to_string(Msg->mode));
    if (Msg->mode == 0)// 模式0下，自动更新下方数据
    {
        msg->ser = &ser;
        ROS_INFO("Get message from UI");
        msg->updateFromUI();
        msg->writeMsg();

        ROS_INFO("UI发送的指令为:\n ID = %d\n x = %d\n y = %d\n theta = %d\n",msg->ID,msg->base.getX()
                ,msg->base.getY()
                ,msg->base.getTheta());

        string backMsgStr = msg->getBackMsgStr();
        msg->updateFromReturn(backMsgStr, msg->getMode());
        ROS_INFO("Present ID :%d",msg->ID);

    }
    else if (Msg->mode == 99)
    {
        ROS_INFO("Start emergency status");
        msg->writeMsg();

    }
    else if (Msg->mode == 100)
    {
        ROS_INFO("Get Launch mode indication");
        msg->writeMsg();

    }
    else if (Msg->mode == 101)
    {
        ROS_INFO("Get IMU set zero mode indication");
        msg->writeMsg();

    }
    else if(Msg->mode == 102)
    {
        ROS_INFO("Get Pick mode indication");
        msg->writeMsg();

    }
    else
    {
        ROS_ERROR("[doMsgFromUI]:Unknow mode get from UI");
    }
    
}




int open_serial()
{
    try
    {
        auto tmp = std::system("sudo chmod 777 /dev/ttyUSB*");
        ser.setPort("/dev/ttyUSB0");
        ser.setBaudrate(115200);
        serial::Timeout to = serial::Timeout::simpleTimeout(1000);
		ser.setTimeout(to);
		ser.open();
    }
    catch(serial::SerialException& e)
    {
        ROS_ERROR_STREAM("Unable to open serial port");
        ROS_ERROR_STREAM("Might you not give rights to USB part right! Please try command: sudo chmod 777 /dev/ttyUSB0");
        return -1;
    }
    catch(...)
    {
        ROS_ERROR("Unknown error occurred while trying to open serial port ttyUSB0");
        return -1;
    }
    if(ser.isOpen())
    {
        ROS_INFO_STREAM("Serial port ttyUSB0 opened");
        return 1;
    }
    else
    {
        return -1;
    }
};
int open_serial_imu()
{
    try
    {
        auto tmp = std::system("sudo chmod 777 /dev/ttyUSB*");
        ser_imu.setPort("/dev/ttyUSB1");
        ser_imu.setBaudrate(115200);
        serial::Timeout to = serial::Timeout::simpleTimeout(1000);
		ser_imu.setTimeout(to);
		ser_imu.open();
    }
    catch(serial::SerialException& e)
    {
        ROS_ERROR_STREAM("Unable to open serial port /dev/ttyUSB1");
        cout << e.what() << endl;
        return -1;
    }
    catch(...)
    {
        ROS_ERROR("[open_serial_imu]Unknown error occurred while trying to open serial port ttyUSB0");
        return -1;
    }
    if(ser_imu.isOpen())
    {
        ROS_INFO_STREAM("Serial port ttyUSB1 opened");
        return 1;
    }
    else
    {
        return -1;
    }
    return -1;
}