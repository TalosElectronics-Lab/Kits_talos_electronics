#include"Seguidor.hpp"
void Seguidor :: modo_seguidor(int Kp, int Ki, int Kd, int Velocidad) {
  leer_sensores();
  P = Error;
  I = I + Anteriror_I;
  D = Error - Error_Anterior;

  PID = (Kp * P) + (Ki * I) + (Kd * D);

  // Limitamos la velocidad
  if (PID > Velocidad) {
    PID = Velocidad;
  } else if (PID < -Velocidad) {
    PID = -Velocidad;
  }

  Anteriror_I = I;
  Error_Anterior = Error;

  if (PID < 0) {
    Motores_mv(Velocidad + PID, Velocidad);
  } else {
    Motores_mv(Velocidad, Velocidad - PID);
  }
  //frenos();
}

void Seguidor::init()
{
    Motores_init();
    pinMode(S1, INPUT_PULLUP);
    pinMode(S2, INPUT_PULLUP);
    pinMode(S3, INPUT_PULLUP);
    pinMode(S4, INPUT_PULLUP);
    pinMode(S5, INPUT_PULLUP);
}
void Seguidor::leer_sensores()
{
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
void Seguidor::print_sensores()
{
  for (size_t i = 0; i < 5; i++) {
    Serial.print(sensor[i]);
    Serial.print("\t");
    /* code */
  }
  Serial.println("");
}
Seguidor::Seguidor() : Robot::Robot() {}
Seguidor::~Seguidor() {}