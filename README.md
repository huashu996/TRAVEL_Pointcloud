## Test Env.
- Ubuntu 18.04 LTS
- ROS Melodic
- Ubuntu 20.04 (Compile the node message only before compiling the main code.)
## How to Build
1. Dependencies
    ```
    sudo apt install cmake libeigen3-dev libboost-all-dev
    sudo apt-get install ros-melodic-jsk-recognition
    sudo apt-get install ros-melodic-jsk-common-msgs
    sudo apt-get install ros-melodic-jsk-rviz-plugins
    ```
2. Build
    ```
    mkdir -p catkin_ws/src/
    cd catkin_ws/src/
    git clone https://github.com/url-kaist/TRAVEL.git
    ../
    catkin_make
    ```
## How to Run TRAVEL
3. RUN!
    ```
    Change the pointcloud topic name in point_publisher.cpp
    roslaunch travel run.launch
    ```


## Citation
If our research has been helpful, please cite the below papers:

```
@ARTICLE{oh2022travel,  
    author={Oh, Minho and Jung, Euigon and Lim, Hyungtae and Song, Wonho and Hu, Sumin and Lee, Eungchang Mason and Park, Junghee and Kim, Jaekyung and Lee, Jangwoo and Myung, Hyun},  
    journal={IEEE Robotics and Automation Letters},   
    title={TRAVEL: Traversable Ground and Above-Ground Object Segmentation Using Graph Representation of 3D LiDAR Scans},   
    volume={7},  
    number={3},  
    pages={7255-7262},  
    year={2022},
    }
```
```
@article{lim2021patchwork,
    title={Patchwork: Concentric Zone-based Region-wise Ground Segmentation with Ground Likelihood Estimation Using a 3D LiDAR Sensor},
    author={Lim, Hyungtae and Minho, Oh and Myung, Hyun},
    journal={IEEE Robot. Autom. Lett.},
    volume={6},
    number={4},
    pages={6458--6465},
    year={2021},
    }
```
```
@article{lim2021erasor,
    title={ERASOR: Egocentric Ratio of Pseudo Occupancy-Based Dynamic Object Removal for Static 3D Point Cloud Map Building},
    author={Lim, Hyungtae and Hwang, Sungwon and Myung, Hyun},
    journal={IEEE Robotics and Automation Letters},
    volume={6},
    number={2},
    pages={2272--2279},
    year={2021},
    publisher={IEEE}
    }
```
