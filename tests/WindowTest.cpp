#include "../src/Window/Window.cpp"

using namespace Droplet;

int main(void) {
    Window App;     // Call to Window constructor to make a new App.

    App.run();      // Starts the app. The window will not yet show.

    return 0;
}