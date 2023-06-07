#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include "dataHolder.h"

//Container for UIElements

class BoundingBox
{
public:
    int x, y, w, h, margin, cols, rows;
    sf::RectangleShape rect; //For debugging
    std::vector<DataHolder*> elements; //Stores the contained element's data
    BoundingBox(int, int, int, int, int, int, int);
};

BoundingBox::BoundingBox(int sx, int sy, int sw, int sh, int smargin, int mycols, int myrows)
{
    x = sx;
    y = sy;
    w = sw;
    h = sh;
    margin = smargin;
    cols = mycols;
    rows = myrows;
    rect.setPosition(x, y);
    rect.setSize(sf::Vector2f(w, h));
    rect.setFillColor(sf::Color::Transparent);
    rect.setOutlineColor(sf::Color::Black);
    rect.setOutlineThickness(1);
}
