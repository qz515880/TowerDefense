#include "TopMenu.h"
#include "GameLayer.h"
#include "SimpleAudioEngine.h"
#include "Chinese.h"
#include "GameData.h"
#include "TopMenu.h"
#include "GameLayer.h"
#include "GameState.h"


TopMenu* TopMenu::_instance = nullptr;

TopMenu::TopMenu(){
	this->init();
}

TopMenu* TopMenu::getInstance(){
	if(_instance == 0){
		_instance = new TopMenu();
	}
	return _instance;
}

bool TopMenu::init(){
	if(!Node::init()){
		return false;
	}
	LoadTopMenu();	
	return true;
}

void TopMenu::LoadTopMenu(){
	Size visibleSize = Director::getInstance()->getVisibleSize();
	//add lifeValue label
	lifeValue = Label::create(
		ChineseWord("lifevalue") + cocos2d::String::createWithFormat(":%d",GAMEDATA::getInstance()->getLifeValue())->_string,
		"Verdana-Bold",24
		);
	lifeValue->setPosition(visibleSize.width/2,visibleSize.height/2);
	this->addChild(lifeValue);

	//add wave value
	waveValue = Label::create(
		ChineseWord("waves") + cocos2d::String::createWithFormat(":%d",1)->_string+"/"+cocos2d::String::createWithFormat("%d",10)->_string,
		"Verdana-Bold",24
		);
	waveValue->setPosition(visibleSize.width/2,visibleSize.height/2+50);
	this->addChild(waveValue);

		//add player god value
	playerGold = Label::create(ChineseWord("gold")+cocos2d::String::createWithFormat(":%d",GAMEDATA::getInstance()->getPlayerGold())->_string,
		"Verdana-Bold",24
		);
	playerGold->setPosition(visibleSize.width/2,visibleSize.height/2+100);
	this->addChild(playerGold);
}
void TopMenu::refresh(){
	lifeValue->setString(ChineseWord("lifevalue") + cocos2d::String::createWithFormat(":%d",GAMEDATA::getInstance()->getLifeValue())->_string);
	waveValue->setString(ChineseWord("waves") + cocos2d::String::createWithFormat(":%d",1)->_string+"/"+cocos2d::String::createWithFormat("%d",10)->_string);
	playerGold->setString(ChineseWord("gold")+cocos2d::String::createWithFormat(":%d",GAMEDATA::getInstance()->getPlayerGold())->_string);
}