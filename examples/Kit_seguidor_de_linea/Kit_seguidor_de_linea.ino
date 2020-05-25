/*
 *  kit Seguidor de linea 2.0
 *  Taloselectronics
 *  soporte@taloselectronics.com Rafael Lozano Rolón
 * Asegurarse que el kit avance en linea recta con robot_1.Mv_motores(50,50);
 * calibrar el motor si es necesario de 10 en 10
 * ejemplo:
 * robot_1.compensar_motor_derecho(10);
 * ver vomo se comporta y si es necesario ajustar el los valores en compensar el otro motor.
 * ¿Como calibrar el PID?
 * 
 */
#include <Kit_seguidor.h>

Kit_seguidor robot_1;
void setup()
{
    robot_1.init();
    Serial.begin(9600);
    robot_1.compensar_motor_derecho(10);
    
    
}

void loop()
{
    robot_1.modo_seguidor(10,1,5,80);
    //robot_1.print_sensores();
}
