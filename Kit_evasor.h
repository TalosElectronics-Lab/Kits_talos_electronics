/*
 *  kit Evasor de obstáculos 2.0
 *  Taloselectronics
 *  soporte@taloselectronics.com Rafael Lozano Rolón
 */
#include <Robot.h>
#include <Servo.h>

//Clase evasor que hereda todos los metodos public de la clase Robot
class Kit_evasor : public Robot
{
private:
    /* data */
const uint8_t Echo = 11;
const uint8_t Trigger = 10;
const uint8_t Servo_pin = 13;
uint8_t Angulo_min = 0;
uint8_t Angulo_max = 180;
uint8_t velocidad_giro = 50;
Servo servo_1;
float distancia;

public:
    Kit_evasor(/* args */);
    ~Kit_evasor();
    void init();
    void modo_evasor(int Distancia, uint8_t velocidad);
    float obtener_distancia();
    void set_velocidad_giro(uint8_t v_giro);
};
