#include <SD.h>
#include <SPI.h>
#include <string.h>
#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <MPU6050.h>
#include <I2Cdev.h>

MPU6050 accelgyro;
TinyGPSPlus gps;
SoftwareSerial mySerial(9, 8);

#define IMUInt      2
#define SDPin       4
#define BAUD        250000

void setup(){
    Serial.begin(BAUD);
    mySerial.begin(BAUD);
    while(!Serial);
    Serial.println(F("Initializing MPU device..."));

    accelgyro.initialize();
    Serial.println("Testing device connections...");
    Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");
    accelgyro.setXAccelOffset(501);
    accelgyro.setYAccelOffset(619);
    accelgyro.setZAccelOffset(2061);
    accelgyro.setXGyroOffset(-26);
    accelgyro.setYGyroOffset(-12);
    accelgyro.setZGyroOffset(35);
    
    Serial.println(F("Initiating SD Card..."));
    if (!SD.begin(4)) {
      Serial.println(F("SD Card initialization failed!"));
      while(1);
    }
    
    delay(1000);
    
    Serial.println(F("Configuration Complete!"));
    delay(1000);
}


double timer;
double lastRec = 0;
long index = 0;
void loop() {
  while(mySerial.available()>0){
    char data = mySerial.read();
    gps.encode(data);
  }
  int16_t ax, ay, az, gx, gy, gz;
    
  accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  String out = "MPU:";
  String GPSDATA;
  out += String(ax)+"|";
  out += String(ay)+"|"; 
  out += String(az)+"|"; 
  out += String(gx)+"|"; 
  out += String(gy)+"|"; 
  out += String(gz)+"|"; 
  timer = millis();
  out += String(timer);

  File file = SD.open("data.txt", FILE_WRITE);
  if (file) {
    file.println(out);
    if(timer-lastRec > 18000 && GPSLogger() != ""){
      lastRec = timer;
      GPSDATA = "GPS:"+GPSLogger();
      file.println(GPSDATA);  
     
    }
    GPSDATA = "GPS:"+GPSLogger();
    Serial.print(out);
    Serial.print(GPSDATA);
      
    Serial.print(F("  Written. #"));
    Serial.print(index);
    Serial.print(F(" at "));
    Serial.println(timer);
    index++;
    file.close();
  }
  else {
    Serial.println(F("error opening data.txt"));
  }
}

String GPSLogger(){  
  //if(gps.location.isUpdated()){
  //  Serial.println(F("The thing workings!"));
    String Data =   String(gps.location.lat(), 9);
    Data +=   String(gps.location.lng(), 9)+"|";
    Data +=   String(gps.altitude.value())+"|";
    Data +=   String(gps.satellites.value())+"|";
    Data +=   String(gps.date.value())+"|";
    Data +=   String(gps.time.value())+"|";
    Data += ",";
    return Data;
  //}
  //return "";
}
