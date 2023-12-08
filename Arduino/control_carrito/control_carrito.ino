int matrizDireccion[5][4] = {
  { 1, 0, 1, 0 },
  { 0, 1, 0, 1 },
  { 1, 0, 0, 1 },
  { 0, 1, 1, 0 },
  { 0, 0, 0, 0 }
};

int matrizVelocidad[5][2] = {
  { 125, 125 },
  { 125, 125 },
  { 125, 125 },
  { 125, 125 },
  { 0, 0 }
};

int inputs[4] = { 2, 3, 7, 8 };  // in1, in2, in3, in4 --pines digitales
int enables[2] = { 5, 6 };         // pines PWM...
int i;

void SetDireccion(int estado) {
  for (i = 0; i < 4; i++) {
    digitalWrite(inputs[i], matrizDireccion[estado][i]);
  }
  for (i = 0; i < 2; i++) {
    analogWrite(enables[i], matrizVelocidad[estado][i]);
  }
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.setTimeout(100);

  for (int i = 0; i < 4; i++) {
    pinMode(inputs[i], OUTPUT);
  }
  for (int i = 0; i < 2; i++) {
    pinMode(enables[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

  // digitalWrite(inputs[0], matrizDireccion[0][0]);
  // digitalWrite(inputs[1], matrizDireccion[0][1]);
  // digitalWrite(inputs[2], matrizDireccion[0][2]);
  // digitalWrite(inputs[3], matrizDireccion[0][3]);
  // analogWrite(enables[0], matrizVelocidad[0][0]);
  // analogWrite(enables[1], matrizVelocidad[0][1]);


  if (Serial.available()) {
    String cadena = Serial.readStringUntil('\n');

    // Serial.println(cadena);

    int estado = cadena.toInt();

    SetDireccion(estado);
  }
}
