#include "AppDelegate.h"
#include "LoadingResScene.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate()
{
}

bool AppDelegate::applicationDidFinishLaunching() {
	// initialize director
	auto director = Director::getInstance();
	auto glview = director->getOpenGLView();
	if(!glview) {
		glview = GLViewImpl::create("TD Game");
		director->setOpenGLView(glview);
	}

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	glview->setDesignResolutionSize(480.0f, 320.0f, ResolutionPolicy::FIXED_HEIGHT);
	director->setContentScaleFactor(864.0f / 320.0f);
#endif
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	Size visibleSize = Director::getInstance()->getVisibleSize();
	if(visibleSize.height/visibleSize.width > 800/480){
		glview->setDesignResolutionSize(800, 480, ResolutionPolicy::EXACT_FIT);
	}
	else{
		glview->setDesignResolutionSize(800, 480, ResolutionPolicy::NO_BORDER);
	}
#endif
	// turn on display FPS
	director->setDisplayStats(false);

	// set FPS. the default value is 1.0/60 if you don't call this
	director->setAnimationInterval(1.0 / 60);

	// create a scene. it's an autorelease object
	auto scene = LoadingResScene::createScene();

	// run
	director->runWithScene(scene);

	return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
	Director::getInstance()->stopAnimation();

	// if you use SimpleAudioEngine, it must be pause
	// SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
	Director::getInstance()->startAnimation();

	// if you use SimpleAudioEngine, it must resume here
	// SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
