/*
This program will 
Created by Kieran Bessert 02/10/2020
Last edited 02/13/2020
*/
const int BUTTON=D4;
const int BUZZER=D2;
const int melody1[]={1900,2550,2550,1900,1900,2550,2550,1900};    // notes in the tune 1
const int melody2[]={550,900,900,550,550,900,900,550};            // notes in the tune 2
const int noteDurations1[]={4,8,8,4,4,8,8,4};                      // note Length
const int noteDurations2[]={8,4,4,8,8,4,4,8};                      // note Length
int count(0);

void setup() {
    pinMode(BUTTON, INPUT);
    pinMode(BUZZER, OUTPUT);
}
void loop() {
    
    if (digitalRead(BUTTON)==1) {
        if (count==0){
            tune_Function1();
            count = count + 1;
            }
        else{
            tune_Function2();
            count = count - 1;
            }
    }
} 
void tune_Function1() {
    for (int thisNote = 0; thisNote < 8; thisNote++) {          // ergodic all notes
            int noteDuration = 1000/noteDurations1[thisNote];    // calculate the note duration
            tone(BUZZER, melody1[thisNote], noteDuration);       // let speaker sonds
            int pauseBetweenNotes = noteDuration * 1.30;        // set a minimum time between notes
            delay(pauseBetweenNotes);                           // delay for the while
            noTone(BUZZER);                                     // stop the tone playing:
            }
}
void tune_Function2() {
     for (int thisNote = 0; thisNote < 8; thisNote++) {         // ergodic all notes
            int noteDuration = 1000/noteDurations2[thisNote];    // calculate the note duration
            tone(BUZZER, melody2[thisNote], noteDuration);       // let speaker sonds
            int pauseBetweenNotes = noteDuration * 1.30;        // set a minimum time between notes
            delay(pauseBetweenNotes);                           // delay for the while
            noTone(BUZZER);                                     // stop the tone playing:
            }
}
