int roll;
int throttle;
int yaw;
int pitch;

void setup() {
  Serial.begin(9600);
}

void loop() {
  roll = pulseIn(4, HIGH);
  throttle = pulseIn(9, HIGH);
  pitch = pulseIn(13, HIGH);
  yaw = pulseIn(12, HIGH);
  Serial.print("Roll---");
  Serial.println(roll) ;
  Serial.print("pitch--");
  Serial.println(pitch);
  Serial.print("Yaw--");
  Serial.println(yaw);
  Serial.print("throttle--");
  Serial.println(throttle);
  delay(1000);
}
