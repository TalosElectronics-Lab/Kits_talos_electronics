#include <Kit_seguidor.h>

Kit_seguidor robot_1;
void setup()
{
    robot_1.init();
    Serial.begin(9600);
}

void loop()
{
    robot_1.modo_seguidor(25,12,30,100);
    robot_1.print_sensores();
}
