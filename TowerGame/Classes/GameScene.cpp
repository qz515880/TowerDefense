#include "GameScene.h"
#include "GameLayer.h"

bool GameScene::init(){
	if(!Scene::init()){
		return false;
	}
	auto layer=GameLayer::create();
	this->addChild(layer);
	return true;
} 