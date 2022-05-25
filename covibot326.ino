// Black Line Follower

int IR1 = 19;       //Right sensor
int IR2 = 23;       //left Sensor
int MotorAip1 = 12;
int MotorAip2 = 14;
int MotorBip1 = 26;
int MotorBip2 = 25;
int buzzer = 18;

//ultrasonic
const int trigPin1 = 13;
const int echoPin1 = 27;
const int trigPin2 = 22;
const int echoPin2 = 5;

unsigned long duration1;
unsigned long distance1;
unsigned long duration2;
unsigned long distance2;

//buzzer


void setup()
{
  Serial.begin(115200);
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(MotorAip1, OUTPUT);
  pinMode(MotorAip2, OUTPUT);
  pinMode(MotorBip1, OUTPUT);
  pinMode(MotorBip2, OUTPUT);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(buzzer, OUTPUT);
}

void automatic()                    //detects obstacles from front
{
  digitalWrite(trigPin1, LOW);
  delay(10);
  digitalWrite(trigPin1, HIGH);
  delay(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  //distance = (duration) / 58.200;
  distance1 = duration1 * 0.034 / 2;
  Serial.print("Distance1 ");
  Serial.println(distance1);
  delay(300);
  if (distance1 < 15 )
  {
    buzzeron();
    Serial.println("Obstacle at Front.");
  }
  else
  {
    line_follower();
  }
}

void ultrasonic2()                      //detects obstacles from left
{
  digitalWrite(trigPin2, LOW);
  delay(10);
  digitalWrite(trigPin2, HIGH);
  delay(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  //distance = (duration) / 58.200;
  distance2 = duration2 * 0.034 / 2;
  Serial.print("Distance2 ");
  Serial.println(distance2);
  delay(300);
  if (distance2 < 15 )
  {
    buzzeron();
    Serial.println("Alert..Rule is broken");
  }
}

void forward()
{
  digitalWrite(MotorAip1, HIGH);
  digitalWrite(MotorAip2, LOW);
  digitalWrite(MotorBip1, HIGH);
  digitalWrite(MotorBip2, LOW);
  delay(2000);
  digitalWrite(MotorAip1, LOW);
  digitalWrite(MotorAip2, LOW);
  digitalWrite(MotorBip1, LOW);
  digitalWrite(MotorBip2, LOW);
  delay(2000);
}

void backward()
{
  digitalWrite(MotorAip1, LOW);
  digitalWrite(MotorAip2, HIGH);
  digitalWrite(MotorBip1, LOW);
  digitalWrite(MotorBip2, HIGH);
  delay(2000);
  digitalWrite(MotorAip1, LOW);
  digitalWrite(MotorAip2, LOW);
  digitalWrite(MotorBip1, LOW);
  digitalWrite(MotorBip2, LOW);
  delay(2000);
}


void left()
{
  digitalWrite(MotorAip1, LOW);
  digitalWrite(MotorAip2, HIGH);
  digitalWrite(MotorBip1, HIGH);
  digitalWrite(MotorBip2,LOW );
  delay(2000);
  digitalWrite(MotorAip1, LOW);
  digitalWrite(MotorAip2, LOW);
  digitalWrite(MotorBip1, LOW);
  digitalWrite(MotorBip2, LOW);
  delay(2000);
}

void right()
{
  digitalWrite(MotorAip1, HIGH);
  digitalWrite(MotorAip2, LOW);
  digitalWrite(MotorBip1, LOW);
  digitalWrite(MotorBip2, HIGH);
  delay(2000);
  digitalWrite(MotorAip1, LOW);
  digitalWrite(MotorAip2, LOW);
  digitalWrite(MotorBip1, LOW);
  digitalWrite(MotorBip2, LOW);
  delay(2000);
}

void stop()
{
  digitalWrite(MotorAip1, LOW);
  digitalWrite(MotorAip2, LOW);
  digitalWrite(MotorBip1, LOW);
  digitalWrite(MotorBip2, LOW);
  delay(2000);

}
void buzzeron()
{
  digitalWrite(buzzer, HIGH);
  delay(500);
  digitalWrite(buzzer, LOW);
  delay(500);
}

void line_follower()
{
  if (digitalRead(IR1) == LOW && digitalRead(IR2) == LOW) //IR not on black line
  {

    forward();
    ultrasonic2();

  }

}



void loop()
{
automatic();
}
