#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "xu.h"
#include "Hero.h"
#include "MenuScene.h"
using namespace cocos2d;
using namespace CocosDenshion;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback) );
    pCloseItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20) );

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu, 1);

   

    // ask director the window size
    CCSize size = CCDirector::sharedDirector()->getWinSize();

   
    // add "HelloWorld" splash screen"
    CCSprite* pSprite = CCSprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    pSprite->setPosition( ccp(size.width/2, size.height/2) );

    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);
    
    
    CCSprite *bg1 = CCSprite::create(BG_1);
    this->addChild(bg1);

    bg1->setPosition(ccp(WINSIZE_W/2,WINSIZE_H/2));
    
    //加载英雄动画
    CCNodeLoaderLibrary *lib = CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
    lib->registerCCNodeLoader("Hero", HeroLoader::loader());
    CCBReader *ccbr = new CCBReader(lib);
    ccbr->autorelease();
    
    herox = ccbr->readNodeGraphFromFile("lrc.ccbi");
    herox->setPosition(ccp(WINSIZE_W/2,WINSIZE_H/2));
    this->addChild(herox);
    
    //开启触摸
    setTouchEnabled(true);
    
    
    return true;
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    
    
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
void HelloWorld::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{

    ((GameObject *) (herox))->handleCollisionWith(NULL);
    
    CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.2f, MenuScene::scene()));

}