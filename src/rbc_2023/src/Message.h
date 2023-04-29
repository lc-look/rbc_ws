#include "ros/ros.h"
#include <string>
#include <exception>
#include <iostream>
#include "serial/serial.h"
#include "stdlib.h"
#include "fstream"
#include "sensor_msgs/Joy.h"
#include "rbc_2023/UI2node.h"
#include "rbc_2023/node2UI.h"
using namespace std;

class MessageTransform
{
public:
string int2ASCIIString(const int i);
char int2char(const int a);
string char2str(const char *C1);

};
class MessageData
{
public:
    MessageData()
    {
        this->value = 0;
        this->valueChar = 0;
    }
    MessageData(int value)
    {
        try
        {
            if(value < 0)
            {
                throw 1;
            }
            else if(value >(2^8)-1)
            {
                throw 1.0;
            }
            this->value = value;
            this->valueChar = value;
        }
        catch(int)
        {
            ROS_WARN("message throw exception value error, which less than zero");
            this->value = 0;
            this->valueChar = 0;
        }
        catch(double)
        {
            ROS_WARN("message throw exception value error, which greater than max value:255");
            this->value = 0;
            this->valueChar =0;
        }
    }
    void updateValue(int value)
    {
        try
        {
            if(value < 0)
            {
                throw 1;
            }
            else if(value >(2^8)-1)
            {
                throw 1.0;
            }
            this->value = value;
            this->valueChar = this->value;
            this->dataPtr = &this->valueChar;
        }
        catch(int)
        {
            ROS_WARN("message throw exception value error, which less than zero.Present value is %d",value);

        }
        catch(double)
        {
            ROS_WARN("message throw exception value error, which greater than max value:255. Present value is %d",value);
        }
        
    }
    int getValue()
    {
        return this->value;
    }
    char* getDataPtr()
    {
        return this->dataPtr;
    }
private:
    int  value;
    char valueChar;
    char* dataPtr = &valueChar;
};


/*
@author: LiuChaos
@maintainer:
    This class is used to store coordinator information of X and Y coordinates
*/
class BaseMsg
{
public:
    void setMsg(int x, int y, int theta);
    int get_xHigh8(){return this->xHigh8;}
    int get_yHigh8(){return this->yHigh8;}
    int get_xLow8(){return this->xLow8;}
    int get_yLow8(){return this->yLow8;}
    int getX(){return this->x;}
    int getY(){return this->y;}
    int getTheta(){return this->theta;}
   void showXYTheta();
/* 
Get message via a string type
    xSign
    xHigh8
    xLow8
    yHigh8
    yLow8
    thetaSign
    thetaHigh8
    thetaLow8

*/
    string getMsgStr();
private:
    int x;
    int theta;
    int thetaHigh8;
    int thetaLow8;
    string msgStr;
    uint8_t msgChar[8];
    int xHigh8;
    int xLow8;
    int y;
    int yLow8;
    int yHigh8;
};

class UpperMsg
{
public:
    void setMsg(int alpha, int beta, int speed);
    string getMsgStr();
private:
    int alpha;//Rule to turn left to positive. This might conclude to be negative
    int beta;
    int speed;
    char msgChar[4];
    string msgStr;
};

class ControllerMsg
{
public:
    // Get message from the controller and update info of controller state
    void setMsg(const sensor_msgs::Joy::ConstPtr& data);
    string getMsgStr();
    void showMsg();
    /*!
    \brief If spped is up status,return 1; else if spped is down status return -1;
    */
    int getSpeedStatue();
private:
    char msgChar[13];
    string msgStr;
    int forward;
    int backups;
    int left;
    int right;
    int turnLeft;
    int turnRight;
    int launchSpeedUp;
    int launchSpeedDown;
    int Y;
    int A;
    int X;
    int B;
    int launch;
};



/*!
    This class is mainly used to write messages to stm32
    @attention
    在使用时请务必要设置关键的几个部分
    1.收发节点至UI的通信部分的设置 
*/
class Message
{
public:
    /*!
        @brief Include the basic exception of message 
    */
    class MessageException : public exception
    {
        
    };
    void setMode();
    void updateFromController(const sensor_msgs::Joy::ConstPtr& data);
    /*
        When message from UI rendered.
        The message will be updated from param

    */
    void updateFromUI();

    void updateFromRecording();
    string getMsgStr();

    void writeMsg();
    void writeMsg(int mode);
    void writeMsgBase();
    void writeMsgUI();
    void writeMsgController();
    

    string readMsg();

    void changeMode(int mode);
    
    int getID(){return this->ID;}
    int getMode(){return this->mode;}
    void showStrInfo(const string& str);
    void setSerial( serial::Serial* serial){this->ser = serial;}
    string getIDStr();
    string getModeStr();
    string getBackMsgStr(){return this->backMsgStr;}
    void updateFromReturn(string backMsgStr, int mode);

    bool checkReturn();

    void addID();
    void showID(){cout<<"ID = "<<this->getID()<<endl;}
    void showMode(){cout<<"Mode = "<<this->getMode()<<endl;}
    void addLaunchSpeedStatus(int i){this->launchSpeedStatus = this->launchSpeedStatus +i;}
    void showLaunchSpeedStatus(){cout<<"LaunchSpeed = "<<this->launchSpeedStatus<<endl;}
    serial::Serial *ser;
    serial::Serial *ser_IMU;
    int ID = 0;
    BaseMsg base;
    UpperMsg upper;
    ControllerMsg controller;
    void openOutputFile();
    void openOutputFile(const std::string filename);
    void OutputTest();
    // 设置串口节点到UI的句柄
    void setPubNode2UI(ros::Publisher pub){this->pub_node2UI = pub;}
    
    void print2UI(const std::string str); 
    void print2UI(const std::string str, const std::string rawStr);
    void print2UI(int m3,const std::string str);
    
    void showWrite(bool t){this->isShowWrite = t;}
    void showPresentSerial(){cout <<"当前串口:";auto tmp__= system("ls -l /dev/ttyUSB*");}
private:
    int mode;
    int launchSpeedStatus = 0;
    string msgStr;
    string controllerMsgStr;
    string backMsgStr;
    int bullet = 10;
    bool isShowWrite = false;
    bool isOutFile = false;
    string outputFileName="/home/rbc/ros_work/rbc_ws/src/rbc_2023/src/ForOutTest.txt";

    void writeMsgInTryMode();
    void writeMsgEmergency();
    void writeMsgLaunch();
    void writeMsgReload();
    void writeMsgPick();
    void writeMsgIMU2zero();
    void processBackMsg();
    //UI部分

    ros::Publisher pub_node2UI;//
    rbc_2023::node2UI sendUIMsg;//发送至UI的消息对象（The message object that will be sent to UI）
    uint8_t* readMsgINBaseMode();
    

    uint8_t* readMsgINControllerMode(int i);
};
// class Message
// {
// //     public:
// //         std::string message ;
// //         /*Set initial value for message
            
// //             1. set message that will be written to stm32 to null string
// //             2. set motivation mode to zero
// //             3. set message that contains controller to zero
// //         */
// //         Message()
// //         {
// //             this->message = "";
// //             this->mode = 0;
// //             back2initialize();
// //         }



// //         /*When recieved message from controller then change controller value
            
// //         */
// //         void update_state(const sensor_msgs::Joy::ConstPtr& data)
// //         {
// //             if(data->axes[7]==1)
// //             {
// //                 this->forward   = 1;
// //                 this->backups    = 0;
// //             }
// //             else if(data->axes[7]==-1)
// //             {
// //                 this->forward   = 0;
// //                 this->backups    = 1;
// //             }
// //             else
// //             {
// //                 this->forward   = 0;
// //                 this->backups    = 0;
// //             }
// //             if(data->axes[6]==1)
// //             {
// //                 this->left      = 1;
// //                 this->right     = 0;
// //             }
// //             else if(data->axes[6]==-1)
// //             {
// //                 this->left      = 0;
// //                 this->right     = 1;
// //             }
// //             else
// //             {
// //                 this->left      = 0;
// //                 this->right     = 0;
// //             }
// //             this->Y = data->buttons[3];
// //             this->A = data->buttons[0];
// //             this->X = data->buttons[2];
// //             this->B = data->buttons[1];
// //             data2message();
// //         }
        
// //         /*Write message to the stm32 device,get data from the device
// //         */
// //         void writeMessage(serial::Serial *ser)
// //         {
            
// //             size_t index = ser->write(this->message);
// //             cout <<"serial number:"<<this->times<<endl;
// //             cout<<"writeMessage:"<<this->message<<endl;
            
// //             // read message from serial
// //             string feedback_string = ser->readline(); 
// //             cout<<"feedback_string:"<<feedback_string<<endl;
// //             this->times = this->times + 1;
// //         }
// //         void writeCoordinatorMsg(serial::Serial *ser);
        
// //         /*Change operation mode
// //             The motivation for this have three modes:
// //                 0:Manual operation 
// //                 1:semi-automatic operation
// //                 2:automatic operation
// //             Default mode is mode 0
// //         */
// //         void changeMode(int mode)
// //         {
// //             this->mode = mode;
// //         }
        
        
// //         // Back the string that get from serial
// //         string getFeedback()
// //         {
// //             return this->feedback_string;
// //         }
// // private:
// //     serial::Serial ser;
// //     string feedback_string;// feedback string from serial 
// //     int times = 0;
// //     int mode;
// //     int forward;
// //     int backups;
// //     int left;
// //     int right;
// //     int Y;
// //     int A;
// //     int X;
// //     int B;
    
// //     // To transform data to writeable format
// //     void data2message()
// //     {
// //         MessageData data[8];
// //         data[0].updateValue(forward);
// //         data[1].updateValue(backups);
// //         data[2].updateValue(left);
// //         data[3].updateValue(right);
// //         data[4].updateValue(Y);
// //         data[5].updateValue(A);
// //         data[6].updateValue(X);
// //         data[7].updateValue(B);
// //         this->message.clear();
// //         for (int i =0;i<8;i++)
// //         {
// //             this->message.append(data[i].getDataPtr());
// //         }
// //         back2initialize();
// //     }
    
// //     // Back All data to initialization --0
// //     void back2initialize()
// //     {
// //         this->forward = 0;
// //         this->backups = 0;
// //         this->left = 0;
// //         this->right = 0;
// //         this->Y = 0;
// //         this->A = 0;
// //         this->X = 0;
// //         this->B = 0;
// //     }
// //     // To transform num from Dec to Hex format
// //     string intToA(int num)
// //     {
// // 	    string str;
// //         long long Temp = num / 16;
// //         int left = num % 16;
// //         if (Temp > 0)
// //             str += intToA(Temp);
// //         if (left < 10)
// //             str += (left + '0');
// //         else
// //             str += ('A' + left - 10);
// //         return str;
// //     }
// };
// // 
