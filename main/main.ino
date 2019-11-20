/*
  Simple example for receiving
  
  https://github.com/sui77/rc-switch/
*/

#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();
int long value ;

String arrayivan[3];
String DatosHEX;
String Almacena;
byte Entero[4];
int x = 0;

void setup() {
  Serial.begin(9600);
  mySwitch.enableReceive(0);  // Receiver on interrupt 0 => that is pin #2
}

void loop() {
  if (mySwitch.available()) {
    

 value = mySwitch.getReceivedValue();
 DatosHEX = String(value);
 x = 0;    
    
  
for ( uint8_t i = 0; i < 4; i++) {  //
    Almacena = DatosHEX.substring(x, x + 2 );
    Entero[i] = Almacena.toInt();
    Serial.println(Entero[i]);
    x = x + 2; 
    delay(5);
  }
 
    if (value == 0) {
      Serial.print("Unknown encoding");
    } 
    else {
      Serial.print("Received ");
      Serial.println( mySwitch.getReceivedValue() );

    mySwitch.resetAvailable();
    delay(4000);
  }
}
}



