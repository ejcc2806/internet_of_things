#include <LiquidCrystal.h>

// Pines del LCD
LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);

// Pines de conexión
const int sensorTemp = A0;   // Sensor TMP36
const int led = 8;           // LED indicador
const int motor = 9;         // Motor o ventilador (puede ser un LED o transistor)

// Variable de temperatura
float temperatura = 0;

void setup() {
  lcd_1.begin(16, 2);          // Inicializa LCD (16 columnas x 2 filas)
  pinMode(led, OUTPUT);
  pinMode(motor, OUTPUT);
  lcd_1.print("Temp actual:");
  delay(2000);
}

void loop() {
  // Leer el sensor TMP36
  int lectura = analogRead(sensorTemp);
  temperatura = (lectura * 5.0 / 1024.0 - 0.5) * 100.0;

  // Mostrar temperatura en LCD
  lcd_1.clear();
  lcd_1.setCursor(0, 0);
  lcd_1.print("Temperatura:");
  lcd_1.setCursor(0, 1);
  lcd_1.print(temperatura);
  lcd_1.print(" C");

  // VALIDACIONES
  if (temperatura <= 10) {
    digitalWrite(motor, LOW);      // Motor apagado
    digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(led, LOW);
    delay(500);
  } 
  else if (temperatura >= 11 && temperatura <= 25) {
    digitalWrite(led, LOW);
    digitalWrite(motor, LOW);
    delay(1000);
  } 
  else if (temperatura >= 26) {
    digitalWrite(led, HIGH);
    digitalWrite(motor, HIGH);
    delay(1000);
  }
}
