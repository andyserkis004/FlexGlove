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

  
  if (angle3<800 && angle2>800 && angle1>800 && angle0<900)
  {Serial.println("Horn");
  delay (5000);
  }

  else if (angle3>800 && angle2>800 && angle1>800 && angle0>900)
  {Serial.println("Stop");
   delay (5000);
  }

  else if (angle3<800 && angle2<800 && angle1>800 && angle0>900)
  {Serial.println("Victory");
   delay (5000);
  }

  else if (angle3<800 && angle2>800 && angle1>800 && angle0>900)
  {Serial.println("One");
   delay (5000);
  }

   else if (angle3<800 && angle2<800 && angle1<800 && angle0>900)
  {Serial.println("Three");
   delay (5000);
  }

  else if (angle3>800 && angle2>800 && angle1<800 && angle0<900)
  {Serial.println("Coffee");
   delay (5000);
  }

   else 
  {Serial.println("No output");
   delay (5000);
  }

  Serial.println();
}
