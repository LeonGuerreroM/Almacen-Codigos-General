#author leonGe
import matplotlib.pyplot as plt
import math
import random
from datetime import datetime
import time
lectura2=0
k2=0.5 ##numero medio de veces qu eocurre el suceso raro en el intervalo
lapsoInicial= 0
kTemp=0 ##variables para la deduccion de k
lapsoPropuesto = 0 
repeticiones2=0 ##numero de experimentos
i2=0
j2=0
lista2=[] ##lista donde se guardan los numeros aleatorios
sucesoRaro=5
frecuenciaRara=0 ##variable para almacenar el valor de la va en el experimento en turno
listaFrecuenciasRaras=[] ##lista de las frecuencias del suceso raro, una frecuencia por cada experimento
semilla=10


##Para este caso el lapso continuo de la Distribucion de Poisson
##será simulado como un numero de intentos de exito (lapsoPropuesto) indicado por el usuario
##el suceso raro sera cuando el numero aleatorio entre 0 y 10 sea igual a 5


print("Distrubucion de Poisson")

print("¿De cuantos intentos se conforma el lapso?") 
lapsoPropuesto=int(input())
print("Si conoce el valor de k presione 1")
print("para calcularlo   presione 2")
##lectura2=int(input())

if lectura2==1: ##ingreso directo de datos
	print("Ingrese el valor de k")
	k2=float(input())
elif lectura2==2: ##deduccion de miu especifica a partir de datos generales
	print("Ingrese el intervalo con k conocido");
	lapsoInicial=input()
	print("Ingrese el mi conocido");
	kTemp=(input())
	k=(lapsoPropuesto*kTemp)/lapsoInicial
	
print("Indique el numero de veces que se hara el experimento")
repeticiones2=int(input())

##variables para la obtencion de frecuencias 
lista2=[] ##lista donde se guardan los numeros aleatorios

usados=[] ##lista donde se guardan los numeros contabilizados

#realizacion del experimento
for i2 in range(repeticiones2):
	frecuenciaRara=0
	lista2=[]
	#generacion de numeros aleatorios
	for j2 in range(lapsoPropuesto):
		lista2.append(random.randrange(0,11))
		print("I",j2," N=",lista2[j2])
	#almacenamiento de la frecuencia en un arreglo
	##estas frecuencias son la x de cada experimento
	for j2 in range(lapsoPropuesto):
		if(lista2[j2]>=sucesoRaro):
			frecuenciaRara+=1
	listaFrecuenciasRaras.append(frecuenciaRara)

print(listaFrecuenciasRaras)
#obtencion de la frecuencia	de cada x
listaFrecuenciasRarasAuxiliar=[]
listaFrecuenciasRarasAuxiliar.extend(listaFrecuenciasRaras)
listaFrecuenciasRarasAuxiliar.sort
temporal2=0
freTemp=0
listaX=[] ##lista donde se guardan las x de cada experimento (sin repeticion)
listaFX=[] ##lista donde se guardan las frecuencias de esas x
for i2 in range(len(listaFrecuenciasRarasAuxiliar)):
	freTemp=0
	if(listaFrecuenciasRarasAuxiliar[i2]!=0.5):
		temporal2=listaFrecuenciasRarasAuxiliar[i2]
		for j2 in range(len(listaFrecuenciasRarasAuxiliar)):
			if(listaFrecuenciasRarasAuxiliar[j2]==temporal2):
				listaFrecuenciasRarasAuxiliar[j2]=0.5
				freTemp+=1
		listaX.append(temporal2)
		listaFX.append(freTemp)

print(listaX)
print(listaFX)

#calculo de probabilidades para las x obtenidas
listaProbabilidades=[]
propabilidad=0
for i2 in range(len(listaX)):
	probabilidad=((k2**listaX[i2])*(math.e**-k2))/(math.factorial(listaX[i2]))
	print("p=",probabilidad)
	listaProbabilidades.append(probabilidad)
	
print(listaProbabilidades)

#graficacion
##plt.hist(listaProbabilidades,listaX)
##plt.xlabel('va X')
##plt.ylabel('Probabiilidades')
##plt.title('x vs Probabilidades Calculadas con Poisson')
##plt.show()