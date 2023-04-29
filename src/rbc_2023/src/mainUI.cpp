#include "controlwindow.h"
#include <QApplication>
#include <std_msgs/Int32.h>
#include "ros/ros.h"
float tmp1;

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    

    QApplication a(argc, argv);
    ros::init(argc, argv,"controlUI");
    ros::NodeHandle nh;
    controlWindow w;
    w.nh = nh;
    w.show();
    return a.exec();
}
