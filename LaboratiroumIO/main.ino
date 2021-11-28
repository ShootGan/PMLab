
#define playerOneLed 8
#define PlayerTwoLed 9
#define playerOneButto 2
#define playerTwoButto 3
void setup()
{
    pinMode(playerOneLed, OUTPUT);
    pinMode(PlayerTwoLed, OUTPUT);
    pinMode(playerOneButto, INPUT_PULLUP);
    pinMode(playerTwoButto, INPUT_PULLUP);
}
void TurnOnLed(int pinNumber)
{
    digitalWrite(pinNumber, HIGH);
    delay(7000);
    digitalWrite(pinNumber, LOW);
}
void loop()
{
    if (digitalRead(playerOneButto) == LOW)
    {
        TurnOnLed(playerOneLed);
    }
    if (digitalRead(playerTwoButto) == LOW)
    {
        TurnOnLed(PlayerTwoLed);
    }
}