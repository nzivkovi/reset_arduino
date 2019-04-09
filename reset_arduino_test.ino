#include <avr/wdt.h>

int i = 5;

void softwareReset( uint8_t prescaller) {
  // start watchdog with the provided prescaller
  wdt_enable(prescaller);
  // wait for the prescaller time to expire
  // without sending the reset signal by using
  // the wdt_reset() method
  while(1) {}
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("pocinje");
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int j=0;j<20;j++)
  {
    Serial.println(i+j);
  }
  softwareReset(WDTO_60MS);
  Serial.println("nece se ispisati");
}
