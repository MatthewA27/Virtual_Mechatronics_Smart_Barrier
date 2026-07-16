#include <Servo.h>

const int pingPin = 7;
const int servoPin = 2;

Servo myServo; 

void setup()
{
  Serial.begin(9600);
  myServo.attach(servoPin); // Uses the variable now!
}

void loop()
{
  long duration, cm;
  
  // Trigger the PING))) sensor with a clean HIGH pulse
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);
  
  // Read the echo pulse return time
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);
  
  // Convert time to distance
  cm = microsecondsToCentimeters(duration);
  Serial.println(cm);
  
  // Servo control logic
  if ((cm > 100) && (cm < 250)) {
    myServo.writeMicroseconds(1500);;
  }
  else {
    myServo.writeMicroseconds(544);
  }

  delay(100);
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}