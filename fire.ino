float vout;
float vout1;
int LED = 13;
int pump = 12;
int gasSensor;
int piezo = 7;
void setup()
{
    pinMode(A0, INPUT);

    pinMode(LED, OUTPUT);
    pinMode(piezo, OUTPUT);
    Serial.begin(9600);
}
void loop()
{
    vout = analogRead(A1);
    vout1 = (vout / 1023) * 5000;

    gasSensor = analogRead(A0);

    if (gasSensor >= 350)
    {
        if (gasSensor > 500)
        {
            digitalWrite(piezo, HIGH);
            digitalWrite(LED, HIGH);
            digitalWrite(pump, HIGH);
        }
        else
        {
            digitalWrite(piezo, HIGH);
            digitalWrite(LED, HIGH);
        }
    }

    else
    {
        digitalWrite(piezo, LOW);
        digitalWrite(LED, LOW);
        digitalWrite(pump, LOW);
    }

    Serial.print("GasSensor= ");
    Serial.print(" ");
    Serial.print(gasSensor);
    Serial.println();
    delay(1000);
}
