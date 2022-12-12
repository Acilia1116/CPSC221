#include "block.h"
#include <cmath>
#include <iostream>

int Block::width() const
{
/* YOUR CODE HERE */
    return data.size();

}
int Block::height() const
{
/* YOUR CODE HERE */
    return data[0].size();
}

void Block::render(PNG &im, int column, int row) const
{
/* YOUR CODE HERE */
    for (int x = 0; x< width();x++) {
        for(int y = 0; y < height(); y++) {
            *im.getPixel(column + x, row + y) = data[x][y];
        }
    }
}

void Block::build(PNG &im, int column, int row, int width, int height)
{
/* YOUR CODE HERE */
    data.resize(width, vector<RGBAPixel>(height));
    for(int x = 0; x<width; x++) {
        for(int y = 0; y< height; y++) {
            data[x][y] = *im.getPixel(column + x, row +y);
        }
    }
}

void Block::flipVert()
{
/* YOUR CODE HERE */
    int centerx = height() - height()/2;
    for(int x = 0; x<width(); x++) {
        for(int y = 0; y<height()/2; y++) {
            RGBAPixel temp = data[x][y];
            data[x][y] = data[x][y + centerx];
            data[x][y + centerx] = temp;

        }
    }
}

void Block::flipHoriz()
{
/* YOUR CODE HERE */
     int centerx = width() - width()/2;
     for(int x = 0; x<width()/2; x++) {
        for(int y = 0; y < height(); y++) {
            RGBAPixel temp = data[x][y];
            data[x][y] = data[x + centerx][y];
            data[x + centerx][y] = temp;
        }
     }
}

void Block::rotateRight()
{
/* YOUR CODE HERE */
    int w = width() -1;
    for(int x = 0; x< width() - width()/2; x++) {
        for(int y = 0; y < width()/2; y++) {
            RGBAPixel temp = data[x][y];
            data[x][y] = data[y][w-x];
            data[y][w-x] = data[w-x][w-y];
            data[w-x][w-y] = data[w-y][x];
            data[w-y][x] = temp;      
        }
    }
}
