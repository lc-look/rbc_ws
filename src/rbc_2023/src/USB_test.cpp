#include "ros/ros.h"
#include "serial/serial.h"
using namespace std;

serial::Serial ser;

int main(int argc, char **argv)
{
    ros::init(argc, argv, "USB_test");
    ros::NodeHandle nh;
    if (open_serial())
    {
        ROS_INFO("All of it is OK");
    }
}

int open_serial()
{
    try
    {
        auto tmp = std::system("sudo chmod 777 /dev/ttyUSB*");
        ser.setPort("/dev/ttyACM0");
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