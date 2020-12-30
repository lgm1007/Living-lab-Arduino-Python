// Slave

#include <Wire.h>
#define TRIG 2
#define ECHO 3

long duration;
int distance;

void setup() {
  Wire.begin(1); //슬레이브 주소                
  //마스터 요청시 requestEvent함수 호출
  Wire.onRequest(requestEvent); 
  //마스터 데이터 전송시 receiveEvent함수 호출
  Wire.onReceive(receiveEvent);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  Serial.begin(9600);           
}

void loop() {
  //초음파 센서
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  duration = pulseIn(ECHO, HIGH);
  distance = duration * 17 / 1000;

   delay(500);
}
//마스터 슬레이브 연결 확인
void receiveEvent(int howMany) {
  while (Wire.available()>1) { 
    char ch = Wire.read(); 
    Serial.print(ch);         
  }
  int x = Wire.read();    
  Serial.println(x);      
}
//마스터 요청 시 수행 함수
void requestEvent() { 
  Wire.write(distance);
}