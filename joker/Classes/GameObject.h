//
//  GameObject.h
//  joker
//
//  Created by JuhnXu on 13-6-1.
//
//

#ifndef __joker__GameObject__
#define __joker__GameObject__

#include "cocos2d.h"

class GameObject : public cocos2d::CCNode
{
    
public:
    CC_SYNTHESIZE(bool, isScheduledForRemove, IsScheduledForRemove);
    
    virtual float radius() = 0;
    virtual void update() = 0;
    virtual void handleCollisionWith(GameObject* gameObject) = 0;
    
};

#endif /* defined(__joker__GameObject__) */
