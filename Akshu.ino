#include <Servo.h>


Servo servo1;
int trigPin = 11;
int echoPin = 10;
float distance, duration;

void setup() 
{
  Serial.begin(9600);
  servo1.attach(9); 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  servo1.write(0);
}

void ultra_sonic()

{
  digitalWrite(trigPin, LOW);

  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);

  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = (duration*.0343)/2;
}

void loop()
{
  ultra_sonic();
  delay(1000);
  if(distance <= 5)
  {
    servo1.write(30);
  }
  else if(distance <= 10)
  {
    servo1.write(60);
  }
  else if(distance <= 15)
  {
    servo1.write(90);
  }
  else if(distance <= 20)
  {
    servo1.write(120);
  }
  else if(distance <= 25)
  {
    servo1.write(150);
  }
  else
  {
      servo1.write(180);
  }
  
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(3000);
  servo1.write(0);
  delay(1000);
}
