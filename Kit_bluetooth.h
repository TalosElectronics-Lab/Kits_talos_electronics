/*
 *  Clase Seguidor que hereda todos los metodos de Robot.h
 *  kit Bluetooth 2.0
 *  Taloselectronics
 *  soporte@taloselectronics.com Rafael Lozano Rolón
*/

#include <Robot.h>
//#include <SoftwareSerial.h>
#include <SoftwareSerial.h> //Libreria para nuevo puerto serial para el bluetooth

class Kit_bluetooth : public Robot
{
private:
    /* data */
    int B_TX= 8;
    int B_RX= 9;
    SoftwareSerial Bluetooth; // RX, TX
    uint8_t Estado;

public:

    void init();
    Kit_bluetooth() : Robot::Robot(), Bluetooth(B_TX, B_RX) {}
    ~Kit_bluetooth();
};


