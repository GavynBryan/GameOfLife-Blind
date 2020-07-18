#include<iostream>
#include "Game.h"

Game::Game(sf::RenderWindow* _window)
{
    mWindow = _window;
}

//add the value if it's within the range of the matrix
int Game::addIfValid(int x, int y)
{
    if(x >= 0 && y >= 0
    && x < gSize  && y < gSize){
        //C matrices are ordered like (row,column) so this feels a bit backwards
        return grid[y][x];
    }
    return 0;
}

//get how many live neighbors there are
int Game::getNeighborCount(int x, int y)
{
    int count = 0;
    //iterate through all of the neighbors in a range of 1 grid
    for (int i = x - 1; i <= x+1; i++){
        for(int j = y - 1; j <= y + 1; j++){
            //don't add a neighbor on the origin cell
            if(i != x || j != y)
                count += addIfValid(i, j);
        }
    }
    return count;
}

void Game::tick(int x, int y)
{
    int neighbors = getNeighborCount(x, y);
    //if the grid is alive
    if(neighbors < 2 || neighbors > 3){
        grid[y][x] = 0;
    }
    else if(neighbors == 3) grid[y][x] = 1;

}

void Game::render()
{
    mWindow->clear();
    for(int i = 0; i <= gSize; i++){
        for(int j = 0; j <= gSize; j++){
            tick(i, j);

            sf::RectangleShape rect;
            rect.setPosition(j * 20, i * 20);
            rect.setSize(sf::Vector2f(20, 20));
            if(grid[i][j] == 1) rect.setFillColor(sf::Color::Black);
            mWindow->draw(rect);
        }
    }
    mWindow->display();
}

