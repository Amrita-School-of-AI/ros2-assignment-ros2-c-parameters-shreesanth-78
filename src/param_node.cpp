#include "rclcpp/rclcpp.hpp"

class ParamNode : public rclcpp::Node
{
public:
    ParamNode() : Node("param_node")
    {
        this->declare_parameter<std::string>("robot_name", "ROS2Bot");
        this->declare_parameter<double>("max_speed", 1.5);
        this->declare_parameter<bool>("enabled", true);

        std::string robot_name;
        double max_speed;
        bool enabled;

        this->get_parameter("robot_name", robot_name);
        this->get_parameter("max_speed", max_speed);
        this->get_parameter("enabled", enabled);

        RCLCPP_INFO(this->get_logger(),
                    "Robot: %s, Max Speed: %.6f, Enabled: %s",
                    robot_name.c_str(),
                    max_speed,
                    enabled ? "true" : "false");
    }
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ParamNode>());
    rclcpp::shutdown();
    return 0;
}

