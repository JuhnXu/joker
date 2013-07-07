//
//  Config.cpp
//  joker
//
//  Created by JuhnXu on 13-6-20.
//
//

#include "Config.h"


CCArray *g_buildings;



static  Config *g_config = NULL;

Config::Config()
{
    
}


Config::~Config()
{
    g_buildings->release();
    g_buildings = NULL;
}


Config* Config::sharedConfig()
{
    if (!g_config) {
        g_config = new Config();
    }
    return g_config;
}


int Config::getScoreValue()
{
    return m_scoreValue;
}

void Config::setScoreValue(int score)
{
    m_scoreValue += score;
}

int Config::getLifeCount()
{
    return m_life;
}
void Config::updateLifeCount()
{
    m_life--;
}

bool Config::getAudioState()
{
    return m_isAudioOn;
}

void Config::updateAudioState(bool isOn)
{
    m_isAudioOn = isOn;
}

void Config::resetConfig()
{
    m_scoreValue = 0;
    m_life = 2;
    //    m_isAudioOn = true;
}
