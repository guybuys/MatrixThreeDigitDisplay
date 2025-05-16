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
  ArduinoLEDMatrix _matrix;
  uint8_t _frame[8][12];
  static const uint8_t _font[10][8];
  void _clearFrame();
  void _displayFrame();
  void _addToFrame(uint8_t digit, int pos);
};

#endif