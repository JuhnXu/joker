//
//  Hero.cpp
//  joker
//
//  Created by JuhnXu on 13-6-1.
//
//

#include "Hero.h"


bool Hero::init()
{
    return true;
}


void Hero::update()
{
    
}

void Hero::handleCollisionWith(GameObject *gameObject)
{
    CCBAnimationManager* animationManager = dynamic_cast<CCBAnimationManager*>(this->getUserObject());
    animationManager->runAnimationsForSequenceNamed("attack");
}


float Hero::radius()
{
    return 25.0f;
}