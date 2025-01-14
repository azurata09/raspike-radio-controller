#include "ev3api.h"
#include "app.h"

#include "Driver.h"
#include "Receiver.h"

#include <stdio.h>

#define DEBUG

#ifdef DEBUG
#define _debug(x) (x)
#else
#define _debug(x)
#endif

Driver driver;
Receiver receiver;

void main_task(intptr_t unused) {
  // Setup
  tslp_tsk(1000 * 1000); // Wait for 1s

  sta_cyc(CONTROL_CYCLER);
  // slp_tsk(); // Wait for wakeup
  // stp_cyc(CONTROL_CYCLER);

  ext_tsk();
}

void control_cycler(intptr_t unused) {
  int cmd = receiver.receive();
  printf("Received command: %d\n", cmd);

  switch(cmd) {
    case FORWARD_ACTION:
      printf("Forward\n");
      driver.forward();
      break;
    case BACKWARD_ACTION:
      printf("Backward\n");
      driver.backward();
      break;
    case SPIN_LEFT_ACTION:
      printf("Spin Left\n");
      driver.spin(SPIN_LEFT);
      break;
    case SPIN_RIGHT_ACTION:
      printf("Spin Right\n");
      driver.spin(SPIN_RIGHT);
      break;
    default:
      printf("Unknown\n");
      break;
  }
}
