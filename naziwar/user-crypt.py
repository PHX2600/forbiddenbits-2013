#!/usr/bin/python

import socket
import sys

username = sys.stdin.readline()

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect(("88.190.221.116", 1337))

header = s.recv(1024)

s.send(username)

intro = s.recv(1024)

password = intro[45:58]

print password

