//
//  GameScene.cpp
//  joker
//
//  Created by JuhnXu on 13-6-2.
//
//

#include "GameScene.h"
#include "SimpleAudioEngine.h"
#include "Hero.h"
#include "MenuScene.h"
#include "xu.h"
using namespace cocos2d;
using namespace CocosDenshion;

CCScene* GameScene::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    GameScene *layer = GameScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    
    /////////////////////////////
    //关闭按钮
    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                                          "CloseNormal.png",
                                                          "CloseSelected.png",
                                                          this,
                                                          menu_selector(GameScene::menuCloseCallback) );
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
    initHero("hero01");
    
//    CCSpriteBatchNode *batch = CCSpriteBatchNode::create("hero01.plist", 4);
//    this->addChild(batch);
////    herox = CCSprite::createWithSpriteFrameName(batch->getTexture());
//    herox = CCSprite::createWithTexture(batch->getTexture());
//    herox->setPosition(ccp(WINSIZE_W - HERO_SIZE_W  ,HERO_SIZE_H ));
//    batch->addChild(herox);
//
//    

//    
//    CCSpriteBatchNode* batchNode = CCSpriteBatchNode::create("hero01.png", 4);
//    batchNode->setPosition(CCPointZero);
//    this->addChild(batchNode);
//    
//   
//        CCSprite* testIcon = CCSprite::createWithTexture(batchNode->getTexture());
//        testIcon->setPosition( ccp(WINSIZE_W /2, WINSIZE_H /2) );
//        batchNode->addChild(testIcon);
    

    
//    
//    CCSpriteFrameCache *cache = CCSpriteFrameCache::sharedSpriteFrameCache();
//    
//    
//    
//    cache->addSpriteFramesWithFile("hero01.plist");
//
//    m_hero = CCSprite::createWithSpriteFrameName("hero01_01.png");
//    this->addChild(m_hero);
//    m_hero->setPosition(ccp(WINSIZE_W - HERO_SIZE_W  ,HERO_SIZE_H ));
    //    herox->runAction(CCMoveTo::create(1, ccp(WINSIZE_W /2, WINSIZE_H /2)));
    //    this->addChild(herox);
    
    //开启触摸
    setTouchEnabled(true);
    scheduleUpdate();
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic(MUSIC_MT_FIGHT);
    
     
     
#if 0
    //返回重复动作用reverse
    //用关闭按钮来测试贝塞尔曲线
    bezierCfg.controlPoint_1 = ccp(0 , WINSIZE_H /2);
    bezierCfg.controlPoint_2 = ccp(-WINSIZE_W + HERO_SIZE_W, WINSIZE_H /2);
    bezierCfg.endPosition = ccp(-WINSIZE_W + HERO_SIZE_W * 2, 0);
    
    CCBezierBy *bezierToAction = CCBezierBy::create(0.7, bezierCfg);
    //    CCMoveBy *bezierToAction = CCMoveBy::create(1, ccp(-100, 20));
    pCloseItem->setPosition(ccp(WINSIZE_W - HERO_SIZE_W  ,HERO_SIZE_H ));
    pCloseItem->runAction(CCRepeatForever::create(CCSequence::create(bezierToAction , bezierToAction->reverse() ,NULL)));

#endif
    
    
    return true;
}



void GameScene::menuCloseCallback(CCObject* pSender)
{
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    
    CCDirector::sharedDirector()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void GameScene::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{
    
    

      
    
}

void GameScene::update(float dt)
{
    
    
}

void GameScene::initBackground()
{
//    m_objectmap = CCTMXTiledMap::create("pretab1.tmx");
//    m_objectmap->setAnchorPoint(ccp(0, 0));
//    this->addChild(m_objectmap);
//    
//    CCTMXLayer *buildingLayer = m_objectmap->layerNamed("layer");
//    CCSprite *node =  buildingLayer->tileAt(ccp(0, 0));
//    
//    if (!node) {
//        buildingLayer->setTileGID(1, ccp(0, 0));
//        
//    }

    m_bg = CCSprite::create(S_BG_2);
    m_bg->setAnchorPoint(ccp(0, 0));
    m_bgH = m_bg->getContentSize().height;
    addChild(m_bg, -10);
    
    
    m_bgH -= OFFSET_H_BG;
    
    m_bg->runAction(CCMoveBy::create(OFFSET_H_TIME, ccp(0, -OFFSET_H_BG)));
    
    
    schedule(schedule_selector(GameScene::movingBackground),OFFSET_H_TIME);
    
    
}

void GameScene::movingBackground()
{
    //滚动背景

    /////////////////////////////////////
    //// 阻碍物下滑
    
//    if (m_objectmap) {
//        
//        
//        m_objectmap->runAction(CCMoveBy::create(OFFSET_H_TIME *3 , ccp(0, -OFFSET_H_BG *2)));
//        
//        if (m_objectmap->getPosition().y <= -640) {
//            //如果超出了屏幕就重新放到前面
//            //设想是可以后面拼接多个不同的场景的
//            m_objectmap->setPosition(ccp(0, WINSIZE_H));
//            
//        }
//    }else
//    {
//        CCLog("m_objectmap is null");
//    }
    //// ~阻碍物下滑
    
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

void GameScene::setFinishMoving()
{
    //完成移动，可以继续点击
    m_isMoving = false;
}




void GameScene::initHero(const char *name)
{
    CCSpriteFrameCache *cache = CCSpriteFrameCache::sharedSpriteFrameCache();
    cache->addSpriteFramesWithFile(CCString::createWithFormat("%s.plist",name)->getCString());
    
    
    m_hero = CCSprite::createWithSpriteFrameName(CCString::createWithFormat("%s_01.png",name)->getCString());
    this->addChild(m_hero);
    m_hero->setPosition(ccp(WINSIZE_W/2  ,WINSIZE_H/2 ));
    
    CCArray *array = CCArray::create();
    
    for (int i = 1; i<5; i++) {
        CCLOG(CCString::createWithFormat("loading ... %s_0%d.png",name ,i)->getCString());
        CCSpriteFrame *frame = cache->spriteFrameByName(CCString::createWithFormat("%s_0%d.png",name ,i)->getCString());
        if (frame) {
            CCLOG("frame is ok");
        }
        array->addObject(frame);
    }
    
    //这里不能直接用CCAnimation::create，会报错强转不了
    CCAnimation *ani = CCAnimation::createWithSpriteFrames(array ,0.2f);

    
    CCAnimate *animate = CCAnimate::create(ani);
    m_hero->runAction(CCRepeatForever::create(animate));

    
}