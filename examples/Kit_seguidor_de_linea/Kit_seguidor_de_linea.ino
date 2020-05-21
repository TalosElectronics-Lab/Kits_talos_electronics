/*
 *  kit Seguidor de linea 2.0
 *  Taloselectronics
 *  soporte@taloselectronics.com Rafael Lozano Rolón
 * 
 * ¿Como calibrar el PID?
 * 
 
 */
#include <Kit_seguidor.h>

Kit_seguidor robot_1;
void setup()
{
    robot_1.init();
    Serial.begin(9600);
}

void loop()
{
    robot_1.modo_seguidor(10,0,1,80);
    //robot_1.print_sensores();
}
