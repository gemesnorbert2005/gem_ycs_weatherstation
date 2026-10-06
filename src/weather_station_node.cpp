#include <chrono>
#include <memory>
#include <random>

#include "rclcpp/rclcpp.hpp"
#include "gem_ycs_weatherstation/msg/weather.hpp"

using namespace std::chrono_literals;

class WeatherStationNode : public rclcpp::Node
{
public:
    WeatherStationNode()
    : Node("weather_station_node")
    {
        publisher_ = this->create_publisher<gem_ycs_weatherstation::msg::Weather>("weather", 10);

        timer_ = this->create_wall_timer(
            1000ms,
            std::bind(&WeatherStationNode::publish_weather, this)
        );

        rng_.seed(std::random_device{}());
    }

private:
    void publish_weather()
    {
        gem_ycs_weatherstation::msg::Weather msg;

        msg.temperature = random_float(15.0f, 30.0f);
        msg.humidity    = random_float(30.0f, 90.0f);
        msg.pressure    = random_float(990.0f, 1030.0f);

        RCLCPP_INFO(this->get_logger(),
            "Publishing Weather: temp=%.2f °C, humidity=%.2f %%, pressure=%.2f hPa",
            msg.temperature, msg.humidity, msg.pressure);

        publisher_->publish(msg);
    }

    float random_float(float min, float max)
    {
        std::uniform_real_distribution<float> dist(min, max);
        return dist(rng_);
    }

    rclcpp::Publisher<gem_ycs_weatherstation::msg::Weather>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    std::mt19937 rng_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<WeatherStationNode>());
    rclcpp::shutdown();
    return 0;
}
