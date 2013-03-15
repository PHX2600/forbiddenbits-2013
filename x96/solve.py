#!/usr/bin/python

import socket

	
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect(("95.170.82.211", 3000))

header = s.recv(1024)
intro1 = s.recv(1024)

print intro1

captcha = intro1[15:]

s.send(captcha)

while True:
	score = s.recv(1024)
	print score

	pattern = s.recv(1024)
	print pattern
	pattern = pattern[:-5]

	part1 = pattern[:-8]
	part2 = pattern[4:8]
	part3 = pattern[8:12]

	offset = ord(part1[0]) - ord(part2[0])

	answer = chr(ord(part3[0]) - offset)
	answer += chr(ord(part3[1]) - offset)
	answer += chr(ord(part3[2]) - offset)
	answer += chr(ord(part3[3]) - offset)

	print answer
	s.send(answer + "\n")

	print "pattern: " + pattern
	print "1: " + part1
	print "2: " + part2
	print "3: " + part3



