#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include "uiElement.h"

//Image-based UIElement. Can be rendered, that's basically it

class Image: public UIElement
{
public:
    sf::Texture tex;
    sf::Sprite sprite;
    void initialize(std::string, int, int);
    void render(sf::RenderWindow& window);
    Image(int sw, int sh, BoundingBox* mybox):UIElement(sw, sh, mybox){} //Use UIElement constructor
};

void Image::initialize(std::string path, int xScale, int yScale)
{
    tex.loadFromFile(path);
    sprite.setTexture(tex);
    sprite.setScale(xScale, yScale);
}

void Image::render(sf::RenderWindow& window)
{
    sprite.setPosition(x, y);
    window.draw(sprite);
}
