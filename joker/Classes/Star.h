//
//  Star.h
//  joker
//
//  Created by JuhnXu on 13-6-20.
//
//

#ifndef __joker__Star__
#define __joker__Star__

#include "cocos2d.h"
#include "xu.h"
#include "GameObject.h"




class Star : public  GameObject{
    
private:
    
    bool init();
    
public:
    
    virtual void update();
    virtual void handleCollisionWith(GameObject* gameObject);
    virtual float radius();
    virtual void removeSelf();
};

#endif /* defined(__joker__Star__) */
