/***********************************************************************
 * Header File:
 *    Bird : Everything that can be shot
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Stuff that moves across the screen to be shot
 ************************************************************************/

#pragma once

#include "point.h"
#include "colleague.h"
#include "mediator.h"

/**********************
 * BIRD
 * Everything that can be shot
 **********************/
class Bird
{
//protected:
protected:
   static Point dimensions; // size of the screen
   Velocity v;                // velocity of the flyer
   double radius;             // the size (radius) of the flyer
   bool dead;                 // is this flyer dead?
   int points;                // how many points is this worth?
   //Mediator* mediator;

public:
    BirdColleague* pBirdColleague;  
    Point pt;                  // position of the flyer
   // mediator(mediator)  pBirdColleague = new BirdColleague(this, mediator);
public:
   Bird() : dead(false), points(0), radius(1.0) {pBirdColleague = new BirdColleague(this);  }
   Bird(Mediator *pMediator) : dead(false), points(0), radius(1.0) { pBirdColleague = new BirdColleague(this, pMediator); }
     
   void wasShot() { pBirdColleague->wasShot(this); }
   // setters
   void operator=(const Point    & rhs) { pt = rhs;    }
   void operator=(const Velocity & rhs) { v = rhs;     }
   void kill()                          { dead = true; }

   // getters
   bool isDead()           const { return dead;   }
   Point getPosition()     const { return pt;     }
   Velocity getVelocity()  const { return v;      }
   double getRadius()      const { return radius; }
   int getPoints() const { return points; }
   bool isOutOfBounds() const
   {
      return (pt.getX() < -radius || pt.getX() >= dimensions.getX() + radius ||
              pt.getY() < -radius || pt.getY() >= dimensions.getY() + radius);
   }
   // setters
   void setPoints(int newPt) { points = newPt; }
   void setPosition(Point newPoint) { pt = newPoint; }
   void setVelocity(Velocity newV) { v = newV; }

   // special functions
   virtual void draw() = 0;
   virtual void advance() = 0;
};

/*********************************************
 * STANDARD
 * A standard bird: slows down, flies in a straight line
 *********************************************/
class Standard : public Bird
{
public:
    Standard(double radius = 25.0, double speed = 5.0, int points = 10);
    Standard(Mediator* pMediator = nullptr, double radius = 25.0, double speed = 5.0, int points = 10);
    //{pBirdColleague = new BirdColleague(this, pMediator);}
    void draw();
    void advance();
};

/*********************************************
 * FLOATER
 * A bird that floats like a balloon: flies up and really slows down
 *********************************************/
class Floater : public Bird
{
public:
    Floater(double radius = 30.0, double speed = 5.0, int points = 15);
    void draw();
    void advance();
};

/*********************************************
 * CRAZY
 * A crazy flying object: randomly changes direction
 *********************************************/
class Crazy : public Bird
{
public:
    Crazy(double radius = 30.0, double speed = 4.5, int points = 30);
    void draw();
    void advance();
};

/*********************************************
 * SINKER
 * A sinker bird: honors gravity
 *********************************************/
class Sinker : public Bird
{
public:
    Sinker(double radius = 30.0, double speed = 4.5, int points = 20);
    void draw();
    void advance();
};
