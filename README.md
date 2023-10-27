README.txt

libmodbus is a library that provides a Serial Modbus implementation for Controllino.

A primary goal was to enable industrial communication for the Arduino in order to link it to industrial devices such as HMIs, CNCs, PLCs, temperature regulators or speed drives.

http://arduino.cc/en/Guide/Libraries

Code was forked from the repo: 
https://github.com/smarmengol/Modbus-Master-Slave-for-Arduino to work with Serial3 port of the Arduino MEGA


To install:

Do not unzip the downloaded library, leave it as is.

In the Arduino IDE, navigate to Sketch > Import Library. At the top of the drop down list, select the option to "Add Library". 

You will be prompted to select this zipped library. 

Return to the Sketch > Import Library menu. You should now see the library at the bottom of the drop-down menu. It is ready to be used in your sketch. 

The zip file will have been expanded in the libraries folder in your Arduino sketches directory.


Go to Open->Examples->ControllinoRTU and open the example sketch

Then, Choose your Controllino Board which must have the RS485 pinouts

Download the included .etmp HMI file into a weintek compatible screen, and connect COM2 to RS485 pins on the CONTROLLINO. You may modify the COM port and it should still work. As long as the appropriate 2W 485 pins are connected, with the screen configured to 9600 8N1.

