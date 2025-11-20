#include <MD_MAX72xx.h>

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define CS_PIN 10
#define SEGMENTS 1

MD_MAX72XX display = MD_MAX72XX(HARDWARE_TYPE, CS_PIN, SEGMENTS);

void spiral(bool state, uint16_t speed = 50) {
    int xStart = 0, yStart = 0;
    int xEnd = 7, yEnd = 7;

    while (xStart <= xEnd && yStart <= yEnd) {
        // Top row left to right
        for (int col = xStart; col <= xEnd; col++) {
            display.setPoint(col, yStart, state);
            delay(speed);
        }
        yStart++;

        // Right column top to bottom
        for (int row = yStart; row <= yEnd; row++) {
            display.setPoint(xEnd, row, state);
            delay(speed);
        }
        xEnd--;

        // Bottom row right to left
        if (yStart <= yEnd) {
            for (int col = xEnd; col >= xStart; col--) {
                display.setPoint(col, yEnd, state);
                delay(speed);
            }
            yEnd--;
        }

        // Left column bottom to top
        if (xStart <= xEnd) {
            for (int row = yEnd; row >= yStart; row--) {
                display.setPoint(xStart, row, state);
                delay(speed);
            }
            xStart++;
        }
    }
}

void displaySpiral() {
    spiral(true);   // draw spiral
    delay(500);
    spiral(false);  // clear spiral in reverse
}

void setup() {
    display.begin();
    display.clear();
}

void loop() {
    displaySpiral();
}

