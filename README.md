# Obtain Arduino Ultrasonic Sensor Result from Python (Living Lab.)

## Arduino

### 회로 구성

![](https://github.com/lgm1007/Living-lab-Arduino-Python/blob/master/circuit/arduino-circuit.JPG?raw=true)

### 동작 리뷰

* 아두이노는 1:N 통신을 수행
* 마스터 아두이노
  * 슬레이브 아두이노에게 매 주기(delay)마다 값 요청
* 슬레이브 아두이노
  * 주기마다 초음파센서로 거리 측정
  * 마스터에서 요청을 받을 때마다 측정값 전달

Code : [ArduinoCode](https://github.com/lgm1007/Living-lab-Arduino-Python/tree/master/ArduinoCode)

<br/>

## Python

### 사용 준비

#### Library

* pyserial

### 동작 리뷰

* pyserial 모듈로 시리얼 통신을 통해 마스터 아두이노에게 측정값 읽어옴
  * 시리얼에서 읽어온 값을 유니코드로 변경해주기 위해 decode() 함수 사용
  * 유니코드로 변경한 값을 문자열 형태로 변경 후 정수형으로 변경
* 측정값이 5cm 이하일 경우 count 값 1 증가
* count 값이 3 이상이 되면 Solapi 솔루션을 이용해 문자메시지 전송 후 count 값 0으로 초기화

Code : [simple](https://github.com/lgm1007/Living-lab-Arduino-Python/tree/master/simple)/test.py

<br/>

## Solapi-Python-Example

[![Python 3.7](https://img.shields.io/badge/python-3.7-blue.svg)](https://www.python.org/downloads/release/python-370/)

### 사용 준비

- [ ] [config.ini](https://github.com/solapi/examples/blob/python/python/config.ini)에 정보 입력
  - [ ] ApiKey
  - [ ] ApiSecret
  - [ ] to (수신번호)
  - [ ] from (발신번호)

### 필요한 Library

#### main

- [ ] requests
- [ ] configparser
- [ ] json
#### auth

- [ ] time
- [ ] datetime
- [ ] uuid
- [ ] hmac
- [ ] hashlib

[Solapi-Example-Link](https://github.com/solapi/examples/tree/master/python)