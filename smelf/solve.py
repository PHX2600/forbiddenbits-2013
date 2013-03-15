#!/usr/bin/python

import sys

byte = "\x00"

for i in range(0, 255):
	print byte
	byte = chr(ord(byte) + 1)
