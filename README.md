## Documentation ##

#1. Contents:#
The payload is made up of the following parts:
a. The Arduino Uno
b. The Ethernet shield with embedded SD card of capacity 16GB
c. The top Shield, with GPS module, and a MPU unit.
d. A power source
e. Arduino cable connector.

2. Connection and testing:
First of all, connect the arduino cable to the arduino UNO and connect the USB part to the computer. DO NOT connect the power source while testing the device, it may cause damage to the computer. The lights on the arduino UNO will start blinking, with rapid succession. Open the Arduino IDE on the computer. The arduino IDE is free and can be downloaded from the internet.
By default the device contains a program that tests for the connection on the GPS unit. There is a green light beneath the GPS module. It contains a battery, which powers it and in order to initialize the device, the GPS module should be turned on. After the light below the GPS module is turned on, open the serial monitor and look at the output. 

The output should be similar to the image above. If the data points are replaced by asterisks, it means that the GPS data is not being read into the device. Either the GPS module is not properly seated, is loose or there is a problem with the GPS device. If the data is being read properly, it means the test was successful and the device is ready to be uploaded with the real code

3. Upload and configuration:
After the setup is completed, you may find the code to upload in the following URL:

https://www.github.com/sandeshbhusal/hab_code

There is a zip folder inside the URL, download it and extracct it somewhere in your computer. The folders need to go inside the default arduino library installation path.
On a MAC OSX, it is inside users/<username/documents/arduino/library. On a linux system it is inside home/<username>/arduino/libraries/  and the location in windows system is c:/users/<username>/documents/arduino/libraries. Paste the library folders downloaded into the directories, and paste the “final.ino” file somewhere on the desktop.

Now, fire up arduino IDE and upload the final.ino sketch onto the arduino. The sketch should be uploaded successfully, otherwise, unplug the arduino and replug it back again. Now, open up serial monitor. The serial monitor shows up initial configuration. It initializes the GPS module and the SD card. If it reports some error on setting up the SD card, then eject the card from the ethernet sheild and replug it. It should work just fine.

After the setup and installation are completed, eject the SD card and format it as FAT32 format, and re seat it on the Ethernet shield. Now, disconnect the arduino cable and plug in the power source on the device. It will write the data onto the SD card.

Please format the SD card before launch, and do not power it until the launching moment. The IMU unit will record wrong data. 

Thank you for the coordination and opportunity to launch our own payload.

Team Project UP
Nepal
