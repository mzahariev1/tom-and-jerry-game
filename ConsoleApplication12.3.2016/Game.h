#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<iostream>
#include<windows.h>
#include "Menu.h"
#include "Grid.h"
#include "Entity.h"
#include "GameOver.h"
using namespace sf;
using namespace std;
class Game{
public:
	sf::RenderWindow window;
	sf::Mouse mouse;
	Menu menu;
	Grid grid;
	GameOver gameOver;
	bool drawMenu;
	bool drawGrid;
	bool drawGameOver;
	Game();
	~Game();
	void run();
};

