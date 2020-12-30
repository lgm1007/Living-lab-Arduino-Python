# -*- coding: utf-8 -*-
import requests
import json
import sys
import os.path
import serial 


sys.path.append('../')

from auth import auth
import config

print('serial ' + serial.__version__)

PORT = '/dev/ttyACM0' 
BaudRate = 9600 
ARD= serial.Serial(PORT,BaudRate)

def Decode(A):
	A = A.decode()
	A = str(A)
	A = int(A)
	result = A
	return result


def Ardread(): 
	count = 0	
	while(True):
		if ARD.readable():
			NUM = ARD.readline()
			dist = Decode(NUM)
			print(dist)
			if dist <= 5:
				if count >= 3:
					if __name__ == '__main__':
					    data = {
						'message': {
						    'to': '01066896321',
						    'from': '01042149072',
						    'text': '쓰레기 가득참'
						}
					    }
					    res = requests.post(config.getUrl('/messages/v4/send'), headers=auth.get_headers(config.apiKey, config.apiSecret), json=data)
					count = 0
				else:
					count = count + 1
				

			else:
				print("Not Full")
		else:
			print("FAIL")


Ardread()

