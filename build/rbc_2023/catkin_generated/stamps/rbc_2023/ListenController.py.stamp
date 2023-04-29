import rospy
import os
from sensor_msgs.msg import Joy

def doJoy(data):
    #set the angle 
    angle_up = 0
    angle_down = 0
    angle_receiver = -data.axes[4]
    if angle_receiver >0:
        angle_up = 1
        angle_down = 0
    elif angle_receiver < 0:
        angle_up = 0
        angle_down = 1
    else:
        angle_up = 0
        angle_down = 0
    # set the direction of the rotation    
    rotate_left = 0;
    rotate_right = 0;
    rotate_receiver = data.axes[3]
    if rotate_receiver >0:
        rotate_left = 1
        rotate_right = 0
    elif rotate_receiver < 0:
        rotate_left = 0
        rotate_right = 1
    else:
        rotate_left = 0
        rotate_right = 0
    speed_up = data.buttons[3];
    speed_down = data.buttons[0];
#     speed_left = data.buttons[2];
#     speed_right = data.buttons[1];
    rospy.set_param('emission_speed_up',speed_up);
    rospy.set_param('emission_speed_down',speed_down);
#     rospy.set_param('motor_speed_left',speed_left);
#     rospy.set_param('motor_speed_right',speed_right);
#     rospy.loginfo("receive times = %d,info:%d,%d,%d,%d", 
#                   seq,speed_up,speed_down
#                   ,speed_left,speed_right)
# 
    rospy.set_param('emission_angle_up',angle_up)
    rospy.set_param('emission_angle_down',angle_down)
    rospy.set_param('emission_rotate_right',rotate_right)  
    rospy.set_param('emission_rotate_left',rotate_left)
    rospy.loginfo("%d,%d,%d,%d,%d,%d",
                  angle_up, angle_down,
                  rotate_left, rotate_right,
                  speed_up, speed_down)


if __name__ == '__main__':
    
    # Initialize ros node 
    a = os.system('sudo chmod 777 /dev/ttyUSB0')
    rospy.init_node('ListenController') 

    sub = rospy.Subscriber('joy',Joy,doJoy,queue_size=1000)
    
    rospy.spin()
