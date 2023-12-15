#!/usr/bin/env python

import rospy
from nav_msgs.msg import Odometry
from geometry_msgs.msg import PoseWithCovarianceStamped
new_odom = Odometry()

def callback(data):
    new_odom.header.frame_id = data.header.frame_id
    new_odom.pose = data.pose
    
def listener():

    # rospy.init_node('listener', anonymous=True)
    rospy.Subscriber("amcl_pose", PoseWithCovarianceStamped, callback)
    # rospy.spin()




def convert_1():
    pub = rospy.Publisher('amcl_pose_odom', Odometry, queue_size=10)
    rospy.init_node('hamda', anonymous=True)
    rate = rospy.Rate(40) # 10hz
    while not rospy.is_shutdown():
        pub.publish(new_odom)
        rate.sleep()

if __name__ == '__main__':
    listener()
    try:
        convert_1()
    except rospy.ROSInterruptException:
        pass