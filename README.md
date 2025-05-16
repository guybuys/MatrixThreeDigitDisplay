# MatrixThreeDigitDisplay Library
A library to display numbers (0-999) on the Arduino Uno R4 WiFi LED matrix in 7-segment style.

## Installation
1. Download the library as a ZIP file from the GitHub repository.
2. In the Arduino IDE, go to `Sketch > Include Library > Add .ZIP Library` and select the downloaded ZIP.
3. Ensure the `Arduino_LED_Matrix` library is installed.

## Usage
```cpp
#include <MatrixThreeDigitDisplay.h>

MatrixThreeDigitDisplay display;

void setup() {
  display.begin();
}

void loop() {
  display.displayNumber(123); // Display the number 123
  delay(1000);
}