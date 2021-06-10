#include "Menu.h"
#include<iostream>

Menu::Menu(){
	width = 1000;
	height = 600;
	numberOfMenuObjects = 3;
	menuObjects = new Entity[numberOfMenuObjects];
	if (!font.loadFromFile("images/GoodDog.otf")) {
		std::cout << "ERROR LOADING MENU FONT" << std::endl;
	}
	menu[0].setFont(font);
	menu[0].setColor(sf::Color(0, 0, 255));
	menu[0].setString("PLAY");
	menu[0].setCharacterSize(70);
	menu[0].setPosition(sf::Vector2f((width / 2 - 65), (height / (MAX_NUMBER_OF_ITEMS + 1) * 1) - 30));

	menu[1].setFont(font);
	menu[1].setColor(sf::Color::White);
	menu[1].setString("EXIT");
	menu[1].setCharacterSize(70);
	menu[1].setPosition(sf::Vector2f((width / 2 - 65), (height / (MAX_NUMBER_OF_ITEMS + 1) * 2) - 30));

	selectedItemIndex = 0;

	if (!menuObjects[0].texture.loadFromFile("images/Tom&jerry_tom.png")) 
		std::cout << "ERROR LOADING TOM TEXTURE IN THE MENU" << std::endl;
	
	if (!menuObjects[1].texture.loadFromFile("images/Jerry_Mouse.png"))
		std::cout << "ERROR LOADING JERRY TEXTURE IN THE MENU" << std::endl;
	
	if (!menuObjects[2].texture.loadFromFile("images/spike_in_menu.png"))
		std::cout << "ERROR LOADING SPIKE TEXTURE IN THE MENU" << std::endl;
	
	for (int i = 0; i < numberOfMenuObjects; i++)
		menuObjects[i].sprite.setTexture(menuObjects[i].texture);

	menuObjects[0].sprite.setPosition(sf::Vector2f(600, -35));
	menuObjects[1].sprite.setPosition(sf::Vector2f(750, 385));
	menuObjects[2].sprite.setPosition(sf::Vector2f(100, 125));

}

Menu::~Menu(){
	delete[] menuObjects;
}

void Menu::draw(sf::RenderWindow& window) {
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
		window.draw(menu[i]);
	for (int i = 0; i < 3; i++)
		window.draw(menuObjects[i].sprite);
	return;
}

void Menu::MoveUp() {
	if (selectedItemIndex - 1 >= 0) {
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setColor(sf::Color(0, 0, 255));
	}
	return;
}

void Menu::MoveDown() {
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS) {
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setColor(sf::Color(0, 0, 255));
	}
	return;
}

int Menu::getSelectedItemIndex()const {
	return selectedItemIndex;
}
void Menu::setSelectedItemIndex(int selectedItemIndex) {
	if (selectedItemIndex >= 0)
		this->selectedItemIndex = selectedItemIndex;
	return;
}
sf::FloatRect Menu::getGlobalBounds(int index) {
	return menu[index].getGlobalBounds();
}
void Menu::setColor(int index, const sf::Color color) {
	menu[index].setColor(color);
	return;
}
void Menu::setWidth(float width) {
	if (width > 0)
		this->width = width;
	return;
}
void Menu::setHeight(float height) {
	if (height > 0)
		this->height = height;
	return;
}