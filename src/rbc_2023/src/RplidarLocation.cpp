#include "ros/ros.h"
#include "sensor_msgs/LaserScan.h"
#include "iostream"
#include <vector>

using namespace std;
void doScan(const sensor_msgs::LaserScan::ConstPtr& data);
float angle_min;
float angle_max;
float angle_increase;
vector<float> ranges;
int main(int argc, char **argv)
{

    setlocale(LC_ALL, "");
    ros::init(argc,argv,"RplidarLocation");
    ros::NodeHandle nh;
    ros::Subscriber sub1 = nh.subscribe<sensor_msgs::LaserScan>("/scan",10,doScan);
    int times = 0;
    while(ros::ok())
    {
        ros::spinOnce();
    }
    // while(ros::ok())
    // {
    //     float angle =  angle_max - angle_min;
    //     float amount  = angle/angle_increase;
    //     auto tmp = angle_min;
    //     int i =0;
    //     while(tmp<0)
    //     {  
    //         i = i+1;
    //         tmp = tmp + angle_increase;
    //     }

    //     // cout<<"amount:"<<amount<<endl;
    //     // cout<<times++<<endl;
    //     // cout<<"angle_0:"<<i<<endl;
    //     // cout<<ranges[0]<<endl;
    //     ros::spinOnce();
    // }
}


void doScan(const sensor_msgs::LaserScan::ConstPtr& data)
{
    angle_min = data->angle_min;
    angle_max = data->angle_max;
    angle_increase= data->angle_increment;
    ROS_INFO("data0:%f",data->ranges[0]);
    // cout<<"data0:"<<data->ranges[0];
}