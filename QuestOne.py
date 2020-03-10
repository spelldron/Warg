def Parity(Num):

	Num = bin(Num)
	print(Num[-1])
	if Num[-1] == '1':
		print("odd Number")
	else:
		print("even Number")
		
Number = 37
Parity(Number)