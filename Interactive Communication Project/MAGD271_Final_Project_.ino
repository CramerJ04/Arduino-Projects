#include <Adafruit_CircuitPlayground.h>
#include <Adafruit_Circuit_Playground.h>
const int BUTTON_PIN1 = 2;  // the number of the pushbutton pin - A5
const int LED_PIN1 =  3;   // the number of the LED pin - A4
const int BUTTON_PIN2 = 0; // A6
const int LED_PIN2 = 1; // A7
const int BUTTON_PIN3 = 10; // A3
const int LED_PIN3 = 9; // A2
int xValue = 0;
int yValue = 0;
int temp = 0;
bool value = false; 
bool leftButtonPressed;
bool rightButtonPressed;
int buttonState = 0;   // variable for reading the pushbutton status

void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
  // initialize the LED pin as an output:
  pinMode(LED_PIN1, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
  pinMode(LED_PIN3, OUTPUT);
  // initialize the pushbutton pin as an pull-up input:
  // the pull-up input pin will be HIGH when the switch is open and LOW when the switch is closed.
  pinMode(BUTTON_PIN1, INPUT_PULLUP);
  pinMode(BUTTON_PIN2, INPUT_PULLUP);
  pinMode(BUTTON_PIN3, INPUT_PULLUP);
}

void loop() {
  leftButtonPressed = CircuitPlayground.leftButton(); // left button
  rightButtonPressed = CircuitPlayground.rightButton(); // right button
  int buttonState1 = digitalRead(BUTTON_PIN1);
  int buttonState2 = digitalRead(BUTTON_PIN2);
  int buttonState3 = digitalRead(BUTTON_PIN3);

  // control LED according to the state of button
  // This method for reseting can be implemented if the circuit playground is outside of the box 
  /*if(leftButtonPressed || rightButtonPressed){
    Serial.println("Values Reset! ");
    xValue = 0;
    yValue = 0;
  }*/
  if(buttonState1 == LOW){         // If button is pressing
    digitalWrite(LED_PIN1, HIGH);
    //Serial.print("1");
    xValue++;
    Serial.print("X position: ");
    Serial.println(xValue);
    CircuitPlayground.playTone(247, 100); // B in 3rd octave 
    // If the user doesn't want to have sound or colors flash when a button is pressed, these elements can be upated accordingly 
  CircuitPlayground.setPixelColor(0, 0,   255,   0); // board turns green 
  CircuitPlayground.setPixelColor(1, 0,   255,   0);
  CircuitPlayground.setPixelColor(2, 0,   255,   0);
  CircuitPlayground.setPixelColor(3, 0,   255,   0);
  CircuitPlayground.setPixelColor(4, 0,   255,   0);
  CircuitPlayground.setPixelColor(5, 0,   255,   0);
  CircuitPlayground.setPixelColor(6, 0,   255,   0);
  CircuitPlayground.setPixelColor(7, 0,   255,   0);
  CircuitPlayground.setPixelColor(8, 0,   255,   0);
  CircuitPlayground.setPixelColor(9, 0,   255,   0);
    } // turn on LED
  else  {                         // otherwise, button is not pressing
    digitalWrite(LED_PIN1, LOW);  // turn off LED
  CircuitPlayground.setPixelColor(0, 0,   0,   0);
  CircuitPlayground.setPixelColor(1, 0,   0,   0);
  CircuitPlayground.setPixelColor(2, 0,   0,   0);
  CircuitPlayground.setPixelColor(3, 0,   0,   0);
  CircuitPlayground.setPixelColor(4, 0,   0,   0);
  CircuitPlayground.setPixelColor(5, 0,   0,   0);
  CircuitPlayground.setPixelColor(6, 0,   0,   0);
  CircuitPlayground.setPixelColor(7, 0,   0,   0);
  CircuitPlayground.setPixelColor(8, 0,   0,   0);
  CircuitPlayground.setPixelColor(9, 0,   0,   0);
  }
  if (buttonState2 == LOW) {
    digitalWrite(LED_PIN2, HIGH);
    yValue++;
    Serial.print("Y position: ");
    Serial.println(yValue);
    CircuitPlayground.playTone(349, 100); // F in 4th octave 
  CircuitPlayground.setPixelColor(0, 0,   255,   0);
  CircuitPlayground.setPixelColor(1, 0,   255,   0);
  CircuitPlayground.setPixelColor(2, 0,   255,   0);
  CircuitPlayground.setPixelColor(3, 0,   255,   0);
  CircuitPlayground.setPixelColor(4, 0,   255,   0);
  CircuitPlayground.setPixelColor(5, 0,   255,   0);
  CircuitPlayground.setPixelColor(6, 0,   255,   0);
  CircuitPlayground.setPixelColor(7, 0,   255,   0);
  CircuitPlayground.setPixelColor(8, 0,   255,   0);
  CircuitPlayground.setPixelColor(9, 0,   255,   0);
  }
  else {
    digitalWrite(LED_PIN2, LOW);
  CircuitPlayground.setPixelColor(0, 0,   0,   0);
  CircuitPlayground.setPixelColor(1, 0,   0,   0);
  CircuitPlayground.setPixelColor(2, 0,   0,   0);
  CircuitPlayground.setPixelColor(3, 0,   0,   0);
  CircuitPlayground.setPixelColor(4, 0,   0,   0);
  CircuitPlayground.setPixelColor(5, 0,   0,   0);
  CircuitPlayground.setPixelColor(6, 0,   0,   0);
  CircuitPlayground.setPixelColor(7, 0,   0,   0);
  CircuitPlayground.setPixelColor(8, 0,   0,   0);
  CircuitPlayground.setPixelColor(9, 0,   0,   0);
  }
  if (buttonState3 == LOW) {
    Serial.print("Position Selected And Clicked: ");
    Serial.print(xValue);
    Serial.print(", ");
    Serial.println(yValue);
    Serial.println("Press The XValue/YValue Buttons At The Same Time To Reset Values...");
    digitalWrite(LED_PIN3, HIGH);
    CircuitPlayground.playTone(494, 100); // B in 4th octave 
  CircuitPlayground.setPixelColor(0, 0,   255,   0);
  CircuitPlayground.setPixelColor(1, 0,   255,   0);
  CircuitPlayground.setPixelColor(2, 0,   255,   0);
  CircuitPlayground.setPixelColor(3, 0,   255,   0);
  CircuitPlayground.setPixelColor(4, 0,   255,   0);
  CircuitPlayground.setPixelColor(5, 0,   255,   0);
  CircuitPlayground.setPixelColor(6, 0,   255,   0);
  CircuitPlayground.setPixelColor(7, 0,   255,   0);
  CircuitPlayground.setPixelColor(8, 0,   255,   0);
  CircuitPlayground.setPixelColor(9, 0,   255,   0);
  }
  else {
    digitalWrite(LED_PIN3, LOW);
  CircuitPlayground.setPixelColor(0, 0,   0,   0);
  CircuitPlayground.setPixelColor(1, 0,   0,   0);
  CircuitPlayground.setPixelColor(2, 0,   0,   0);
  CircuitPlayground.setPixelColor(3, 0,   0,   0);
  CircuitPlayground.setPixelColor(4, 0,   0,   0);
  CircuitPlayground.setPixelColor(5, 0,   0,   0);
  CircuitPlayground.setPixelColor(6, 0,   0,   0);
  CircuitPlayground.setPixelColor(7, 0,   0,   0);
  CircuitPlayground.setPixelColor(8, 0,   0,   0);
  CircuitPlayground.setPixelColor(9, 0,   0,   0);
  }
  if (buttonState2 == LOW && buttonState1 == LOW){
    Serial.println("Values Reset! ");
    xValue = 0;
    yValue = 0;    
  }
}
