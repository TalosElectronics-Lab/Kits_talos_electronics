#include<Kit_3_en_1.h>
void Kit_3_en_1::init()
{
    Motores_init();
    Bluetooth.begin(9600);
    Serial.begin(9600);

    Motores_init();
    pinMode(Trigger, OUTPUT);
    pinMode(Echo, INPUT);
    servo_1.attach(Servo_pin);
    servo_1.write(90);
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
        modo_evasor(25,50); //25cm=Distancia del obstaculo
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
void Kit_3_en_1::modo_evasor(int Distancia, uint8_t velocidad)
{
    float Distancia_izq, Distancia_der;

    Motores_mv(velocidad, velocidad);
    if (obtener_distancia() <= Distancia)
    {
        Motores_mv(-50, -50);
        delay(250);
        Motores_mv(0, 0);

        //Barrido de servo de derecha a izquierda
        for (size_t i = 90; i < Angulo_max; i++)
        {
            servo_1.write(i);
            delay(5);
        }

        delay(300);
        Distancia_izq = obtener_distancia();

        for (size_t i = Angulo_max; i > Angulo_min; i--)
        {
            servo_1.write(i);
            delay(5);
        }

        delay(300);
        Distancia_der = obtener_distancia();

        for (size_t i = Angulo_min; i < 90; i++)
        {
            servo_1.write(i);
            delay(5);
        }
        delay(250);

        if (Distancia_izq < Distancia_der)
        {
            //Obstaculo detectado en el lado izquierdo, debe girar a la derecha
            Motores_mv(velocidad_giro, -velocidad_giro);
            delay(500);
            Motores_mv(velocidad, velocidad);
        }
        else
        {
            //Obstaculo detectado en el lado derecho por lo que debe girar a la izquierda
            Motores_mv(-velocidad_giro, velocidad_giro);
            delay(500);
            Motores_mv(velocidad, velocidad);
        }
    }
}

float Kit_3_en_1::obtener_distancia()
{
    long lduration;
    long ldistance;

    //Se manda un pulso por el pin Trigger
    digitalWrite(Trigger, LOW);
    delayMicroseconds(2);
    digitalWrite(Trigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(Trigger, LOW);

    //Se mide cuanto tiempo tardo en us
    //Ecuación d = l_distancia/2 * velocidad cm/us
    lduration = pulseIn(Echo, HIGH);
    ldistance = (lduration / 2) / 29.1;
    return ldistance;
}