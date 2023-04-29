#include "controlwindow.h"
#include "./ui_controlwindow.h"
#include <iostream>
#include <string>
#include <unistd.h>
#include <stdlib.h>
#include <QThread>
#include "rbc_2023/recive.h"
#include "qt_files/qt_node_thread.h"
#include <QTimer>
#include "qt_files/CommandThread.h"
#include "sensor_msgs/Joy.h"
#include "std_msgs/Int32.h"
using namespace std;

controlWindow* obj_ptr;
// public object
//1. FeedbackMessage , this object is recive from lower


/*callbakc function*/
void doGetFeedback(const rbc_2023::node2UI::ConstPtr& msg)
{
    if(msg->mode == -1)
    {
        string str = msg->backStr;
        obj_ptr->OutputRegion->append(str.c_str());
    }
}

void doGetImu(const rbc_2023::imu::ConstPtr& data)
{
    obj_ptr->ui->pub_alpha->setValue(data->pitch);
    obj_ptr->ui->pub_beta->setValue(data->yaw);
}





QString OutputString;
controlWindow::controlWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::controlWindow)
{
    // Set language of the control window
    
    setlocale(LC_ALL,"");
    
    //create subscriber
    // ros::Subscriber sub1 = this->nh.subscribe("MsgPublishQt",10,doGetFeedback);
    // this->sub1 = sub1;

    ros::NodeHandle nh1;
    ros::Subscriber sub1 = nh1.subscribe("node_UI",10,doGetFeedback);
    this->sub1 = sub1;
    // ui->OutputRegion->setText(QString("Hello,My friend!"));
    ui->setupUi(this);
    OutputString.append(QString("成功开启前端界面！"));
    ui->OutputRegion->setText(OutputString);
    obj_ptr = this;
    
    //create timer 
    ui->OutputRegion->append("开启参数更新计时器!");
    this->tim = new QTimer(this);
    //set interval of timer 
    this->tim->setInterval(10);
    this->tim->start();
    
    this->ui->lcdNumber->display(0);
    
    
    //To update UI widget to window
    this->OutputRegion = ui->OutputRegion;
    // Init connection
    this->connect_init();

}

controlWindow::~controlWindow()
{
    delete ui;
}


int times = 0;// remember the times number
void controlWindow::on_tim_timeout()
{
    ros::NodeHandle nh1;
    ros::spinOnce();
    this->UI2NodeMsg->isCheckShowRead =  this->ui->showRead->isChecked(); 
    this->ui->lcdNumber->display(this->UI2NodeMsg->mode);
    // 测试程序
    // this->OutputRegion->append(QString("Start update info")+QString::number(times++));
    // 测试程序结束


}


// pass command "rosnode list" command
// read from process getOutputo get output


void controlWindow::timeDelay(int sec)
// sleep seconds
{
    ros::Duration(sec).sleep();
}
/*!
    @brief 将前端中输入的值传递到ROS参数服务器（Pass the value of the UI to the ROS parameter service）
*/
void controlWindow::on_publishIndicatorButton_pressed()
{
    if(this-> UI2NodeMsg->mode != 0)
    {
        this->  UI2NodeMsg->mode = 0;
        this->ui->Mode->setText("Mode 0");
        this->OutputRegion->append("当前模式切换为自动模式");
    }
    this->ui->Mode->setText("Mode 0");
    this->OutputRegion->append("检查相关参数");
    if(this->ui->showWrite->isChecked())
    {
        this->OutputRegion->append("测试模式开始！");
        this->  UI2NodeMsg->isCheckShowWrite = true;
    }
    else
    {
        this->  UI2NodeMsg->isCheckShowWrite = false;
    }
    int x = this->ui->pub_x->value();
    int y = this->ui->pub_y->value();
    int theta = this->ui->pub_theta->value();
    int speed = this->ui->pub_speed->value();
    int alpha = this->ui->pub_alpha->value();
    int beta = this->ui->pub_beta->value();
    ros::param::set("X_position",x);
    ros::param::set("Y_position",y);
    ros::param::set("Theta",theta);
    ros::param::set("Speed",speed);
    ros::param::set("Alpha",alpha);
    ros::param::set("Beta",beta);
    this->OutputRegion->append("正在发送相关内容！");
    this->pub_ui_writeMsg.publish(*this->  UI2NodeMsg);
    this->OutputRegion->append("Both info have published successfully!");
    
}
void controlWindow::on_launchButton_pressed()
{
    this->OutputRegion->append("开始执行发射命令");
    this->UI2NodeMsg->mode = 100;
    this->UI2NodeMsg->isCheckShowWrite = this->ui->showWrite->isChecked();
    this->pub_ui_writeMsg.publish(*(this->UI2NodeMsg));
}
/*!
    @author Chao Liu
    @brief 当紧急制动按钮按下时
*/
void controlWindow::on_emergencyButton_pressed()
{
    this->OutputRegion->append("[on_emergencyButton_pressed]紧急停止命令开始启动");
    this->UI2NodeMsg->mode = 99;
    this->UI2NodeMsg->isCheckShowWrite = this->ui->showWrite->isChecked();
    this->pub_ui_writeMsg.publish(*(this->UI2NodeMsg));
}
/*！
    @brief This function is used to initialize the connection between SIGN and SLOT
*/
void controlWindow::connect_init()
{
    this->OutputRegion->append("UI starting to initialize connection"); 
    connect(this->tim, SIGNAL(timeout()), this, SLOT(on_tim_timeout()));
    connect(this->ui->PublishIndicator, SIGNAL(pressed()),this, SLOT(on_publishIndicatorButton_pressed()));
    connect(this->ui->launch, SIGNAL(pressed()),this, SLOT(on_launchButton_pressed()));
    connect(this->ui->emergencyStop, SIGNAL(pressed()),this, SLOT(on_emergencyButton_pressed()));
    connect(this->ui->IMUSetZero, SIGNAL(pressed()),this, SLOT(on_IMUSetZeroButton_pressed()));
    connect(this->ui->clearOutputButton, SIGNAL(pressed()),this, SLOT(on_clearOutputButton_pressed()));
}
void controlWindow::on_IMUSetZeroButton_pressed()
{
    this->OutputRegion->append("开始执行IMU调零命令");
    this->UI2NodeMsg->mode = 101;
    this->UI2NodeMsg->isCheckShowWrite = this->ui->showWrite->isChecked();
    this->pub_ui_writeMsg.publish(*(this->UI2NodeMsg));
 
}

void controlWindow::on_clearOutputButton_pressed()
{
    this->OutputRegion->clear();
}