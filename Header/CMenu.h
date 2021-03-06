#ifndef CMenu_h
#define CMenu_h

#include "CFont.h"
#include "CImage.h"

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

using namespace std;

class CMenu {
public:
	CMenu(vector<string> optString, float x, float y, float height, bool inputPath = false);
	~CMenu();

	void draw(sf::RenderWindow& window, int id = -1);
	void MoveUp();
	void MoveDown();
	int GetPressedItem();

	void setOption(int index, string content);
private:
	int MAX_NUM_OF_OPT;
	int selectedIndex;
	CFont* localFont;
	CImage* localImage;
	vector<sf::Text> optText;

	const sf::Color normalColor = sf::Color(0, 0, 0);
	const sf::Color selectedColor = sf::Color(255, 0, 0);

	// support TextField
	//sf::TextField tf(20);
};

#endif