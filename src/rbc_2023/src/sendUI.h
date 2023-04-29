#include "iostream"
#include "ros/ros.h"
#include "string.h"
#include "std_msgs/String.h"
#include "rbc_2023/node2UI.h"
using namespace std;
/*!
    @brief 将相应的消息发送至UI界面
    @param pub:ros发送消息对象
    @exception 如果pub对象没有设置将会产生报错
*/
class sendUI
{
public:
    sendUI(ros::Publisher & pub);
    sendUI(){};
    void print2UI(const std::string & str);
    void setPub(ros::Publisher & pub){this->pub = pub;this->isPubSet = true;}
private:
    ros::Publisher pub;
    bool isPubSet = false;
    rbc_2023::node2UI msg;
};