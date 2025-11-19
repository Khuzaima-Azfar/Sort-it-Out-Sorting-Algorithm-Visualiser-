#include <SFML/Graphics.hpp>
#include <vector>
#include <random>
#include <thread>
#include <chrono>
#include "sorting.hpp"

class SelectionSortVisualizer {
public:
    void sortAndVisualize(std::vector<int>& data, sf::RenderWindow& window) {
        size_t n = data.size();
        for (size_t i = 0; i < n - 1; ++i) {
            size_t minIndex = i;
            for (size_t j = i + 1; j < n; ++j) {
                if (data[j] < data[minIndex]) {
                    minIndex = j;
                }
            }
            std::swap(data[i], data[minIndex]);

            // Visualization logic
            window.clear(sf::Color::White);
            drawData(data, window);
            window.display();
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
    }

private:
    void drawData(const std::vector<int>& data, sf::RenderWindow& window) {
        float width = window.getSize().x / static_cast<float>(data.size());
        for (size_t i = 0; i < data.size(); ++i) {
            sf::RectangleShape rectangle(sf::Vector2f(width - 1, data[i] * 5)); // Scale for visibility
            rectangle.setPosition(i * width, window.getSize().y - data[i] * 5);
            rectangle.setFillColor(sf::Color::Green);
            window.draw(rectangle);
        }
    }
};