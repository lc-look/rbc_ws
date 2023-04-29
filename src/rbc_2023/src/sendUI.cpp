#include "sendUI.h"

sendUI::sendUI(ros::Publisher &pub)
{
    this->pub = pub;
    this->isPubSet = true;
}
/*!
    @brief 将信息发送至UI界面
*/
void sendUI::print2UI(const std::string &str)
{
    if(this->isPubSet == false)
    {
        throw("sendUI 没有设置publisher对象");
    }
    this->msg.mode = -1;
    this->msg.backStr = str;
    this->pub.publish(this->msg);
}