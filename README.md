
## esp8266-ps4-jailbreak

###  For PS4 FW 9.00 there is a new version online at https://github.com/CelliesProjects/ps4_jb900_esp8266

This is a minimal implementation of the PS4 hack by qwertyoruiopz.

It only contains the 'PS4HEN v2.1.2'.

You will need an ESP8266 board with 4MB flash memory and a PS4 on fw 5.05 (or a later hackable firmware) to use the software.

![Hardware](ps4jb.png)

### How to flash your ESP8266:
1. Download [ESPAsyncTCP](https://github.com/me-no-dev/ESPAsyncTCP) and [ESPAsyncWebServer](https://github.com/me-no-dev/ESPAsyncWebServer) and install these libraries in the Arduino libraries folder. 
2. Restart the Arduino IDE after this step.

3. Unpack the [latest release](releases/latest) zipfile.

4. Compile and flash the software to your ESP8266.

### How to connect and install PS4HEN:
1. The ESP8266 will start an accesspoint named `ESP8266 5.05 jailbreak server`.

2. Connect to this AP with your PS4 and browse to http://192.168.4.1/ to enable PS4HEN on your PS4.

### Credits:
Specter, IDC, qwertyoruiopz, Flatz, CTurt, Mistawes, XVortex, Al-Azif
