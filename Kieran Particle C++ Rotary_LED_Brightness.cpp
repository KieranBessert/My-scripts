/*
This program will turn on an LED using a rotary sensor to control voltage/brightness
Created by Kieran Bessert 02/25/2020
Last edited 02/25/2020
*/

#define POT1 A0
#define LED1 D7
int AV = 0;

void setup() {
    pinMode(LED1, OUTPUT);
    pinMode(POT1, INPUT);
}

void loop() {
    AV = analogRead(POT1);
    analogWrite(LED1, map(AV, 0, 4095, 0, 255));
}
