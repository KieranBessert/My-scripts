/*
This program will blink an led on and off every second.
Created by Kieran Bessert 02/06/2020
Last edited 02/06/2020
*/

int led1 = D7;
int button = D4;

void setup() {
    pinMode(led1, OUTPUT);
    pinMode(button, INPUT_PULLDOWN);
}

void loop() { //The blink pattern should be three parts and repeat.

    if (digitalRead(button)==1){
        digitalWrite(led1, HIGH);
            delay(750);
            
        digitalWrite(led1, LOW);
            delay(200);
            
        digitalWrite(led1, HIGH);
            delay(200);
            
        digitalWrite(led1, LOW);
            delay(3000);    //With a 3 second pause between each cycle.
    }
}
