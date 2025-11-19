#include <SFML/Graphics.hpp>
#include "Visualizer.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Algorithm Visualizer");
    Visualizer visualizer(window);

    visualizer.run();

    return 0;
}