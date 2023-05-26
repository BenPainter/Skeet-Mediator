#pragma once
#include "colleague.h"

enum MessageType { BIRD_DIED, BULLET_FIRED };


struct Message
{
public:
   MessageType type;
   int value;
};