#include "Obsticle.h"
#include<time.h>
#include<iostream>

Obsticle::Obsticle(){
	counter = 0;
	direction = 0;
	movementLength = 7;
}


Obsticle::~Obsticle()
{
}

void Obsticle::updateMovement() {
	if (rect.getPosition().x < 10) {
		rect.setPosition(sf::Vector2f(10, rect.getPosition().y));
	}
	if (rect.getPosition().y < 10) {
		rect.setPosition(sf::Vector2f(rect.getPosition().x, 10));
	}
	if (rect.getPosition().x > 549) {
		rect.setPosition(sf::Vector2f(549, rect.getPosition().y));
	}
	if (rect.getPosition().y > 549) {
		rect.setPosition(sf::Vector2f(rect.getPosition().x, 549));
	}
	if (rect.getPosition().x >= 10 && rect.getPosition().y >= 10 && rect.getPosition().x <= 549 && rect.getPosition().y <= 549) {
		if (direction == 1) {
			rect.move(sf::Vector2f(0, -movementSpeed));
		}
		if (direction == 2) {
			rect.move(sf::Vector2f(0, movementSpeed));
		}
		if (direction == 3) {
			rect.move(sf::Vector2f(-movementSpeed, 0));
		}
		if (direction == 4) {
			rect.move(sf::Vector2f(movementSpeed, 0));
		}
		counter++;
		if (counter >= movementLength) {
			direction = rand() % 4 + 1;
			counter = 0;
		}
	}
}
void Obsticle::draw(sf::RenderWindow& window)const {
	window.draw(sprite);
	return;
}
