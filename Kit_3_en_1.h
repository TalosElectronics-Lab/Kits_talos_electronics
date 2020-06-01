#include<Robot.h>
#include<SoftwareSerial.h>


class Kit_3_en_1 : public Robot
{
private:
    /* data */
    const uint8_t B_TX = 8;
    const uint8_t B_RX = 9;
    SoftwareSerial Bluetooth; // RX, TX
    char Estado;
    int Menu;
    int Velocidad_Max = 230;
    int Velocidad_Med = 130;

public:
    void init(); 
    void modo_3_en_1();
    char Leer_BT();
    void modo_bluetooth();
    Kit_3_en_1(/* args */): Robot::Robot(), Bluetooth(B_TX, B_RX){};
    ~Kit_3_en_1();
};

