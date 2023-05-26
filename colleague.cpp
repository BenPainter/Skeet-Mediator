#include "colleague.h"
# include "bullet.h"
# include "bird.h"
#include "message.h"
# include "score.h"



void BirdColleague::wentOutOfBounds()
{
   Message message;
   message.type = BIRD_DIED;
   message.value = -(pBird->getPoints());
   notify(message);
}

void BirdColleague::wasShot(Bird *bird)
{
   Message message;
   message.type = BIRD_DIED;
   message.value = bird->getPoints();
   std::cout << "I WAS SHOT" << std::endl;
   pMediator->notify(message);
}

void HitRatioColleague::notify(Message &message)
{
   if (message.type == BIRD_DIED)
      pHitRatio->adjust(message.value);
}

void ScoreColleague::notify(Message& message)
{
   pScore->adjust(message.value);
}

void BulletColleague::notify(Message& message) {}
void BirdColleague::notify(Message& message) {}

void BulletColleague::firedBullet()
{
   Message message;
   message.type = BIRD_DIED;
   message.value = pBullet->getValue();
   notify(message);
}
