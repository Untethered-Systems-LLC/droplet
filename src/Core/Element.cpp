#include <string>
#include <sys/types.h>
#include <utility>
#include <vector>
#define GLFW_INCLUDE_VULKAN
#include <string.h>
#include <iostream>
#include "GLFW/glfw3.h"
#include "../Widget/Widget.cpp"

namespace Droplet {
    class Element {
        private:
        std::pair<int, int> placement;      // x, y placement (starting from top left)
        std::vector<Widget> widgets;        // The widgets the element carries
        bool visible;                       // Determines visibility
    };
}