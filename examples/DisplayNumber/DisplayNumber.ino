#include <MatrixThreeDigitDisplay.h>

MatrixThreeDigitDisplay display;

void setup() {
  display.begin();
}

void loop() {
  for (uint16_t i = 0; i < 1000; i++) {
    display.displayNumber(i);
    delay(100);
  }
}