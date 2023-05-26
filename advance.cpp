#include "advance.h"
#include "bird.h"
#include "point.h"

/***************************************************************/
/***************************************************************/
/*                             MISC.                           */
/***************************************************************/
/***************************************************************/


/******************************************************************
 * RANDOM
 * These functions generate a random number.
 ****************************************************************/
int advanceRandomInt(int min, int max)
{
   int num = (rand() % (max - min)) + min;
   return num;
}
double advanceRandomFloat(double min, double max)
{
   double num = min + ((double)rand() / (double)RAND_MAX * (max - min));
   return num;
}


void Advance::advance(Bird *bird)
{
     drag(bird);
     inertia(bird);
     buoyancy(bird);
     turn(bird);


   if (bird->isOutOfBounds())
      {
        bird->kill();
        int points = bird->getPoints();
        bird->setPoints(points *= -1); // points go negative when it is missed!
      }
}

void Advance::inertia(Bird *bird)
{
   bird->pt.add(bird->getVelocity());
}


void StandardAdvance::drag(Bird *bird) 
{
    bird->setVelocity(bird->getVelocity() *= 0.995);
}

void CrazyAdvance::turn(Bird *bird)
{
    Velocity v;

   if (advanceRandomInt(0, 15) == 0)
   {
        v.addDy(advanceRandomFloat(-1.5, 1.5));
        v.addDx(advanceRandomFloat(-1.5, 1.5));
        bird->setVelocity(v);
   }

}

void SinkerAdvance::buoyancy(Bird* bird)
{
   Velocity v = bird->getVelocity();
   v.addDy(-0.07);
   bird->setVelocity(v);
}

void FloaterAdvance::drag(Bird *bird)
{
bird->setVelocity(bird->getVelocity() *= 0.990);
}

void FloaterAdvance::buoyancy(Bird* bird)
{
   Velocity v = bird->getVelocity();
   v.addDy(0.05);
   bird->setVelocity(v);
}

