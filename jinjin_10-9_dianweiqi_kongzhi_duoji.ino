#include <Servo.h> // 声明调用 Servo.h 库


Servo myservo3; // 创建一个舵机对象
Servo myservo2; // 创建一个舵机对象
int potpin3 = 3;
int potpin2 = 2;
// 连接到模拟口 2
int val3;
int val2;
//变量 val 用来存储从模拟口3 读到的值
void setup() {

myservo2.attach(9);
myservo3.attach(10);
}

 

void loop() {

val2 = analogRead(potpin2); //从模拟口 0 读值，并通过val 记录

val2 = map(val2, 0, 1023, 0, 360); //通过 map 函数进行数值转换

myservo2.write(val2); // 给舵机写入角度

delay(15); // 延时 15ms 让舵机转到指定位置

val3 = analogRead(potpin3); //从模拟口 3 读值，并通过val 记录

val3 = map(val3, 0, 1023, 0, 360); //通过 map 函数进行数值转换

myservo3.write(val3); // 给舵机写入角度

delay(15); // 延时 15ms 让舵机转到指定位置
}

 
