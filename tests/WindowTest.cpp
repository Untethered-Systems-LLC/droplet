#include "../src/Window/Window.cpp"
#include "../src/Droplet.cpp"

using namespace Droplet;

int main(void) {
    Application::start();

    Window App =
    {"Hi",
    {900, 400},
    {Pin, Minimise, Maximise, Close},
    Windowed};     // Call to Window constructor to make a new App.

    App.display();      // Starts a window to show.

    return 0;
}

