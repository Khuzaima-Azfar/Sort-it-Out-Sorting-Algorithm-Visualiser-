#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <SFML/Graphics.hpp>
#include <string>

class Renderer {
public:
    Renderer(sf::RenderWindow& window);
    void drawCircle(float x, float y, float radius, const sf::Color& color);
    void drawText(const std::string& text, float x, float y, const sf::Font& font, unsigned int size, const sf::Color& color);
    void clear(const sf::Color& color);
    void display();

private:
    sf::RenderWindow& window;
};

#endif // RENDERER_HPP