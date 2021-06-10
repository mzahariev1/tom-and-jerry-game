#pragma once
#include "SFML/Graphics.hpp"
class GameOver
{
private:
	sf::Font font;
	sf::Text text;
	sf::Text exit;
public:
	GameOver();
	~GameOver();
	void setTextPosition(sf::RenderWindow&);
	void draw(sf::RenderWindow&);
	sf::FloatRect getGlobalBounds();
	void setColor(const sf::Color);
};

