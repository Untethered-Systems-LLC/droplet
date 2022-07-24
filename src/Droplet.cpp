#define GLFW_INCLUDE_VULKAN
#include <iostream>
#include "GLFW/glfw3.h"

namespace Droplet {
    class Application {
        public:
        static void start() {
            if (!glfwInit()) {
                std::cerr << "Cannot start the program." << std::endl;
            }
        }
    };
}