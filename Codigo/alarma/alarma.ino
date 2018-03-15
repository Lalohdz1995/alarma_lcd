// ARDUINO-BASED SECURITY ALARM //
// T.K.Hareendran //
#include  <LiquidCrystal.h>

int sensPin = 2; // Sensor Input Pin
int ledPin = 13; // LED output Pin
int pzSpeaker = 5; //Piezo-speaker Output Pin
int val = 0; // variable for reading the Input Pin status
LiquidCrystal lcd (7, 8, 9, 10, 11, 12);
void setup() {
   pinMode(sensPin, INPUT); // Set Sensor as input
   pinMode(pzSpeaker, OUTPUT); // Set Piezo-Speaker as output
   pinMode(ledPin, OUTPUT); // Set LED as output
   lcd.begin(16, 2); 
   lcd.print("ALARMA ACTIVADA");
   lcd.noDisplay();
  
}
void loop(){


  
   val = digitalRead(sensPin); // read input value
   if (val == HIGH) { // check if the input is HIGH
      digitalWrite(ledPin, HIGH); // turn LED ON
      lcd.setCursor(0, 1);
      lcd.print(" PUERTA ABIERTA");
      playTone(500, 600);
      delay(100);
      playTone(500, 800);
      delay(100);
      lcd.display();
   } else {
      digitalWrite(ledPin, LOW); // turn LED OFF
      playTone(0, 0);
      delay(300);
      lcd.noDisplay();
   }

}
// duration in mSecs, frequency in hertz
void playTone(long duration, int freq) {
   duration *= 1000;
   int period = (1.0 / freq) * 1000000;
   long elapsed_time = 0;
   while (elapsed_time < duration) {
      digitalWrite(pzSpeaker,HIGH);
      delayMicroseconds(period / 2);
      digitalWrite(pzSpeaker, LOW);
      delayMicroseconds(period / 2);
      elapsed_time += (period);
   }
}
