#include <Servo.h>

#define X_SERVO_PIN 3
#define Y_SERVO_PIN 4
#define X_POT_PIN A0
#define Y_POT_PIN A1
#define X_HOME 86
#define Y_HOME 86
#define X_MIN 0
#define Y_MIN 71
#define X_MAX 180
#define Y_MAX 98

//#define DEBUG


Servo xServo;
Servo yServo;

void setup() {
  // put your setup code here, to run once:
  xServo.attach(X_SERVO_PIN);
  yServo.attach(Y_SERVO_PIN);
  xServo.write(X_HOME);
  yServo.write(Y_HOME);
  #ifdef DEBUG
  Serial.begin(9600);
  #endif
}

void loop() {
  // put your main code here, to run repeatedly:
  #ifdef DEBUG
  Serial.print("X: ");Serial.print(getXPosition());Serial.print(" Y: ");Serial.println(getYPosition());
  #endif
  xServo.write(getXPosition());
  yServo.write(getYPosition());
}

int getXPosition() {
  int input;
  input = analogRead(X_POT_PIN);
  input = map(input, 0, 1023, X_MIN, X_MAX);
  return input;
}

int getYPosition() {
  int input;
  input = analogRead(Y_POT_PIN);
  input = map(input, 0, 1023, Y_MIN, Y_MAX);
  return input;
}

