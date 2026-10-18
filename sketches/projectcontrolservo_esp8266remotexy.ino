// you can enable debug logging to Serial at 115200
//#define REMOTEXY__DEBUGLOG    

// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__WIFI_POINT
#include <ESP8266WiFi.h> 

#define REMOTEXY_WIFI_SSID "YOUR_WIFI_SSID" //e.g. RA
#define REMOTEXY_WIFI_PASSWORD "YOUR_WIFI_PASSWORD" //e.g. pesendulu123
#define REMOTEXY_SERVER_PORT 6377
#include <RemoteXY.h>

#pragma pack(push, 1)  
uint8_t RemoteXY_CONF[] =   // 82 bytes
  { 255,4,0,0,0,75,0,19,0,0,0,82,79,66,79,84,95,82,69,77,
  79,84,69,0,31,2,106,200,200,84,1,1,4,0,4,20,50,7,86,37,
  3,13,73,0,2,26,4,41,45,7,86,77,5,13,71,0,2,26,4,61,
  45,7,86,115,4,14,72,0,2,26,4,85,47,7,86,160,4,14,72,0,
  2,26 };
  
struct {
  // input variables
  int8_t slider_01; // from 0 to 100
  int8_t slider_02; // from 0 to 100
  int8_t slider_03; // from 0 to 100
  int8_t slider_04; // from 0 to 100

  // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0
} RemoteXY;   
#pragma pack(pop)

#include <Servo.h> 
Servo myservo;

// FIXED: Changed D1 to the absolute GPIO number (GPIO 5 corresponds to D1 on NodeMCU)
const int servoPin = 5; 

#define SERVOMIN  500
#define SERVOMAX  2500

int pos = 0;
int pulse = 0;      

void setup() 
{
  // FIXED: Initialized Serial communication protocol for logging parameters
  Serial.begin(115200); 
  
  RemoteXY_Init(); 
  myservo.attach(servoPin);
  
  // Set default initial midpoint position for safety under load
  RemoteXY.slider_01 = 50;
}

void loop() 
{ 
  RemoteXY_Handler();
  
  int ms = RemoteXY.slider_01;   
  pos = map(ms, 0, 100, 0, 180); 
  pulse = map(pos, 0, 180, SERVOMIN, SERVOMAX);
  
  // Clean real-time telemetry output to serial monitor
  Serial.print("Servo Pulse Output: ");
  Serial.println(pulse);
  
  myservo.writeMicroseconds(pulse);    
  
  // Small delay to prevent crashing the ESP8266 watchdog timer
  delay(10); 
}
