#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <random>

std::vector<int> generateRandomData(int size, int minValue, int maxValue) {
    std::vector<int> data(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(minValue, maxValue);
    
    for (int& value : data) {
        value = dis(gen);
    }
    
    return data;
}

std::string formatText(const std::string& text, const sf::Font& font, unsigned int characterSize) {
    sf::Text formattedText;
    formattedText.setFont(font);
    formattedText.setString(text);
    formattedText.setCharacterSize(characterSize);
    formattedText.setFillColor(sf::Color::Black);
    
    return formattedText.getString();
}