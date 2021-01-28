unsigned long s0;//计时起始
unsigned long sc;//当前计时
boolean flg=false; //可计数标志
int c=0; //敲击计数器

//初始化函数：
void setup() {
  Serial.begin(9600);  
  while (!Serial) {
     // wait for serial port to connect. Needed for native USB port only
  }
}

//主函数
void loop() {     
     int A0_v=analogRead(A0);//读取模拟信号
     sc=millis(); //计时    
     //digitalWrite(7,LOW);//

/*
    if (digitalRead(8)==HIGH){
        Serial.print('H');
     }else{
        Serial.print('L'); 
     }
*/     
     //信号达到阈值时，开始翻转FLG：
     if (A0_v>1000 and flg==false){
        flg=true;
        s0=millis();
        Serial.println(s0); 
        delay(100);         
     }

     //信号达到阈值，且LFG为真，且在1秒之内时：---累计C
     if ((A0_v>1000) and (flg==true) and (sc-s0<1000)){
         c++;
         Serial.println(c);
         delay(100);    
     }
     
     //超时的，放弃：
     if(sc-s0>900 and flg==true  and digitalRead(8)==HIGH){
        flg=false;
        c=0;
        s0= millis();
        Serial.write('x'); 
        digitalWrite(5,LOW);    
     }
     
     //正好在三次时：
     if(c==3 and digitalRead(8)==LOW){
        flg=false;
        c=0;
        digitalWrite(5,HIGH);
        Serial.write('#');
        delay(5000); 
        digitalWrite(7,LOW);
     }
}

