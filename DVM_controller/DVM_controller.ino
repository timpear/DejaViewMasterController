/* Deja View Master controller
 Created by Tim Bartlett
 
 written for Teesny 3.0:
 Serial is for wired connection
 Serial1 is for XBEE S1 connection
 */

int potPin = A0;
const int LEDA=3;
const int LEDB=4;
int c = 0;
int brtA = 0;
int brtB = 0;
int ledMax = 255; // set maximum LED brightness, 0-255

void setup() {
  pinMode (LEDA, OUTPUT);
  pinMode (LEDB, OUTPUT);
  analogWrite (LEDA, brtA);
  analogWrite (LEDB, brtB);
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop() {
 int val = map(analogRead(potPin), 3, 1005, 0, 255);
 val = constrain(val, 0, 255);
 c = c - val;
 
 int brtA = map(analogRead(potPin), 3, 1005, ledMax * (-1), ledMax); // change negative multiplier for "now" to fade faster
 brtA = constrain(brtA, 0, ledMax);
 
 int brtB = map(analogRead(potPin), 3, 1005, ledMax, 0);
 brtB = constrain(brtB, 0, ledMax);
   
 if (c != 0) {
   Serial.println(val);
   Serial1.println(val);
   analogWrite (LEDA, brtA);
   analogWrite (LEDB, brtB);
 }
 
 c = val;
 delay(5);
}
