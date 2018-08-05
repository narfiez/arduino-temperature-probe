#include <Time.h>
#include <TimeLib.h>
#include <SD.h>

const int CS_PIN = 10;
const int POW_PIN = 8;

int refreshrate = 5000;

bool start = true;

float temp;
void setup()

{

  Serial.begin(9600);

  //Initialize SD Card
  Serial.println("Initializing Card");
  pinMode(CS_PIN, OUTPUT);
  pinMode(POW_PIN, OUTPUT);
  digitalWrite(POW_PIN, HIGH);
  if (!SD.begin(CS_PIN)) {
    Serial.println("Card Failure");
    return;
  }
  Serial.println("Card Ready");

}

void loop()

{
  File dataFile = SD.open("log.csv", FILE_WRITE);
  float temp;
  float tempAdj;

  float emf;

  int raw = analogRead(A0);

  float Vout = raw * (5.0 / 1023.0);
  temp = Vout/0.005;

  
  emf=((Vout*1000)-1.25)/122.4;
  tempAdj = (25.08355 * emf) + (0.07860106 * pow(emf,2))-(0.2503131*pow(emf,3))+(0.08315270*pow(emf,4))-(0.01228034 *pow(emf,5))+(0.0009804036*pow(emf,6))-(0.0000441303*pow(emf,7))+(0.000001057734*pow(emf,8))-(0.00000001052755*pow(emf,9));
  // tempAdj: The adjusted temperature to compensate for the non-lionearity of the sensor
  
  temp = temp-250;
  tempAdj=tempAdj-250;


  long timeStamp = millis();

  if (start) {
    dataFile.println();
    dataFile.println("New startup");
    dataFile.println("-----------");
    dataFile.println("Time,Temperature");
  }
  start=false;
  if (dataFile) {

    if(hour()<10)
    {
      dataFile.print("0");
      Serial.print("0");
    }
    dataFile.print(hour());
    dataFile.print(":");
    Serial.print(hour());
    Serial.print(":");
    if(minute()<10)
    {
      dataFile.print("0");
      Serial.print("0");
    }
    dataFile.print(minute());
    dataFile.print(":");
    Serial.print(minute());
    Serial.print(":");
    if(second()<10)
    {
      dataFile.print("0");
      Serial.print("0");
    }
    dataFile.print(second());

    dataFile.print(",");
    // A comma to delimit the cells in Excel
    dataFile.print(tempAdj-25);
    //The specific Arduino nano seemed to read the analog voltage slightly wrong, causing about 25 degrees C shift. Cause unknown.
    
    dataFile.println();
    //dataFile.println(" degrees Celsius");
    Serial.print(second());
    Serial.print("\t");
    //Serial.print(", Temp: ");
    Serial.print(tempAdj-25);
    Serial.println();
    //Serial.println(" degrees Celsius");
    dataFile.close();
  }

  else {
    Serial.println("Couldn't open log file");
  }

  delay(2000);
}

