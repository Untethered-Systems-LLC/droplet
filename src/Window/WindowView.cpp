#include <string>
#include <sys/types.h>
#include <utility>
#include <vector>
#define GLFW_INCLUDE_VULKAN
#include <string.h>
#include <iostream>
#include "GLFW/glfw3.h"
#include "../Core/Element.cpp"

namespace Droplet {
    class WindowView {
        private:
        std::vector<Element> elements; // contains elements to be displayed
        
    };
}