#author LeónMora

import random
import matplotlib.pyplot as plt

q=10000
qmenor=0
qsuperior=704
lista=[]
existe=0
gMuestra=0
acumulador=0
contadorFrecuencias=0
promedios=[]
promediosSR=[]
promediosF=[]

print("Cuantos datos de sea que se generen?")
#q=int(input())
print("Limite Inferior:")
#qmenor=int(input())
print("Limite Superior:")
#qsuperior=int(input())
lista=[0]*q
for j in range(q):
	lista[j] = random.randint(qmenor,qsuperior)
print("aleatorios")
print(lista)
	
	
plt.title("Frecuencia de X")
plt.xlabel("X")
plt.ylabel("Freciencia de x")
plt.hist(lista,histtype='bar',rwidth=0.9,color = 'g')
plt.show()

print("Defina n")
n=int(input())
#Separacion en muestras y calculo de los promedios
for i2 in range(len(lista)):
	if(gMuestra==10):
		promedios.append(acumulador/10)
		gMuestra=0
		acumulador=0
	acumulador=acumulador+lista[i2]
	gMuestra+=1
print("Valores de los promedios")
print(promedios)

#Calculo de frecuencias de los promedios
#sin repeticion
for i2 in range(len(lista)):
	for j2 in range(len(promediosSR)):
		if(promediosSR[j2]==lista[i2]):
			existe=1
if(existe==0):
	promediosSR.append(lista[i2])
else:
	existe=0

#frecuencias
for i2 in range(len(promediosSR)):
	for j2 in range(len(lista)):
		if(promediosSR[i2]==lista[j2]):
			contadorFrecuencias+=1
promediosF.append(contadorFrecuencias)
contadorFrecuencias=0

print("Promedios SR")
print(promediosSR)
print("Frecuencia promedios")
print(promediosF)

#Graficacion
plt.title("Frecuencia vs Promedio")
plt.xlabel("Promedios")
plt.ylabel("Freciencia de Promedios")
plt.hist(promedios,histtype='bar',rwidth=0.9,color = 'g')
plt.show()
