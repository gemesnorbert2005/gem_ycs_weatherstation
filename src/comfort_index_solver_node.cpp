#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "gem_ycs_weatherstation/msg/weather.hpp"

class ComfortIndexSolverNode : public rclcpp::Node
{
public:
    ComfortIndexSolverNode()
    : Node("comfort_index_solver_node")
    {
        subscription_ = this->create_subscription<gem_ycs_weatherstation::msg::Weather>(
            "weather",
            10,
            std::bind(&ComfortIndexSolverNode::callback, this, std::placeholders::_1)
        );
    }
private:
    void callback(const gem_ycs_weatherstation::msg::Weather::SharedPtr msg)
    {
        RCLCPP_INFO(
            this->get_logger(),
            "Received Weather: temp=%.2f °C, humidity=%.2f %%, pressure=%.2f hPa",
            msg->temperature,
            msg->humidity,
            msg->pressure
        );
    }

    // "comfort index" számítása

    float comfort_index = msg->temperature - (0.55f - 0.0055f)

}