#include "ros/ros.h"
#include "serial/serial.h"
#include "string.h"
#include "tf2_ros/static_transform_broadcaster.h"
#include "tf2/LinearMath/Quaternion.h"
#include "geometry_msgs/TransformStamped.h"
#include "geometry_msgs/PointStamped.h"
using namespace std;


int main(int argc, char **argv)
{
    setlocale(LC_ALL,"");
    ros::init(argc, argv, "test_1");

    tf2_ros::StaticTransformBroadcaster broadcaster;

    geometry_msgs::TransformStamped ts;

    ts.header.seq = 100;
    ts.header.stamp = ros::Time::now();
    ts.header.frame_id = "Base_link";

    ts.child_frame_id = "laser";

    ts.transform.translation.x = 0.2;
    ts.transform.translation.y = 0.0;
    ts.transform.translation.z = 0.5;

    tf2::Quaternion qtn;
    qtn.setRPY(0,0,0);
    ts.transform.rotation.x = qtn.getX();
    ts.transform.rotation.y = qtn.getY();
    ts.transform.rotation.z = qtn.getZ();
    ts.transform.rotation.w = qtn.getW();

    broadcaster.sendTransform(ts);
    ros::spin();
    return 0;
};