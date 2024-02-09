#define Trig   0
#define Echo   4
#define buzzer 27
#define motor  22
int cm;

void setup() {
  Serial.begin(9600);
  
  pinMode(buzzer, OUTPUT);
  pinMode(motor, OUTPUT);
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
  delay(100);
}

void loop() {
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  
  long ultra_time = pulseIn(Echo, HIGH);
  cm = ultra_time / 29 / 2;

  Serial.print("cm: ");
  Serial.println(cm);

  if (cm > 250) {
    // Level 1: Everything Low
    digitalWrite(motor, LOW);
    digitalWrite(buzzer, LOW);
  } 
  else if (cm > 150 && cm <= 250) {
    // Level 2: Low Vibration
    digitalWrite(motor, HIGH);
    delay(150);  // Adjust the delay for vibration intensity
    digitalWrite(motor, LOW);
    digitalWrite(buzzer, LOW);
  } 
  else if (cm >= 100 && cm <= 150) {
    // Level 3: Medium Vibration
    digitalWrite(motor, HIGH);
    delay(100); 
    digitalWrite(motor, LOW);
    digitalWrite(buzzer, LOW);
  } 
  else if (cm >= 30 && cm <= 100) {
    // Level 4: High Vibration
    digitalWrite(motor, HIGH);
    delay(50); 
    digitalWrite(motor, LOW);
    digitalWrite(buzzer, LOW);
  } 
  else {
    // Level 5: Buzzer On and High Vibration
    digitalWrite(motor, HIGH);
    digitalWrite(buzzer, HIGH);
  }

  delay(100); 
}
