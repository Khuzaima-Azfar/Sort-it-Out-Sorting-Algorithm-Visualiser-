#include "Visualizer.hpp"
#include "renderer.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <memory>

class Visualizer {
public:
    Visualizer();
    void run();

private:
    void processEvents();
    void update();
    void render();
    void handleInput();
    
    sf::RenderWindow window;
    std::unique_ptr<Renderer> renderer;
    std::vector<int> data;
    bool isSorting;
};

Visualizer::Visualizer() 
    : window(sf::VideoMode(800, 600), "Algorithm Visualizer"), isSorting(false) {
    renderer = std::make_unique<Renderer>();
    // Initialize data or load algorithms here
}

void Visualizer::run() {
    while (window.isOpen()) {
        processEvents();
        if (!isSorting) {
            handleInput();
        }
        update();
        render();
    }
}

void Visualizer::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}

void Visualizer::update() {
    // Update logic for the visualizer
}

void Visualizer::render() {
    window.clear();
    renderer->draw(window, data);
    window.display();
}

void Visualizer::handleInput() {
    // Handle user input for starting algorithms or generating data
}