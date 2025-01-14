#ifndef DRIVER_H
#define DRIVER_H

#include "ev3api.h"

#define SPIN_LEFT 0
#define SPIN_RIGHT 1

class Driver
{
private:
  const motor_port_t LEFT;
  const motor_port_t RIGHT;
  int speed = 30;

public:
  Driver();
  ~Driver();
  void forward();
  void backward();
  void spin(int direction);
};

#endif