import std 

#compute zolotarev coefficients
#complete elliptic integral and jacobi elliptic function is defined
#The main purpose is to approximate sign(x) through rational approximation
#For GWU-QCD

def c_rf(x,y,z):
	print "//usage rf(double x, double y, double z)"
	print "//The carlson's integral of the first kind"
	

def DECLARE(vname):
	for i in range(len(vname)):
		if(type(vname[i])==str):
			print "//blank"
		else:
			print "DECLARE ERROR: arguments should string list."
	for i in range(len(vname)-1):
		print vname[0]+" "+vname[i+1]+";"
def WHILE_START(ARG):
	#ARG=["condition"]
	#while(condition){
	if(len(ARG)!=1):
		print "WHILE_START ERROR: Length of array should be 1."
	for i in range(len(ARG)):
		if(type(ARG[i])!=str):
			print "WHILE_START ERROR: arguments should be string list"
	for i in range(len(ARG)):
		print "while"+"("+ARG[0]+"){"

def WHILE_END():
	print "}"

		

def IF_START(ARG):
	#if(arg[0]){
	if(len(ARG)!=1):
		print "IF_START ERROR: Length of array should be 1."
	for i in range(len(ARG)):
		if(type(ARG) != str):
			print "IF_START ERROR: arguments should be string list."

	for i in range(len(ARG)):
		print "if("+ARG[i]+"){"

def IF_END():
	print "}"


def FOR_START(ARG):
	#for(ARG[0];ARG[1];ARG[2])
	if(len(ARG)!=3):
		print "FOR_START ERROR: Length of array should be 3."

	for i in range(len(ARG)):
		if(type(ARG) != str):
			print "FOR_START ERROR: arguments should be string list."

	print "for("+ARG[0]+";"+ARG[1]+";"+ARG[2]+"){"

def FOR_END():
	print "}"




