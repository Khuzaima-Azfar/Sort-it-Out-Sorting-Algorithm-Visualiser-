#include "renderer.hpp"
#include <SFML/Graphics.hpp>

Renderer::Renderer(sf::RenderWindow& window) : window(window) {}

void Renderer::drawCircle(float x, float y, float radius, const sf::Color& fillColor, const sf::Color& outlineColor, float outlineThickness) {
    sf::CircleShape circle(radius);
    circle.setFillColor(fillColor);
    circle.setOutlineColor(outlineColor);
    circle.setOutlineThickness(outlineThickness);
    circle.setPosition(x, y);
    window.draw(circle);
}

void Renderer::drawText(const std::string& textString, const sf::Font& font, unsigned int characterSize, float x, float y, const sf::Color& color) {
    sf::Text text;
    text.setFont(font);
    text.setString(textString);
    text.setCharacterSize(characterSize);
    text.setFillColor(color);
    text.setPosition(x, y);
    window.draw(text);
}

void Renderer::clear(const sf::Color& color) {
    window.clear(color);
}

void Renderer::display() {
    window.display();
}