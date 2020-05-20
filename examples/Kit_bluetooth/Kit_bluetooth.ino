#include<Kit_bluetooth.h>
Kit_bluetooth Robot;
void setup()
{
    Robot.init();
}
void loop()
{
    Robot.Modo_bluetooth();
    
}