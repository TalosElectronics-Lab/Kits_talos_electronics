/*
 *  Clase Seguidor que hereda todos los metodos de Robot.h
 *  kit Bluetooth 2.0
 *  Taloselectronics
 *  soporte@taloselectronics.com Rafael Lozano Rolón
*/

#include <Robot.h>
#include <SoftwareSerial.h> //Libreria para nuevo puerto serial para el bluetooth

class Kit_bluetooth : public Robot
{
private:
    /* data */
    const uint8_t B_TX= 8;
    const uint8_t B_RX= 9;
    const uint8_t Buzzer = A4;
    SoftwareSerial Bluetooth; // RX, TX
    char Estado;

public:

    void init();
    uint8_t Leer_BT();
    void modo_bluetooth();
    Kit_bluetooth() : Robot::Robot(), Bluetooth(B_TX, B_RX) {}
    ~Kit_bluetooth();
};


