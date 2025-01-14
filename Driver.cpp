#include "Driver.h"

Driver::Driver()
: LEFT(EV3_PORT_C), RIGHT(EV3_PORT_B)
{
  ev3_motor_config(LEFT, LARGE_MOTOR);
  ev3_motor_config(RIGHT, LARGE_MOTOR);
}

Driver::~Driver()
{
  ev3_motor_stop(LEFT, true);
  ev3_motor_stop(RIGHT, true);
}

void Driver::forward()
{
  ev3_motor_set_power(LEFT, speed);
  ev3_motor_set_power(RIGHT, speed);
}

void Driver::backward()
{
  ev3_motor_set_power(LEFT, -speed);
  ev3_motor_set_power(RIGHT, -speed);
}

void Driver::spin(int direction)
{
  if (direction == SPIN_LEFT)
  {
    ev3_motor_set_power(LEFT, -speed);
    ev3_motor_set_power(RIGHT, speed);
  }
  else
  {
    ev3_motor_set_power(LEFT, speed);
    ev3_motor_set_power(RIGHT, -speed);
  }
}
