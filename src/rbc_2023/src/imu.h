#ifndef __IMU
#define __IMU
#endif

#include "ros/ros.h"
#include "serial/serial.h"
#include "string.h"
#include "iostream"
#include "rbc_2023/imu.h"
using namespace std;

/*!
 \brief This is a class that used to read messages from IMU sensor
*/

class IMU_read
{
public:
    IMU_read(const uint8_t type)
    {
        this->type = type;
    }
    int data_length = 11;
    uint8_t type;
    uint8_t data[11];
    string  data_str;
};
/*!
    \brief This IMU class contains the function that get raw data of IMU from sensor, 
    which is used on launch mechanism 
*/
class IMU
{
public:
    IMU(serial::Serial* ser);
    double roll;
    double pitch;
    double yaw;
    void processRead(const string str);
    string data2str(uint8_t * data, int length);
    
    void openIMU();
    void showAngle();
    void updateAngle(uint8_t * data);
    void setZero();
    void writeType(uint8_t * data);
    rbc_2023::imu* getImuMsg();
    uint8_t unlock[5] = {0xFF, 0xAA, 0x69, 0x88, 0xB5};
    uint8_t save[5] = {0xFF, 0xAA, 0x00, 0x00, 0x00};
    uint8_t BAUD[5] = {0xFF, 0xAA, 0x04, 0x06, 0x00};
    uint8_t LED_OFF[5] = {0xFF, 0xAA, 0x1B, 0x01, 0x00};
    uint8_t LED_ON[5] = {0xFF, 0xAA, 0x1B, 0x00, 0x00};
    uint8_t angle_referred[5] = {0xFF, 0xAA, 0X11, 0X08, 0X00};
private:
    serial::Serial *ser;
    int readLength;
    int writeLength;
    
    IMU_read* time  = new IMU_read(0x50);
    IMU_read* acceleration = new IMU_read(0x51);
    IMU_read* angularVelocity = new IMU_read(0x52);
    IMU_read* angle = new IMU_read(0x53);
    
    void angle_dataProcess(uint8_t* data);
};