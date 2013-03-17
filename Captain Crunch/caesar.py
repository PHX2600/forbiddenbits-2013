#!/usr/bin/python

import sys

with open("binary", mode='rb') as file:
	fileContent = file.read()
	#print fileContent

	for index in range(0, 256):
		out = ""

		for i in fileContent:
			out += chr((ord(i) + index) % 256)

		text_file = open("trials/out" + str(index), "w")
		text_file.write(out)
		text_file.close()
