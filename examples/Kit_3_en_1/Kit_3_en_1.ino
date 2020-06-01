#include<Kit_3_en_1.h>
Kit_3_en_1 robot;
char Menu;
void setup()
{
    robot.init();
    robot.compensar_motor_izquierdo(-20);
}
void loop()
{
    robot.modo_3_en_1();
}