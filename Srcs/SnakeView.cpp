/*
 * SnakeView.cpp
 *
 *  Created on: Oct 18, 2018
 *      Author: nonmaislol
 */

#include "SnakeView.h"

SnakeView::SnakeView()
{

}

SnakeView::~SnakeView()
{

}

void			SnakeView::Play(SnakeBrain& brain)
{
	sf::RenderWindow win(sf::VideoMode(500, 500), "Smart Snakeeee");
	sf::Clock	clock;
	sf::Time	elapsed;
	sf::Text	score;
	sf::Font	fscore;
	Game		game;

	sf::RectangleShape	body(sf::Vector2f(10, 10));
	body.setFillColor(sf::Color(51, 153, 102));
	sf::RectangleShape	food(sf::Vector2f(10, 10));
	food.setFillColor(sf::Color(0, 200, 0));

	fscore.loadFromFile("Squareo.ttf");
	score.setFillColor(sf::Color::Green);
	score.setCharacterSize(24);
	score.setFont(fscore);
	score.setString(std::string("Score: 0"));

	while (win.isOpen())
	{
        sf::Event event;
        while (win.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                win.close();
        }

		elapsed = clock.getElapsedTime();
		if (elapsed.asMilliseconds() > FRAMERATE)
		{
			game.Step();
			game.ChangeDir(brain.TakeDecision(game));
			if (game.GetState() == LOST)
			{
				return ;
			}
			score.setString(std::string("Score: ") + std::to_string(game.GetScore()));

			clock.restart();

			// DRAW
			win.clear();
			for (int y = 0; y < game.GetSize(); ++y)
			{
				for (int x = 0; x < game.GetSize(); ++x)
				{
					if (game.GetElement(x, y) == FOOD)
					{
						food.setPosition(x * 10, y * 10);
						win.draw(food);
					}
					else if (game.GetElement(x, y) == SHEAD || game.GetElement(x, y) == SBODY ||
							game.GetElement(x, y) == STAIL || game.GetElement(x, y) == WALL)
					{
						body.setPosition(x * 10, y * 10);
						win.draw(body);
					}
				}
			}
			score.setPosition(20, 20);
			win.draw(score);

			win.display();
		}
		else
		{
			;//usleep(((RATE + 1) * 1000) - elapsed.asMicroseconds());
		}
	}
}
