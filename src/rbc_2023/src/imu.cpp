#include "imu.h"



using namespace std;
/*!
    \param str The type of string which sent by the sensor
*/
void IMU::processRead(const string str)
{
    uint8_t data[11];
    int index = 0;
    // cout << "here is processRead" << endl;
    while (index < str.length())
    {
        // printf("%x  ",str[index]);
        if(uint8_t(str[index]) == 0x55)
        {
            // ROS_INFO("识别到帧头！");
            // cout<<"this is header of frame"<< endl;
            if(str[index+1] == this->angle->type)
            {
                // ROS_INFO("检测到角度帧");
                for(int i = index; i < index+11;i++)
                {
                    data[i-index] = str[i];
                }
                // ROS_INFO("开始处理角度帧!");
                this->updateAngle(data);
            }
            else
            {
                // ROS_INFO("该帧不符！");
            }
        }
        index++;
    }

}

/*!
    \brief Process the IMU data of angle 
    \param data the reading data that from IMU
*/
void IMU::angle_dataProcess(uint8_t* data)
{
    this->roll = (data[2]<<8)|data[3]/(32768*180);
    this->pitch = (data[4]<<8)|data[5]/(32768*180);
    this->yaw = (data[6]<<8)|data[7]/(32768*180);

    this->showAngle();
}

/*!
    \brief Transfer the type of unsigned char to the type of string
    \param data The data that you want to transfer
    \param length The length of the data
*/
string IMU:: data2str(uint8_t * data, int length)
{
    string str = "";
    for (int i = 0; i < length; i++)
    {
        str.append(1,data[i]);
    }
    return str;
}


IMU::IMU(serial::Serial* ser)
{
    this->ser = ser;
    this->readLength = 11;
    this->writeLength = 5;
}

/*!
    \brief Unlock the IMU by sending message
*/
void IMU::openIMU()
{
    string str = data2str(this->unlock, this->writeLength);
    cout<<str<<endl;
    this->ser->write(str);

    str = data2str(this->BAUD, this->writeLength);
    this->ser->write(str);
    
    str = data2str(this->save, this->writeLength);
    this->ser->write(str);


}

// print data of IMU
void IMU::showAngle()
{
    cout<<"roll:"<<this->roll<<endl;
    cout<<"pitch:"<<this->pitch<<endl;
    cout<<"yaw:"<<this->yaw<<endl;
}

/*!
    \brief Process the frame of angle
    \param data The pointer of data, the length of which is 11
*/
void IMU::updateAngle(uint8_t* data)
{
    if(data[1] != this->angle->type)
    {
        return;
    }
    else
    {
        this->roll  = (double((data[3]<<8)|(data[2]))/32768)*180;
        this->pitch = (double((data[5]<<8)|data[4])/32768)*180;
        this->yaw   = (double((data[7]<<8)|data[6])/32768)*180;
        // this->showAngle();
    }
}

rbc_2023::imu* IMU::getImuMsg()
{
    rbc_2023::imu * Msg = new rbc_2023::imu();
    Msg->roll = this->roll;
    Msg->pitch = this->pitch;
    Msg->yaw = this->yaw;
    return Msg;
}
void IMU::  setZero()
{

    ROS_INFO("进行调零！");
    uint8_t head1 = 0xFF;
    uint8_t head2 = 0xAA;
    uint8_t roll_register = 0x3D;
    uint8_t pitch_register = 0x3E;
    uint8_t yaw_register = 0x3F;
    uint8_t data_low = 0x00;
    uint8_t data_high = 0x00;

    uint8_t zero_roll[5] = {head1,head2,roll_register,data_low,data_high};
    uint8_t zero_pitch[5] = {head1,head2,pitch_register,data_low,data_high};
    uint8_t zero_yaw[5] = {head1,head2,yaw_register,data_low,data_high};
    uint8_t ledoff[5] = {head1,head2,0x1B,0x01,0x00};

    // this->ser->write(this->data2str(this->unlock,5));
    // this->ser->write(this->data2str(zero_roll,5));
    // this->ser->write(this->data2str(this->save,5));

    // this->ser->write(this->data2str(this->unlock,5));
    // this->ser->write(this->data2str(zero_pitch,5));
    // this->ser->write(this->data2str(this->save,5));

    // this->ser->write(this->data2str(this->unlock,5));
    // this->ser->write(this->data2str(ledoff,5));
    // this->ser->write(this->data2str(this->save,5));


    // this->ser->write(this->data2str(this->unlock,5));
    // this->ser->write(this->data2str(zero_yaw,5));
    // this->ser->write(this->data2str(this->save,5));

    this->ser->write(this->data2str(this->unlock,5));
    cout<<this->data2str(this->unlock,5).length()<<endl;
    this->ser->write(this->data2str(this->angle_referred,5));
    this->ser->write(this->data2str(this->save,5));
    // this->ser->write();
    // this->ser->write();
}

/*!
    \brief write type of message to imu sensor
*/
void IMU::writeType(uint8_t *data)
{
    string str;
    
    str = this->data2str(this->unlock,5);
    this->ser->write(str);
    
    str = data2str(data,this->writeLength)+this->data2str(this->save,5);;
    this->ser->write(str);
    // cout<<str.length()<<endl;

    str = 
    this->ser->write(str);

    ROS_INFO("The command have successfully sent to imu!");

}

