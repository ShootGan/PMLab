#include "LiquidCrystal.h"
char inputBuffer[15];
void setup()
{
    Serial.begin(9600);
    //init lcd
    lcd.begin(16, 2);
    lcd.setCursor(0, 0);
}
void readInput()
{
    int i = 0;
    while (Serial.available() > 0)
    {
        char c = Serial.read();
        if (c == '\n')
        {
            inputBuffer[i] = '\0';
            break;
        }
        else
        {
            inputBuffer[i] = c;
            i++;
        }
    }
}
void loop()
{
    while (serial.available > 0)
    {
        readInput();
    }
    serila.println(inputBuffer);
}
