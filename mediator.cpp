#include "mediator.h"

#include<iostream>

Mediator::Mediator() { }

Mediator::Mediator(std::list<Colleague*>& colleagueList) : colleagues(colleagueList) {}


void Mediator::addColleague(Colleague* colleague)
{
   
   std::cout<<"I got Pushed Back"<<std::endl;
   colleagues.push_back(colleague);
}

void Mediator::removeColleague(Colleague* colleague)
{
   std::cout << "I got Removed :(" << std::endl;
   colleagues.remove(colleague);
}

void Mediator::notify(Message& message)
{
   std::cout << "I MADE IT TO MEDIATOR" << std::endl;
    for (auto colleague : colleagues)
       colleague->notify(message);


 }
