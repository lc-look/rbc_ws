#ifndef CONTROLWINDOW_H
#define CONTROLWINDOW_H
#include <QMainWindow>
#include "ros/ros.h"
#include "QString"
#include "string"
#include <thread>
#include <QThread>
#include <QTextBrowser>
#include <rbc_2023/recive.h>
#include "std_msgs/Int32.h"
#include "rbc_2023/imu.h"
#include "rbc_2023/UI2node.h"
#include "rbc_2023/node2UI.h"

QT_BEGIN_NAMESPACE
namespace Ui { class controlWindow; }
QT_END_NAMESPACE
class controlWindow : public QMainWindow
{
    Q_OBJECT
private:
    QTimer *tim;
    rbc_2023::UI2node* UI2NodeMsg = new rbc_2023::UI2node();
    void connect_init();
public:
    ros::NodeHandle nh;
    // 订阅和Written message 通信的节点(It subscribe to the topic of the node of communication)
    ros::Publisher pub_ui_writeMsg = nh.advertise<rbc_2023::UI2node>("UI_writeMsg",100);
    ros::Subscriber sub1;
    ros::Subscriber sub2;// It subscribe message from IMU
    Ui::controlWindow *ui;
    QTextBrowser *OutputRegion;


    
    void timeDelay(int secs);
    void mainProcess();

    controlWindow(QWidget *parent = nullptr);
    ~controlWindow();
public slots:

    void on_tim_timeout();
    void on_publishIndicatorButton_pressed();
    void on_launchButton_pressed();
    void on_emergencyButton_pressed();
    void on_IMUSetZeroButton_pressed();
    void on_clearOutputButton_pressed();
};
#endif // CONTROLWINDOW_H
