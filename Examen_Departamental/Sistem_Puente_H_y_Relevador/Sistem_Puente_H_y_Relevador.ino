const int motorPin1 = 3;
const int motorPin2 = 4;
const int relayPin = 5;
const int sensorPin = A0;

void setup() {
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(relayPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(sensorPin); 
  Serial.println(sensorValue);

  if (sensorValue < 500) {
    digitalWrite(relayPin, HIGH);
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
  } else {
    digitalWrite(relayPin, LOW);
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
  }
  delay(500);
}
