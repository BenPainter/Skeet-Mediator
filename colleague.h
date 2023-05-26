#pragma once

//#include "mediator.h"

class Score;
class HitRatio;
class Bullet;
class Bird;
struct Message;
class Mediator;

/******************************
* Abstract Colleague class
******************************/
class Colleague
{
protected: 
   Mediator* pMediator;

public:  
   Colleague(){}
   Colleague(Mediator *mediator){pMediator = mediator;}     
   virtual void notify(Message& message) = 0;

};

/******************************
* Hit Ratio Colleague class
******************************/
class HitRatioColleague : public Colleague
{
   HitRatio* pHitRatio;
public:
   HitRatioColleague(HitRatio* pHitRatioParameter) : pHitRatio(pHitRatioParameter) {}
   HitRatioColleague(HitRatio* pHitRatioParameter, Mediator* pMediator) : pHitRatio(pHitRatioParameter) { this->pMediator = pMediator; }
   void notify(Message& message);
};

/******************************
 Score Colleague class
******************************/
class ScoreColleague : public Colleague
{
   Score* pScore;
public:
   ScoreColleague(Score* pScoreParameter) : pScore(pScoreParameter) {}
   ScoreColleague(Score* pScoreParameter, Mediator* pMediator) : pScore(pScoreParameter) { this->pMediator = pMediator; }
   void notify(Message &message);

};

/******************************
* Bullet Colleague class
******************************/
class BulletColleague : public Colleague
{
   Bullet* pBullet;
public:

   BulletColleague(Bullet* pBulletParameter) : pBullet(pBulletParameter) {}
   BulletColleague(Bullet* pBulletParameter, Mediator* pMediator) : pBullet(pBulletParameter) { this->pMediator = pMediator; }
   void notify(Message& message);
   void firedBullet();

};

/******************************
*
******************************/
class BirdColleague : public Colleague
{
   Bird* pBird;
public:
//BirdColleague(Bird* pBirdParameter) : pBird(pBirdParameter), Colleague(mediator) {}
   BirdColleague(Bird* pBirdParameter) : pBird(pBirdParameter) {}
   BirdColleague(Bird* pBirdParameter, Mediator* pMediator) : pBird(pBirdParameter) { this->pMediator = pMediator; }
   virtual void notify(Message &message);
   void wentOutOfBounds();
   void wasShot(Bird* bird);
};