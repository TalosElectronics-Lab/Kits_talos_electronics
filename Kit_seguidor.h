/*
 *  Clase Seguidor que hereda todos los metodos de Robot.h
 *  kit Bluetooth 2.0
 *  Taloselectronics
 *  soporte@taloselectronics.com Rafael Lozano Rolón
 * 
 * 
*/

#include <Robot.h>

class Kit_seguidor : public Robot
{
private:
    /* data */
  const uint8_t S1 = A0;
  const uint8_t S2 = A1;
  const uint8_t S3 = A2;
  const uint8_t S4 = A3;
  const uint8_t S5 = 12;

  bool sensor[5];
  float Error = 0, P = 0, I = 0, D = 0, PID = 0;
  float Error_Anterior = 0, Anteriror_I = 0;
  bool Frenos;

public:
    Kit_seguidor(/* args */);
    ~Kit_seguidor();
    void init();
    void leer_sensores();
    void print_sensores();
    void modo_seguidor(float Kp, float Ki, float Kd, float Velocidad);
    void frenos(int velocidad);
    
};


