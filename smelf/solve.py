#!/usr/bin/python

import sys
import os
import subprocess

byte1 = "\x01"
byte2 = "\x01"

for j in range(0, 254):
	
	for i in range(0, 254):
		#print byte1 + byte2
		byte2 = chr((ord(byte2) + 1) % 255)
		if ord(byte2) > 0:
			subprocess.Popen("./reversed " + str(byte1 + byte2))

	byte1 = chr(ord(byte1) + 1)

