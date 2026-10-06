from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='gem_ycs_weatherstation',
            executable='weather_station_node',
            name='weather_station_node',
            output='screen'
        ),
        Node(
            package='gem_ycs_weatherstation',
            executable='comfort_index_solver_node',
            name='comfort_index_solver_node',
            output='screen'
        )
    ])
