#include <iostream>
#include "Game.h"

int main()
{
    // Create the main window
    sf::RenderWindow app(sf::VideoMode(300, 300), "Game of Life - Gavyn's Implementation");
    sf::Clock clock;

    Game game(&app);
    game.render();
	// Start the game loop
    while (app.isOpen())
    {
        // Process events
        sf::Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                app.close();
            if(clock.getElapsedTime().asSeconds() >= 3.5f){
                game.render();
                clock.restart();
            }
        }
    }

    return EXIT_SUCCESS;
}
