#include "LiquidCrystal.h"
#define Led 13
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
char inputBuffer[15];
LiquidCrystal Lcd(rs, en, d4, d5, d6, d7);
void setup()
{
    Serial.begin(9600);
    pinMode(13, OUTPUT);
    Lcd.begin(16, 2);
    lcd.setCursor(0, 0);
    Lcd.write("Wpisz komende.");
}
void ledCommend()
{

    if (inputBuffer[1] == 0x41)
    {
        digitalWrite(Led, HIGH);
    }
    else if (inputBuffer[1] == 0x42)
    {
        digitalWrite(Led, LOW);
    }
}
void dispalyOnLcd()
{
    char *pInputBuffer = inputBuffer;
    Lcd.clear();
    Lcd.setCursor(0, 0);
    Lcd.print(++pInputBuffer);
}

void loop()
{
    if (Serial.available() > 0)
    {
        Serial.readBytesUntil('/n', inputBuffer, 15);
        if (inputBuffer[0] == 0x30)
        {
            dispalyOnLcd();
        }
        else if (inputBuffer[0] == 0x31)
        {
            ledCommend();
        }
    }
}
