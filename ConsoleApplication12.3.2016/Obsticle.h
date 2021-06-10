#pragma once
#include "Entity.h"
class Obsticle :public Entity{
private:
	int counter;
	int movementLength;
public:
	void draw(sf::RenderWindow&)const;
	void updateMovement();
	Obsticle();
	~Obsticle();
};

