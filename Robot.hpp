#include<Arduino.h>

class Robot
{
private:
    const uint8_t In1 = 2;
    const uint8_t In2 = 4;
    const uint8_t Pwm1 = 3;
    const uint8_t In3 = 6;
    const uint8_t In4 = 7;
    const uint8_t Pwm2 = 5;

public:
    void Motores_init();
    void Motores_mv(int velocidad_izquierda, int velocidad_derecha);
    Robot();
    ~Robot();
};
