// MatrixThreeDigitDisplay.cpp
#include "MatrixThreeDigitDisplay.h"

const uint8_t MatrixThreeDigitDisplay::_font[10][8] = {
  {0b000, 0b111, 0b101, 0b101, 0b101, 0b111, 0b000, 0b000}, // 0
  {0b000, 0b001, 0b001, 0b001, 0b001, 0b001, 0b000, 0b000}, // 1
  {0b000, 0b111, 0b001, 0b111, 0b100, 0b111, 0b000, 0b000}, // 2
  {0b000, 0b111, 0b001, 0b111, 0b001, 0b111, 0b000, 0b000}, // 3
  {0b000, 0b101, 0b101, 0b111, 0b001, 0b001, 0b000, 0b000}, // 4
  {0b000, 0b111, 0b100, 0b111, 0b001, 0b111, 0b000, 0b000}, // 5
  {0b000, 0b111, 0b100, 0b111, 0b101, 0b111, 0b000, 0b000}, // 6
  {0b000, 0b111, 0b001, 0b001, 0b001, 0b001, 0b000, 0b000}, // 7
  {0b000, 0b111, 0b101, 0b111, 0b101, 0b111, 0b000, 0b000}, // 8
  {0b000, 0b111, 0b101, 0b111, 0b001, 0b111, 0b000, 0b000}  // 9
};

MatrixThreeDigitDisplay::MatrixThreeDigitDisplay() {
  // Constructor
}

void MatrixThreeDigitDisplay::begin() {
  matrix.begin();
}

void MatrixThreeDigitDisplay::_clearFrame() {
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 12; col++) {
      frame[row][col] = 0;
    }
  }
}

void MatrixThreeDigitDisplay::_displayFrame() {
  matrix.renderBitmap(frame, 8, 12);
}

void MatrixThreeDigitDisplay::_addToFrame(uint8_t digit, int pos) {
  if (digit > 9) return;
  for (int row = 0; row < 8; row++) {
    uint32_t temp = font[digit][row] << (8 - pos);
    for (int col = 0; col < 12; col++) {
      frame[row][col] |= (temp >> (11 - col)) & 1;
    }
  }
}

void MatrixThreeDigitDisplay::displayNumber(uint16_t number) {
  clearFrame();
  while (number >= 1000) {
    number -= 1000;
  }
  bool leading = false;
  uint8_t hundreds = 0;
  while (number >= 100) {
    number -= 100;
    hundreds++;
  }
  if (hundreds > 0) {
    leading = true;
    addToFrame(hundreds, 0);
  }
  uint8_t tens = 0;
  while (number >= 10) {
    number -= 10;
    tens++;
  }
  if (leading || tens > 0) {
    addToFrame(tens, 4);
  }
  addToFrame(number, 8);
  displayFrame();
}