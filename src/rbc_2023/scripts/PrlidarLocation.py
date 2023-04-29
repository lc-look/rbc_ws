#! /bin/env python3
import rospy
from sensor_msgs.msg import LaserScan


present_data = LaserScan()
present_data.

def doScan(data):
    pass

if __name__ == '__main__':
    rospy.init_node('PrlidarLocation')
    
    sub = rospy.Subscriber("scan",LaserScan,queue_size=100)