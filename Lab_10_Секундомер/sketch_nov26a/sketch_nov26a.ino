#define FIRST_SEGMENT_PIN   2 
#define SEGMENT_COUNT       7 

byte numberSegments[10] = {   0b00111111, 0b00001010, 0b01011101, 0b01011110, 0b01101010,   0b01110110, 0b01110111, 0b00011010, 0b01111111, 0b01111110, };

void setup() {  
  for (int i = 0; i < SEGMENT_COUNT; ++i)  
  pinMode(i + FIRST_SEGMENT_PIN, OUTPUT); }
  
  void loop() { 
    // определяем число, которое собираемся отображать. Пусть им  
    // будет номер текущей секунды, зацикленный на десятке  
    int number = (millis() / 1000) % 10;   
    // получаем код, в котором зашифрована арабская цифра  
    int mask = numberSegments[number];  
    // для каждого из 7 сегментов индикатора... 
    for (int i = 0; i < SEGMENT_COUNT; ++i) {  
      // ...определяем: должен ли он быть включён. Для этого 
      // считываем бит (англ. read bit), соответствующий текущему 
      // сегменту «i». Истина — он установлен (1), ложь — нет (0)   
      boolean enableSegment = bitRead(mask, i);  
      // включаем/выключаем сегмент на основе полученного значения    
      digitalWrite(i + FIRST_SEGMENT_PIN, enableSegment); 
  } 
  }
