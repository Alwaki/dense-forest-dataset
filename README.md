# dense-forest-dataset
This repository contains a dataset collected by UAV over dense boreal forest. 

The files are available at [Link](https://huggingface.co/Alwaki/forest_dataset/tree/main).

## Usage


## Collection process
The dataset is collected over 4 plots, as seen below. The annotation "S" indicates where the drone takes off from. For collection, a Matrice 300 drone is used. Ranged sensor modalities include LiDAR (Livox Avia), and RGB camera (Basler dart 1600-60uc). Each plot is provided as a separate file, with corresponding information regarding annotations and sensor extrinsics provided. The files are stored in a separate repository, in case storage options change over time.

![survey-area](images/survey.png)

## Visual examples
The output can be visualized in for example RVIZ from the rosbags, as shown here

### RVIZ angled point cloud visualization
![view with road](images/pc_side.png)

### RVIZ top down point cloud visualization
![top](images/pc_top.png)
