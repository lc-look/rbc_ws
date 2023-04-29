#include "LidarMap.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
Location::Location(int* x, int* y, int* z)
{
    this->Location_xyz(0,0) = x[0];
    this->Location_xyz(0,1) = x[1];
    this->Location_xyz(1,1) = y[0];
    this->Location_xyz(1,2) = y[1];
    this->Location_xyz(2,1) = z[0];
    this->Location_xyz(2,2) = z[1];
        // ROS_INFO("初始化柱子坐标及其分割范围");
    this->column_locations<<-3200,2700,1000,//0
                            0,2700,1000,
                            3200,2700,1000,
                            -1400,4600,1200,//3
                            1400,4600,1200,
                            0,6000,1900;
}
Location::Location()
{
        // ROS_INFO("初始化柱子坐标及其分割范围");
    this->column_locations<<-3200,2700,1000,//0
                            0,2700,1000,
                            3200,2700,1000,
                            -1400,4600,1200,//3
                            1400,4600,1200,
                            0,6000,1900;
}


/*!
    @brief Showing present location of object
*/
void Location::showLocation()
{
    cout<<"present location is:"<<this->Location_xyz<<endl;
}

void Location::setUI(const sendUI& UI)
{
    this->UI = UI;
}

/*!
    @brief Initial filed and the location of columns 
*/
LidarMap::LidarMap()
{

    for(int i = 0; i < 6;i++)
    {
        this->columns[i] =new Column(i);
    }

}
LidarMap::LidarMap(const sendUI &UI)
{
        for(int i = 0; i < 6;i++)
    {
        this->columns[i] =new Column(i);
    }
    this->UI = UI;
}

Column::Column(int i)
{
    this->column_locations<<-3200,2700,1000,//0
                            0,2700,1000,
                            3200,2700,1000,
                            -1400,4600,1200,//3
                            1400,4600,1200,
                            0,6000,1900;
    this->Location_xyz(0) = this->column_locations(i*3+0);
    this->Location_xyz(1) = this->column_locations(i*3+1);
    this->Location_xyz(2) = this->column_locations(i*3+2);

}
/*！
    @brief 目标柱子相对位置
*/
Vector3d LidarMap::distance(int i)
{
    int delta_x = this->columns[i]->Location_xyz(0)-this->myLocation.Location_xyz(0);
    int delta_y = this->columns[i]->Location_xyz(1)-this->myLocation.Location_xyz(1);
    int delta_z = this->columns[i]->Location_xyz(2)-this->myLocation.Location_xyz(2);
    Vector3d result;
    result << delta_x,delta_y,delta_z;
    return result;
}
/*!
    @brief 根据ros 参数服务器实时更新当前的位姿信息
*/
void LidarMap::UpdateMyLocation()
{
    int x;
    int y;
    int theta;
    ros::param::get("X_present",x);
    ros::param::get("Y_present",y);
    ros::param::get("Theta_present",theta);
    this->myLocation.Location_xyz(0)=x;
    this->myLocation.Location_xyz(1)=y;
    this->myLocation.Location_xyz(2)=theta;
}