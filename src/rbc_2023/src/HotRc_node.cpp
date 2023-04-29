#include "ros/ros.h"
#include "serial/serial.h"
#include "string"
#include "iostream"
#include "termios.h"
#include "unistd.h"
#include "fcntl.h"

using namespace std;


serial::Serial ser;

int open_serial();


int main(int argc, char **argv)
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "HT_controller");

    if(open_serial())
    {
        ROS_INFO("Serial is opened");
        int flag = 0;
        while(ros::ok())
        {
            string str;
            str = ser.read(25);
            if(str.length() > 0)
            {
                cout <<"Present num"<<flag++<<":"<< str.length() << endl;
                // for(int i = 0; i < str.length(); i++)
                // {
                //     printf("%x")
                // }
            }
            else if(str.length() == 0)
            {
                ROS_INFO("No message found");
            }
        }
    }

}

// int open_dev(char *Dev)
// {
//     int fd;
//     fd = open("/dev/ttyUSB0", O_RDONLY|O_NOCTTY);
// }

int open_serial()
{
    try
    {
        auto tmp = std::system("sudo chmod 777 /dev/ttyUSB*");
        ser.setPort("/dev/ttyUSB0");
        ser.setBaudrate(100000);
        ser.setStopbits(serial::stopbits_t::stopbits_two);
        ser.setParity(serial::parity_even);
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