int val;

int led_red = 2;
int led_yellow = 3;
int led_green = 4;

const int N = 0;
const int S = 1;
const int G = 2;
const int R = 3;

void setup()
{
	Serial.begin(9600);
	pinMode(led_red, OUTPUT);
	pinMode(led_yellow, OUTPUT);
	pinMode(led_green, OUTPUT);
}

void trafficLightsMod(int mod)
{
	switch (mod)
	{
	case 'N':
	{
		normalMod();
		Serial.println("Normal mod");
	} break;
	case 'S':
	{
		sleepMod();
		Serial.println("Sleep mod");
	} break;
	case 'G':
	{
		greenMod();
		Serial.println("Green mod");
	} break;
	case 'R':
	{
		redMod();
		Serial.println("Red mod"); 
	} break;
	default:
	{
		normalMod();
		Serial.println("Normal mod");
	} break;
	}
}

void loop()
{
	val = Serial.read();
	trafficLightsMod(val);
}

void normalMod()
{
	for (int i = 0; i < 4; i++)
	{
		digitalWrite(led_green, HIGH);
		if (i == 0)
			delay(5000);
		else
			delay(500);
		digitalWrite(led_green, LOW);
		if (i < 3)
			delay(1000);
	}
	digitalWrite(led_yellow, HIGH);
	delay(2000);
	digitalWrite(led_yellow, LOW);
	digitalWrite(led_red, HIGH);
	delay(5000);
	digitalWrite(led_yellow, HIGH);
	digitalWrite(led_red, HIGH);
	delay(2000);
	digitalWrite(led_red, LOW);
	digitalWrite(led_yellow, LOW);
}

void sleepMod()
{
	digitalWrite(led_yellow, HIGH);
	delay(1000);
	digitalWrite(led_yellow, LOW);
	delay(1000);
}

void greenMod()
{
	digitalWrite(led_green, HIGH);
}

void redMod()
{
	digitalWrite(led_red, HIGH);
}