#include "Robot.hpp"

void Robot::Motores_init()
{
    Serial.begin(9600);
    pinMode(In1, OUTPUT);
    pinMode(In2, OUTPUT);
    pinMode(Pwm1, OUTPUT);

    pinMode(In3, OUTPUT);
    pinMode(In4, OUTPUT);
    pinMode(Pwm2, OUTPUT);
}
void Robot::Motores_mv(int velocidad_izquierda, int velocidad_derecha)
{
    if (velocidad_izquierda > 0)
    {
        analogWrite(Pwm1, velocidad_izquierda);
        digitalWrite(In1, LOW);
        digitalWrite(In2, HIGH);
    }
    else
    {
        velocidad_izquierda = -1 * velocidad_izquierda;
        analogWrite(Pwm1, velocidad_izquierda);
        digitalWrite(In1, HIGH);
        digitalWrite(In2, LOW);
    }
    if (velocidad_derecha > 0)
    {
        analogWrite(Pwm2, velocidad_derecha);
        digitalWrite(In3, LOW);
        digitalWrite(In4, HIGH);
    }
    else
    {
        velocidad_derecha = -1 * velocidad_derecha;
        analogWrite(Pwm2, velocidad_derecha);
        digitalWrite(In3, HIGH);
        digitalWrite(In4, LOW);
    }
}

Robot::Robot()
{
}

Robot::~Robot()
{
}