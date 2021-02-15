#author LeónMora

import matplotlib.pyplot as plt
import math
import random

##declaracion de variables
k2=3.7 ##media del experimento
lectura2=0
lapsoInicial=0
kTemp=0
lapsoPropuesto=0
nExperimentos=100000
distro=[] ##muestra de datos aleatorios con muestra especifica
existe=0
listaX=[] ##lista donde se guardan las x de cada experimento (sin repeticion)
listaFX=[] ##lista donde se guardan las frecuencias de esas x
contadorFrecuencias=0
listaFR=[]
listaPT=[]
ca2=''
ca4=''
ca6=''
tlc=0;
n=0
acumulador=0
gMuestra=0
promedios=[]
promediosSR=[]
promediosF=[]

print("Distribucion de Poisson")
##obtencion de parametros para la prueba
print("Si conoce el valor de k presione 1")
print("para calcularlo   presione 2")
##lectura2=int(input())

if lectura2==1: ##ingreso directo de datos
	print("Ingrese el valor de k")
	k2=float(input())
elif lectura2==2: ##deduccion de k especifica a partir de datos generales
	print("Ingrese el intervalo con k conocido");
	lapsoInicial=int(input())
	print("Ingrese el intervalo con k propuesto");
	lapsoPropuesto=int(input())
	print("Ingrese el mi conocido");
	kTemp=float((input()))
	k2=(lapsoPropuesto*kTemp)/lapsoInicial
print("Indique el numero de veces que se hará el experimento")
#nExperimentos=int(input())

print("Media de la distribucion: ",k2)
print("Numero de experimentos: ",nExperimentos,)

##distro=np.random.normal(k2,1,nExperimentos) #creacion de muestra con media determinada
##print(distro)

##redondeo de la muestra
##for j2 in range(len(distro)):
	##b = abs(distro[j2]) - abs(int(distro[j2]))
	##if(b>=0.5):
		##redonde=math.ceil(distro[j2])
	##else:
		##redonde=math.floor(distro[j2])
	##if(redonde<0):
		##redonde=redonde*-1;
	##distro[j2]=redonde
##print("Distribucion de numeros aleatorios (Muestra)")
##print(distro)	
	
##Generacion de una distribucion de Poisson con metodo de la transformada inversa
for i2 in range(nExperimentos):
	generado=random.random()
	i=0
	p=math.e**-k2
	F=p
	while generado>=F:
		p=(k2*p)/(i+1)
		F=F+p
		i=i+1
	distro.append(i)
print("valores de distro")
print(distro)
##llenado de listaX con las v.a. que se generaron (sin repeticion)
for i2 in range(len(distro)):
	for j2 in range(len(listaX)):
		if(listaX[j2]==distro[i2]):
			existe=1
	if(existe==0):
		listaX.append(distro[i2])
	else:
		existe=0

listaX.sort()	
print("Valores de X")
print(listaX)	
	
##calculo del numero de veces que aparecio cada x
for i2 in range(len(listaX)):
	for j2 in range(len(distro)):
		if(listaX[i2]==distro[j2]):
			contadorFrecuencias+=1
	listaFX.append(contadorFrecuencias)
	contadorFrecuencias=0
	
print("Frecuencias de X")
print(listaFX)	

plt.title("Frecuencia vs X")
plt.xlabel("Valores de X")
plt.ylabel("Freciencia de X")
plt.hist(distro,len(listaX),histtype='bar',rwidth=0.9,color = 'c')
plt.show()

print("Presione cualquier tecla para continuar")
b=input()

##calculo de frecuencias relativas	
for i2 in range(len(listaX)):
	listaFR.append(listaFX[i2]/nExperimentos)

print("fr")
print(listaFR)

#calculo de valores teoricos
for i2 in range(len(listaX)):
	b=((k2**listaX[i2])*(math.e**-k2))/(math.factorial(listaX[i2]))
	listaPT.append(b)



print("Valores Teoricos")
print(listaPT)

#Grafiacion
plt.figure()

plt.subplot(2,1,1)
plt.plot(listaX,listaFR,'g--',linewidth=2)
plt.title("Frecuencias Relativas")
##plt.xlabel("Valores de X")
plt.ylabel("Freciencia relativa de X")

plt.subplot(2,1,2)
plt.plot(listaX,listaPT,'c-.',linewidth=3)
plt.title("Valores Teoricos")
plt.xlabel("Valores de X")
plt.ylabel("Probabilidad de X")

plt.show()

#Impresion de la tabla
print("X\tFrecuencia Relativa\tValor Teorico")
for i2 in range(len(listaFR)):
	cadena0="{}".format(listaX[i2])
	cadena1="\t {}".format(listaFR[i2])
	cadena2="\t {}".format(listaPT[i2])
	print(cadena0+"\t"+cadena1+cadena2+"\t")

#Guardado de los valores en un archivo
ca1="X"
for i2 in range(len(listaX)):
	ca2+=" {}".format(listaX[i2])
ca3="Frecuencias Relativas"
for i2 in range(len(listaFR)):
	ca4+=" {}".format(listaFR[i2])
ca5="Valores Teoricos"
for i2 in range(len(listaPT)):
	ca6+=" {}".format(listaPT[i2])
ca7=(ca1+"\n"+ca2+"\n"+ca3+"\n"+ca4+"\n"+ca5+"\n"+ca6)
archi=open('SimulacionPoisson.txt','w')
archi.write(ca7)
archi.close()

print("Continuar con TCL?\n1. Si\n2. No")
tlc=int(input())
if(tlc==1):
	print("Defina n")
	n=int(input())
	#Separacion en muestras y calculo de los promedios
	for i2 in range(len(distro)):
		if(gMuestra==10):
			promedios.append(acumulador/10)
			gMuestra=0
			acumulador=0
		acumulador=acumulador+distro[i2]
		gMuestra+=1
	print("Valores de los promedios")
	print(promedios)
	#Calculo de frecuencias de los promedios
	for i2 in range(len(distro)):
		for j2 in range(len(promediosSR)):
			if(promediosSR[j2]==distro[i2]):
				existe=1
	if(existe==0):
		promediosSR.append(distro[i2])
	else:
		existe=0
		
	for i2 in range(len(promediosSR)):
		for j2 in range(len(distro)):
			if(promediosSR[i2]==distro[j2]):
				contadorFrecuencias+=1
	promediosF.append(contadorFrecuencias)
	contadorFrecuencias=0
	
	#print("Promedios SR")
	#print(promediosSR)
	#print("Frecuencia promedios")
	#print(promediosF)
	
	#Graficacion de las frecuencias de los promedios
	plt.title("Frecuencia vs Promedio")
	plt.xlabel("Promedios")
	plt.ylabel("Freciencia de Promedios")
	plt.hist(promedios,histtype='bar',rwidth=0.9,color = 'm')
	plt.show()
	