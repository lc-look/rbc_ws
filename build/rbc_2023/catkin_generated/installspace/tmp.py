#!/usr/bin/env python3
# coding:utf-8
from std_msgs.msg import *
import rospy

if __name__ == '__main__':
    rospy.init_node('tmp');
    pub = rospy.Publisher('SendingType',Int32,queue_size=100);
    msg = Int32();
    msg.data = 0;
    r = rospy.Rate(10)
    while not rospy.is_shutdown():
        pub.publish(msg);
        r.sleep();
        rospy.loginfo("sending successful:%d",msg.data);
        