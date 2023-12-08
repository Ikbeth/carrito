int matrizDireccion[4][4] = {
  { 1, 0, 1, 0 },
  { 0, 1, 1, 0 },  // IQUIERDA
  { 1, 0, 0, 1 },  // DERECHA
  { 0, 0, 0, 0 }
};

int matrizVelocidad[4][2] = {
  { 125, 125 },
  { 125, 125 },
  { 125, 125 },
  { 0, 0 }
};

int inputs[4] = { 2, 3, 7, 8 };  // in1, in2, in3, in4 --pines digitales
int enables[2] = { 5, 6 };       // pines PWM...

void SetDireccion(int estado) {
  for (int i = 0; i < 4; i++) {
    digitalWrite(inputs[i], matrizDireccion[estado][i]);
  }
  for (int i = 0; i < 2; i++) {
    analogWrite(enables[i], matrizVelocidad[estado][i]);
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  for (int i = 0; i < 4; i++) {
    pinMode(inputs[i], OUTPUT);
  }
  for (int i = 0; i < 2; i++) {
    pinMode(enables[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  SetDireccion(1);
  delay(5000);
  SetDireccion(3);
}
