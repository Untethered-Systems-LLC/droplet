#include "../src/Window/Window.cpp"

using namespace Droplet;

int main(void) {
    Window* App = new Window();
    App->start();
    App->display();

    return 0;
}