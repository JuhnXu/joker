//
//  GameScene.cpp
//  joker
//
//  Created by JuhnXu on 13-6-2.
//
//

#include "GameScene.h"
#include "Hero.h"


GameScene* GameScene::sharedInstance = NULL;

GameScene* GameScene::sharedScene()
{
    return sharedInstance;
}

CCScene* GameScene::scene()
{
    CCScene* scene = CCScene::create();
    sharedInstance = GameSceneLoader::load();
    
    scene->addChild(sharedInstance);
    
    return scene;
}

void GameScene::onEnter()
{
    CCLayer::onEnter();

    
    this->setTouchEnabled(true);
    
    CCObject *obj ;
    CCARRAY_FOREACH(this->getChildren(), obj)
    {
        if (dynamic_cast<Hero *>(obj)) {
            this->hero = dynamic_cast<Hero *>(obj);
            CCLog("转换成功！！");
        }
    };
}

bool GameScene::init()
{
    
    
    if (!CCLayer::init()) {
        return false;
    }
    
    if (hero) {
        CCLog("转换成功！！");
    }else
    {
        CCLog("转换失败！！");
    }
    
    
    return true;
}

int GameScene::getScore()
{
    return score;
}

void GameScene::setScore(int s)
{
//    score = s;
//    
//    CCString* newScore = CCString::createWithFormat("%d", score);
//    scoreLabel->setString(newScore->getCString());
}

void GameScene::handleGameOver()
{
    CCDirector::sharedDirector()->replaceScene(MenuScene::scene());
}

void GameScene::handleLevelComplete()
{
    CCDirector::sharedDirector()->replaceScene(MenuScene::scene());
}

void GameScene::registerWithTouchDispatcher()
{
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->addTargetedDelegate(this, this->getTouchPriority(), true);
}

bool GameScene::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    CCLog("!!!");
    return true;
}

//加载器
GameScene* GameSceneLoader::load()
{
    cocos2d::extension::CCNodeLoaderLibrary * ccNodeLoaderLibrary = cocos2d::extension::CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
    
    ccNodeLoaderLibrary->registerCCNodeLoader("GameScene", GameSceneLoader::loader());
    ccNodeLoaderLibrary->registerCCNodeLoader("Hero", HeroLoader::loader());
    
    /* Create an autorelease CCBReader. */
    cocos2d::extension::CCBReader * ccbReader = new cocos2d::extension::CCBReader(ccNodeLoaderLibrary);
    ccbReader->autorelease();
    
    /* Read a ccbi file. */
    cocos2d::CCNode * node = ccbReader->readNodeGraphFromFile("GameScene.ccbi");
    GameScene* layer = (GameScene*) node;
    
    // return the layer
    return layer;
}