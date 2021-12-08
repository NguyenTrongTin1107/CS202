#include "CGame.h"

// CGame* CGame::instancePtr = nullptr;

void CGame::initVariable()
{
	this->window = nullptr;
}

void CGame::initWindow()
{
	this->videoMode.height = SCREEN_HEIGHT;
	this->videoMode.width = SCREEN_WIDTH;
	this->window = new sf::RenderWindow(this->videoMode, "Crossing road", sf::Style::Titlebar | sf::Style::Close);
}

void CGame::initEnemies()
{
	this->enemy.setPosition(20.f, 10.f);
	this->enemy.setSize(sf::Vector2f(100.f, 100.f));
	this->enemy.setFillColor(sf::Color::Cyan);
	this->enemy.setOutlineColor(sf::Color::Green);
	this->enemy.setOutlineThickness(1.f);
}

void CGame::initTexts() {
	text.setFont(localFont.SemiBold);
	text.setString("Welcome");
	text.setCharacterSize(60);
	text.setFillColor(sf::Color::White);
	//text.setStyle(sf::Text::Bold | sf::Text::Underlined);

	sf::FloatRect textRect = text.getLocalBounds();
	text.setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);
	text.setPosition(sf::Vector2f(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f));
}

CGame::CGame() {
	this->state = GameState::welcome;

	this->initVariable();
	this->initWindow();
	this->initEnemies();
	this->initPrimaryMenu();

	initTexts();
}

/*CGame* CGame::getInstance()
{
	if (instancePtr == nullptr)
		instancePtr = new CGame;
	return instancePtr;
}*/

CGame::~CGame()
{
	delete this->window;
	delete this->primaryMenu;
}

const bool CGame::isRuning() const
{
	return this->window->isOpen();
}

void CGame::welcome()
{
	this->window->draw(text);
}

void CGame::initPrimaryMenu()
{
	vector<string> opt = { "New game", "Load game", "Setting" };
	primaryMenu = new CMenu(opt, 100, 100);
}

void CGame::drawGame()
{
	cout << "Draw game." << endl;
}

void CGame::pollEvent()
{
	while (this->window->pollEvent(this->event)) {
		switch (this->event.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			switch (this->state) {
			case GameState::welcome:
				handleWelcomeState();
				break;
			case GameState::primaryMenu:
				handlePrimaryMenuState();
				break;
			}
		default:
			break;
		}
	}
}

void CGame::handleWelcomeState() {
	if (this->event.key.code == sf::Keyboard::Escape)
		this->window->close();
	else if (this->event.key.code == sf::Keyboard::Enter)
		this->state = GameState::primaryMenu;
}

void CGame::handlePrimaryMenuState() {
	switch (this->event.key.code) {
	case sf::Keyboard::W:
	case sf::Keyboard::Up:
		primaryMenu->MoveUp();
		break;
	case sf::Keyboard::S:
	case sf::Keyboard::Down:
		primaryMenu->MoveDown();
		break;
	case sf::Keyboard::Enter:
		int choice = primaryMenu->GetPressedItem();
		cout << "Choice: " << choice << endl;
		break;
	}
}

void CGame::update()
{
	pollEvent();
}

void CGame::render()
{
	this->window->clear();
	
	switch (state) {
	case GameState::welcome:
		welcome();
		break;
	case GameState::primaryMenu:
		primaryMenu->draw(*this->window);
		break;
	default:
		break;
	}	

	this->window->display();
}