#include <Arduino.h>
#include <RF24-STM.h>
#include <nRF24L01-STM.h>

RF24 radio (PB0, PA4);
const uint64_t address = 0xF0F0F0F0E1LL;

void setup() {
  Serial.begin (115200);
  while(!Serial);
  delay(1000);
  Serial.println ("----------init----------");
  pinMode (LED_BUILTIN, OUTPUT);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MAX);
  radio.startListening();
  radio.printDetails();
}

void loop() {
  digitalWrite (LED_BUILTIN, HIGH);
  Serial.println("HIGH");
  delay (1000);
  digitalWrite (LED_BUILTIN, LOW);
  Serial.println("LOW");
  delay (1000);
}