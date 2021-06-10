#include "Entity.h"
#include "SFML/Graphics.hpp"
void Entity::setRectangleShape(sf::RectangleShape rect) {
	this->rect = rect;
}

void Entity::setSprite(sf::Sprite sprite) {
	this->sprite = sprite;
}


void Entity::setTexture(sf::Texture texture) {
	this->texture = texture;
}

Entity::Entity(){
	movementSpeed = 41.5;
	rect.setSize(sf::Vector2f(41.5, 41.5));
}

Entity::Entity(const Entity& e) {
	setRectangleShape(e.rect);
	setSprite(e.sprite);
	setTexture(e.texture);
}


Entity::~Entity(){}

void Entity::draw(sf::RenderWindow& window)const {
	window.draw(sprite);
	return;
}

void Entity::update() {
	sprite.setPosition(rect.getPosition());
	return;
}
void Entity::updateMovement() {
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
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			rect.move(sf::Vector2f(0, -movementSpeed));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			rect.move(sf::Vector2f(0, movementSpeed));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			rect.move(sf::Vector2f(-movementSpeed, 0));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			rect.move(sf::Vector2f(movementSpeed, 0));
		}
	}
}