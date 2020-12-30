// Master
#include <Wire.h>

void setup() {
  Wire.begin();
  Serial.begin(9600); 
}

//마스터 슬레이브 연결
void loop() {  
  for(int i=1;i<5;i++){
    Wire.beginTransmission(i);                
    Wire.write("test ");       
    Wire.write(i);             
    Wire.endTransmission();    
     
    delay(500);
    Wire.requestFrom(i, 1);   
    while (Wire.available()) {
        int c = Wire.read(); 
        Serial.println(c);        
    }
  }   
}