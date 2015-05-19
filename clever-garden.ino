#include <Wire.h>
#include <Time.h>
#include <DS1307RTC.h>
#include "DHT.h"
#define DHTPIN1 26        //пин датчика температуры
#define DHTTYPE DHT11     //все датчики 11
//#include <DS1307.h>
//RTC_DS1307 RTC;


int hours;
int minutes;
int Relay2 = 2;            //номер порта 1 реле
int Relay3 = 3;            //номер порта 2 реле
int Relay4 = 4;            //номер порта 3 реле
int Relay5 = 5;            //номер порта 4 реле
int On_TimeR2  = 21*60+0;  //Раз в сутки включается в 21:00
int Off_TimeR2 = 21*60+05; //Раз в сутки выключается в 21:05
int On_TimeR3  = 26;       //каждый час  
int Off_TimeR3 = 28;       //каждый час 
//int On_TimeR4 = 30;      //раз в час  On_TimeR4 = 45;
//int Off_TimeR4 = 32;     //раз в час Off_TimeR4 = 50;
//int On_TimeR5 = 31;      //раз в час  On_TimeR5 = 45;
//int Off_TimeR5 = 35;     //раз в час Off_TimeR5 = 50;
int Curent_Time;           //полностью время(номер минуты в сутках)
int Curent_Minutes;        //сокращенное время(номер минуты в часе)
DHT dht(DHTPIN1, DHTTYPE);

void setup() 
{
 Serial.begin(9600);
 while (!Serial) ; // ожидаем ответа порта
 delay(200);
 Serial.println("DS1307RTC Read Test");
 Serial.println("-------------------");
  pinMode(Relay2, OUTPUT);
  pinMode(Relay3, OUTPUT);
  pinMode(Relay4, OUTPUT);
  pinMode(Relay5, OUTPUT);
  dht.begin();
  digitalWrite(Relay2, HIGH); //выставляем 1 на выходе - соответствует отключенному реле
  digitalWrite(Relay3, HIGH); //выставляем 1 на выходе - соответствует отключенному реле
  digitalWrite(Relay4, HIGH); //выставляем 1 на выходе - соответствует отключенному реле
  digitalWrite(Relay5, HIGH); //выставляем 1 на выходе - соответствует отключенному реле
}
void loop()
{
  tmElements_t tm;
  float h = dht.readHumidity();
  float t = dht.readTemperature();
    if(t>=35){digitalWrite(Relay4, LOW);}else if(t<25){digitalWrite(Relay4, HIGH);} //тут температура выключения должна быть ниже температуры включения. чтобы не было пограничных значений
    Serial.print("Internal temperature: "); 
    Serial.print(t);
    Serial.println(" *C");
    
  if(RTC.read(tm))
  {
 // Serial.print(tm.Hour);
  //Serial.print(tm.Minute);
  //Serial.print(tm.Second);
  //Serial.println();
  minutes = tm.Minute;
  hours = tm.Hour;
  Curent_Minutes = tm.Minute;
  Curent_Time = tm.Hour*60+tm.Minute;


R2();
R3();
//R4(); //оставлю сработку только по температуре
//R5(); //оставлю сработку только по температуре
  }

 else { Serial.println("---------- NO ds3231 INSTALLED -----------"); }

}
void R2()
{

  if(On_TimeR2 < Off_TimeR2)
   {
    if (Curent_Time >= On_TimeR2 && Curent_Time <= Off_TimeR2)
      {
        digitalWrite(Relay2, LOW);
      }
    else
      {
        digitalWrite(Relay2, HIGH);
      }
  }
else // если сутки сменились
  {
        if ((Curent_Time >= On_TimeR2 && Curent_Time <= 2820)||(Curent_Time >= 0 && Curent_Time <= Off_TimeR2))//2820=24часа*60
      {
        digitalWrite(Relay2, LOW);
      }
    else
      {
        digitalWrite(Relay2, HIGH);
      }
 } 
  }

void R3()
{

  if(On_TimeR3 < Off_TimeR3)
   {
    if (Curent_Minutes >= On_TimeR3 && Curent_Minutes <= Off_TimeR3)
      {
        digitalWrite(Relay3, LOW);
      }
    else
      {
        digitalWrite(Relay3, HIGH);
      }
  }
else // если сутки сменились
  {
        if ((Curent_Minutes >= On_TimeR3 && Curent_Minutes <= 2820)||(Curent_Minutes >= 0 && Curent_Minutes <= Off_TimeR3))//2820=24часа*60
      {
        digitalWrite(Relay3, LOW);
      }
    else
      {
        digitalWrite(Relay3, HIGH);
      }
 } 
  }

