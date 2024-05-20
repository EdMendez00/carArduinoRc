#include <SoftwareSerial.h>

#define FORWARD 'F'
#define BACKWARD 'B'
#define LEFT 'L'
#define RIGHT 'R'
#define START 'A'
#define PAUSE 'P'

// CONEXIONES PARA EL BLUETOOTH.
int bluetoothTx = 1; // Cambiar estos pines si es necesario
int bluetoothRx = 0; // Cambiar estos pines si es necesario
SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

// MOTOR 1.
const int pinENA = 10;
const int Motor1A = 9;
const int Motor1B = 8;

// MOTOR 2.
const int pinENB = 5;
int Motor2A = 7;
int Motor2B = 6;

void setup() {
  bluetooth.begin(9600);
  delay(100);
  bluetooth.println("U,9600,N");

  pinMode(pinENA, OUTPUT);
  pinMode(Motor1A, OUTPUT);
  pinMode(Motor1B, OUTPUT);
  pinMode(pinENB, OUTPUT);
  pinMode(Motor2A, OUTPUT);
  pinMode(Motor2B, OUTPUT);

  digitalWrite(Motor1A, LOW);
  digitalWrite(Motor1B, LOW);
  digitalWrite(Motor2A, LOW);
  digitalWrite(Motor2B, LOW);
}

void loop() {
  if (bluetooth.available()) {
    char toSend = bluetooth.read();
    carRC(toSend);
  }
}

void carRC(char command) {
  switch (command) {
    case FORWARD:
      // ESTOS HARAN QUE VAYA PARA ADELANTE EL CARRITO.
      digitalWrite(Motor1A, HIGH);
      digitalWrite(Motor1B, LOW);
      analogWrite(pinENA, 255);
      digitalWrite(Motor2A, HIGH);
      digitalWrite(Motor2B, LOW);
      analogWrite(pinENB, 255);
      break;

    case BACKWARD:
      digitalWrite(Motor1A, LOW);
      digitalWrite(Motor1B, HIGH);
      analogWrite(pinENA, 255);
      digitalWrite(Motor2A, LOW);
      digitalWrite(Motor2B, HIGH);
      analogWrite(pinENB, 255);
      break;

    case LEFT:
      digitalWrite(Motor1A, LOW);
      digitalWrite(Motor1B, HIGH);
      analogWrite(pinENA, 255);
      digitalWrite(Motor2A, HIGH);
      digitalWrite(Motor2B, LOW);
      analogWrite(pinENB, 255);
      break;

    case RIGHT:
      digitalWrite(Motor1A, HIGH);
      digitalWrite(Motor1B, LOW);
      analogWrite(pinENA, 255);
      digitalWrite(Motor2A, LOW);
      digitalWrite(Motor2B, HIGH);
      analogWrite(pinENB, 255);
      break;

    case START:
      // START no hace nada en este caso.
      break;

    case PAUSE:
      digitalWrite(Motor1A, LOW);
      digitalWrite(Motor1B, LOW);
      analogWrite(pinENA, 0);

      digitalWrite(Motor2A, LOW);
      digitalWrite(Motor2B, LOW);
      analogWrite(pinENB, 0);
      break;
  }
}

