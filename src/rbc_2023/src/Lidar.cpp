#include "ros/ros.h"
#include "LidarMap.h"
#include <iostream>
#include "sensor_msgs/PointCloud2.h"
using namespace std;

void doMsgFromPcl(const sensor_msgs::PointCloud2::ConstPtr &msg)
{
    cout << "Get message from livox" << endl;
    cout << msg->header.seq<<endl;
}

int main(int argc, char **argv)
{
    setlocale(LC_ALL,"");
    ros::init(argc, argv, "Lidar");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe<sensor_msgs::PointCloud2>("/livox/lidar",100,doMsgFromPcl);
    while(ros::ok())
    {
        ros::spinOnce();
    }
}