
const int FLEX_PIN0 = A0; // Pin connected to voltage divider output
const int FLEX_PIN1 = A1;
const int FLEX_PIN2 = A2;
const int FLEX_PIN3 = A3;

// Measure the voltage at 5V and the actual resistance of your
// 47k resistor, and enter them below:
const float VCC = 4.98; // Measured voltage of Ardunio 5V line
const float R_DIV = 10000.0; // Measured resistance of 3.3k resistor

// Upload the code, then try to adjust these values to more
// accurately calculate bend degree.
const float STRAIGHT_RESISTANCE = 37300.0; // resistance when straight
const float BEND_RESISTANCE = 48800.0; // resistance at 90 deg

void setup() 
{
  Serial.begin(9600);
  pinMode(FLEX_PIN0, INPUT);
  pinMode(FLEX_PIN1, INPUT);
  pinMode(FLEX_PIN2, INPUT);
  pinMode(FLEX_PIN3, INPUT);
}

void loop() 
{
  // Read the ADC, and calculate voltage and resistance from it
  int flexADC0 = analogRead(FLEX_PIN0);
  float flexV0 = flexADC0 * VCC / 1023.0;
  float flexR0 = R_DIV * (VCC / flexV0 - 1.0);
  Serial.println("Resistance: " + String(flexR0) + " ohms");

  // Use the calculated resistance to estimate the sensor's
  // bend angle:
  float angle0 = map(flexR0, STRAIGHT_RESISTANCE, BEND_RESISTANCE,
                   0, 90.0);
  Serial.println("Bend0: " + String(angle0) + " degrees");

  int flexADC1 = analogRead(FLEX_PIN1);
  float flexV1 = flexADC1 * VCC / 1023.0;
  float flexR1 = R_DIV * (VCC / flexV1 - 1.0);
  Serial.println("Resistance: " + String(flexR1) + " ohms");

  // Use the calculated resistance to estimate the sensor's
  // bend angle:
  float angle1 = map(flexR1, STRAIGHT_RESISTANCE, BEND_RESISTANCE,
                   0, 90.0);
  Serial.println("Bend1: " + String(angle1) + " degrees");

  int flexADC2 = analogRead(FLEX_PIN2);
  float flexV2 = flexADC2 * VCC / 1023.0;
  float flexR2 = R_DIV * (VCC / flexV2 - 1.0);
  Serial.println("Resistance: " + String(flexR2) + " ohms");

  // Use the calculated resistance to estimate the sensor's
  // bend angle:
  float angle2 = map(flexR2, STRAIGHT_RESISTANCE, BEND_RESISTANCE,
                   0, 90.0);
  Serial.println("Bend2: " + String(angle2) + " degrees");

  int flexADC3 = analogRead(FLEX_PIN3);
  float flexV3 = flexADC3 * VCC / 1023.0;
  float flexR3 = R_DIV * (VCC / flexV3 - 1.0);
  Serial.println("Resistance: " + String(flexR3) + " ohms");

  // Use the calculated resistance to estimate the sensor's
  // bend angle:
  float angle3 = map(flexR3, STRAIGHT_RESISTANCE, BEND_RESISTANCE,
                   0, 90.0);
  Serial.println("Bend3: " + String(angle3) + " degrees");

  
  if (angle3<400 && angle2>0 && angle1>150 && angle0<150)
  {Serial.println("Horn");
  }

  else if (angle3>400 && angle2>0 && angle1>150 && angle0>150)
  {Serial.println("Stop");
  }

  else if (angle3>400 && angle2>0 && angle1<150 && angle0<150)
  {Serial.println("Victory");
  }

  else if (angle3>400 && angle2>0 && angle1>150 && angle0<150)
  {Serial.println("One");
  }

   else if (angle3>400 && angle2<0 && angle1<150 && angle0<150)
  {Serial.println("Three");
  }

  else if (angle3<400 && angle2<0 && angle1>150 && angle0<150)
  {Serial.println("Coffee");
  }

  
  else 
  {Serial.println("No output");
  }

  Serial.println();

  delay(500);
}
