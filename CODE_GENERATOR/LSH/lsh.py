#!/usr/bin/python

bufsize=1024
#declare basic data type
def c_var(vname,arg):
	if(type(vname)==str):
		#do nothing
		print "//blank"
	else:
		print "c_var Error:"
		print vname+" should be a string"
	if(arg=="int"):
		print "int"+" "+vname+";"
	elif(arg=="double"):
		print "double"+" "+vname+";"
	elif(arg == "float"):
		print "float"+" " +vname+";"
	elif(arg == "char"):
		print "char"+" "+vname;
	elif(arg == "char_pointer"):
		print "char *"+" "+vname+"=malloc(sizeof(char)*"+bufsize+");"
		print "if (!"+vname+") {"
		print "fprintf(stderr,\"allocation error:\\n\")"
		print "exit(EXIT_FAILURE);"
		print "}"
	elif(arg == "int_pointer"):
		print "int *"+vname+"=malloc(sizeof(int)*"+bufsize+");"
                print "if (!"+vname+") {"
                print "fprintf(stderr,\"allocation error:\\n\")"
                print "exit(EXIT_FAILURE);"
		print "}"
	elif(arg=="double_pointer"):
		print "double *"+vname+"=malloc(sizeof(int)*"+bufsize+");"
                print "if (!"+vname+") {"
                print "fprintf(stderr,\"allocation error:\\n\")"
                print "exit(EXIT_FAILURE);"
                print "}"
	else:
		print "Error: "
		print "Undefined data type!"

#basic operation

def c_print(str):
	print "//header <stdio.h>"
	print "printf(\""+str+"\");"

def c_generator(str):
	print "#include<stdio.h>"
	print "int main()"
	print "{"
	c_var("a","int")
	c_print(str)
	print "return 0;"
	print "}"


c_generator("Hello World!\\n")

