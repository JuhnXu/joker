//
//  Config.h
//  joker
//
//  Created by JuhnXu on 13-6-20.
//
//

#ifndef __joker__Config__
#define __joker__Config__


#include "cocos2d.h"
#include <vector>

USING_NS_CC;
using namespace std;

extern cocos2d::CCArray *g_buildings;


class Config : public CCObject{
private:

    int m_scoreValue;
    int m_life;
    bool m_isAudioOn;
    Config();
    
public:
    ~Config();
    static Config* sharedConfig();

    int getLifeCount();
    bool getAudioState();
    void updateAudioState(bool isOn);
    int getScoreValue();
    void updateLifeCount();
    void setScoreValue(int score);
    void resetConfig();
};


#endif /* defined(__joker__Config__) */
