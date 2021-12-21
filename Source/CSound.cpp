#include "../Header/CSound.h"

#include <iostream>

CSoundEffect::CSoundEffect() {
    this->sound = nullptr;
    this->soundBuffer = nullptr;
}

CSoundEffect::CSoundEffect(string path) {
    soundBuffer = new sf::SoundBuffer;
    if (soundBuffer->loadFromFile(path)) cout << "LOAD SOUND SUCCESS FROM: " << path << endl;
    else cout << "LOAD SOUND FAILED FROM: " << path << endl;
    sound = new sf::Sound(*soundBuffer);
}

CSoundEffect::~CSoundEffect() {
    delete soundBuffer;
    delete sound;
}

void CSoundEffect::playSound() { this->sound->play(); }

CSound* CSound::instance = nullptr;

CSound* CSound::getInstance() {
    if (!instance) instance = new CSound;
    return instance;
}

CSound::~CSound() {
    delete instance;
    delete car_collision;
}

CSound::CSound() {
    std::string path = "Resource/Sound/";

    intro = new CSoundEffect(path + "intro.wav");
    car_collision = new CSoundEffect(path + "car-collision.wav");
    truck_collision = new CSoundEffect(path + "truck-collision.wav");
    bird_collision = new CSoundEffect(path + "bird-collision.wav");
    dinausor_collision = new CSoundEffect(path + "dinausor-collision.wav");
    people_move = new CSoundEffect(path + "people-move.wav");
    playing = new CSoundEffect(path + "playing.wav");
    waiting = new CSoundEffect(path + "waiting.wav");
}