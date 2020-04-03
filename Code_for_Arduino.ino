#include<Servo.h>
Servo servo_01;
Servo servo_02;

#define ldr_01 0
#define ldr_02 1
#define ldr_03 2
#define ldr_04 3
#define servo_01_pin 12
#define servo_02_pin 13

void setup()
{
  pinMode(ldr_01, INPUT);
  pinMode(ldr_02, INPUT);
  pinMode(ldr_03, INPUT);
  pinMode(ldr_04, INPUT);
  pinMode(servo_01_pin, OUTPUT);
  pinMode(servo_02_pin, OUTPUT);

  servo_01.attach(servo_01_pin);
  servo_02.attach(servo_02_pin);

  servo_01.write(90);
  servo_02.write(90);
}

void loop()
{
  int ldr_01_value = analogRead(ldr_01);
  int ldr_02_value = analogRead(ldr_02);
  int ldr_03_value = analogRead(ldr_03);
  int ldr_04_value = analogRead(ldr_04);

  if ((ldr_01_value < ldr_02_value) && (ldr_03_value < ldr_04_value))
  {
    for (int i = 90; i < 180; i++)
    {
      if ((ldr_01_value > ldr_02_value) && (ldr_03_value > ldr_04_value))
      {
        break;
      }
      servo_01.write(i);
      servo_02.write(i);
      delay(100);
    }
  }

  if ((ldr_01_value > ldr_02_value) && (ldr_03_value > ldr_04_value))
  {
    for (int j = 90; j < 0; j++)
    {
      if ((ldr_01_value < ldr_02_value) && (ldr_03_value < ldr_04_value))
      {
        break;
      }
      servo_01.write(j);
      servo_02.write(j);
      delay(100);
    }
  }

  if ((ldr_01_value < ldr_02_value) && (ldr_03_value > ldr_04_value))
  {
    for (int k = 90; k < 180; k++)
    {
      if ((ldr_01_value > ldr_02_value) && (ldr_03_value < ldr_04_value))
      {
        break;
      }
      servo_01.write(k);
      delay(100);
    }
    for (int l = 90; l < 0; l++)
    {
      if ((ldr_01_value > ldr_02_value) && (ldr_03_value < ldr_04_value))
      {
        break;
      }
      servo_02.write(l);
      delay(100);
    }
  }

  if ((ldr_01_value > ldr_02_value) && (ldr_03_value < ldr_04_value))
  {
    for (int k = 90; k < 180; k++)
    {
      if ((ldr_01_value < ldr_02_value) && (ldr_03_value > ldr_04_value))
      {
        break;
      }
      servo_02.write(k);
      delay(100);
    }
    for (int l = 90; l < 0; l++)
    {
      if ((ldr_01_value < ldr_02_value) && (ldr_03_value > ldr_04_value))
      {
        break;
      }
      servo_01.write(l);
      delay(100);
    }
  }

}
