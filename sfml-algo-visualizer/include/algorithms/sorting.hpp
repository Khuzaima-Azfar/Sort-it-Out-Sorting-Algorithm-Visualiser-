#ifndef SORTING_HPP
#define SORTING_HPP

#include <SFML/Graphics.hpp>

class SortingAlgorithm {
public:
    virtual void sort(sf::RenderWindow& window) = 0;
    virtual ~SortingAlgorithm() = default;
};

#endif // SORTING_HPP