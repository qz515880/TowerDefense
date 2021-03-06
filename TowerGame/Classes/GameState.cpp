#include "GAMESTATE.h"
#include "cocos2d.h"
using namespace cocos2d;

GAMESTATE* GAMESTATE::_instance = 0;

GAMESTATE::GAMESTATE(){
	this->init();
}

void GAMESTATE::init(){
	reset();
}

void GAMESTATE::reset(){
	gamePause = false;
	gameOver = false;
}

GAMESTATE* GAMESTATE::getInstance(){
	if(_instance == 0){
		_instance = new GAMESTATE();
	}
	return _instance;
}

void GAMESTATE::setGamePause(bool pause){
	gamePause = pause;
}

bool GAMESTATE::getGamePause(){
	return gamePause;
}

void GAMESTATE::setGameOver(bool over){
	gameOver = over;
}

bool GAMESTATE::getGameOver(){
	return gameOver;
}

void GAMESTATE::setRefreshTopmenu(bool refresh){
	refreshTopmenu = refresh;
}

bool GAMESTATE::getRefreshTopmenu(){
	return refreshTopmenu;
}

bool GAMESTATE::getLevelResult(){
    return levelResult;
}

void GAMESTATE::setLevelResult(bool pass){
	levelResult=pass;
}

void GAMESTATE::setRefreshGameHUD(bool refresh){
   refreshGameHUD = refresh;
}
bool GAMESTATE::getRefreshGameHUD(){
    return refreshGameHUD;
}

void GAMESTATE::setNeedRefesh(bool refresh){
	refreshGameHUD=refresh;
	refreshTopmenu=refresh;
}