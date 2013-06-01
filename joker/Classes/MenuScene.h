//
//  MenuScene.h
//  joker
//
//  Created by JuhnXu on 13-6-1.
//
//

#ifndef __joker__MenuScene__
#define __joker__MenuScene__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class MenuScene :public cocos2d::CCLayer{
    
    
public:
    static cocos2d::CCScene* scene();
    
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(MenuScene, create);

    void doPlay(cocos2d::CCObject * pSender);
    
    bool init();
};



class MenuSceneLoader : CCLayerLoader {
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(MenuSceneLoader ,loader);
    static MenuScene *load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(MenuScene);
};
#endif /* defined(__joker__MenuScene__) */
