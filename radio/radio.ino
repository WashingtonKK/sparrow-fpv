int ch1;
int ch2;
int ch3;
int ch4;

void setup() {
  Serial.begin(9600);
}

void loop() {
  //ch1 = pulseIn(4, HIGH);
  //ch2 = pulseIn(9, HIGH);
  //ch3 = pulseIn(13, HIGH);
  ch4 = pulseIn(12, HIGH);
  //Serial.print("Roll");
  //Serial.println(ch1);
  //Serial.print("pitch");
  //Serial.println(ch2);
  //Serial.print("Yaw");
  //Serial.println(ch3);
  //Serial.print("throttle");
  Serial.println(ch4);
}
