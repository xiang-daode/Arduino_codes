/*
 IRrecvDemo
 红外控制，接收红外命令控制板载LED灯亮灭
 项目/加载库/管理库中，搜索 : IRremote 2.2.3
 红外管接入3号管脚,
 LED有8个,分别接入11,12,13,4,5,6,7,8号管脚
 */

#include <IRremote.h>

int RECV_PIN = 3;
long irKey[10];
int pinLED[10];
IRrecv irrecv(RECV_PIN);
decode_results results;
    /*
    IR  codeHex  LED_Pin
    0:  FF6897   All off
    1:  FF30CF  11
    2:  FF18E7  12
    3:  FF7A85  13
    4:  FF10EF  4
    5:  FF38C7  5
    6:  FF5AA5  6
    7:  FF42BD  7
    8:  FF4AB5  8
    9:  FF52AD  All on 
   */

void setup()
{
    //Array for IR_keys:
    irKey[0]=0xFF6897;
    irKey[1]=0xFF30CF;
    irKey[2]=0xFF18E7;
    irKey[3]=0xFF7A85;
    irKey[4]=0xFF10EF;
    irKey[5]=0xFF38C7;
    irKey[6]=0xFF5AA5;
    irKey[7]=0xFF42BD;
    irKey[8]=0xFF4AB5;
    irKey[9]=0xFF52AD;
    //Array for LED pins:    
    pinLED[0]=0;  
    pinLED[1]=11;  
    pinLED[2]=12;  
    pinLED[3]=13;  
    pinLED[4]=4;  
    pinLED[5]=5;  
    pinLED[6]=6;    
    pinLED[7]=7; 
    pinLED[8]=8;  
    pinLED[9]=9; 
     
    Serial.begin(9600);
    irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
   
    //IR_key= 0,All LED  off
   if (results.value == irKey[0]) 
    {
      for(int i=1;i<=8;i++){
         digitalWrite(pinLED[i],LOW);
      }
    }
    
   //IR_key= 9,All LED  on
   if (results.value == irKey[9]) 
    {
      for(int i=1;i<=8;i++){
         digitalWrite(pinLED[i],HIGH);
      }
    }

    //IR_key= 1,...,8, pinLED[i]=on: 
   for(int i=1;i<=8;i++){ 
      if (results.value == irKey[i]) 
      {
        digitalWrite(pinLED[i], HIGH);
      }
   }
  
    irrecv.resume(); // Receive the next value
  }  
  delay(100);
}




