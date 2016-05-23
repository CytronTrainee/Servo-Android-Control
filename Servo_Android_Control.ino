#include <SoftwareSerial.h> // TX RX software library for bluetooth

#include <Servo.h> // servo library 
Servo myservo; // servo name

int bluetoothTx = 0; // bluetooth tx to 0 pin
int bluetoothRx = 1; // bluetooth rx to 1 pin

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

void setup()
{
  myservo.attach(8,620,2500); // attach servo signal wire to pin 8
 //620 is the min range while 2500 is the max range of Duty Cycle
 //Change it to suit your servo. The standard min is 500 while max is 2500 
 //Setup usb serial connection to computer
  Serial.begin(9600);
  Serial.setTimeout(50);//default 1000ms, slow update
  //Setup Bluetooth serial connection to android
  bluetooth.begin(9600);
  bluetooth.setTimeout(50);//default 1000ms, slow update
}

void loop()
{
 
  //Read from bluetooth and write to usb serial
  if(bluetooth.available()> 0 ) // receive number from bluetooth
  {
    int servopos = bluetooth.parseInt(); // save the received number to servopos
    Serial.println(servopos); // serial print servopos current number received from bluetooth
    myservo.write(servopos); // roate the servo the angle received from the android app
  }


}
