//
//  Hero.h
//  joker
//
//  Created by JuhnXu on 13-6-1.
//
//

#ifndef __joker__Hero__
#define __joker__Hero__

#include "GameObject.h"
#include "cocos-ext.h"
USING_NS_CC_EXT;
class Hero : public GameObject {
    
private:
    
    float ySpeed;
    
    bool init();
    
public:
    
    CC_SYNTHESIZE(float, xTarget, XTarget);
    
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(Hero,create);
    
    virtual void update();
    virtual void handleCollisionWith(GameObject* gameObject);
    virtual float radius();
    
    
};

//加载器
class HeroLoader : public cocos2d::extension::CCNodeLoader {
    
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(HeroLoader, loader);
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(Hero);
    
};

#endif /* defined(__joker__Hero__) */
