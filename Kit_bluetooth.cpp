#include<Kit_bluetooth.h>

Kit_bluetooth::~Kit_bluetooth() {}

void Kit_bluetooth::init()
{
    Motores_init();
    Bluetooth.begin(9600);

}

uint8_t Kit_bluetooth::Leer_BT()
{
    if (Bluetooth.available() > 0)
    {
        Estado = Bluetooth.read();
        Serial.println(Estado);
    }
    return Estado;
}
void Kit_bluetooth::modo_bluetooth()
{
    int Velocidad_Max = 255;
    int Velocidad_Med = 150;
    Estado = Leer_BT();
    if (Estado == '1')
    {
        //Arriba_Izquierda
        Motores_mv(Velocidad_Med, Velocidad_Max);
    }
    if (Estado == '2')
    {
        //Derecho
        Motores_mv(Velocidad_Max, Velocidad_Max);
    }
    if (Estado == '3')
    {
        //Arriba_Derecha
        Motores_mv(Velocidad_Max, Velocidad_Med);
    }
    if (Estado == '4')
    {
        //Girar a la izquierda
        Motores_mv(-Velocidad_Max, Velocidad_Max);
    }
    if (Estado == '5')
    {
        //Serial.println("Logo talos");
    }
    if (Estado == '6')
    {
        //Girar a la derecha
        Motores_mv(Velocidad_Max, -Velocidad_Max);
    }
    if (Estado == '7')
    {
        //Abajo Izquierda
        Motores_mv(-Velocidad_Med, -Velocidad_Max);
    }
    if (Estado == '8')
    {
        //Reversa
        Motores_mv(-Velocidad_Max, -Velocidad_Max);
    }
    if (Estado == '9')
    {
        //Abajo Derecha
        Motores_mv(-Velocidad_Max, -Velocidad_Med);
    }
    if (Estado == 'w')
    {
        Motores_mv(0, 0);
    }
}