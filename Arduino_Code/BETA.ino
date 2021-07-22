#define enA 7
#define in1 6
#define in2 5
#define enB 2
#define in3 4
#define in4 3
#define wtrSens 11
#define lightRED 10
#define lightBLU 12
#define vMotorF A0
#define vMotorB A1
int xAxis, yAxis;
int  x = 0;
int  y = 0;
int  A;
int  B;
int motorSpeedA = 0;
int motorSpeedB = 0;
const int pingPin = 9;
const int echoPin = 8;
const int sensorMin = 0;
const int sensorMax = 1024;
void setup() {
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(lightRED, OUTPUT);
  Serial.begin(38400);
}
void loop() {
//CONTROL CODE
  xAxis = 510;
  yAxis = 510;
  while (Serial.available() >= 2) {
    x = Serial.read();
    delay(10);
    y = Serial.read();
  }
  delay(10);
  
  if (x > 60 & x < 220) {
    xAxis = map(x, 220, 60, 1023, 0);
  }
  if (y > 60 & y < 220) {
    yAxis = map(y, 220, 60, 0, 1023);
  }
  if (yAxis < 470) {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    motorSpeedA = map(yAxis, 470, 0, 0, 255);
    motorSpeedB = map(yAxis, 470, 0, 0, 255);
  }
  else if (yAxis > 550) {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    motorSpeedA = map(yAxis, 550, 1023, 0, 255);
    motorSpeedB = map(yAxis, 550, 1023, 0, 255);
  }
  else {
    motorSpeedA = 0;
    motorSpeedB = 0;
  }
  if (xAxis < 470) {
    int xMapped = map(xAxis, 470, 0, 0, 255);
    motorSpeedA = motorSpeedA - xMapped;
    motorSpeedB = motorSpeedB + xMapped;
    if (motorSpeedA < 0) {
      motorSpeedA = 0;
    }
    if (motorSpeedB > 255) {
      motorSpeedB = 255;
    }
  }
  if (xAxis > 550) {
    int xMapped = map(xAxis, 550, 1023, 0, 255);
    motorSpeedA = motorSpeedA + xMapped;
    motorSpeedB = motorSpeedB - xMapped;
    if (motorSpeedA > 255) {
      motorSpeedA = 255;
    }
    if (motorSpeedB < 0) {
      motorSpeedB = 0;
    }
  }

  if (A == 1) {
    digitalWrite(vMotorF, HIGH);    
  }

  if (B == 1) {
    digitalWrite(vMotorB, LOW);
  }

  if (motorSpeedA < 70) {
    motorSpeedA = 0;
  }
  if (motorSpeedB < 70) {
    motorSpeedB = 0;
  }
  analogWrite(enA, motorSpeedA); // Send PWM signal to motor A
  analogWrite(enB, motorSpeedB); // Send PWM signal to motor B

//WATER SENSOR CODE
  pinMode(wtrSens, INPUT);
  if( digitalRead(wtrSens) == HIGH) {
      digitalWrite(lightBLU,HIGH);
   }else {
      digitalWrite(lightBLU,LOW);
   }

//ULTRASONIC CODE
  long duration, inches, cm;
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pingPin, LOW);

  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  cm = microsecondsToCentimeters(duration);

  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  if (cm < 20)  {
    digitalWrite(lightRED, HIGH);
    delay(1000);
    digitalWrite(lightRED, LOW);
  } else {
    digitalWrite(lightRED, LOW);
  }
  
  delay(100);
  }

  long microsecondsToCentimeters(long microseconds)
  {
  return microseconds / 29 / 2;
  }
