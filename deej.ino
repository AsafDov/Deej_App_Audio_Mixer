#include <TimerOne_V2.h>

unsigned long time = 0;     
unsigned long debounce = 200UL; 

const int NUM_SLIDERS = 5;
//const int analogInputs[NUM_SLIDERS] = {A10,A0, A1, A2, A3};
const int analogInputs[NUM_SLIDERS] = {A3,A2,A1,A0,A10};
const int NUM_BUTTONS = 4;
const int NUM_LEDS = 4;
const int digitalInputs[2] = {2,3};

int buttonPin[4] = {8,6,4,2};     // the number of the pushbutton pin
int buttonLedPin[4] =  {9,7,5,3};      // the number of the LED pin
bool toggle[4] = {true,true,true,true};
int currentButtonState = 0;

int analogSliderValues[NUM_SLIDERS];

void setup() { 
  for (int i = 0; i < NUM_SLIDERS; i++) {
    pinMode(analogInputs[i], INPUT);
  }
   for (int i = 0; i < 4; i++) {
    pinMode(buttonPin[i], INPUT_PULLUP);
    pinMode(buttonLedPin[i], OUTPUT);
//    buttonState[i]=false;
  }
  
//  for (int i = 0; i < NUM_SLIDERS; i++) {
//    pinMode(digitalInputs[i], OUTPUT;)
//    digitalWrite(digitalInputs[i], LOW)
//  }
  Serial.begin(9600);
}

void loop() {
  updateSliderValues();
  checkButtons(); // check mute button pressed 
  sendSliderValues(); // Actually send data (all the time)
  
  
  //printSliderValues(); // For debug
  delay(10);
}

void updateSliderValues() {
  for (int i = 0; i < NUM_SLIDERS; i++) {
     analogSliderValues[i] = analogRead(analogInputs[i]);
  }
}

void checkButtons() {
  for (int i = 0; i < 4; i++) {
    currentButtonState = digitalRead(buttonPin[i]);
    if(!currentButtonState && millis() - time > debounce){
      toggle[i]=!toggle[i];
      time = millis();
      
    }
    if(toggle[i] && analogSliderValues[NUM_SLIDERS-1 -i]!=0){
      digitalWrite(buttonLedPin[i], HIGH);
    }
    else if(analogSliderValues[NUM_SLIDERS-1 -i]==0 | !toggle[i]){
      digitalWrite(buttonLedPin[i], LOW);
      analogSliderValues[NUM_SLIDERS-1 - i] = 0;
    }

  }
}

void sendSliderValues() {
  String builtString = String("");

  for (int i = 0; i < NUM_SLIDERS; i++) {
    builtString += String((int)analogSliderValues[i]);

    if (i < NUM_SLIDERS - 1) {
      builtString += String("|");
    }
  }
  
  Serial.println(builtString);
}

void printSliderValues() {
  for (int i = 0; i < NUM_SLIDERS; i++) {
    String printedString = String("Slider #") + String(i + 1) + String(": ") + String(analogSliderValues[i]) + String(" mV");
    Serial.write(printedString.c_str());

    if (i < NUM_SLIDERS - 1) {
      Serial.write(" | ");
    } else {
      Serial.write("\n");
    }
  }
}
