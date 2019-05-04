
#include <Arduino.h>
#include <SPI.h>
#include "Adafruit_BLE.h"
#include "Adafruit_BluefruitLE_SPI.h"
#include "Adafruit_BluefruitLE_UART.h"

#include "BluefruitConfig.h"

#if SOFTWARE_SERIAL_AVAILABLE
  #include <SoftwareSerial.h>
#endif

#define FACTORYRESET_ENABLE         1
#define MINIMUM_FIRMWARE_VERSION    "0.6.6"
#define MODE_LED_BEHAVIOUR          "MODE"

int flexSensorPin0 = A0; //analog pin 0
int flexSensorPin1 = A1; //analog pin 0
int flexSensorPin2 = A2; //analog pin 0
int flexSensorPin3 = A3; //analog pin 0


// Create the bluefruit object, either software serial...uncomment these lines
/*
SoftwareSerial bluefruitSS = SoftwareSerial(BLUEFRUIT_SWUART_TXD_PIN, BLUEFRUIT_SWUART_RXD_PIN);

Adafruit_BluefruitLE_UART ble(bluefruitSS, BLUEFRUIT_UART_MODE_PIN,
                      BLUEFRUIT_UART_CTS_PIN, BLUEFRUIT_UART_RTS_PIN);
*/

/* ...or hardware serial, which does not need the RTS/CTS pins. Uncomment this line */
// Adafruit_BluefruitLE_UART ble(Serial1, BLUEFRUIT_UART_MODE_PIN);

/* ...hardware SPI, using SCK/MOSI/MISO hardware SPI pins and then user selected CS/IRQ/RST */
Adafruit_BluefruitLE_SPI ble(BLUEFRUIT_SPI_CS, BLUEFRUIT_SPI_IRQ, BLUEFRUIT_SPI_RST);

/* ...software SPI, using SCK/MOSI/MISO user-defined SPI pins and then user selected CS/IRQ/RST */
//Adafruit_BluefruitLE_SPI ble(BLUEFRUIT_SPI_SCK, BLUEFRUIT_SPI_MISO,
//                             BLUEFRUIT_SPI_MOSI, BLUEFRUIT_SPI_CS,
//                             BLUEFRUIT_SPI_IRQ, BLUEFRUIT_SPI_RST);


// A small helper
void error(const __FlashStringHelper*err) {
  Serial.println(err);
  while (1);
}

/**************************************************************************/
/*!
    @brief  Sets up the HW an the BLE module (this function is called
            automatically on startup)
*/
/**************************************************************************/



void setup(void){
 
  while (!Serial);  // required for Flora & Micro
  delay(500);

  Serial.begin(115200);
  Serial.println(F("Adafruit Bluefruit Command Mode Example"));
  Serial.println(F("---------------------------------------"));

  /* Initialise the module */
  Serial.print(F("Initialising the Bluefruit LE module: "));

  if ( !ble.begin(VERBOSE_MODE) )
  {
    error(F("Couldn't find Bluefruit, make sure it's in CoMmanD mode & check wiring?"));
  }
  Serial.println( F("OK!") );

  if ( FACTORYRESET_ENABLE )
  {
    /* Perform a factory reset to make sure everything is in a known state */
    Serial.println(F("Performing a factory reset: "));
    if ( ! ble.factoryReset() ){
      error(F("Couldn't factory reset"));
    }
  }

  /* Disable command echo from Bluefruit */
  ble.echo(false);

  Serial.println("Requesting Bluefruit info:");
  /* Print Bluefruit information */
  ble.info();

  Serial.println(F("Please use Adafruit Bluefruit LE app to connect in UART mode"));
  Serial.println(F("Then Enter characters to send to Bluefruit"));
  Serial.println();

  ble.verbose(false);  // debug info is a little annoying after this point!

  /* Wait for connection */
  while (! ble.isConnected()) {
      delay(500);
  }

  // LED Activity command is only supported from 0.6.6
  if ( ble.isVersionAtLeast(MINIMUM_FIRMWARE_VERSION) )
  {
    // Change Mode LED Activity
    Serial.println(F("******************************"));
    Serial.println(F("Change LED activity to " MODE_LED_BEHAVIOUR));
    ble.sendCommandCheckOK("AT+HWModeLED=" MODE_LED_BEHAVIOUR);
    Serial.println(F("******************************"));
  }
  
}

void loop(void){
  int angle0 = analogRead(flexSensorPin0); 
  int angle1 = analogRead(flexSensorPin1); 
  int angle2 = analogRead(flexSensorPin2); 
  int angle3 = analogRead(flexSensorPin3); 
 
  if (angle3<800 && angle2>800 && angle1>800 && angle0<900)
  {Serial.println("Horn");
  ble.print("AT+BLEUARTTX=");
  ble.println("Horn");
  delay (2000);
  }

  else if (angle3>800 && angle2>800 && angle1>800 && angle0>900)
  {Serial.println("Stop");
   ble.print("AT+BLEUARTTX=");
  ble.println("Stop");
  delay (2000);
  }

  else if (angle3<800 && angle2<800 && angle1>800 && angle0>900)
  {Serial.println("Victory");
   ble.print("AT+BLEUARTTX=");
  ble.println("Victory");
  delay (2000);

  }

  else if (angle3<800 && angle2>800 && angle1>800 && angle0>900)
  {Serial.println("One");
   ble.print("AT+BLEUARTTX=");
  ble.println("One");
  delay (2000);

  }

   else if (angle3<800 && angle2<800 && angle1<800 && angle0>900)
  {Serial.println("Three");
   ble.print("AT+BLEUARTTX=");
  ble.println("Three");
  delay (2000);

  }

  else if (angle3>800 && angle2>800 && angle1<800 && angle0<900)
  {Serial.println("Coffee");
  ble.print("AT+BLEUARTTX=");
  ble.println("Coffee");
  delay (2000);

  }

  else if (angle3>800 && angle2<800 && angle1<800 && angle0>900)
  {Serial.println("Check");
  ble.print("AT+BLEUARTTX=");
  ble.println("Check");
  delay (2000);

  }

  else if (angle3>800 && angle2<800 && angle1<800 && angle0<900)
  {Serial.println("This");
  ble.print("AT+BLEUARTTX=");
  ble.println("This");
  delay (2000);

  }

  else if (angle3<800 && angle2>800 && angle1<800 && angle0<900)
  {Serial.println("Out");
  ble.print("AT+BLEUARTTX=");
  ble.println("Out");
  delay (2000);

  }

  else if (angle3<800 && angle2<800 && angle1>800 && angle0<900)
  {Serial.println("Thank");
  ble.print("AT+BLEUARTTX=");
  ble.println("Thank");
  delay (2000);

  }

   else if (angle3>800 && angle2>800 && angle1<800 && angle0>900)
  {Serial.println("You");
  ble.print("AT+BLEUARTTX=");
  ble.println("You");
  delay (2000);

  }

   else if (angle3>800 && angle2>800 && angle1>800 && angle0<900)
  {Serial.println("Pee");
  ble.print("AT+BLEUARTTX=");
  ble.println("Pee");
  delay (2000);

  }

  else if (angle3>800 && angle2<800 && angle1>800 && angle0>900)
  {Serial.println("Phak");
  ble.print("AT+BLEUARTTX=");
  ble.println("Phak");
  delay (2000);

  }

   else 
  {Serial.println("No output");
   ble.print("AT+BLEUARTTX=");
  ble.println("No output");
  delay (2000);

  }
  }
