float T = 0;
float H = 0;

#include <Wire.h>
#include "ASOLED.h"
#include "DHT.h"

DHT dht_4(4, DHT22);

void setup() {
  LD.init();
  LD.clearDisplay();
  Serial.begin(9600);
  dht_4.begin();
}

void loop() {
    T = dht_4.readTemperature();
    H = dht_4.readHumidity();
    
    // Вывод температуры
    LD.printString_12x16("Темп ", 0, 0);
    LD.printString_12x16("", 70, 0);
    LD.printNumber((long)T);
    LD.printString_12x16("C°", 100, 0);
    
    // Вывод влажности
    LD.printString_12x16("ВЛАГА", 0, 5);
    LD.printString_12x16("", 70, 5);
    LD.printNumber((long)H);
    LD.printString_12x16("%", 100, 5);
    
    // Очистка области сообщения (16 пробелов)
    LD.printString_6x8("                ", 0, 11);
    
    // Вывод сообщения в зависимости от влажности
    if (H < 30) {
      LD.printString_6x8("Опасная сухость", 0, 11);
    }
    else if (H < 40) {
      LD.printString_6x8("Очень сухо", 0, 11);
    }
    else if (H < 55) {
      LD.printString_6x8("Суховато", 0, 11);
    }
    else if (H < 70) {
      LD.printString_6x8("Нормальная влага", 0, 11);
    }
    else if (H < 80) {
      LD.printString_6x8("Высокая влажность", 0, 11);
    }
    else {
      LD.printString_6x8("Опасная влага", 0, 11);
    }
    
    delay(2000); // Обновление данных каждые две секунды
}