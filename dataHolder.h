#pragma once

#include <vector>
#include <string>

//Holds information on UIElements

class DataHolder
{
public:
    int w, h, r, c;
    std::string posX, posY;
    DataHolder(int, int, int, int, std::string, std::string);
};

DataHolder::DataHolder(int sw, int sh, int row, int col, std::string sx, std::string sy)
{
    w = sw;
    h = sh;
    r = row;
    c = col;
    posX = sx;
    posY = sy;
}
