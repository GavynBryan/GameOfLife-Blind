#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include <SFML/Graphics.hpp>>

constexpr int gSize = 15;

class Game
{
public:
    Game(sf::RenderWindow* _window);
private:
    sf::RenderWindow    *mWindow;
    sf::RectangleShape rect;
    int grid[gSize][gSize] =
               {{0,0,0,0,0,0,1,0,0,0,0,1,0,0,1},
                {1,0,1,0,0,0,0,0,0,0,1,0,0,1,0},
                {0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,1,0,0,0,0,0,1,0,1,0,1,1,0},
                {0,0,0,1,0,1,0,0,0,0,0,0,0,0,1},
                {0,1,0,0,0,0,0,1,0,1,0,0,1,0,0},
                {0,0,0,0,0,1,0,1,0,0,0,0,0,0,0},
                {0,0,1,0,0,0,0,0,0,1,0,1,0,0,1},
                {0,0,0,0,1,0,0,0,0,0,1,0,1,0,0},
                {0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
                {1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
                {1,1,1,0,0,0,1,0,0,0,1,0,1,0,1},
                {0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
                {0,0,0,1,0,1,0,1,0,1,0,0,1,0,0}
};


    int addIfValid(int x, int y);
public:

    int getNeighborCount(int x, int y);

    void tick(int x, int y);
    void render();
};


#endif // GAME_H_INCLUDED
