#ifndef OBSERVER_H
#define OBSERVER_H

#include "gameEvent.h"
#include "trade.h"

class Tile; 
class Criteria; 
class Goal; 

class Observer {
 public:
  virtual void notify(GameEvent ge) = 0; 
  virtual void notify(GameEvent ge, Trade t) = 0; 
  
  //virtual void notify(Criteria &c) = 0; 
  //virtual void notify(Tile &t) = 0; 
  virtual ~Observer() = default; 
};

#endif