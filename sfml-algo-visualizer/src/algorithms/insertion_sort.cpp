#include <SFML/Graphics.hpp>
#include <vector>
#include <random>
#include <thread>
#include <chrono>
#include "sorting.hpp"

class InsertionSortVisualizer {
public:
    void sortAndVisualize(sf::RenderWindow& window, std::vector<int>& data) {
        for (size_t i = 1; i < data.size(); ++i) {
            int key = data[i];
            size_t j = i - 1;

            while (j < data.size() && data[j] > key) {
                data[j + 1] = data[j];
                j--;
                drawData(window, data);
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
            }
            data[j + 1] = key;
            drawData(window, data);
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }

private:
    void drawData(sf::RenderWindow& window, const std::vector<int>& data) {
        window.clear(sf::Color::White);
        for (size_t i = 0; i < data.size(); ++i) {
            sf::RectangleShape rectangle(sf::Vector2f(50, data[i] * 5));
            rectangle.setFillColor(sf::Color::Blue);
            rectangle.setPosition(i * 55, 600 - data[i] * 5);
            window.draw(rectangle);
        }
        window.display();
    }
};