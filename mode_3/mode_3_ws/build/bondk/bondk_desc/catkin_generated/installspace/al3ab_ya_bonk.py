#!/usr/bin/env python3


import rospy
from geometry_msgs.msg import Twist
import keyboard
s_s = 0.7
# step = 0.001

bonk_twist = Twist()
def speed():
    if keyboard.is_pressed("w"):
         bonk_twist.linear.x = s_s
         if keyboard.is_pressed("d"):
              bonk_twist.angular.z = -s_s
         elif keyboard.is_pressed("a"):
              bonk_twist.angular.z = s_s
         else:
              bonk_twist.angular.z = 0

    elif keyboard.is_pressed("s"):
         bonk_twist.linear.x = -s_s
         if keyboard.is_pressed("d"):
              bonk_twist.angular.z = -s_s
         elif keyboard.is_pressed("a"):
              bonk_twist.angular.z = s_s
         else:
              bonk_twist.angular.z = 0
    elif keyboard.is_pressed("d"):
         bonk_twist.angular.z = -s_s

    elif keyboard.is_pressed("a"):
         bonk_twist.angular.z = s_s
    else:
         bonk_twist.linear.x = 0
         bonk_twist.angular.z = 0


    # elif keyboard.is_pressed("d"):
    #      bonk_twist.angular.z = s_s

    # elif keyboard.is_pressed("a"):
    #      bonk_twist.angular.z = -s_s
    # else:
    #      bonk_twist.angular.z = 0
         
          


def control():
    pub = rospy.Publisher('cmd_vel', Twist, queue_size=10)
    rospy.init_node('spped', anonymous=True)
    rate = rospy.Rate(10) # 10hz
    while not rospy.is_shutdown():
        speed()
        pub.publish(bonk_twist)
        rate.sleep()

if __name__ == '__main__':
    try:
        control()
    except rospy.ROSInterruptException:
        pass