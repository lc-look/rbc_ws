#include "imu.h"
#include "rbc_2023/imu.h"


using namespace std;
int open_serial();

serial::Serial ser;

int open_serial();
int main(int argc, char **argv)
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "imu");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<rbc_2023::imu>("IMU", 1000);

    IMU* imu = new IMU(&ser);
    rbc_2023::imu* imuMsg = new rbc_2023::imu();
    if(open_serial())
    {
        imu->openIMU();
        imu->writeType(imu->LED_OFF);

        while(ros::ok())
        {
            bool isIMU2zero = false;
            nh.getParam("IMU2zero",isIMU2zero);
            // Zero setting to IMU
            if(isIMU2zero)
            {
                imu->setZero();
                nh.setParam("IMU2zero",false);
                
            }
            string str;
            str = ser.readline();
            // cout<<"The length of string:"<<str.length()<<endl; 
            imu->processRead(str);
            imuMsg = imu->getImuMsg();
            pub.publish(*imuMsg);
        }
    }
    else
    {
        ROS_ERROR_ONCE("串口打开失败！");
    }
    // uint8_t unlock[] = {0xFF, 0xAA, 0x69, 0x88, 0xB5};
    // uint8_t BAUD[] = {0xFF, 0xAA, 0x04, 0x05, 0x00};
    // string bootIMU ="";
    // for (int i =0; i <5; i++)
    // {
    //     bootIMU.append(1,unlock[i]);
    // }
    // string changeBaud ="";
    // for (int i =0; i <5; i++)
    // {
    //     changeBaud.append(1,BAUD[i]);
    // }
    // if(open_serial())
    // {
    //     ser.write(bootIMU);

    //     ser.write(changeBaud);
    // }
    // string offLED = "";
    // uint8_t off[] = {0xFF,0xAA,0x1B,0x01,0x00};
    // for(int i = 0; i <5;i++)
    // {
    //     offLED.append(1,off[i]);
    // }
    // int t = 0;
    // while(ros::ok())
    // {
    //     string str;
    //     // ser.read(&str,);
    //     ser.write(offLED);
    //     str = ser.readline();
    //     cout<<t++<<"="<<str<<endl;
    // }
    
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
    if(ser.isOpen())
    {
        ROS_INFO_STREAM("Serial port opened");
        return 1;
    }
    else
    {
        return -1;
    }
};