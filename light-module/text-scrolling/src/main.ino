#include <MD_Parola.h>
#include <MD_MAX72xx.h>

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define CS_PIN 10
#define SEGMENTS 1

MD_Parola display = MD_Parola(HARDWARE_TYPE, CS_PIN, SEGMENTS);

void setup() {
    display.begin();
    display.displayClear();
    display.displayScroll("Capyboard", PA_CENTER, PA_SCROLL_LEFT, 100);
}

void loop() {
    if (display.displayAnimate()) {
        display.displayReset();
    }
}
