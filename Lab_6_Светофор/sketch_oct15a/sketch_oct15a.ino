int red = 13;
int yellow = 12;
int green = 11;

char command;

bool onExit = false;

void setup()
{
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  char incomingChar;
  if(Serial.available() || onExit)
  {
    incomingChar = Serial.read();
    if(incomingChar == 'N' || incomingChar == 'S' || 
      incomingChar == 'R' || incomingChar == 'G' || onExit)
    {
        if(!onExit)
          command  = incomingChar;
        switch(command)
        {
          case 'N':
          {
            powerLowPorts();
            Serial.println("Normal");
            break;
          }
          case 'S':
          {
            powerLowPorts();
            Serial.println("Sleep");
            break;
          }
          case 'R':
          {
            powerLowPorts();
            Serial.println("Red");
            break;
          }
          case 'G':
          {
            powerLowPorts();
            Serial.println("Green");
            break;
          }
        }        
      onExit = false;
      }
    }
  switch(command)
  {
    case 'N':    normalMode();    break;
    case 'S':    sleepMode();    break;
    case 'R':    redMode();    break;
    case 'G':    greenMode();    break;
  }
}

void checkexit()
{
  if(Serial.available())
  {
    char  incomingChar = Serial.read();
    if(incomingChar == 'N' || incomingChar == 'S' || 
      incomingChar == 'R' || incomingChar == 'G')
    {
      onExit = true;
      command = incomingChar;
      powerLowPorts();
    }
  }  
}

void powerLowPorts()
{
  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
  digitalWrite(yellow, LOW);
}

void ping(int color,int t, int t1){
  digitalWrite(color, HIGH);
  delay(t);
  digitalWrite(color, LOW);
  delay(t1);
 }
 
void greenMode()
{
  digitalWrite(green, HIGH);
}

void redMode()
{
  digitalWrite(red, HIGH);
}

void sleepMode()
{
  ping(yellow,500, 500);
}

void normalMode()
{
  ping(red,4000,0);
  checkexit();
  if(onExit)
    return;
  digitalWrite(red, HIGH);
  ping(yellow,1500,0);
  checkexit();
  if(onExit)
    return;
  digitalWrite(red, LOW);
  ping(green,5000,0);
  checkexit();
  if(onExit)
    return;
  for(int i = 0; i < 3; i++)
  {
    ping(green,500,500);
    checkexit();
    if(onExit)
      return;
  }
  ping(green,500,0);
  checkexit();
  if(onExit)
    return;
  ping(yellow,2000, 0);
  checkexit();
  if(onExit)
    return;
}
