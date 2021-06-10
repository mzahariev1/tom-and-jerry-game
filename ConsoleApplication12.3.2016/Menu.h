#pragma once
#include "SFML/Graphics.hpp"
#include "Entity.h"
#define MAX_NUMBER_OF_ITEMS 2
class Menu{
private:
	Entity* menuObjects = nullptr;
	int numberOfMenuObjects;
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];
	float width;
	float height;
public:
	Menu();
	~Menu();
	void draw(sf::RenderWindow&);
	void MoveUp();
	void MoveDown();
	int getSelectedItemIndex()const;
	void setSelectedItemIndex(int);
	sf::FloatRect getGlobalBounds(int);
	void setColor(int, const sf::Color);
	void setWidth(float);
	void setHeight(float);
};

