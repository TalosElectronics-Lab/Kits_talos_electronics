#include<Kit_3_en_1.h>
void Kit_3_en_1::init()
{
    Motores_init();
    Bluetooth.begin(9600);
    Serial.begin(9600);
}
void Kit_3_en_1::modo_3_en_1(){
    Serial.print("Estado: ");
    Serial.println(Estado);
    Serial.print("Menu: ");
    Serial.println(Menu);
    Estado = Leer_BT();
    if (Estado == 'a')
    {
        Menu = 30;
    }
    if (Estado == 'b')
    {
        Menu = 10;
    }
    if (Estado == 'c')
    {
        Menu = 20;
    }

    switch (Menu)
    {
    case 10:
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
        break;

    case 20:
        //Robot.Modo_Evasor(25); //25cm=Distancia del obstaculo
        break;

    case 30:
        //Robot.Modo_Seguidor();
        break;
    }
}
Kit_3_en_1::~Kit_3_en_1()
{
}

char Kit_3_en_1::Leer_BT()
{
    if (Bluetooth.available() > 0)
    {
        Estado = Bluetooth.read();
        //Serial.println(Estado);
    }
    return Estado;
}
