#include "Grid.h"
#include<iostream>
#include<time.h>

Grid::Grid() {
	srand(time(0));
	topAndBottom = sf::VertexArray(sf::Lines, 31);
	leftAndRight = sf::VertexArray(sf::Lines, 31);
	float k = 10.0;
	for (int i = 0; i < 31; i++) {
		if (i % 2 == 0) {
			leftAndRight[i].position = sf::Vector2f(10, k);
			topAndBottom[i].position = sf::Vector2f(k, 10);
		}
		else {
			leftAndRight[i].position = sf::Vector2f(590, k);
			topAndBottom[i].position = sf::Vector2f(k, 590);
			k += 41.5;
		}
	}
	if (!exitFont.loadFromFile("images/GoodDog.otf"))
		std::cout << "ERROR LOADING EXIT FONT" << std::endl;
	exitText.setFont(exitFont);
	exitText.setString("EXIT");
	exitText.setColor(sf::Color::White);
	exitText.setCharacterSize(40);

	tom = new Entity;
	jerry = new Obsticle;
	spike = new  Obsticle;
	obsticle1 = new Obsticle;
	obsticle2 = new Obsticle;
	obsticle3 = new Obsticle;

	if (!tom->texture.loadFromFile("images/tom_cat.png"))
		std::cout << "ERROR LOADING TOM IN THE GRID" << std::endl;
	tom->sprite.setTexture(tom->texture);
	tom->rect.setPosition(sf::Vector2f(10, 10));

	if (!jerry->texture.loadFromFile("images/jerry_mouse1.png"))
		std::cout << "ERROR LOADING JERRY IN THE GRID" << std::endl;
	jerry->sprite.setTexture(jerry->texture);
	jerry->rect.setPosition(sf::Vector2f(41.5*(rand() % 13 + 2) + 10, 41.5*(rand() % 13 + 2) + 10));

	if (!spike->texture.loadFromFile("images/spike_in_game.png"))
		std::cout << "ERROR LOADING SPIKE IN THE GRID" << std::endl;
	spike->sprite.setTexture(spike->texture);
	spike->rect.setPosition(sf::Vector2f(41.5*(rand() % 13 + 2) + 10, 41.5*(rand() % 13 + 2) + 10));

	if (!obsticle1->texture.loadFromFile("images/obsticle1.png"))
		std::cout << "ERROR LOADING OBSTICLE 1 IN THE GRID" << std::endl;
	obsticle1->sprite.setTexture(obsticle1->texture);
	obsticle1->rect.setPosition(sf::Vector2f(41.5*(rand() % 13 + 2) + 10, 41.5*(rand() % 13 + 2) + 10));

	if (!obsticle2->texture.loadFromFile("images/obsticle2.png"))
		std::cout << "ERROR LOADING OBSTICLE 2 IN THE GRID" << std::endl;
	obsticle2->sprite.setTexture(obsticle2->texture);
	obsticle2->rect.setPosition(sf::Vector2f(41.5*(rand() % 13 + 2) + 10, 41.5*(rand() % 13 + 2) + 10));

	if (!obsticle3->texture.loadFromFile("images/obsticle3.png"))
		std::cout << "ERROR LOADING OBSTICLE 3 IN THE GRID" << std::endl;
	obsticle3->sprite.setTexture(obsticle3->texture);
	obsticle3->rect.setPosition(sf::Vector2f(41.5*(rand() % 13 + 2) + 10, 41.5*(rand() % 13 + 2) + 10));



}



Grid::~Grid(){
	delete tom;
	delete jerry;
	delete spike;
	delete obsticle1;
	delete obsticle2;
	delete obsticle3;
}

void Grid::draw(sf::RenderWindow& window) {
	window.draw(topAndBottom);
	window.draw(leftAndRight);
	window.draw(exitText);
	tom->update();
	window.draw(tom->sprite);
	jerry->update();
	jerry->updateMovement();
	window.draw(jerry->sprite);
	spike->update();
	spike->updateMovement();
	window.draw(spike->sprite);
	obsticle1->update();
	obsticle1->updateMovement();
	window.draw(obsticle1->sprite);
	obsticle2->update();
	obsticle2->updateMovement();
	window.draw(obsticle2->sprite);
	obsticle3->update();
	obsticle3->updateMovement();
	window.draw(obsticle3->sprite);
	return;
}
sf::Text Grid::getText()const {
	return exitText;
}
void Grid::setTextPosition(sf::RenderWindow& window) {
	exitText.setPosition(sf::Vector2f(0.93*window.getSize().x, 0));
	return;
}
sf::FloatRect Grid::getGlobalBounds() {
	return exitText.getGlobalBounds();
}
void Grid::setColor(const sf::Color color) {
	exitText.setColor(color);
	return;
}

Entity* Grid::getTom()const {
	return tom;
}
Obsticle* Grid::getJerry()const {
	return jerry;
}
Obsticle* Grid::getSpike()const {
	return spike;
}
Obsticle* Grid::getObsticle1()const {
	return obsticle1;
}
Obsticle* Grid::getObsticle2()const {
	return obsticle2;
}
Obsticle* Grid::getObsticle3()const {
	return obsticle3;
}