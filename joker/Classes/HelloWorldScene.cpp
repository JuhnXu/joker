#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

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
    
    /////////////////////////////    
    //关闭按钮
    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback) );
    pCloseItem->setPosition( ccp(WINSIZE_W - 20,WINSIZE_H - 20) );

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu, 1);
    /////////////////////////////
    //~关闭按钮
    
    //初始化地图
    initBackground();
     //~初始化地图
    
    //加载英雄动画
    CCNodeLoaderLibrary *lib = CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
    lib->registerCCNodeLoader("Hero", HeroLoader::loader());
    CCBReader *ccbr = new CCBReader(lib);
    ccbr->autorelease();
    
    herox = ccbr->readNodeGraphFromFile("lrc.ccbi");
    herox->setPosition(ccp(WINSIZE_W - HERO_SIZE_W  ,HERO_SIZE_H ));
    this->addChild(herox);
    
    //开启触摸
    setTouchEnabled(true);
    scheduleUpdate();
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic(BG_MT_FIGHT);
    
    
    return true;
}



void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    
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

void HelloWorld::update(float dt)
{

  
}

void HelloWorld::initBackground()
{
    m_bg = CCSprite::create(S_BG_2);
    m_bg->setAnchorPoint(ccp(0, 0));
    m_bgH = m_bg->getContentSize().height;
    addChild(m_bg, -10);
    
      
    m_bgH -= OFFSET_H_BG;

    m_bg->runAction(CCMoveBy::create(OFFSET_H_TIME, ccp(0, -OFFSET_H_BG)));

    
    schedule(schedule_selector(HelloWorld:: movingBackground),OFFSET_H_TIME);


}

void HelloWorld::movingBackground()
{
    //滚动背景
    
    m_bg->runAction(CCMoveBy::create(OFFSET_H_TIME, ccp(0, -OFFSET_H_BG)));
    m_bgH -= OFFSET_H_BG;
    
    // 图的顶部到达屏幕顶部时
    if (m_bgH <= WINSIZE_H) {
        if (!m_isReload) {
            
            // 如果另一张图还没加载则create一个
            m_bg_re = CCSprite::create(S_BG_2);
            m_bg_re->setAnchorPoint(ccp(0, 0));
            addChild(m_bg_re,-10);
            m_bg_re->setPosition(ccp(0, WINSIZE_H));
            
            m_isReload = true;
        }
        // 第二张图紧接着第一张图滚动
        m_bg_re->runAction(CCMoveBy::create(OFFSET_H_TIME, ccp(0, -OFFSET_H_BG)));
        
    }
    
    // 第一张图完全经过屏幕
    if (m_bgH <= -OFFSET_H_BG) {
        m_bgH = m_bg->getContentSize().height -OFFSET_H_BG;
        // 移除第一张的精灵
        this->removeChild(m_bg, true);
        
        // 指向第二张图的精灵
        m_bg = m_bg_re;
        
        // 第二张的精灵指针置空
        m_bg_re = NULL;
        
        // 反转标志位
        m_isReload = false;
    }
    
    

}