/*
    Project name : IR Infrared Sensor
    Modified Date: 13-06-2024
    Code by : Projectslearner
    Website : https://projectslearner.com/learn/arduino-mega-ir-infrared-sensor
*/

const int irSensorPin = 2; // Pin connected to the IR sensor module
const int buzzerPin = 3; // Pin connected to the buzzer

void setup() {
  Serial.begin(9600); // Initialize serial communication for debugging
  pinMode(irSensorPin, INPUT); // Set IR sensor pin as input
  pinMode(buzzerPin, OUTPUT); // Set buzzer pin as output
}

void loop() {
  // Read the state of the IR sensor pin
  int sensorValue = digitalRead(irSensorPin);

  // Print the state to Serial Monitor
  Serial.print("IR Sensor State: ");
  Serial.println(sensorValue);

  // If an obstacle is detected (active LOW), sound the buzzer
  if (sensorValue == LOW) {
    Serial.println("Obstacle Detected");
    digitalWrite(buzzerPin, HIGH); // Turn the buzzer on
  } else {
    digitalWrite(buzzerPin, LOW); // Turn the buzzer off
  }

  delay(100); // Add a small delay to debounce the sensor
}
