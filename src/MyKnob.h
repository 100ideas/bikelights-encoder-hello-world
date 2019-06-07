// #include <Encoder.h>

// Encoder knob2(2, 3);

class FakeEncoder {
public:
    int neverUsedInt;

    FakeEncoder() {
      neverUsedInt = 42;
    }
    
  int read() {
    _mockKnobPosition = 8;
    return _mockKnobPosition;
  }

private:
  int _mockKnobPosition;
};

#ifndef MyKnob_H
#define MyKnob_H
class MyKnob {
public:
    // Encoder knob;
    FakeEncoder knob;
    MyKnob(int a, int b) {
        pinA = a;
        pinB = b;
        // Encoder knob(pinA, pinB);
        // Encoder knob(2, 3);
        knob = FakeEncoder();
    }

private:
    int pinA;
    int pinB;
    int position;
    void checkRotary() {
        long newPos = knob.read();
        if (newPos != position)
        {
            position = newPos;
            /* Serial.println(newPos); */
        }
    }
};
#endif
