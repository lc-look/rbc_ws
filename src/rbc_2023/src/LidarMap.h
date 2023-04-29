#include <iostream>
#include "sendUI.h"
#include "eigen3/Eigen/Core"
#include "eigen3/Eigen/Dense"
#include "sensor_msgs/PointCloud2.h"
#include <pcl_ros/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl_conversions/pcl_conversions.h>
using namespace std;
using namespace Eigen;
/*!
    @brief 地点坐标位置，采用Eigen库进行计算
*/
class Location
{
public:
    Location(int* x, int* y, int* z);
    Location();
    void showLocation();
    void setRegion(int *offset);
    void setUI(const sendUI & UI);
    Matrix<int,3,1>Location_xyz;
    Matrix<int,3,6> column_locations;
private:
    sendUI UI;
    Vector2d x_region;
    Vector2d y_region;
    Vector2d z_region;


};
/*!
    @brief 柱子类
    @param i 表示第几根柱子
*/
class Column:public Location
{
public:
    Column(int i);
    Column(){}
    int type_;//1表示1型柱子,2表示2型柱子
private:
    

};
/*!
    @brief 主要用于获取地图上相对位置距离

*/
class LidarMap
{
public:
    LidarMap();
    LidarMap(const sendUI& UI);
    Vector3d distance(int i);
    void UpdateMyLocation();
private:
    Column* columns[6];//柱子的矩阵
    Location myLocation;
    sendUI UI;
};
/*!
    @brief 获取雷达数据并将雷达数据与当前的点进行处理累计获取共计
*/
class LidarScan : public LidarMap
{
public:
    LidarScan(const sendUI& UI):LidarMap(UI){}
    void scan(Location *columnGoal);
    void setData(sensor_msgs::PointCloud2 *LidarData){this->LidarData = LidarData;}

private:
    sensor_msgs::PointCloud2 *LidarData;
};