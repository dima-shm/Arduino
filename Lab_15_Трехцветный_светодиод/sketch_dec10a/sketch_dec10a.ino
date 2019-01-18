int redLed = 13;
int greenLed = 11;
int blueLed = 12;
String inputSerialStr;

void setup()
{
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  while (Serial.available()) {
    inputSerialStr = Serial.readStringUntil('\n');
    char r = inputSerialStr[0];
    char g = inputSerialStr[1];
    char b = inputSerialStr[2];
    if (r >= '0' && r <= '9' && 
        g >= '0' && g <= '9' &&
        b >= '0' && b <= '9') {
      setColor(r, g, b);
    }
  }
}

int parseCharToInt(char c)
{
	return c - '0';
}

void setColor(char red, char green, char blue)
{
  digitalWrite(redLed, parseCharToInt(red));
  digitalWrite(greenLed, parseCharToInt(green));
  digitalWrite(blueLed, parseCharToInt(blue));  
}