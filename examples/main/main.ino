#include <Controllino.h> /* Usage of CONTROLLINO library allows you to use CONTROLLINO_xx aliases in your sketch. */
#include "ControllinoRTU.h" /* Usage of ModBusRtu library allows you to implement the Modbus RTU protocol in your sketch. */
/*
CONTROLLINO - Modbus RTU protocol Slave example for MAXI and MEGA, Version 01.00
The sketch is relevant only for CONTROLLINO variants MAXI and MEGA (because of necessity of RS485 interface)!
This sketch is intended as an example of the communication between devices via RS485 with utilization the 
ModbusRTU protocol.
In this example the CONTROLLINO is used as the Modbus slave at address 1!
Modbus master device can read Modbus 10bit registers (provided by the slave):

Modbus Master-Slave library for Arduino (ModbusRtu.h) was modified from the website: 
https://github.com/smarmengol/Modbus-Master-Slave-for-Arduino to work with Serial3 port of the Arduino MEGA

Created by Vishnu Hu
This sketch works on Weintek screens with the CONTROLLINO Mega. Ensure you have RTU hex based addressing, 9600 8N1 on RS485 2W Comport!

Slave addresses are handled by regBank array of 10 bits!

Addressing is as followed:
Slave Addr        HMI Bit Addr          HMI Reg Addr
regBank[0]        0x0 to 0x9            4x0
regBank[1]        0x10 to 0x19          4x1

... to NumberOfAddresses

It may be valuable to create a customized regBank handler 
*/



// Ensure this address is properly configured on your screen too
#define SlaveModbusAddress 1
// Expand this when needed
#define NumberOfAddresses 8

Modbus ControllinoModbusSlave(SlaveModbusAddress, Serial3, 14);

//
uint16_t regBank[NumberOfAddresses];


void setup()
{
delay(200);
Serial.begin(9600);
Serial.println("Started");

//default 9600 8N1
ControllinoModbusSlave.begin(9600);
}
// The loop function runs over and over again forever
void loop()
{
  // This needs to be in every loop
ControllinoModbusSlave.poll(regBank, NumberOfAddresses);

//Check outputs (Control Shift M)
Serial.print("regBank[0]: ");
Serial.print(regBank[0]);
Serial.print("\n");
Serial.print("regBank[1]: ");
Serial.print(regBank[1]);
Serial.print("\n\n");

//Do code...
}