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
    BoundingBox* box; //The box it is contained in
    void position(std::string, std::string); //Positions it in the box
    void render(sf::RenderWindow& window);
    bool mouseIn(int, int);
    UIElement(int, int, BoundingBox*);
};

void UIElement::position(std::string hori, std::string vert)
{
    //Set variables
    posX = hori;
    posY = vert;
    int px, py; //Where it should be placed
    //Starting placement based in parameters
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
    if(hori == "center")
    {
        col = box->cols / 2;
        px = box->x + (box->w / 2) - w / 2;
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
    if(vert == "center")
    {
        row = box->rows / 2;
        py = box->y + (box->h / 2) - h / 2;
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
            if(hori == "center")
            {
                col = box->cols / 2;
                px = box->x + (box->w / 2) - w / 2;
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
            if(vert == "center")
            {
                row = box->rows / 2;
                py = box->y + (box->h / 2) - h / 2;
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
        if(hori == "center")
        {
            col = box->cols / 2;
            px = box->x + (box->w / 2) - w / 2;
        }
        if(vert == "top")
        {
            py = box->y + box->margin;
        }
        if(vert == "bottom")
        {
            py = box->y + box->h - box->margin - h;
        }
        if(vert == "center")
        {
            py = box->y + (box->h / 2) - h / 2;
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
                if(hori == "center")
                {
                    col = box->cols / 2;
                    px = box->x + (box->w / 2) - w / 2;
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
                if(vert == "center")
                {
                    row = box->rows / 2;
                    py = box->y + (box->h / 2) - h / 2;
                }
            }
        }
    }
    x = px;
    y = py;
    box->elements.push_back(new DataHolder(w, h, row, col, hori, vert));
}

bool UIElement::mouseIn(int mX, int mY)
{
    if(mX > x && mX < x + w && mY > y && mY < y + h)
        return true;
    return false;
}

UIElement::UIElement(int sw, int sh, BoundingBox* mybox)
{
    w = sw;
    h = sh;
    row = 1;
    col = 1;
    box = mybox;
}
