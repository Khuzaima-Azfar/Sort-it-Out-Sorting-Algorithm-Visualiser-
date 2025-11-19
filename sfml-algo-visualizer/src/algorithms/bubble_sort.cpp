#include <SFML/Graphics.hpp>
#include <vector>
#include <random>
#include <thread>
#include <chrono>

class BubbleSortVisualizer {
public:
    void sort(std::vector<int>& data, sf::RenderWindow& window) {
        size_t n = data.size();
        for (size_t i = 0; i < n - 1; ++i) {
            for (size_t j = 0; j < n - i - 1; ++j) {
                if (data[j] > data[j + 1]) {
                    std::swap(data[j], data[j + 1]);
                    drawData(data, window);
                    std::this_thread::sleep_for(std::chrono::milliseconds(100));
                }
            }
        }
    }

private:
    void drawData(const std::vector<int>& data, sf::RenderWindow& window) {
        window.clear(sf::Color::White);
        for (size_t i = 0; i < data.size(); ++i) {
            sf::RectangleShape rectangle(sf::Vector2f(50.f, static_cast<float>(data[i]) * 10.f));
            rectangle.setFillColor(sf::Color::Blue);
            rectangle.setPosition(sf::Vector2f(static_cast<float>(i) * 55.f, static_cast<float>(window.getSize().y) - static_cast<float>(data[i]) * 10.f));
            window.draw(rectangle);
        }
        window.display();
    }
};