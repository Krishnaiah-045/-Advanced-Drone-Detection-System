#include <ESP32Servo.h>
Servo myservo;  // create servo object to control a servo

#include <LiquidCrystal.h>
#include <stdio.h>
//LiquidCrystal lcd(A0, A1, 4, 5, 6, 7);
LiquidCrystal lcd(13, 12, 14, 27, 26, 25);

#include <WiFi.h>
#include <HTTPClient.h>

HTTPClient http;

const char *ssid = "iotserver";
const char *password = "iotserver123";

int sti=0;
String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete

int cntlmk1=0;
int cntlmk2=0;
int ang=0;

int httpResponseCode;
String servername = "http://projectsfactoryserver.in/storedata.php?name=";
String accountname = "iot1229";
String field1 = "&s1=";
String payload="";


int cam_pin = 19;
int buzzer  = 23;
int button  = 22;

#define RXD2 16
#define TXD2 17




void iot_send()
{
  http.begin(servername + accountname + field1 + "Drone_UAV_Detected");
  
  httpResponseCode = http.GET();

   if(httpResponseCode>0) 
     {
        payload="";
      //  Serial.print("HTTP Response code: ");
      //  Serial.println(httpResponseCode);
        payload = http.getString();
      //  Serial.println(payload);
     }
   else 
     {
       ;
       // Serial.print("Error code: ");
       // Serial.println(httpResponseCode);
     }
}

void serial2clear()
{
  while(Serial2.available() > 0) 
       {
          char t = Serial2.read();
       }
}
void lcdbasic()
{
  lcd.clear();
}
void beep()
{
  digitalWrite(buzzer, LOW);delay(3000);digitalWrite(buzzer, HIGH);
}
void setup() 
{
  Serial.begin(9600);
  Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);

  myservo.attach(21);
  myservo.write(1);
  
  pinMode(cam_pin, INPUT);pinMode(button, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT); 
  digitalWrite(buzzer, HIGH);
  
 //4. Drone and UAV Detection for security applications using Deep Learning
  lcd.begin(16, 2);
  lcd.print("  Drone And UAV ");
  lcd.setCursor(0,1);
  lcd.print("  Detection For ");
    delay(2500);
  
  lcd.clear();
  lcd.print("Security Applica");
  lcd.setCursor(0,1);
  lcd.print("Using Deeplearning");
    delay(2000);

  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) 
       {
           delay(500);
       }
  
  Serial2.flush();
  serial2clear();
   
  lcd.clear();
}

void loop() 
{
   while(Serial2.available() > 0)
        {
         char chrt = (char)Serial2.read();
         if(chrt == '*')
           {
             sti=1;
           }
         if(sti == 1)
           {
             inputString += chrt;
           }
         if(chrt == '#')
           {sti=0;
              stringComplete = true;      
           }  
        }
        
   if(stringComplete)
     {
      lcd.setCursor(0,1);lcd.print(inputString);             
        inputString = "";
        stringComplete = false;              
      lcd.setCursor(0,0);lcd.print("                ");  
      serial2clear();
     }      

if(digitalRead(button) == HIGH)
  {
    lcd.setCursor(15,0);lcd.print("S");
       if(digitalRead(cam_pin) == LOW)
        {
          cntlmk1++;
        }
      if(digitalRead(cam_pin) == HIGH)
        {
          cntlmk1=0;
        }   

      if(cntlmk1>= 4)
        {  
          cntlmk1=0;
          lcd.setCursor(0,0);lcd.print("Drone-UAV Detec");  
          beep();
          iot_send();
          delay(2000);
          lcd.setCursor(0,0);lcd.print("                ");
        }
  }  
  
if(digitalRead(button) == LOW)
  {
    lcd.setCursor(15,0);lcd.print("R");  
  for(ang=1;ang<=45;ang++)
     {
       myservo.write(ang);
        delay(400);
      
      if(digitalRead(cam_pin) == LOW)
        {
          cntlmk1++;
        }
      if(digitalRead(cam_pin) == HIGH)
        {
          cntlmk1=0;
        }   

      if(cntlmk1>= 4)
        {  
          cntlmk1=0;
          lcd.setCursor(0,0);lcd.print("Drone-UAV Detec");  
          beep();
          iot_send();
          delay(2000);
          lcd.setCursor(0,0);lcd.print("                ");
        }
     }
     
  for(ang=45;ang>=1;ang--)
     {
       myservo.write(ang);
        delay(400);
      
      if(digitalRead(cam_pin) == LOW)
        {
          cntlmk1++;
        }
      if(digitalRead(cam_pin) == HIGH)
        {
          cntlmk1=0;
        }   

      if(cntlmk1>= 4)
        {  
          cntlmk1=0;
          lcd.setCursor(0,0);lcd.print("Drone-UAV Detec");  
          beep();
          iot_send();
          delay(2000);
          lcd.setCursor(0,0);lcd.print("                ");
        }
     }
  }
}


void convertl(unsigned int value)
{
  unsigned int a,b,c,d,e,f,g,h;

      a=value/10000;
      b=value%10000;
      c=b/1000;
      d=b%1000;
      e=d/100;
      f=d%100;
      g=f/10;
      h=f%10;


      a=a|0x30;               
      c=c|0x30;
      e=e|0x30; 
      g=g|0x30;              
      h=h|0x30;
    
     
   lcd.write(a);
   lcd.write(c);
   lcd.write(e); 
   lcd.write(g);
   lcd.write(h);
}
