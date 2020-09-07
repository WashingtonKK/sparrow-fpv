#include <Servo.h>
#include <MPU6050_tockn.h>
#include <Wire.h>


Servo esc1;
Servo esc2;
Servo esc3;
Servo esc4;

MPU6050 mpu6050(Wire);

const int esc = 1500;   //1950

int ua, ub, uc, ud;

int esca = 1950;
int escb = 1950;
int escc = 1950;
int escd = 1950;

int kpa = 0;
int kpb = 10;
int kpc = 0;
int kpd = 10;

int kia = 0;
int kib = 0;
int kic = 0;
int kid = 0;

int kda = 0;
int kdb = 0;
int kdc = 0;
int kdd = 0;


float angleX, angleY, angleZ;
int setpoint = 0;
int errorX = 0;
int errorY = 0;
int errorZ = 0;
int prevTime = 0;
int currentTime = 0;
int Time;

int cumErrorX, cumErrorY, cumErrorZ; 
int rateErrorX, rateErrorY, rateErrorZ;
int lastAngleX, lastAngleY, lastAngleZ;


//int pitch = 1700;

void setup() {
  Serial.begin(9600);
  
  esc1.attach(4);
  esc2.attach(5);
  esc3.attach(6);
  esc4.attach(7);

  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);


  
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

void loop() {
//  roll = pulseIn(4, HIGH);
//  throttle = pulseIn(9, HIGH);
//  pitch = pulseIn(13, HIGH);
//  yaw = pulseIn(12, HIGH);

    mpu6050.update();
    do {
      currentTime = 0;
    } while (false);
    currentTime = millis();
    Time = currentTime - prevTime;

    if (Time > 150) 
      Time = 150;

    angleX = mpu6050.getAngleX(); 
    angleY = mpu6050.getAngleY();
    angleZ = mpu6050.getAngleZ();
    
    errorX = 0  -  angleX;
    errorY = 0  -  angleY;
    errorZ = 0  -  angleZ;

    if (errorX <= 1.50  && errorX >= -1.50 && errorY <= 1.50  && errorY >= -1.50 && errorZ <= 1.50  && errorZ >= -1.50) {
      esca = 1650;
      escb = 1650;
      escc = 1650;
      escd = 1650;
    }




//    if (errorX < 0) {  //positive roll
//
//    }
//
//    if (errorX > 0) {  //negative roll
//      
//    }
//    if (errorY < 0) {  //positive pitch
//      
//    }
//    if (errorY > 0) {  //negative pitch
//      
//    }
//    if (errorZ < 0) {  //positive yaw
//      
//    }
//    if (errorZ > 0) {  //negative yaw
//      
//    }



//Summing up the proportional intergral and derivative constants

      cumErrorX += angleX*Time ;
      cumErrorY += angleY*Time ;
      cumErrorZ += angleZ*Time ;

      rateErrorX += (angleX - lastAngleX)/Time;
      rateErrorY += (angleY - lastAngleY)/Time;
      rateErrorZ += (angleZ - lastAngleZ)/Time;
            
      ub = ( (kpb*angleX) + (kib*cumErrorX) + (kdb*rateErrorY) + (kpb*angleY) + (kib*cumErrorY) + (kdb*rateErrorY) + (kpb*angleZ) + (kib*cumErrorY) + (kdb*rateErrorZ) )/2;
//    ud = ( (kpd*angleX) + (kid*cumErrorX) + (kdd*rateErrorX) + (kpd*angleY) + (kid*cumErrorY) + (kdd*rateErrorY) + (kpd*angleZ) + (kid*cumErrorY) + (kdd*rateErrorZ) )/2;
      ud = ub;
      ua = -1*ud;
      uc = -1*ub;


      
      

    
//Setting the limits of the pid    
//    if (ua < -450) {  //positive roll
//      ua = 450; 
//    }
//
//    if (ua > 450) {  //negative roll
//      ua = 450;
//    }
    if (ub < -450) {  //positive pitch
      ub = -450;
    }
    if (ub > 450) {  //negative pitch
      ub = 450;
    }
//    if (uc < -450) {  //positive yaw
//      uc = -450;
//    }
//    if (uc > 450) {  //negative yaw
//      uc = 450;
//    }

//    if (ud < -450) {  //positive yaw
//      ud = -450;
//    }
//    if (ud > 450) {  //negative yaw
//      ud = 450;
//    }
    
    esc1.writeMicroseconds(esca + ua + ub);
    esc2.writeMicroseconds(escb + ua + (-1*ua));
    esc3.writeMicroseconds(escc + (-1*ua) + ub);
    esc4.writeMicroseconds(escd + (-1*ua) + (-1*ua));

    prevTime = currentTime;
    
    lastAngleX = angleX;
    lastAngleY = angleY;
    lastAngleZ = angleZ;

    Serial.println("ua");
    Serial.println(ua);
    Serial.println(ub);
    Serial.println(uc);
    Serial.println(ud);
    Serial.println("Constants");
    Serial.println(cumErrorX);
    Serial.println(rateErrorY);
    Serial.println(cumErrorY);
    Serial.println(cumErrorZ);
    Serial.println(rateErrorX);
    Serial.println(rateErrorZ);
    Serial.println("angles");
    Serial.println(angleX);
    Serial.println(angleY);
    Serial.println(angleZ);
    Serial.println("Time");
    Serial.println(Time);
    
    
    

}
