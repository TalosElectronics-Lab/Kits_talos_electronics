#include <Kit_seguidor.h>
#include<math.h>
void Kit_seguidor::frenos(int velocidad)
{
  leer_sensores();
  if(sensor[4]==1)
  {
    while (sensor[3] == 0)
    {
      leer_sensores();
      Motores_mv(velocidad-20, -velocidad +20);
    }
  }
  else if(sensor[0] == 1)
  {
    while (sensor[1] == 0)
    {
      leer_sensores();
      Motores_mv(-velocidad +20, velocidad -20);
    }
  }
}
void Kit_seguidor::modo_seguidor(float Kp, float Ki, float Kd, float Velocidad)
{
  leer_sensores();
  int velocidad_recta;
  P = Error;
  I = I + Anteriror_I;
  D = Error - Error_Anterior;
  if ((P * I) < 0) I = 0; // corrige el overshooting - integral windup

  PID = (Kp * P) + (Ki * I) + (Kd * D);

  // Limitamos la velocidad
  if (PID > Velocidad) {
    PID = Velocidad;
  } else if (PID < -Velocidad) {
    PID = -Velocidad;
  }

  Anteriror_I = I;
  Error_Anterior = Error;
  velocidad_recta = 50 + (Velocidad + 20 - 50) * exp(-1 *abs(Kp * P));

  if (PID < 0) {
    Motores_mv(velocidad_recta + PID, velocidad_recta);
  } else {
    Motores_mv(velocidad_recta, velocidad_recta - PID);
  }

  frenos(Velocidad);
}

void Kit_seguidor::init() {
  Motores_init();
  pinMode(S1, INPUT_PULLUP);
  pinMode(S2, INPUT_PULLUP);
  pinMode(S3, INPUT_PULLUP);
  pinMode(S4, INPUT_PULLUP);
  pinMode(S5, INPUT_PULLUP);
}
void Kit_seguidor::leer_sensores() {
  sensor[0] = digitalRead(S1);
  sensor[1] = digitalRead(S2);
  sensor[2] = digitalRead(S3);
  sensor[3] = digitalRead(S4);
  sensor[4] = digitalRead(S5);

  // Detectar la desviacion ("Error") del seguidor de linea
  if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 0) && (sensor[4] == 0)) {
    Error = Error;
  } 
  else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 0) && (sensor[4] == 1))
    Error = 4;
  else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 1))
    Error = 3;
  else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 0))
    Error = 2;
  else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 1) && (sensor[3] == 1) && (sensor[4] == 0))
    Error = 1;
  else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 1) && (sensor[3] == 0) && (sensor[4] == 0))
    Error = 0;
  else if ((sensor[0] == 0) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 0) && (sensor[4] == 0))
    Error = -1;
  else if ((sensor[0] == 0) && (sensor[1] == 1) && (sensor[2] == 0) && (sensor[3] == 0) && (sensor[4] == 0))
    Error = -2;
  else if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 0) && (sensor[3] == 0) && (sensor[4] == 0))
    Error = -3;
  else if ((sensor[0] == 1) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 0) && (sensor[4] == 0))
    Error = -4;
  
}
void Kit_seguidor::print_sensores() {
  for (size_t i = 0; i < 5; i++) {
    Serial.print(sensor[i]);
    Serial.print("\t");
    /* code */
  }
  Serial.println("");
}
Kit_seguidor::Kit_seguidor() : Robot::Robot() {}
Kit_seguidor::~Kit_seguidor() {}