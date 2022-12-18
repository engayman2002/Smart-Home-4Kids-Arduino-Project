// ----------------------------- Librarys -----------------------------
#include <Arduino_FreeRTOS.h>
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
#include <Keypad.h>
#include <Servo.h>
#include <EEPROM.h>

// ----------------------------- LCD
#define rs 3
#define en 4
#define d4 5
#define d5 6
#define d6 7
#define d7 8
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

// ----------------------------- UltraSonic
// UltraSonic Pins & Variables
#define echoPin 10
#define trigPin 9

// ----------------------------- Keypad
char keys[4][4]=
{
  {'1','2','3','+'},
  {'4','5','6','-'},
  {'7','8','9','*'},
  {'C','0','=','/'}
  };

byte rowPins[4]={14,15,16,17};
byte colPins[4]={18,19,20,21};

Keypad mykey=Keypad(makeKeymap(keys),rowPins,colPins,4,4);

// ----------------------------- MQ2
#define mq2pin 48

// ----------------------------- IR
#define ir0pin 2
#define ir1pin 12
#define ir2pin 13

// ----------------------------- LEDs
#define ledmpin 51
#define led0pin 52
#define led1pin 50
#define led2pin 53

// ----------------------------- Soil Moisture and Motor
#define soilpin A0
#define motor 26
#define motor2 27

// ----------------------------- Bluetooth
SoftwareSerial mySerial(28,29); // RX, TX

// ----------------------------- Servo
#define servopin 22
Servo myservo;


// ----------------------------- Fan
#define fanpin 24
#define fanpin2 25

// ----------------------------- Buzzer
#define buz 44
bool stbuz=false;

// --------------------------------------------- Start Tasks ---------------------------------------------

void TaskPassword(void *pvParameters); // Task 1
void TaskMQ2(void *pvParameters); // Task 2
void TaskBluetooth(void *pvParameters); // Task 3
void Task2IR(void *pvParameters); // Task 4
void TaskSoil(void *pvParameters); // Task 5

// --------------------------------------------- End Tasks ---------------------------------------------


// ----------------------------- Main Function -----------------------------
void setup() 
{
  // El Serial Ya Ayman ^_^
  Serial.begin(9600);
  
  // LCD Initial
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0,0);

  // UltraSonic Pins
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);

  // Keypad NO

  // MQ-2 Pins
  pinMode(mq2pin,INPUT);

  // IRs Pins
  pinMode(ir0pin,INPUT);
  pinMode(ir1pin,INPUT);
  pinMode(ir2pin,INPUT);

  // Soil Moisture and Motors Pins
  pinMode(soilpin,INPUT);
  pinMode(motor,OUTPUT);
  pinMode(motor2,OUTPUT);
  digitalWrite(motor,0);
  digitalWrite(motor2,0);

  // Bluetooth Serial
  mySerial.begin(9600);

  // Servo Pins
  myservo.attach(servopin);
  Door(0);

  // Fan Pins
  pinMode(fanpin,OUTPUT);
  pinMode(fanpin2,OUTPUT);
  digitalWrite(fanpin2,0);

  // Buzzer
  pinMode(buz,OUTPUT);

  // LEDs
  pinMode(ledmpin,OUTPUT);
  pinMode(led0pin,OUTPUT);
  pinMode(led1pin,OUTPUT);
  pinMode(led2pin,OUTPUT);
  
  // Tasks Creation
  xTaskCreate(TaskPassword,"Password",128,NULL,1,NULL); // 1
  xTaskCreate(TaskMQ2,"MQ2",128,NULL,1,NULL); // 2
  xTaskCreate(TaskBluetooth,"Bluetooth",128,NULL,1,NULL); // 3
  xTaskCreate(Task2IR,"2IR",128,NULL,1,NULL); // 4
  xTaskCreate(TaskSoil,"Soil",128,NULL,1,NULL); // 5
  vTaskStartScheduler();
}

// Empty Loop
void loop() {}

// ------------------------- Tasks -------------------------

void TaskPassword(void *pvParameters) // Task 1
{
while(1){
    // Start Fpassword();
    if( (ULTRA()<=50) )
    {
      Fpassword();
    }
    else
    {
      lcd.clear();
      lcd.setCursor(0,0);
    }
    // End Fpassword
    
}}
void TaskMQ2(void *pvParameters) // Task 2
{
  while(1)
  {
    MQ2();
    }
}
void TaskBluetooth(void *pvParameters) // Task 3
{
  while(1)
  {
    Bluetooth();
    }
}
void Task2IR(void *pvParameters) // Task 4
{
  while(1)
  {
    if(digitalRead(ir0pin)==1)
    {
      IRMain();
      }
      
    if(digitalRead(ir1pin)==1)
    {
      digitalWrite(led1pin,1);
      }
    
    if(digitalRead(ir2pin)==1)
    {
      digitalWrite(led2pin,1);
      }
    
  }
}
void TaskSoil(void *pvParameters) // Task 5
{
  while(1)
  {
    SoilM();
  }
}

/*
 * if( millis()-t1>=2000 )
  {
    t1=millis();
    // Function
    }
  else if( millis()-t2>=2000 )
  {
    t2=millis();
    // Function
    }
  else if( millis()-t3>=2000 )
  {
    t2=millis();
    // Function
    }
   else if( millis()-t4>=2000 )
  {
    t2=millis();
    // Function
    }
   else if( millis()-t5>=2000 )
  {
    t2=millis();
    // Function
    }
   else if( millis()-t6>=2000 )
  {
    t2=millis();
    // Function
    }
   else if( millis()-t7>=2000 )
  {
    t2=millis();
    // Function
    }
   else if( millis()-t8>=2000 )
  {
    t2=millis();
    // Function
    }
   else if( millis()-t9>=2000 )
  {
    t2=millis();
    // Function
    }
    else if( millis()-t10>=2000 )
  {
    t2=millis();
    // Function
    }
    
 */

/*
1- lcd
2- ultrasonic
3- keypad
4- MQ-2
5- IR
6- Soil
7- Bluetooth
8- Servo
9- Fan
 */
