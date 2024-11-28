#ifndef OBSERVER_H
#define OBSERVER_H

class Tile; 
class Criteria; 
class Goal; 

class Observer {
 public:
  virtual void notify(Goal &g) = 0; 
  virtual void notify(Criteria &c) = 0; 
  virtual void notify(Tile &t) = 0; 
  virtual ~Observer() = 0; 
};

#endif