/*
 *  kit Evasor de obstáculos 2.0
 *  Taloselectronics
 *  soporte@taloselectronics.com Rafael Lozano Rolón
 * 
 * Archivos Kit_evasor.h & Kit_evasor.cpp
 * --Funciones basicas 
 *  -init()
 *      Inicializa todos los pines necesarios
 *  -modo evasor(Distancia,Velocidad)
 *      -Distancia: distancia mínima para poder evadir obstáculos
 *      -Velocidad: Rango 0-255 
*/
#include<Kit_evasor.h>

Kit_evasor Robot_1;//Se instancía un objeto Kit_evasor con el nombre de Robot_1

void setup()
{
    Robot_1.init();//Inicializa todos los pines necesarios
    Serial.begin(9600);
    Robot_1.compensar_motor_derecho(10);//Si el robot no avanza derecho compensar el motor que le haga falta
}
void loop()
{
    Robot_1.modo_evasor(10,55);//Pone el robot en modo evasor
    //a los 10cm evade el obstaculo avanza con una velocidad de 55 [0-255]
    Serial.println(Robot_1.obtener_distancia());
}