#!/usr/bin/python

def c_print(str):
	print "//header <stdio.h>"
	print "printf(\""+str+"\\n\");"

def c_generator(str):
	print "#include<stdio.h>"
	print "int main()"
	print "{"
	c_print(str);
	print "return 0;"
	print "}"


c_generator("Hello World!")
