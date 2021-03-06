#include <Arduino.h>
#include <Servo.h>

byte servoPin = 8;
const int nbMotor = 4;
Servo servo[nbMotor];

void setup()
{
    Serial.begin(9600);
    for (int i=0; i < nbMotor; i++) {
        servo[i].attach(servoPin+i);
        servo[i].writeMicroseconds(1000); 
    }

    delay(7000); 
}

void loop()
{

    Serial.println("Enter PWM signal [0,9]");
    while (Serial.available() == 0){
    }

    int key = Serial.parseInt();
    int val = map(key, 0, 9, 1000, 1500);
    Serial.print(key);
    Serial.print(" ");
    Serial.println(val);

    if (val < 1000 || val > 1652)
    {
        Serial.println("not valid");
        val = 1000;
    }

    for (int i=0; i < nbMotor; i++) {
        servo[i].writeMicroseconds(val);
    }    
}