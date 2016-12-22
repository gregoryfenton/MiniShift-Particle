#include <MiniShift-Particle/glcdfont.h>
#include <MiniShift-Particle/MiniShift-Particle.h>

Minishift ms(3, 2, 4); // data_pin, clock_pin, latch_pin

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  Serial.begin(57600);
}

void loop() {
  char buf[64];
  
  while(1) {
    int len = Serial.readBytesUntil('\n', buf, 63);
    buf[len] = '\0';
    ms.writeString(buf);
  }
}
