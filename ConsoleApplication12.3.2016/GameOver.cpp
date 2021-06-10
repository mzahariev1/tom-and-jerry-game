#include "GameOver.h"
#include<iostream>


GameOver::GameOver()
{
	if (!font.loadFromFile("images/GoodDog.otf")) {
		std::cout << "ERROR LOADING FONT IN GAMEOVER" << std::endl;
	}
	text.setFont(font);
	text.setColor(sf::Color::White);
	text.setString("YOU WIN");
	text.setCharacterSize(80);


	exit.setFont(font);
	exit.setString("EXIT");
	exit.setColor(sf::Color::White);
	exit.setCharacterSize(40);

}


GameOver::~GameOver()
{
}

void GameOver::setTextPosition(sf::RenderWindow& window) {
	text.setPosition(sf::Vector2f(window.getPosition().x / 2 - 40, window.getPosition().y / 2 - 10));
	exit.setPosition(sf::Vector2f(0.93*window.getSize().x, 0));
	return;
}

void GameOver::draw(sf::RenderWindow& window) {
	window.draw(text);
	window.draw(exit);
	return;
}

sf::FloatRect GameOver::getGlobalBounds() {
	return exit.getGlobalBounds();
}

void GameOver::setColor(const sf::Color color) {
	exit.setColor(color);
}