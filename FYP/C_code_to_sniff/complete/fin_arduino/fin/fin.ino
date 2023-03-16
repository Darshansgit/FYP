#include <Wire.h>

volatile byte i2c_data_rx;       // indicates there are available data from the i2c bus. 
volatile uint16_t count;         // indicates the total number of data collected.
volatile uint8_t sys, dia, hr; 
int button=3;
int buttonstate;


void setup()
{
  Serial.begin(9600);
  pinMode(button, INPUT_PULLUP);
  Wire.begin(0x50);
  Wire.onReceive(receiveEvent);
}

void receiveEvent(int datain)   // Interrupt service routine.
{
  if ( datain > 0 )
  {
    while ( datain-- )
    {
      i2c_data_rx = Wire.read();
      // Serial.println(i2c_data_rx);
      count++;
      if (count == 28)
      {
        sys = i2c_data_rx;
      }
      if (count == 29)
      {
        dia = i2c_data_rx;
      }
      if (count == 30)
      {
        hr = i2c_data_rx;
      }
    }
  }
}

void loop()
{
  delay(100);  
  buttonstate=digitalRead(button);
  if(buttonstate==0)
  { 
  if (count == 35)
    {
      // int msg= 'sys'+'dia'+'hr';
      // Serial.print("Blood Presure Data: ");
      Serial.print(sys);
      Serial.print("/");
      Serial.print( dia);
      Serial.print("/");
      Serial.println( hr);
      
    }
    
  count = 0;
  }

}


