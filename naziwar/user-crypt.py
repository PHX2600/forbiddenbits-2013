#!/usr/bin/python

import socket
import sys


def getHash(name):
	s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	s.connect(("88.190.221.116", 1337))
	header = s.recv(1024)

	s.send(name)

	intro = s.recv(1024)

	password = intro[45:58]

	return password

for i in range(101, 200):
	print "i=" + str(i)
	print getHash(str(i))

