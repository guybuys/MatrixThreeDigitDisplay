// MatrixThreeDigitDisplay.h
#ifndef MATRIX_THREE_DIGIT_DISPLAY_H
#define MATRIX_THREE_DIGIT_DISPLAY_H

#include <Arduino_LED_Matrix.h>

class MatrixThreeDigitDisplay {
public:
  MatrixThreeDigitDisplay();
  void begin();
  void displayNumber(uint16_t number);

private:
  ArduinoLEDMatrix matrix;
  uint8_t frame[8][12];
  static const uint8_t font[10][8];
  void clearFrame();
  void displayFrame();
  void addToFrame(uint8_t digit, int pos);
};

#endif