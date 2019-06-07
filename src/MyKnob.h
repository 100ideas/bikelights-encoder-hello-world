#include <Encoder.h>

#ifndef MyKnob_H
#define MyKnob_H

Encoder knob2(2, 3);

class MyKnob
{
public:
    Encoder knob;
    MyKnob(int a, int b) {
        pinA = a;
        pinB = b;
        // Encoder knob(pinA, pinB);
        // Encoder knob(2, 3);
    }

private:
    int pinA;
    int pinB;
    int position;
    void checkRotary()
    {
        long newPos = knob.read();
        if (newPos != position)
        {
            position = newPos;
            /* Serial.println(newPos); */
        }
    }
};
#endif
