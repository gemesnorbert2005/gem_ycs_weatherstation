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
        // RCLCPP_INFO(
        //     this->get_logger(),
        //                msg->temperature,
        //     msg->humidity,
        //     msg->pressure
        // );

        float comfort_index =
            msg->temperature -
            (0.55f - 0.0055f * msg->humidity) * (msg->temperature - 14.5f);

        RCLCPP_INFO(
            this->get_logger(),
            "Comfort Index: %.2f",
            comfort_index
        );
    }

    rclcpp::Subscription<gem_ycs_weatherstation::msg::Weather>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ComfortIndexSolverNode>());
    rclcpp::shutdown();
    return 0;
}
