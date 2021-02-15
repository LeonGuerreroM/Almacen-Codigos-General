numero = 5
valor=1
acumulable = 1

while valor<=numero:
	acumulable*=valor
	valor+=1
else:
	print("El factorial de {} es {}".format(numero,acumulable))
	
