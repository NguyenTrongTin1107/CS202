#ifndef Game_h
#define Game_h

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <iostream>
#include "CFont.h"
#include "CMenu.h"
#include "CPeople.h"
#include "CLevel.h"
#include "CPlayGround.h"

using namespace std;

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 720

#define WIDTH 400

#define MAX_NUM_OBJ 5

enum GameState {
	welcome_state,
	intro_menu_state,
	playing_state,
	collision_state,
	pause_state,
	wait_for_level_up,
};

class CGame {
private:
	//static CGame* instancePtr;

	// Properties
	GameState state;
	CLevel level;

	bool pauseCars;
	bool pauseTrucks;
	
	// Window
	sf::RenderWindow* window;
	sf::Event event;
	sf::VideoMode videoMode;

	/*
	* Object
	*/
	sf::Text text;

	CPlayground* playground;

	/* --- MENU --- */
	CMenu* introMenu;
	CMenu* collisionMenu;
	CMenu* pauseMenu;

	CPeople* people;

	// Vehicle
	vector<CCar> cars;
	vector<CTruck> trucks;

	// Animal
	vector<CBird> birds;
	vector<CDinausor> dinausors;
	
	// User interface
	CFont localFont;
	CImage localImage;

	//CGame();

	// Private Functions
	void initVariable();
	void initWindow();
	void initMenu();

	void reInitObj();

	void initTexts();

	void initCars(int number = MAX_NUM_OBJ);
	void initTrucks(int number = MAX_NUM_OBJ);
	void initBirds(int number = MAX_NUM_OBJ);
	void initDinausors(int number = MAX_NUM_OBJ);

	void drawCar();

	/*------- POLL EVENT -------*/
	void handleWelcomeState();
	void handleIntroMenuState();
	void handlePlayingState();
	void handleCollisionMenuState();
	void handlePauseState();

	/*------- UPDATE EVENT -------*/
	void checkCollision();
	void objMove();
	void reuseObj();
	
public:
	CGame();
	//static CGame* getInstance();
	~CGame();

	const bool isRuning() const;

	// Functions
	void welcome();

	void drawGame();

	void pollEvent();
	void update();
	void render();
};

#endif