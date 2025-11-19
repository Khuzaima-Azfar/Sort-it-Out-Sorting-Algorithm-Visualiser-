#ifndef VISUALIZER_HPP
#define VISUALIZER_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "renderer.hpp"

class Visualizer {
public:
    Visualizer();
    void run();
    void drawAlgorithms();
    void handleInput();
    
private:
    sf::RenderWindow window;
    Renderer renderer;
    std::vector<int> data;
    void generateData(int size);
    void sortAndVisualize();
};

#endif // VISUALIZER_HPP