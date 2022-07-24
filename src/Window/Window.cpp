#include <GL/gl.h>
#include <cstddef>
#include <iterator>
#include <string>
#include <sys/types.h>
#include <utility>
#include <string.h>
#include <iostream>
#include <vector>

#define GLFW_INCLUDE_VULKAN
#include "GLFW/glfw3.h"
#include "WindowView.cpp"

namespace Droplet {
    using std::string;
    using std::pair;
    using std::cerr;
    using std::endl;
    using std::vector;

    enum WindowDecorations {                // The buttons of the window
        Pin,
        Minimise,
        Maximise,
        Close
    };

    enum WindowMode {                       // Shows whether the window is Windowed or in Fullscreen mode
        Windowed,
        Fullscreen
    };

    class Window {
        private:
        string title = "Droplet Window";                // Window title
        pair<uint, uint> dimensions = {640, 480};  // Window dimensions <x, y>
        vector<WindowDecorations> decorations = {
            Pin, Minimise, Maximise, Close
        };                                              // All possible decorators are 4.
        pair<bool, bool> state = {false, true};    // Pair of two states: isMinimised and isFocused
        WindowMode mode = Windowed;                     // Windowed or Fullscreen
        WindowView view;                                // Shows the window view
        GLFWmonitor* monitor;                           // Monitor
        GLFWwindow* window;                             // Window

        void create() {
            switch (mode) {
                case Windowed:
                monitor = NULL;
                break;

                case Fullscreen:
                monitor = glfwGetPrimaryMonitor();
                break;

                default:
                cerr << "Failed to create window." << endl;
            }
            
            window = glfwCreateWindow(dimensions.first,
                        dimensions.second,
                        title.c_str(),
                        monitor,
                        NULL);
        }
        
        public:
        // Empty constructor with all defaults as set above
        Window() {
            this->create();
        }

        // Constructor with optional parameters
        Window(string title = "Droplet Window", pair<uint, uint> dimensions = {640, 480},
                vector<WindowDecorations> decorations = {Pin, Minimise, Maximise, Close},
                WindowMode mode = Windowed) {
                    int i = 0;
                    this->title = title;
                    this->dimensions = dimensions;
                    for (auto decorator : decorations) {
                        this->decorations[i] = decorator;
                        i++;
                    }
                    this->mode = mode;

                    this->create();
                }

        // Full contructor with provided view parameter
        Window(string title, pair<uint, uint> dimensions,
                vector<WindowDecorations> decorations,
                WindowMode mode, WindowView view) {
                    int i = 0;
                    this->title = title;
                    this->dimensions = dimensions;
                    for (auto decorator : decorations) {
                        this->decorations[i] = decorator;
                        i++;
                    }
                    this->mode = mode;
                    this->view = view;

                    this->create();
                }

        ~Window() {
            glfwDestroyWindow(window);
        }

        void display() {
            while (!glfwWindowShouldClose(window)) {                
                glfwPollEvents();
            }
        }
    };
}