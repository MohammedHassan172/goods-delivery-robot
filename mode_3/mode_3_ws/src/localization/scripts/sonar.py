#!/usr/bin/env python3
import rospy
from std_msgs.msg import *
from geometry_msgs.msg import *
from sensor_msgs.msg import LaserScan
from tf.transformations import euler_from_quaternion
import numpy as np
import time
from itertools import count

index = count(step=1)  #### time counter 

pub_laser=rospy.Publisher("scan", LaserScan, queue_size=100)
pub_servo=rospy.Publisher("servo", UInt16  , queue_size=10)

w_list = [0,0,0,0]
a=[0]
def callback1(data):
    global w_list
    for i in range(4):
        q=data.data[i]
        w=q/100
        if w>4:
            w=4
        elif w==0:
            w=0.01
        w_list[i]=round(w,3)
        # print(w1)

    # q=data.data
    # w=q/100
    # if w>4:
    #     w=4
    # elif w==0:
    #     w=0.01
    # w1=round(w,3)
    # print(w1)


scan_time=0.1
def laser():
    global w_list
    #now = rospy.get_rostime()
    time_begin = rospy.Time.now()
    r = rospy.Rate(10) # 10hz
    b=a*360
    while not rospy.is_shutdown():
        time_end = rospy.Time.now()
        for i in range(90):
            pub_servo.publish(i)
            
            time.sleep(scan_time)
            #b.insert(i,w1)
            b[i]=w_list[2]
            b[i + 90]=w_list[1]            # other ultra sonic go there.
            b[i + 180]=w_list[0]
            b[i + 270]=w_list[3]
            laser=LaserScan()
            Time=next(index)
            d=time_end-time_begin
            laser.header.seq=d
            laser.header.stamp=time_end
            laser.header.frame_id='scan5'
            laser.angle_min= 0*np.pi/180
            laser.angle_max= 359*np.pi/180
            laser.angle_increment= np.pi/180
            laser.time_increment= 0.001
            laser.scan_time= 0.001
            laser.range_min= 0.01
            laser.range_max= 4
            laser.ranges=b
            laser.intensities=[]
            pub_laser.publish(laser)

    if i==90:
        pub_servo.publish(0)
        #b=b  
    r.sleep()

rospy.Subscriber('/sonar', Float64MultiArray, callback1)


rospy.init_node('laser', anonymous=True)


if __name__ == '__main__':
    try:
        laser()
    except rospy.ROSInterruptException:
        pass

