#include <Servo.h>
Servo esc1;
Servo esc2;
Servo esc3;
Servo esc4;


void setup () {
  Serial.begin(9600);
  esc1.attach(2);
  esc2.attach(0);
  esc3.attach(14);
  esc4.attach(13);
  
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
  esc2.writeMicroseconds(2350);
  esc3.writeMicroseconds(2350);
  esc4.writeMicroseconds(2350);

  delay(2000);
  
  esc1.writeMicroseconds(1550);
  esc2.writeMicroseconds(1550);
  esc3.writeMicroseconds(1550);
  esc4.writeMicroseconds(1550);
  }


void loop () {
    esc1.writeMicroseconds(1850);
    esc2.writeMicroseconds(1850);
    esc3.writeMicroseconds(1850);
    esc4.writeMicroseconds(1850);

    delay (5000);
    
  
    esc1.writeMicroseconds(1550);
    esc2.writeMicroseconds(1550);
    esc3.writeMicroseconds(1550);
    esc4.writeMicroseconds(1550);

    delay (5000);

    esc1.writeMicroseconds(1850);
    esc2.writeMicroseconds(1850);
    esc3.writeMicroseconds(1850);
    esc4.writeMicroseconds(1850);

    delay (5000);
    
    esc1.writeMicroseconds(2050);
    esc2.writeMicroseconds(2050);
    esc3.writeMicroseconds(2050);
    esc4.writeMicroseconds(2050);

    delay (5000); 

    esc1.writeMicroseconds(2350);
    esc2.writeMicroseconds(2350);
    esc3.writeMicroseconds(2350);
    esc4.writeMicroseconds(2350);

    delay (5000);
    
  }
