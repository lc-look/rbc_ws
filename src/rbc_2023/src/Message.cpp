#include "Message.h"
#include "ros/ros.h"

/*
    This is BaseMsg class realized region
*/
// set x and y ,Theta
void BaseMsg::setMsg(int x, int y, int theta)
{
    this->x = x;
    this->y = y;
    this->theta = theta;
    this->xHigh8 = abs(x)>>8;
    this->xLow8 = x%255;
    this->yHigh8 = abs(y)>>8;
    this->yLow8 = y%255;
    this->thetaHigh8 = abs(theta)>>8;
    this->thetaLow8 = theta%255;
    // try
    // {
    //     this->x = x;
    //     int x_abs = abs(x);
    //     int y_abs = abs(y);
    //     int theta_abs = abs(theta);
    //     this->y = y;
    //     this->theta = theta;
    //     // This is X part
    //     if(x_abs>=2^8)
    //     {
    //         this->xLow8  = x_abs&255;
    //         this->xHigh8 = x_abs>>8;
    //     }
    //     else if(x_abs>=0 && x_abs<=(2^8)-1)
    //     {
    //         this->xLow8 = x;
    //         this->xHigh8 = 0;
    //     }
    //     else
    //     {
            
    //         throw 1;
    //     }

    //     if (x<0)
    //     {
    //         this->xHigh8 = this->xHigh8 + 2^7;
    //     }
    //     // This is Y part
    //     if(y>=2^8)
    //     {
    //         this->yLow8  = y&255;
    //         this->yHigh8 = y>>8;
    //     }
    //     else if(y>=0 && y<=(2^8)-1)
    //     {
    //         this->yLow8 = y;
    //         this->yHigh8 = 0;
    //     }
    //     else
    //     {
            
    //         throw 1.0;
    //     }

    //     // This is theta part
    //     if(theta>=2^8)
    //     {
    //         this->thetaLow8  = theta&255;
    //         this->thetaHigh8 = theta>>8;
    //     }
    //     else if(theta>=0 && theta<=(2^8)-1)
    //     {
    //         this->thetaLow8 = theta;
    //         this->thetaHigh8 = 0;
    //     }
    //     else
    //     {
            
    //         throw 'a';
    //     }
    // }
    // catch(int i)
    // {
    //     ROS_WARN("The input x coordinate is out of range");
    // }
    // catch(double i)
    // {
    //     ROS_WARN("The input y coordinate is out of range");
    // }
    // catch(char i)
    // {
    //     ROS_WARN("The input theta coordinate is out of range");
    // }
}
void BaseMsg::showXYTheta()
{
    cout<<"xHigh8="<<this->xHigh8<<","
        <<"xLow8="<<this->xLow8<<","
        <<"yHigh8="<<this->yHigh8<<","
        <<"yLow8="<<this->yLow8<<","
        <<"thetaHigh8="<<this->thetaHigh8<<","
        <<"thetaLow8="<<this->thetaLow8<<endl;
}
string BaseMsg::getMsgStr()
{
    if(this->x <0)
    {
        this->msgChar[0] =(uint8_t)1;
    }
    else
    {
        this->msgChar[0] =(uint8_t)0;
    }
    this->msgChar[1] =(uint8_t)(this->xHigh8);
    this->msgChar[2] =(uint8_t)(this->xLow8);
    this->msgChar[3] =(uint8_t)(this->yHigh8);
    this->msgChar[4] =(uint8_t)(this->yLow8);
    if(this->theta < 0)
    {
        this->msgChar[5] =(uint8_t)1;
    }
    else
    {
        this->msgChar[5] =(uint8_t)0;
    }
    string str = "";

    for (int i = 0; i<8;i++)
    {
        str.append(1,this->msgChar[i]);
    }
    this->msgStr = str;
    return str;
}


void UpperMsg::setMsg(int alpha,int beta,int speed)
{
    this->alpha = alpha;
    this->beta = beta;
    this->speed = speed;
}

string UpperMsg::getMsgStr()
{
    if (this->alpha<0)
    {
        this->msgChar[0] = (uint8_t)(1);
        this->msgChar[1] = (uint8_t)(-this->alpha);
    }
    else
    {
        this->msgChar[0] = (uint8_t)(0);
        this->msgChar[1] = (uint8_t)(this->alpha);
    }
    this->msgChar[2] = (uint8_t)(this->beta);
    this->msgChar[3] = (uint8_t)(this->speed);
    string tmp = "";
    for (int i = 0; i < 4; i++)
    {
        tmp.append(1,this->msgChar[i]);
    }
    this->msgStr = tmp;
    return this->msgStr;
}

void ControllerMsg::setMsg(const sensor_msgs::Joy::ConstPtr& data)
{
    if(data->axes[7]==1)
    {
        this->forward   = 1;
        this->backups   = 0;
    }
    else if(data->axes[7]==-1)
    {
        this->forward   = 0;
        this->backups    = 1;
    }
    else
    {
    this->forward   = 0;
    this->backups    = 0;
    }
    if(data->axes[6]==1)
    {
    this->left      = 1;
    this->right     = 0;
    }
    else if(data->axes[6]==-1)
    {
        this->left      = 0;
        this->right     = 1;
    }
    else
    {
        this->left      = 0;
        this->right     = 0;
    }
    this->turnLeft  = data->buttons[4];
    this->turnRight = data->buttons[5];
    this->Y = data->buttons[3];
    this->A = data->buttons[0];
    this->X = data->buttons[2];
    this->B = data->buttons[1];
    this->launch = data->buttons[6];
    if(data->axes[2]<0)
    {
        this->launchSpeedUp   = 1;
        this->launchSpeedDown = 0;
    }
    else if(data->axes[5]<0)
    {
        this->launchSpeedUp   = 0;
        this->launchSpeedDown = 1;
    }
    else
    {
        this->launchSpeedUp = 0;
        this->launchSpeedDown = 0;
    }
}
/*!
    \brief Transform controller messages in type of int to string
    \return 
    string:
        1.forwards
        2.backups(backwards)
        3.left
        4.right
        5.turnLeft
        6.turnRight
        7.Y
        8.A
        9.X
        10.B
        11.加速
        12.减速
        13.发射

*/
string ControllerMsg::getMsgStr()
{
    this->msgChar[0] = this->forward;
    this->msgChar[1] = this->backups;
    this->msgChar[2] = this->left;
    this->msgChar[3] = this->right;
    this->msgChar[4] = this->turnLeft;
    this->msgChar[5] = this->turnRight;
    this->msgChar[6] = this->Y;
    this->msgChar[7] = this->A;
    this->msgChar[8] = this->X;
    this->msgChar[9] = this->B;
    this->msgChar[10] = this->launchSpeedUp;
    this->msgChar[11] = this->launchSpeedDown;
    this->msgChar[12] = this->launch;
    this->msgStr = "";
    for (int i =0; i<12;i++)
    {
        this->msgStr.append(1,this->msgChar[i]);
    }
    return this->msgStr;
}


// Change mode from ros parameter service
void Message::setMode()
{
    ros::param::get("mode",this->mode);
}

// return Id in type of string
string Message::getIDStr()
{
    string IDStr = "";
    IDStr.append(1,(uint8_t)this->ID);
    return IDStr;
}


/*!
    @brief 返回字符串类型的Mode，其中字符串中的数据单位为字符型
*/
string Message::getModeStr()
{
    string ModeStr = "";
    ModeStr.append(1,(uint8_t)this->mode);
    return ModeStr;
}

void Message::updateFromController(const sensor_msgs::Joy::ConstPtr& data)
{
    this->controller.setMsg(data);
    this->controllerMsgStr = this->controller.getMsgStr();
}
/*
    This function will get x,y,theta from param service and change base object message x,y,theta
*/
void Message::updateFromUI()
{
    // update Base position 
    int x;
    int y;
    int theta;
    ros::param::get("X_position",x);
    ros::param::get("Y_position",y);
    ros::param::get("Theta",theta);
    this->base.setMsg(x,y,theta);
    int alpha;
    int beta;
    int speed;
    ros::param::get("Alpha",alpha);
    ros::param::get("Beta",beta);
    ros::param::get("Speed",speed);
    this->upper.setMsg(alpha,beta,speed);
    ROS_INFO("Message have updated from UI!");
}

void Message::writeMsgUI()
{
    ROS_INFO("Automatic Mode message");
    this->msgStr.clear();
    this->msgStr.append(1,(uint8_t)this->ID);
    this->msgStr.append(1,uint8_t(this->mode));
    this->msgStr.append(this->base.getMsgStr());
    this->msgStr.append(this->upper.getMsgStr());
    this->writeMsgInTryMode();
    // 
    // if(~this->checkReturn())
    // {
    //     ROS_WARN("当前ID与发送ID不同,重新发送");
    //     this->writeMsg();
    // }

}
/*!
    @brief 发送紧急消息指令(send command of emergency indicator)
*/
void Message::writeMsgEmergency()
{
    this->msgStr.clear();
    this->msgStr.append(this->getIDStr());
    this->msgStr.append(this->getModeStr());
    this->msgStr.append(1,(uint8_t)1);
    this->writeMsgInTryMode();
    // this->ser->write(this->msgStr);
    // string str = this->readMsg();
    this->print2UI("[writeMsg]紧急停止命令下达完毕！");
    // if(~this->checkReturn())
    // {
    //     this->writeMsg();//递归发送(Send in traverse message)
    // }
}
/*!
    @brief 此方法将会将发射消息下达至stm32，同时该命令中包含两个消息第一个是发射第二个是收回，id在该方法中增加两次
*/
void Message::writeMsgLaunch()
{
    ros::Rate r(1);

    if(this->bullet-1 > 0)
    {
        this->msgStr.clear();
        this->msgStr.append(this->getIDStr());
        this->msgStr.append(1,(uint8_t)102);
        this->msgStr.append(1,(uint8_t)4);
    }
    else
    {
        this->print2UI("[writeMsgLaunch]需要重新拾取,当前剩余弹量为0");
    }
    

    this->msgStr.clear();
    this->msgStr.append(this->getIDStr());
    this->msgStr.append(this->getModeStr());
    this->msgStr.append(1,(uint8_t)1);
    this->writeMsgInTryMode();
    r.sleep();
    // this->ser->write(this->msgStr);
    // string str = this->readMsg();
    
    //
    this->print2UI("[writeMsgLaunch]开始执行发射！");
    //
    


    this->print2UI("开始收回！");
    this->msgStr.clear();
    this->msgStr.append(this->getIDStr());
    this->msgStr.append(this->getModeStr());
    this->msgStr.append(1,(uint8_t)0);
    this->writeMsgInTryMode();
    // this->ser->write(this->msgStr);
    // string str12 = this->readMsg();
    
    ROS_INFO("Take back and reload to bullet");
    this->bullet = this->bullet -1;
}

/*!
    @author Chao Liu
    @brief 根据当前模式选择相应的消息写入，当写入完成后会自动读取消息并将返回消息存储在成员backMsgStr中
    @attention 当前写入的消息部分包括前面的头部，mode和ID后面的数据根据mode进行区分
*/
void Message::writeMsg()
{
    bool isRight = true;//是否是包含对应的模式
    cout<< this->mode <<endl;
    if(this->mode == 0)
    {
        ROS_INFO("[writeMsg]Write message in UI mode ");
        this->writeMsgUI();
    }
    else if(this->mode == 1)
    {
        ROS_INFO("controller mode message");
        this->writeMsgController();
    }
    else if (this ->mode == 99)
    {
        ROS_INFO("Emergency mode");
        this->writeMsgEmergency();
    }
    else if (this ->mode == 100)
    {
        ROS_INFO("[writeMsg]Write message in launch mode");
        this->writeMsgLaunch();
    }
    else if (this->mode == 101)
    {
        ROS_INFO("[writeMsg]Write message in IMU setting zero mode");
        this->writeMsgIMU2zero();
    }
    else if (this->mode == 102)
    {
        ROS_INFO("[writeMsg]Write message in pick mode");
        this->writeMsgPick();
    }
    else if (this->mode == 103)
    {
        ROS_INFO("[writeMsg]Write message in reload mode");
        this->writeMsgReload();
    }
    else
    {
        ROS_INFO("[writeMsg]Unknown mode:%d", this->mode);
    }

    //Check if output stream to output file
    // if(this->isOutFile)
    // {
    //     ofstream fileOut;
    //     string str;
    //     str.append("[writeMsg]:");
    //     str.append("开始定向文件流输出至："); 
    //     str.append(this->outputFileName+"\n"); 
    //     fileOut.open(this->outputFileName);
    //     fileOut << this->msgStr << endl;
    //     str.append("定向文件流结束");
    //     this->print2UI(str);
    //     fileOut.close();
    // }
    
}

/*
    write base message to stm32
    1. dataID,Mode,xHigh,xLow,yHigh,yLow,theta 
    2. Via serial to send message
*/
void Message::writeMsgBase()
{
    string baseStr = this->base.getMsgStr();//base string takes 6 bytes
    string dataID  = this->getIDStr();
    string modeStr = this->getModeStr();
    this->ser->write(dataID+modeStr+baseStr);
    string str = dataID + modeStr + baseStr;
    const char * data = str.c_str();
    this->showStrInfo(str);
    this->base.showXYTheta();
    cout<<"The length of string:"<<str.length()<<endl;
}
/*
    Transform the string to array of char type show it in int format
*/
void Message::showStrInfo(const string& strInfo) 
{
    int len  = strInfo.length();
    const char *a;
    uint8_t tmp[len];
    a = strInfo.c_str();
    cout<<"The written message :"<<endl;
    for (int i =0; i<len; i++)
    {
        tmp[i] =  a[i];
        if(i != len-1)
        {
            cout<<int(tmp[i])<<",";
        }
        else
        {
            cout<<int(tmp[i])<<endl;
        }
    }
}
void Message::addID()
{
    this->ID = (++(this->ID))%255;
}
/*!
    @brief 检查当前返回值ID是否与发送IDa相同，如果是则1返回true否则返回false
            (check whether the message of ID is seem as send. It will return true if the message)
*/
bool Message::checkReturn()
{
    if((int)this->backMsgStr[1] == this->mode)
    {
        return true;
    }
    else
    {
        return false;
    }
}
/*!
    \author Chao Liu
    \brief This function get message information from stm32 in controller mode
    \param  i The size buffer to read from stm32
*/
uint8_t* Message::readMsgINControllerMode(int i)
{
    uint8_t * backMsg;
    this->ser->read(backMsg,i);
    return backMsg;
}
uint8_t* Message::readMsgINBaseMode()
{
    uint8_t * backMsg;
    this->ser->read(backMsg, 7);
    return backMsg;
}

/*!
    \author Chao Liu
    \brief This function get message from controller and send it to stm32, when you use controller 
    and this will change your message mode
*/
void Message::writeMsgController()
{
    this->msgStr = this->getIDStr() + this->getModeStr() + this->controller.getMsgStr();
    this->ser->write(this->msgStr);

}
void ControllerMsg::showMsg()
{
    cout<<"Forward = "<<this->forward<<endl;
    cout<<"Backward = "<<this->backups<<endl;
    cout<<"Left = "<<this->left<<endl;
    cout<<"Right = "<<this->right<<endl;
    cout<<"TurnLeft = "<<this->turnLeft<<endl;
    cout<<"TurnRight = "<<this->turnRight<<endl;
    cout<<"Y = "<<this->Y<<endl;
    cout<<"A = "<<this->A<<endl;
    cout<<"X = "<<this->X<<endl;
    cout<<"B = "<<this->B<<endl;
    cout<<"launchSpeedUp = "<<this->launchSpeedUp<<endl;
    cout<<"launchSpeedDown = "<<this->launchSpeedDown<<endl;
    cout<<"launch = "<<this->launch<<endl;
}

int ControllerMsg::getSpeedStatue()
{
    if(this->launchSpeedUp == 1 && this->launchSpeedDown == 0)
    {
        return 1;
    }
    else if(this ->launchSpeedUp == 0 && this->launchSpeedDown == 1)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

void Message::changeMode(int m)
{
    cout << m <<endl;
    if(m == this->mode)
    {
        return;
    }
    else if(m == 1)
    {
       ROS_INFO("[changeMode]Change controller mode"); 
       this->mode = 1;
    }
    else if(m == 0)
    {
        ROS_INFO("[changeMode]Change Automatically mode"); 
       this->mode = 0;
    }
    else if(m == 100)
    {
        ROS_INFO("[changeMode]Change Launch mode");
        this->mode = 100;
    }
    else if(m == -1)
    {
        this->mode =-1;
    }
    else if(m == 99)
    {
        ROS_INFO("[changeMode]Change Emergency mode");
        this->mode = 99;
    }
    else if(m == 101)
    {
        ROS_INFO("[changeMode]Change IMU to zero mode");
        this->mode = 101;
    }
    else if(m == 102)
    {
        ROS_INFO("[changeMode]Change pick mode");
        this->mode = 102;
    }
    else if(m == 103)
    {
        ROS_INFO("[changeMode]Change reload mode");
        this->mode = 103;
    }
    else
    {
        ROS_WARN("Unknown mode: %d,Please add it at function changeMode", m);
    }
}



/*!
    @brief 读取串口数据，并设置当前返回消息字符串(Setting string of back messages, which is read from serial)
*/
string Message::readMsg()
{
    bool isReadSuccess = false;
    try
    {
        this->backMsgStr = this->ser->readline();
        string str_tmp;
        if((uint8_t)this->msgStr[1]==10 || (uint8_t)this->msgStr[1]==11)
        {
            // print2UI(to_string((uint8_t)this->msgStr[1]));
        }
        else
        {
            if(this->backMsgStr.length()==0)
            {
                this->print2UI("[readMsg]接受到的消息为空");
                return this->backMsgStr;
            }
            else
            {
                str_tmp.append("[readMsg]收到消息:");
                for(int i = 0; i < this->backMsgStr.length(); i++)
                {
                    str_tmp.append((to_string((uint8_t)this->backMsgStr[i])));
                    str_tmp.append(" ");
                }
                this->print2UI(str_tmp);
            }
        }
        this->processBackMsg();
        return this->backMsgStr;
    }
    catch(serial::PortNotOpenedException &e)
    {
        cout << "[readMsg]Error:Can't read message from port " << e.what() << endl;        this->print2UI("[readMsg]Error:Can't read message from port ");
    }
    return this->backMsgStr;
}
/*!
    @brief 根据模式和返回的字符串更新相应参数（Update parameter from return according to the mode and string）
*/
void Message::updateFromReturn(string backMsgStr, int mode)
{
    if(mode == 0)
    {
        ROS_INFO("Update message from return in mode 0");
        int x_sign = (int)backMsgStr[1];
        int x = backMsgStr[2]<<8 + backMsgStr[3];
        if(x == 1)
        {
            x = x*(-1);
        }
        int y = backMsgStr[4]<<8 + backMsgStr[5];
        int theta_sign = (int)backMsgStr[6];
        int theta = backMsgStr[7]<<8 + backMsgStr[8];
        if(theta == 1)
        {
            theta = theta*(-1);
        }
        ros::param::set("X_present",x);
        ros::param::set("Y_present",y);
        ros::param::set("Theta_present",theta);
    }
}

/*!
    @brief 将写入到stm32的命令保存到指定文件，默认为ForOutTest.txt文件
*/
void Message::openOutputFile()
{
    this->outputFileName = "ForOutTest.txt";
    ROS_INFO("[openOutFile]:Start to open output file:%s",this->outputFileName.c_str());
    this->isOutFile = true;
}
/*!
    @brief 将写入到stm32的命令保存到指定文件，默认为ForOutTest.txt文件
    @param fileName 指定的文件
*/
void Message::openOutputFile(const std::string filename)
{
    this->outputFileName = "ForOutTest.txt";
    ROS_INFO("[openOutFile]:Start to open output file:%s",this->outputFileName.c_str());
    this->isOutFile = true;
}
/*!
    @brief 将消息发送到UI的窗口界面
    @param str 将要发送的消息
*/
void Message::print2UI(const std::string str)
{
    this->sendUIMsg.mode = -1;
    this->sendUIMsg.backStr = str;
    // cout <<"successfully"<<endl;
    this->pub_node2UI.publish(this->sendUIMsg);
}
/*!
    @brief 将消息发送到UI的窗口界面，同时将接受到的原始数据发送到UI
    @param str 将要发送的消息
    @param rawStr 收到的原始数据
*/
void Message::print2UI(const std::string str,const std::string rawStr)
{
    this->sendUIMsg.mode = -2;
    this->sendUIMsg.backStr = str;
    this->sendUIMsg.rawStr = rawStr;
    this->pub_node2UI.publish(this->sendUIMsg);
} 
/*!
    @brief 将接受到的原始数据发送到UI
    @param m3 推荐值为-3
    @param rawStr 原始数据
*/
void Message::print2UI(int m3,const std::string rawStr)
{
    this->sendUIMsg.mode = -3;
    this->sendUIMsg.rawStr = this->backMsgStr;
    this->pub_node2UI.publish(this->sendUIMsg);
}

/*!
    @brief 处理串口接受到的消息

*/
void Message::processBackMsg()
{
    int m = (u_int8_t)this->backMsgStr[1];
    if(m == 10)
    {
        int x_flag = (u_int8_t)this->backMsgStr[2];
        if(x_flag == 0)
        {
            x_flag = 1;
        }
        else if(x_flag == 1)
        {
            x_flag = -1;
        }
        else
        {
            ROS_ERROR("[processBackMsg]接受到错误的X符号位");
        }
        int x_high8 = (u_int8_t)this->backMsgStr[3];
        x_high8 = x_high8<<8;
        int x_low8 = (u_int8_t)this->backMsgStr[4];
        int x = x_high8 + x_low8;
        x = x*x_flag;
        int y_high8 = (u_int8_t)this->backMsgStr[5];
        y_high8 = y_high8<<8;
        int y_low8 = (u_int8_t)this->backMsgStr[6];
        int y = y_high8 + y_low8;
        y = y;
        int theta_flag = (u_int8_t)this->backMsgStr[7];
        if(theta_flag == 0)
        {
            theta_flag = 1;
        }
        else if(theta_flag == 1)
        {
            theta_flag = -1;
        }
        else
        {
            ROS_ERROR("[processBackMsg]接受到错误的tehta符号位");
        }
        int theta_high8 = (u_int8_t)this->backMsgStr[8];
        theta_high8 = theta_high8<<8;
        int theta_low8 = (u_int8_t)this->backMsgStr[9];
        int theta = theta_high8 + theta_low8;
        theta = theta*theta_flag;
        ros::param::set("X_present",x);
        ros::param::set("Y_present",y);
        ros::param::set("Theta_present",theta);
    }
    else if(m == 11)
    {
        int speed = (uint8_t)this->backMsgStr[2];
        int alpha = (uint8_t)this->backMsgStr[3];
        int beta_flag = (uint8_t)this->backMsgStr[4];
        if(beta_flag == 0)
        {
            beta_flag = 1;
        }
        else if(beta_flag == 1)
        {
            beta_flag = -1;
        }
        else
        {
            ROS_ERROR("[processBackMsg]接受到错误的beta符号位");
        }
        int beta = (uint8_t)this->backMsgStr[5];
        beta = beta*beta_flag;
        ros::param::set("Speed_present",speed);
        ros::param::set("Alpha_present",alpha);
        ros::param::set("Beta_present",beta);
    }
    else
    {
        return;
    }
}
void Message::writeMsgIMU2zero()
{
    this->msgStr.clear();
    this->msgStr.append(this->getIDStr());
    this->msgStr.append(this->getModeStr());
    this->msgStr.append(1,(uint8_t)1);
    this->writeMsgInTryMode();
    // this->ser->write(this->msgStr);
    // string str = this->readMsg();
    this->print2UI("[writeMsg]IMU 调零命令完成");
    // if(~this->checkReturn())
    // {
    //     this->writeMsg();//递归发送(Send in traverse message)
    // }
}
/*!
    @brief 向下位机获取指令,该消息不改变本地mode
    @param mode 指令类型
    @exception int mode 指出发生异常的模式
*/
void Message::writeMsg(int mode)
{
    if(mode ==10)
    {
        try
        {
            this->msgStr.clear();
            this->msgStr.append(this->getIDStr());
            this->msgStr.append(1,(uint8_t)(mode));
            this->ser->write(this->msgStr);
            // cout << "10can we get here? " << endl;
            
            string str = this->readMsg();
        }
        catch(std::invalid_argument &ia)
        {
            ROS_ERROR("[writeMsg(10)]串口ttyUSB0找不到");
            cout << "Error: "<<ia.what()<<endl;
            throw(mode);
        }
        catch(serial::PortNotOpenedException &e)
        {
            cout << "[writeMSg(10)]Error: "<<e.what()<<endl;
            if(this->ser->getPort() == "/dev/ttyUSB1")
            {
                ROS_INFO("检测到串口不匹配，重新开始设置串口！");
                this->ser->setPort("/dev/ttyUSB0");
                cout <<"设置串口为"<<this->ser->getPort() << endl;
            }
            else
            {
                ROS_INFO("[writeMsg(10)]未正确写入数据请检查串口连接！");
            }
            this->print2UI("[writeMsg(10)]Can't open port:"+this->ser->getPort());
                throw(mode);
        }
        catch(serial::IOException &e)
        {
            cout << "[writeMSg(10)]Error: "<<e.what()<<endl;
            this->print2UI("[writeMsg(10)]串口没有插好或未插");
            throw(mode);
        }
        catch(...)
        {
            cout << "[writeMsg(10)]Unknown error" <<endl;
            throw(mode);
        }

        // if(~this->checkReturn())
        // {
        //     this->writeMsg();//递归发送(Send in traverse message)
        // }
    }
    else if(mode == 11)//IMU数据
    {
        this->msgStr.clear();
        this->msgStr.append(this->getIDStr());
        this->msgStr.append(1,(uint8_t)(mode));
        bool isHaveErro = false;
        try
        {   
            this->ser->write(this->msgStr);
            string str = this->readMsg();
            // throw("Prot /dev/ttyUSB1 might be not open error 01");
        }
        catch(std::invalid_argument &ia)
        {
            ROS_ERROR("串口ttyUSB1找不到");
            cout << "Error: "<<ia.what()<<endl;
            throw(mode);
        }
        catch(serial::PortNotOpenedException &e)
        {
            cout << "[writeMSg]Error: "<<e.what()<<endl;
            this->print2UI("[writeMsg]Can't open port ttyUSB1");
            throw(mode);
        }
        catch(serial::IOException &e)
        {
            cout << "[writeMSg]Error: "<<e.what()<<endl;
            this->print2UI("[writeMsg]串口没有插好或未插");
            throw(mode);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            throw(mode);
        }
        catch(...)
        {
            cout << "[writeMsg(11)]unknown Exception" << std::endl;
            throw(mode);
        }
    }
    else
    {
        ROS_WARN("当前想要获取指令的mode未知!");
    }
}
/*!
    @brief This written mode is used to write message in security method. It will check all exceptional exception and send that to UI;If the exception didn't occurred it will read message from serial
    @attention 这是所有写消息的基方法
*/
void Message::writeMsgInTryMode()
{
    try
    {
        this->ser->write(this->msgStr);
        string str = this->readMsg();
        
    }
    catch (serial::PortNotOpenedException & e)
    {
        this->print2UI("[writeMsg]模式"+to_string(this->mode)+"写入消息错误!");
        ROS_ERROR("[writeMsg]mode:%d Message didn't write correctly",this->mode);
    }
    catch (...)
    {
        this->print2UI("[writeMsg]unknown Exception error at mode :"+to_string(this->mode));
    }
    if(this->isShowWrite)
    { 
        string tmp_str="";
        tmp_str.append("发射数据：");
        for (int i =0;i<this->msgStr.size();i++)
        {
            tmp_str.append(to_string(uint8_t(this->msgStr[i])));
            tmp_str.append(" ");
        }
        this->print2UI(tmp_str);
    }
    this->addID();
}


void Message::writeMsgReload()
{
    this->msgStr.clear();
    this->msgStr.append(this->getIDStr());
    this->msgStr.append(this->getModeStr());
    this->msgStr.append(1,(uint8_t)1);
    
    this->writeMsgInTryMode();

    this->print2UI("[writeMsgReload]上膛");


    this->msgStr.clear();
    this->msgStr.append(this->getIDStr());
    this->msgStr.append(this->getModeStr());
    this->msgStr.append(1,(uint8_t)0);
    ros::Duration d(1);
    d.sleep();
    this->writeMsgInTryMode();
    
    ROS_INFO("[writeMsgReload]Reloading mission is over");

}

void Message::writeMsgPick()
{
    this->bullet = 10;
    // 首先张开双臂
    string str = "";
    this->msgStr.clear();
    this->msgStr.append(this->getIDStr());
    this->msgStr.append(this->getModeStr());
    this->msgStr.append(1,(uint8_t)2);
    this->print2UI("[writeMsgPick]拾取动作开始启动");
    this->writeMsgInTryMode();

    ros::Duration d(1);
    d.sleep();

    // 放下
    this->msgStr.clear();
    this->msgStr.append(this->getIDStr());
    this->msgStr.append(this->getModeStr());
    this->msgStr.append(1,(uint8_t)0);
    this->writeMsgInTryMode();
    d.sleep();

    // 夹
    this->msgStr.clear();
    this->msgStr.append(this->getIDStr());
    this->msgStr.append(this->getModeStr());
    this->msgStr.append(1,(uint8_t)1);
    this->writeMsgInTryMode();
    d.sleep();

    // 抬
    this->msgStr.clear();
    this->msgStr.append(this->getIDStr());
    this->msgStr.append(this->getModeStr());
    this->msgStr.append(1,(uint8_t)3);
    this->writeMsgInTryMode();
    this->print2UI("[writeMsgPick]拾取动作完成");


}