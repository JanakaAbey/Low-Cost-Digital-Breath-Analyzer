#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET 4 // Define the OLED screen
int TIME_UNTIL_WARMUP = 1; // Time for the warm-up delay in minutes
unsigned long time;
float analogPin = 0; // Set analog pin as A0
float actual_val = 0; // Set a value to read from the analog pin
float val = 0;
Adafruit_SSD1306 display(OLED_RESET);
void setup() { // Set up the OLED screen
display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
display.clearDisplay();
}
void loop() { // Take the reading and show it onscreen
delay(100);
val = readAlcohol();
printTitle();
printWarming();
time = millis() / 1000;
time /= 60;
if (time <= TIME_UNTIL_WARMUP) { // If warm-up is less than 4 mins
time = map(time, 0, TIME_UNTIL_WARMUP, 0, 100); // Show countdown
display.drawRect(10, 50, 110, 10, WHITE); // Empty bar
display.fillRect(10, 50, time, 10, WHITE);
} else { // When warm-up time has passed
// the value and message are printed on the screen
printTitle();
printAlcohol(val);
printAlcoholLevel(val);
}
display.display();
}
void printTitle() { // Position and text of title on the screen
display.clearDisplay();
display.setTextSize(1);
display.setTextColor(WHITE);
display.setCursor(22, 0);
display.println("Breath Analyzer");
}
void printWarming() { // Warm-up message
display.setTextSize(1);
display.setTextColor(WHITE);
display.setCursor(30, 24);
display.println("Warming up");
}
void printAlcohol(float value) { // Print alcohol value to screen
display.setTextSize(2);
display.setTextColor(WHITE);
display.setCursor(20, 10);
display.println(actual_val);
display.setTextSize(2);
display.setTextColor(WHITE);
display.setCursor(80, 10);
display.println("g/dl");
}

void printAlcoholLevel(float value) { // Print message to screen
display.setTextSize(1);
display.setTextColor(WHITE);
display.setCursor(20, 25);
if (value < 0.06) { // If value read is less than 0., you are sober
display.println("You are sober..");
}
if (value >= 0.06) {
display.println("person has drunk!!!");
}
}
// Finds average by summing three readings and
// dividing by 3 for better accuracy
float readAlcohol() {
float val = 0;
float actual_val = 0;
float val1;
float val2;
float val3;
float val4;
float val5;
float val6;
float val7;
float val8;
float val9;
float val10;

display.clearDisplay();
val1 = analogRead(analogPin);
delay(50);
val2 = analogRead(analogPin);
delay(50);
val3 = analogRead(analogPin);
delay(50);
val4 = analogRead(analogPin);
delay(50);
val5 = analogRead(analogPin);
delay(50);
val6 = analogRead(analogPin);
delay(50);
val7 = analogRead(analogPin);
delay(50);
val8 = analogRead(analogPin);
delay(50);
val9 = analogRead(analogPin);
delay(50);
val10 = analogRead(analogPin);
val = ((val1 + val2 + val3 + val4 + val5 + val6 + val7 + val8 + val9 + val10) / 10);
actual_val = (0.001/1024)*val;
return val;
}
