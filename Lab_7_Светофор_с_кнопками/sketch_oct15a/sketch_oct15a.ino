#include <LiquidCrystal.h>
int normal_button = 4;
int green_button = 5;
int sleep_button = 6;
int red_button = 7;

int red_led = 10;
int yellow_led = 9;
int green_led = 8;

char command;
bool onExit = false;

LiquidCrystal lcd(13, 12, 3, 2, 1, 0);

void setup() 
{
  pinMode(green_led, OUTPUT);
  pinMode(yellow_led, OUTPUT);
  pinMode(red_led, OUTPUT);
  pinMode(normal_button, INPUT);
  pinMode(green_button, INPUT);
  pinMode(sleep_button, INPUT);
  pinMode(red_button, INPUT);
  lcd.begin(16, 2);
}

void loop() 
{
  if(!onExit)
  {
    switch(command)
    {
      case 'N':
      {
        powerLowPorts();
        lcd.clear();
        lcd.print("Normal");
        normalMode();
        break;
      }
      case 'S':
      {
        powerLowPorts();
        lcd.clear();
        lcd.print("Sleep");
        sleepMode();
        break;
      }
      case 'R':
      {
        powerLowPorts();
        redMode();
        break;
      }
      case 'G':
      {
        powerLowPorts();
        greenMode();
        break;
      }
    }
    onExit = true;     
  }
  if(onExit)
  {
  	if (digitalRead(normal_button) == HIGH) 
    {
      command = 'N';
    }
    else if (digitalRead(sleep_button) == HIGH) 
    {
      command = 'S';
    }
    else if (digitalRead(red_button) == HIGH) 
    {
      command = 'R';
      lcd.clear();
      lcd.print("Red");
    }
    else if (digitalRead(green_button) == HIGH) 
    {
      command = 'G';
      lcd.clear();
      lcd.print("Green");
    }
    onExit = false;
  }
}

void checkexit()
{
  if(command == 'N' || command == 'S' || 
      command == 'R' || command == 'G')
    {
      onExit = true;
      powerLowPorts();
    } 
}

void powerLowPorts()
{
  digitalWrite(red_led, LOW);
  digitalWrite(green_led, LOW);
  digitalWrite(yellow_led, LOW);
}

void ping(int color,int t, int t1)
{
  digitalWrite(color, HIGH);
  delay(t);
  digitalWrite(color, LOW);
  delay(t1); 
}

void greenMode()
{
  digitalWrite(green_led, HIGH);
}

void redMode()
{
  digitalWrite(red_led, HIGH);
}

void sleepMode()
{
  ping(yellow_led, 700, 700);
}

void normalMode()
{
   command = '0';
  ping(red_led,4000,0);
  checkexit();
  if(onExit)
    return;
  digitalWrite(red_led, HIGH);
  ping(yellow_led,1500,0);
  checkexit();
  if(onExit)
    return;
  digitalWrite(red_led, LOW);
  ping(green_led,5000,0);
  checkexit();
  if(onExit)
    return;
  for(int i = 0; i < 3; i++)
  {
    ping(green_led,500,500);
    checkexit();
    if(onExit)
      return;
  }
  ping(green_led,500,0);
  checkexit();
  if(onExit)
    return;
  ping(yellow_led,2000, 0);
  checkexit();
  if(onExit)
    return;
}