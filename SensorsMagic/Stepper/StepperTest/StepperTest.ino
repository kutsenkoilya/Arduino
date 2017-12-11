#include <Stepper.h>

Stepper Name(32,8,9,10,11);
void setup() {
 
  Name.setSpeed(100);
}

void loop() {
  Name.step(200);
}
