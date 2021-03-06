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
 * -Partir de la velocidad deseada
 * -Dejar KI y KD = 0 y ajustar KP para que no se salga de la linea. 
 * -Si el robot oscila de un lado a otro se recomienda disminuir KP. 
 * -Con KI = 0 aumentar KD para hacer que reaccione mas rapido a cambios de direccion
 * -Una vez que el robot es estable en la línea siguiente, asigne un valor de 0,5 a 1,0 a Ki 
 */
#include <Kit_seguidor.h>

Kit_seguidor robot_1;
void setup()
{
  robot_1.init();
  Serial.begin(9600);
  robot_1.compensar_motor_izquierdo(-10);//Compensar motor izquierdo porque avanza mucho mas rapido
  robot_1.compensar_motor_derecho(20);//Compensar motor derecho porque avanza lento
  
  //robot_1.Motores_mv(100, 100);
  //delay(5000);
  
}

void loop()
{
  robot_1.modo_seguidor(10,.2,10,65);//KP KI KD Velocidad
  //robot_1.print_sensores(); //muestra estado de los sensores
}
