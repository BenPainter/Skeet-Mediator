#pragma once

# include "colleague.h"
# include "message.h"
# include <list>

class Colleague;

class Mediator
{
public:
   std::list<Colleague*> colleagues;

public:
  
   Mediator(std::list<Colleague*>& colleagueList);
   Mediator();
   void addColleague(Colleague* colleague);
   void removeColleague(Colleague* colleague);
   void notify(Message& message);

};

