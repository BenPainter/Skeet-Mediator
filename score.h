/***********************************************************************
 * Header File:
 *    Score
 * Author:
 *    Br. Helfrich
 * Summary:
 *    How well the player is doing
 ************************************************************************/

#pragma once

# include "colleague.h"
#include <string>

/**********************
 * STATUS
 * How well the player is doing
 **********************/
class Status
{
public:
    Status() {}
    virtual std::string getText() const = 0;
    virtual void adjust(int value) = 0;
    virtual void reset() = 0;
};

/**********************
 * SCORE
 * Points earned vs lost
 **********************/
class Score : public Status
{
public:
  
    Score() {pScoreColleague = new ScoreColleague(this),  reset(); }
    Score(Mediator* pMediator) { pScoreColleague = new ScoreColleague(this, pMediator), reset(); }
    std::string getText() const;
    void adjust(int value) { points += value; }
    void reset() { points = 0; }

    ScoreColleague* pScoreColleague;

private:
    int points;

};

/**********************
 * HIT RATIO
 * Bird hit ratio
 **********************/
class HitRatio : public Status
{
public:
    HitRatio()  { pHitRatioColleague = new HitRatioColleague(this), reset(); }
    HitRatio(Mediator* pMediator)  { pHitRatioColleague = new HitRatioColleague(this, pMediator), reset(); }
    std::string getText() const;
    void adjust(int value);
    void reset() { numKilled = numMissed = 0; }

    HitRatioColleague* pHitRatioColleague;

private:
    int numKilled;
    int numMissed;
};
