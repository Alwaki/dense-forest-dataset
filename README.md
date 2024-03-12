# dense-forest-dataset
This repository contains a dataset collected by UAV over dense boreal forest.

## Dataset description
| Plot ID      | Plot size    | Tree density | nbr pine  | nbr spruce | nbr broad-leaf | 
| ------------ |:------------:|:------------:|:---------:|:----------:|:--------------:|
| 1            | 850          | 2050         | 121       | 53         | 0              |
| 2            | 840          | 2040         | 40        | 131        | 1              |
| 3            | 590          | 1930         | 71        | 40         | 3              |
| 4            | 850          | 1940         | 71        | 26         | 0              |


![survey-area](images/survey.png)

## Sensor description
The drone used is the Matrice 300. Ranged sensor modalities include LiDAR (Livox Avia), and RGB camera (Basler dart 1600-60uc).

## Example output

### RVIZ angled point cloud visualization
![view with road](images/pc_side.png)

### RVIZ top down point cloud visualization
![top](images/pc_top.png)
