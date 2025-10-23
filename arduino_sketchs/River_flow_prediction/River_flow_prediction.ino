// C++ code
// Proyecto: River Flow Prediction
// Autor: Edwin Cortés Cerón
// Descripción: Sistema de detección de nivel de agua utilizando el sensor ultrasónico HC-SR04
// y tres LEDs que representan diferentes niveles de alerta (verde, amarillo y rojo).

int DISTANCIA = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop()
{
  DISTANCIA = 0.01723 * readUltrasonicDistance(10, 9);
  if (DISTANCIA < 90) {
    digitalWrite(3, HIGH);
  } else {
    digitalWrite(3, LOW);
  }
  if (DISTANCIA < 60) {
    digitalWrite(4, HIGH);
  } else {
    digitalWrite(4, LOW);
  }
  if (DISTANCIA < 30) {
    digitalWrite(5, HIGH);
  } else {
    digitalWrite(5, LOW);
  }
  delay(10);
}

