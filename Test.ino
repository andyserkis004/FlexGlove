int flexSensorPin0 = A0; //analog pin 0
int flexSensorPin1 = A1; //analog pin 0
int flexSensorPin2 = A2; //analog pin 0
int flexSensorPin3 = A3; //analog pin 0


void setup(){
  Serial.begin(9600);
}

void loop(){
  int angle0 = analogRead(flexSensorPin0); 
  int angle1 = analogRead(flexSensorPin1); 
  int angle2 = analogRead(flexSensorPin2); 
  int angle3 = analogRead(flexSensorPin3); 

  
  Serial.println(angle0);
  delay (1000);
  Serial.println(angle1);
  delay (1000);
  Serial.println(angle2);
  delay (1000);
  Serial.println(angle3);
  delay (1000);
  Serial.println("-----------------");
  delay (1000);

  Serial.println();
}
