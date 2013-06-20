//
//  GameScene.h
//  joker
//
//  Created by JuhnXu on 13-6-2.
//
//

#ifndef __joker__GameScene__
#define __joker__GameScene__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "MenuScene.h"
USING_NS_CC;
USING_NS_CC_EXT;
class GameScene : public cocos2d::CCLayer
{
public:
    CCNode *herox ;
    
    CCSprite *m_bg;
    CCSprite *m_bg_re;
    CCSprite *heroShell;
    ccBezierConfig bezierCfg;
    CCTMXTiledMap *m_objectmap;
    
    bool m_isMoving = false;
    bool m_isRight = true;
    int m_bgH  ,m_bgreH = 0;
    bool m_isReload = false;
    // Method 'init' in cocos2d-x returns bool, instead of 'id' in cocos2d-iphone (an object pointer)
    virtual bool init();
    
    // there's no 'id' in cpp, so we recommend to return the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
    
    // preprocessor macro for "static create()" constructor ( node() deprecated )
    CREATE_FUNC(GameScene);
    
    
    void ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
    
    void initBackground();
    void movingBackground();
    void update(float dt);
    void setFinishMoving();

};






#endif /* defined(__joker__GameScene__) */
