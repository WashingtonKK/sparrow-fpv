#include <Servo.h>
Servo esc1;
//Servo esc2;
//Servo esc3;
//Servo esc4;


int roll;
int throttle;
int yaw;
int pitch;

void setup() {
  Serial.begin(9600);
  
  esc1.attach(5);
  //esc2.attach(6);
  //esc3.attach(7);
  //esc4.attach(8);


  Serial.println("1");
  delay(1000);
 
  Serial.println("2");
  delay(1000);

  Serial.println("3");
  delay(1000);

  Serial.println("4");
  delay(1000);

  Serial.println("5");
  delay(1000);

  Serial.println("Connect now");
  delay(1000);
  
  esc1.writeMicroseconds(2350);
  //esc2.writeMicroseconds(2350);
  //esc3.writeMicroseconds(2350);
  //esc4.writeMicroseconds(2350);

  delay(2000);
  
  esc1.writeMicroseconds(1550);
  //esc2.writeMicroseconds(1550);
  //esc3.writeMicroseconds(1550);
  //esc4.writeMicroseconds(1550);
  
}

void loop() {
  roll = pulseIn(4, HIGH);
  throttle = pulseIn(9, HIGH);
  pitch = pulseIn(13, HIGH);
  yaw = pulseIn(12, HIGH);
  //Serial.print("Roll---");
  //Serial.println(roll) ;
  //Serial.print("pitch--");
  //Serial.println(pitch);
  //Serial.print("Yaw--");
  //Serial.println(yaw);
  //Serial.print("throttle--");
  //Serial.println(throttle);
  //delay(1000);

  pitch = pitch + 530;

   if ((pitch) < 1350) 
     pitch = 1350;

    if ((pitch) > 2450)
      pitch = 2300;

     

    esc1.writeMicroseconds(pitch);
    //esc2.writeMicroseconds(pitch);
    //esc3.writeMicroseconds(pitch);
    //esc4.writeMicroseconds(pitch);

    Serial.println(pitch);

}
