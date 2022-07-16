#include <cstddef>
#include <iterator>
#include <string>
#include <sys/types.h>
#include <utility>
#include <string.h>
#include <iostream>

#define GLFW_INCLUDE_VULKAN
#include <vulkan/vulkan.h>
#include "GLFW/glfw3.h"
#include "WindowView.cpp"

namespace Droplet {
    using std::string;
    using std::pair;
    using std::cerr;
    using std::endl;

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
        WindowDecorations decorations[4] = {
            Pin, Minimise, Maximise, Close
        };                                              // All possible decorators are 4.
        pair<bool, bool> state = {false, true};    // Pair of two states: isMinimised and isFocused
        WindowMode mode = Windowed;                     // Windowed or Fullscreen
        WindowView view;                                // Shows the window view
        GLFWwindow* window;                             // Window

        void start() {
            if (!glfwInit()) {
                cerr << "Cannot start the program." << endl;
            }
        }

        void create() {
            switch (mode) {
                case Windowed:
                window = glfwCreateWindow(dimensions.first,
                        dimensions.second,
                        title.c_str(),
                        NULL,
                        NULL);
                break;

                case Fullscreen:
                window = glfwCreateWindow(dimensions.first,
                        dimensions.second,
                        title.c_str(),
                        glfwGetPrimaryMonitor(),
                        NULL);
                break;

                default:
                cerr << "Failed to create window." << endl;
            }
        }
        
        public:
        Window() {}
        Window(string title, pair<uint, uint> dimensions,
                WindowDecorations decorations[],
                WindowMode mode) {
                    this->title = title;
                    this->dimensions = dimensions;
                    for (int i = 0; i < 4; i++) {
                        this->decorations[i] = decorations[i];
                    }
                    this->mode = mode;

                    this->start();
                    this->create();
                }

        Window(string title, pair<uint, uint> dimensions,
                WindowDecorations decorations[],
                WindowMode mode, WindowView view) {
                    this->title = title;
                    this->dimensions = dimensions;
                    for (int i = 0; i < 4; i++) {
                        this->decorations[i] = decorations[i];
                    }
                    this->mode = mode;
                    this->view = view;

                    this->start();
                    this->create();
                }

        ~Window() {
            glfwTerminate();
        }

        void run() {
            while (!glfwWindowShouldClose(window)) {
                glfwSwapBuffers(window);
                glfwPollEvents();
            }
        }
    };
}