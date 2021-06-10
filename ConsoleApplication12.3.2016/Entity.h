#pragma once
#include "SFML/Graphics.hpp"
class Entity{
public:
	float movementSpeed;
	int direction;
	//1=up
	//2=down
	//3=left
	//4=right
	sf::RectangleShape rect;
	sf::Sprite sprite;
	sf::Texture texture;
	Entity();
	Entity(const Entity&);
	~Entity();
	void setRectangleShape(sf::RectangleShape);
	void setSprite(sf::Sprite);
	void setTexture(sf::Texture);
	virtual void draw(sf::RenderWindow&)const;
	void update();
	virtual void updateMovement();
};

