const int ledPin = 9; // Pin del LED
const int ldrPin = A0; // Pin de la fotorresistencia

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int ldrValue = analogRead(ldrPin); // Leer el valor de la LDR
  Serial.println(ldrValue);

  if (ldrValue < 500) {
    digitalWrite(ledPin, HIGH); // Encender el LED
  } else {
    digitalWrite(ledPin, LOW); // Apagar el LED
  }

  delay(500);
}
