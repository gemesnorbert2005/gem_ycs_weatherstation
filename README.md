# `gem_ycs_weatherstation` package
ROS 2 C++ package.  [![Static Badge](https://img.shields.io/badge/ROS_2-Humble-34aec5)](https://docs.ros.org/en/humble/)


A package két node-ból áll. A `/weather_station_node` egy Weather típusú üzenetben időjárási adatokat hirdet a `/weather` topicban. A `/comfort_index_solver_node` fogadja az adatokat és kiszámol a segítségükkel egy úgynevezett "comfort index"-et, majd kiírja ennek értékét. Megvalósítás `ROS 2 Humble` alatt
## Packages and build

It is assumed that the workspace is `~/ros2_ws/`.

### Clone the packages
``` r
cd ~/ros2_ws/src
```
``` r
git clone https://github.com/gemesnorbert2005/gem_ycs_weatherstation
```

### Build ROS 2 packages
``` r
cd ~/ros2_ws
```
``` r
colcon build --packages-select gem_ycs_weatherstation --symlink-install
```

<details>
<summary> Don't forget to source before ROS commands.</summary>

``` bash
source ~/ros2_ws/install/setup.bash
```
</details>

``` r
ros2 launch gem_ycs_weatherstation weather_system.launch.py
```

