//Lab. 1
int ledRojo = 12;      
int ledAmarillo = 8;   
int ledVerde = 4;
int boton = 2;

int contador = 0;               
bool intermitenciaActiva = false; 

void setup() {
  pinMode(ledRojo, OUTPUT);      
  pinMode(ledAmarillo, OUTPUT);  
  pinMode(ledVerde, OUTPUT);     
  pinMode(boton, INPUT_PULLUP);  

  Serial.begin(9600);   
  mostrarMenu();        
}

void loop() {
  // leer consola
  if (Serial.available() > 0) {
    char opcion = Serial.read();

    if (opcion == '1') { apagarTodos(); digitalWrite(ledRojo, HIGH); intermitenciaActiva = false; }
    if (opcion == '2') { digitalWrite(ledRojo, LOW); intermitenciaActiva = false; }
    if (opcion == '3') { apagarTodos(); digitalWrite(ledAmarillo, HIGH); intermitenciaActiva = false; }
    if (opcion == '4') { digitalWrite(ledAmarillo, LOW); intermitenciaActiva = false; }
    if (opcion == '5') { apagarTodos(); digitalWrite(ledVerde, HIGH); intermitenciaActiva = false; }
    if (opcion == '6') { digitalWrite(ledVerde, LOW); intermitenciaActiva = false; }
    if (opcion == '7') { encenderTodos(); intermitenciaActiva = false; }
    if (opcion == '8') { apagarTodos(); intermitenciaActiva = false; }
    if (opcion == '9') { intermitenciaActiva = true; }  
  }

  // leer boton
  if (digitalRead(boton) == LOW) {
    delay(200); 
    contador++;
    if (contador > 6) contador = 1;

    if (contador == 1) { apagarTodos(); digitalWrite(ledRojo, HIGH); intermitenciaActiva = false; }
    if (contador == 2) { apagarTodos(); digitalWrite(ledVerde, HIGH); intermitenciaActiva = false; }
    if (contador == 3) { apagarTodos(); digitalWrite(ledAmarillo, HIGH); intermitenciaActiva = false; }
    if (contador == 4) { apagarTodos(); intermitenciaActiva = false; }
    if (contador == 5) { encenderTodos(); intermitenciaActiva = false; }
    if (contador == 6) { intermitenciaActiva = true; } 
  }

  // parpadeo
  if (intermitenciaActiva) {
    encenderTodos();
    delay(300);
    apagarTodos();
    delay(300);
  }
}

// menu en consola
void mostrarMenu() {
  Serial.println("Menu:");
  Serial.println("[1] Rojo ON");
  Serial.println("[2] Rojo OFF");
  Serial.println("[3] Amarillo ON");
  Serial.println("[4] Amarillo OFF");
  Serial.println("[5] Verde ON");
  Serial.println("[6] Verde OFF");
  Serial.println("[7] Todos ON");
  Serial.println("[8] Todos OFF");
  Serial.println("[9] Intermitencia");
}

// encender leds
void encenderTodos() {
  digitalWrite(ledRojo, HIGH);
  digitalWrite(ledAmarillo, HIGH);
  digitalWrite(ledVerde, HIGH);
}

// apagar leds
void apagarTodos() {
  digitalWrite(ledRojo, LOW);
  digitalWrite(ledAmarillo, LOW);
  digitalWrite(ledVerde, LOW);
}

