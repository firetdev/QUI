#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include "boundingBox.h"

//UIElements are paced in a BoundingBox

class UIElement
{
public:
    int x, y, w, h, row, col;
    std::string posX, posY; //Where it should be placed in the BoundingBox ("right" or "left", "top" or "bottom")
    sf::Texture tex;
    sf::Sprite img;
    BoundingBox* box; //The box it is contained in
    void position(std::string, std::string); //Positions it in the box
    void render(sf::RenderWindow& window);
    UIElement(std::string, int, int, BoundingBox*);
};

void UIElement::position(std::string hori, std::string vert)
{
    //Set variables
    posX = hori;
    posY = vert;
    int px, py; //Where it should be placed
    //STarting placement based in parameters
    if(hori == "left")
    {
        col = 1;
        px = box->x + box->margin;
    }
    if(hori == "right")
    {
        col = box->cols;
        px = box->x + box->w - box->margin - w;
    }
    if(vert == "top")
    {
        row = 1;
        py = box->y + box->margin;
    }
    if(vert == "bottom")
    {
        row = box->cols;
        py = box->y + box->h - box->margin - h;
    }
    //Makes sure they don't overlap
    for(int i = 0; i < box->elements.size(); i++)
    {
        if(box->elements[i]->r == row) //Same row as another element
        {
            //Reposition
            if(hori == "left")
            {
                px += box->elements[i]->w + box->margin;
                col++;
            }
            if(hori == "right")
            {
                px -= box->elements[i]->w + box->margin;
                col--;
            }
        }
        if(box->elements[i]->c == col) //Same column as another element
        {
            //Reposition
            if(vert == "top")
            {
                py += box->elements[i]->h + box->margin;
                row++;
            }
            if(vert == "bottom")
            {
                py -= box->elements[i]->h + box->margin;
                row--;
            }
            
        }
    }
    //Keeps them in the box
    while(px + w + box->margin > box->x + box->w || px < box->x + box-> margin)
    {
        //Change row (new line)
        if(vert == "top")
            row++;
        if(vert == "bottom")
            row--;
        //Reset column (new line). Also reposition.
        if(hori == "left")
        {
            col = 1;
            px = box->x + box->margin;
        }
        if(hori == "right")
        {
            col = box->cols;
            px = box->x + box->w - box->margin - w;
        }
        if(vert == "top")
        {
            py = box->y + box->margin;
        }
        if(vert == "bottom")
        {
            py = box->y + box->h - box->margin - h;
        }
        //Same code as above
        for(int i = 0; i < box->elements.size(); i++)
        {
            if(box->elements[i]->r == row)
            {
                if(hori == "left")
                {
                    px += box->elements[i]->w + box->margin;
                    col++;
                }
                if(hori == "right")
                {
                    px -= box->elements[i]->w + box->margin;
                    col--;
                }
            }
            if(box->elements[i]->c == col)
            {
                if(vert == "top")
                {
                    py += box->elements[i]->h + box->margin;
                    row++;
                }
                if(vert == "bottom")
                {
                    py -= box->elements[i]->h + box->margin;
                    row--;
                }
                
            }
        }
    }
    x = px;
    y = py;
    img.setPosition(sf::Vector2f(x, y));
    box->elements.push_back(new DataHolder(w, h, row, col, hori, vert));
}

void UIElement::render(sf::RenderWindow& window)
{
    window.draw(img);
}

UIElement::UIElement(std::string path, int sw, int sh, BoundingBox* mybox)
{
    tex.loadFromFile(path);
    img.setTexture(tex);
    w = sw;
    h = sh;
    row = 1;
    col = 1;
    box = mybox;
}
