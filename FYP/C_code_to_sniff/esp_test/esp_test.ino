// this sample code provided by www.programmingboss.com
#include <SoftwareSerial.h>
SoftwareSerial abc (18, 19);  //rx tx
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  abc.begin(9600);
}
void loop() {
    String msg = abc.readStringUntil('\n');
    Serial.println(msg);
    
}