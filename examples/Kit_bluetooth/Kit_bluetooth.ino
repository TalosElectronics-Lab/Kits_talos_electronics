/*
 *  kit bluetooth 2.0
 *  Taloselectronics
 *  soporte@taloselectronics.com Rafael Lozano Rolón
 * Asegurarse que el kit avance en linea recta con robot_1.Mv_motores(50,50);
 * calibrar el motor si es necesario de 10 en 10
 * ejemplo:
 * robot_1.compensar_motor_derecho(10);
 * ver vomo se comporta y si es necesario ajustar el los valores en compensar el otro motor.
 */
#include<Kit_bluetooth.h>
Kit_bluetooth Robot;
void setup()
{
    Robot.init();
}
void loop()
{
    Robot.modo_bluetooth();
    
}