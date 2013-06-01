//
//  MenuScene.cpp
//  joker
//
//  Created by JuhnXu on 13-6-1.
//
//

#include "MenuScene.h"
#include "xu.h"
#include "GameScene.h"

CCScene *MenuScene::scene()
{
    CCScene *scene = CCScene::create();
    
    scene->addChild(MenuSceneLoader::load());
    
    return scene;
}


void MenuScene::doPlay(cocos2d::CCObject *pSender)
{
    CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.2f, GameScene::scene()));
}


bool MenuScene::init()
{
    if (!CCLayer::init()) {
        
        return false;
    }
    
    CCMenuItemFont *button_play = CCMenuItemFont::create("开始游戏", this, menu_selector(MenuScene::doPlay));
    CCMenu *menu = CCMenu::create(button_play,NULL);

    this->addChild(menu ,10);
    return true;
}



//加载器




MenuScene *MenuSceneLoader::load()
{
    CCNodeLoaderLibrary *lib = CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
    lib->registerCCNodeLoader("MenuScene", MenuSceneLoader::loader());
    
    CCBReader *reader = new CCBReader(lib);
    
    reader->autorelease();
    
    CCNode *node = reader->readNodeGraphFromFile("MenuScene.ccbi");
    

    return (MenuScene*)node;
    
}