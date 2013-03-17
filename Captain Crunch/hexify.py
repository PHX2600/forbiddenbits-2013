#!/usr/bin/python

import sys


content = [line.strip() for line in open('hex')]
for line in content:
	print line.decode("hex")

