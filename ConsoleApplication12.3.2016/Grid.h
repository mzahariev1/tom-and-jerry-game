#pragma once
#include "SFML/Graphics.hpp"
#include "Entity.h"
#include "Obsticle.h"
class Grid{
private:
	sf::Font exitFont;
	sf::Text exitText;
	sf::VertexArray topAndBottom;
	sf::VertexArray leftAndRight;
	Entity* tom = nullptr;
	Obsticle* jerry = nullptr;
	Obsticle* spike = nullptr;
	Obsticle* obsticle1 = nullptr;
	Obsticle* obsticle2 = nullptr;
	Obsticle* obsticle3 = nullptr;
public:
	void draw(sf::RenderWindow&);
	Grid();
	~Grid();
	sf::Text getText()const;
	void setTextPosition(sf::RenderWindow&);
	sf::FloatRect getGlobalBounds();
	void setColor(const sf::Color);
	Entity* getTom()const;
	Obsticle* getJerry()const;
	Obsticle* getSpike()const;
	Obsticle* getObsticle1()const;
	Obsticle* getObsticle2()const;
	Obsticle* getObsticle3()const;
};

