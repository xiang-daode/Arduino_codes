#include <Servo.h> // 声明调用 Servo.h 库

Servo myservo1; // 创建一个舵机对象
Servo myservo2; // 创建一个舵机对象
Servo myservo3; // 创建一个舵机对象
Servo myservo4; 
int potpin1= 1; // 连接到模拟口 1
int potpin2 = 2; // 连接到模拟口 2
int potpin3 = 3; // 连接到模拟口 3
int potpin4 = 4;
int val1; //变量 val 用来存储从模拟口 1 读到的值
int val2; //变量 val 用来存储从模拟口 2 读到的值
int val3; //变量 val 用来存储从模拟口3 读到的值
int val4;
void setup() {
myservo4.attach(12);
myservo1.attach(8); // 将引脚 9 上的舵机与声明的舵机对象连接起来
myservo2.attach(9);
myservo3.attach(10);
}

 

void loop() {

val1 = analogRead(potpin1); //从模拟口 0 读值，并通过val 记录

val1 = map(val1, 0, 1023, 0, 360); //通过 map 函数进行数值转换

myservo1.write(val1); // 给舵机写入角度
delay(10); // 延时 15ms 让舵机转到指定位置
val2 = analogRead(potpin2); //从模拟口 0 读值，并通过val 记录

val2 = map(val2, 0, 1023, 0, 360); //通过 map 函数进行数值转换

myservo2.write(val2); // 给舵机写入角度

delay(10); // 延时 15ms 让舵机转到指定位置
val3 = analogRead(potpin3); //从模拟口 0 读值，并通过val 记录

val3 = map(val3, 0, 1023, 0, 360); //通过 map 函数进行数值转换

myservo3.write(val3); // 给舵机写入角度

delay(10); // 延时 15ms 让舵机转到指定位置
val4 = analogRead(potpin4); //从模拟口 0 读值，并通过val 记录

val4 = map(val4, 0, 1023, 0, 90); //通过 map 函数进行数值转换

myservo4.write(val4); // 给舵机写入角度

delay(15); // 延时 15ms 让舵机转到指定位置
}

 
