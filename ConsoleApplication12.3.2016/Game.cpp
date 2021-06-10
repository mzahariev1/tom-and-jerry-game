#include "Game.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<iostream>
#include<windows.h>
#include "Menu.h"
#include "Tom.h"
#include "Grid.h"
using namespace sf;
using namespace std;

Game::Game(){

	window.create(sf::VideoMode(1000, 600), "Trap-o-matic", sf::Style::Close);;

	menu.setWidth(window.getSize().x);
	menu.setHeight(window.getSize().y);

	gameOver.setTextPosition(window);

	grid.setTextPosition(window);

	drawMenu = true;

	drawGrid = false;

	drawGameOver = false;

}

Game::~Game(){}

void Game::run(){

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (event.type == sf::Event::KeyReleased) {
				if (event.key.code == sf::Keyboard::Up) {
					menu.MoveUp();
				}
				if (event.key.code == sf::Keyboard::Down) {
					menu.MoveDown();
				}
				if (event.key.code == sf::Keyboard::Return) {
					if (menu.getSelectedItemIndex() == 1) {
						window.close();
					}
					if (menu.getSelectedItemIndex() == 0) {
						drawMenu = false;
						drawGrid = true;
					}
				}
			}

			if (menu.getGlobalBounds(0).contains(sf::Vector2f(mouse.getPosition(window).x, mouse.getPosition(window).y)) && drawMenu) {
				menu.setColor(0, sf::Color(0, 0, 255));
				menu.setColor(1, sf::Color::White);
				menu.setSelectedItemIndex(0);
			}

			if (menu.getGlobalBounds(1).contains(sf::Vector2f(mouse.getPosition(window).x, mouse.getPosition(window).y)) && drawMenu) {
				menu.setColor(0, sf::Color::White);
				menu.setColor(1, sf::Color(0, 0, 255));
				menu.setSelectedItemIndex(1);
			}

			if (grid.getGlobalBounds().contains(sf::Vector2f(mouse.getPosition(window).x, mouse.getPosition(window).y)) && drawGrid) 
				grid.setColor(sf::Color(0, 0, 255));
			else grid.setColor(sf::Color::White);

			if (event.type == sf::Event::MouseButtonReleased) {
				if (event.key.code == sf::Mouse::Left) {

					if (grid.getText().getGlobalBounds().contains(sf::Vector2f(mouse.getPosition(window).x, mouse.getPosition(window).y)) && drawGrid)
						window.close();

					if (menu.getGlobalBounds(0).contains(sf::Vector2f(mouse.getPosition(window).x, mouse.getPosition(window).y)) && drawMenu) {
						drawMenu = false;
						drawGrid = true;
					}

					if (menu.getGlobalBounds(1).contains(sf::Vector2f(mouse.getPosition(window).x, mouse.getPosition(window).y)) && drawMenu)
						window.close();

					if (gameOver.getGlobalBounds().contains(sf::Vector2f(mouse.getPosition(window).x, mouse.getPosition(window).y)) && drawGameOver)
						window.close();

				}
			}

			if (grid.getTom()->rect.getGlobalBounds().intersects(grid.getJerry()->rect.getGlobalBounds())) {
				drawGameOver = true;
				drawGrid = false;
			}
			if (gameOver.getGlobalBounds().contains(sf::Vector2f(mouse.getPosition(window).x, mouse.getPosition(window).y)) && drawGameOver)
				gameOver.setColor(sf::Color(0, 0, 255));
			else gameOver.setColor(sf::Color::White);
	
			window.clear(sf::Color(0,137,255));
			grid.getTom()->updateMovement();

			if(drawMenu)
				menu.draw(window);

			if (drawGrid)
				grid.draw(window);

			if (drawGameOver)
				gameOver.draw(window);

			window.display();
		}
	}
	return;
}

