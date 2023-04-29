#!/usr/bin/env python3
# coding:utf-8
import rospy
import sys
import tty
import termios

def readchar():
    fd = sys.stdin.fileno()
    old_settings = termios.tcgetattr(fd)
    try:
        tty.setraw(sys.stdin.fileno())
        ch = sys.stdin.read(1)
    finally:
        termios.tcsetattr(fd, termios.TCSADRAIN,old_settings)
    return ch
def readkey(getchar_fn=None):
    getchar = getchar_fn or readchar
    c1 = getchar()
    if ord(c1) !=0x1b:
        return c1
    c2 = getchar()
    if ord(c2) !=0x5b:
        return c1
    c3 = getchar()
    return chr(0x10+ord(c3) - 65)


if __name__ == '__main__':
    # Create node
    rospy.init_node("ChangeParams")
    print("Please input angle and spped")
    print("w means to increase angle ,s means to decrease")
    print("a means to increase spped ,d means to decrease")
    rospy.set_param("send_speed",0)
    rospy.set_param("send_angle",0)
    key = readkey()
    while  rospy.is_shutdown:
        while key != "w":
            angle = 0;
            rospy.set_param("send_angle",angle)
        if key == "w":
            angle = 1;
            rospy.set_param("send_angle",angle)
        key = readkey()
        if key == "q":
            break
    #     # angle = int(input("angle:"))
    #     # speed = int(input("speed:"))
    #     # rospy.set_param("send_angle",angle)
    #     # rospy.set_param("send_speed",speed)
    #     key = readkey()
    #     if key == 'w' or key == 'W':
    #         angle = rospy.get_param("send_angle");
    #         angle = 1
    #         rospy.set_param("send_angle",angle)
    #     else:
    #         angle = 0;
    #         rospy.set_param("send_angle",angle)
    #     if key == 's' or key == 'S':
    #         angle = rospy.get_param("send_angle");
    #         angle = angle - 1
    #         rospy.set_param("send_angle",angle)
    #     if key == 'a' or key == 'A':
    #         speed = rospy.get_param("send_speed");
    #         speed = speed +1;
    #         rospy.set_param("send_speed",speed)
    #     if key == 'd' or key == 'd':
    #         speed = rospy.get_param("send_speed");
    #         speed = speed - 1
    #         rospy.set_param("send_speed",speed)
    #     if key == 'q' or key == 'Q':
    #         break