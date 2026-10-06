cmake_minimum_required(VERSION 3.8)
project(gem_ycs_weatherstation)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

find_package(rosidl_default_generators REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/Weather.msg"
)

ament_export_dependencies(rosidl_default_runtime)

set(ament_dependencies
  rclcpp
  std_msgs
)

add_executable(weather_station_node src/weather_station_node.cpp)
ament_target_dependencies(weather_station_node ${ament_dependencies})

rosidl_target_interfaces(weather_station_node
  ${PROJECT_NAME} "rosidl_typesupport_cpp")

add_executable(comfort_index_solver_node src/comfort_index_solver_node.cpp)
ament_target_dependencies(comfort_index_solver_node ${ament_dependencies})

rosidl_target_interfaces(comfort_index_solver_node
  ${PROJECT_NAME} "rosidl_typesupport_cpp")

install(
  DIRECTORY launch
  DESTINATION share/${PROJECT_NAME})

install(TARGETS
  weather_station_node
  comfort_index_solver_node
DESTINATION lib/${PROJECT_NAME})

ament_package()