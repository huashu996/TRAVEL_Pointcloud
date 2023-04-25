//
// Created by Hyungtae Lim on 6/23/21.
//

// For disable PCL complile lib, to use PointXYZILID
#define PCL_NO_PRECOMPILE
#include "travel/node.h"
#include "utils/kitti_loader.hpp"
#include "utils/utils.hpp"

#include "travel/aos.hpp"
#include "travel/tgs.hpp"

using PointType = pcl::PointXYZI;
using namespace std;
class Pubnode
{
private:
    ros::NodeHandle nh;
    ros::Publisher NodePublisher;
    ros::Subscriber sub_lidar_points;
    std::string node_topic;
    
public:
	Pubnode():
    nh("~"){
    	sub_lidar_points = nh.subscribe("/velodyne_points", 100, &Pubnode::callback, this);
    	nh.param<string>("/node_topic" , node_topic, "/node");
    	NodePublisher = nh.advertise<travel::node>(node_topic, 100, true);
    }


    void callback(const sensor_msgs::PointCloud2 input_cloud_msg)
    {
        /*
        pcl::fromROSMsg(*input_cloud_msg, *input_cloud_ptr);
        cout<<"receiving pointcloud"<<endl;
        
        sensor_msgs::PointCloud2 cloud_ROS;
    	pcl::toROSMsg(cloud, cloud_ROS);
    	*/
    	travel::node node;
        node.lidar = input_cloud_msg;
        node.header = node.lidar.header;
        node.header.frame_id = "os_sensor";
        
        NodePublisher.publish(node);
    }
};

int main(int argc, char** argv)
{
  //1、节点初始化 及定义参数
    ros::init(argc, argv, "pub_node");
    Pubnode pnode;
    ros::spin();
    return 0;
}
