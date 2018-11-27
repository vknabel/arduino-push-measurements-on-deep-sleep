#ifndef Behavior_H
#define Behavior_H

#include<Arduino.h>

class Behavior {
protected:
  Behavior();
public:
  virtual void setup();
  virtual String characteristics();
};

#endif // Behavior_H
