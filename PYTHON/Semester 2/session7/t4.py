import re 
psw=input("Enter the password : ")
flag=0
while True: 
	if (len(psw)<5 or len(psw)>15): 
		flag = -1
		break
	elif not re.search("[a-z]", psw): 
		flag = -1
		break
	elif not re.search("[A-Z]", psw): 
		flag = -1
		break
	elif not re.search("[0-9]", psw): 
		flag = -1
		break
	elif not re.search("[_@$!#%^&*+-+/]", psw): 
		flag = -1
		break
	elif re.search("\s", psw): 
		flag = -1
		break
	else: 
		flag = 0
		print("Valid Password") 
		break
if flag ==-1: 
	print("Not a Valid Password") 
