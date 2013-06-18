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
private:
    cocos2d::CCLayer* levelLayer;
    cocos2d::CCLabelTTF* scoreLabel;
    cocos2d::CCNode* hero;
    
    int score;
    
public:
    static GameScene* sharedInstance;
    
    static GameScene* sharedScene();
    
    static cocos2d::CCScene* scene();
    
    virtual void onEnter();
    
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(GameScene, create);
    
    bool init();
    
    void handleGameOver();
    void handleLevelComplete();
    
    int getScore();
    void setScore(int s);
    
    void registerWithTouchDispatcher();
    
    bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);

};




class GameSceneLoader : public cocos2d::extension::CCLayerLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(GameSceneLoader, loader);
    static GameScene* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(GameScene);
    
};


#endif /* defined(__joker__GameScene__) */
