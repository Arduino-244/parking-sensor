int echo = 7;
int trig = 6;
int piezo = 3;
void setup() {
  Serial.begin(9600);
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
}
void loop() {
  resetSensor();
  tone(piezo, getActualFrequency());
  delay(300);
  noTone(piezo);
  delay(500);
}
int getActualFrequency() {
  long duration = pulseIn(echo, HIGH);
  int distanceCm = duration*0.034/2;
  Serial.print(distanceCm);
  if (distanceCm < 60 && distanceCm > 50){
     return distanceCm * 20;
  }else{
    if (distanceCm <= 50 && distanceCm > 30){
         return distanceCm * 50;
    }else{
        if (distanceCm <= 30){
            return distanceCm * 80;
        }else{
            noTone(piezo);
        }
    }
  }
}
void resetSensor() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
}