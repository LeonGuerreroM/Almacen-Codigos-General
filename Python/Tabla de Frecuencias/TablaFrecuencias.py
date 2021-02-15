import math
import random
contadorA=0
contadorB=0
opcionA=1
##lista=[22,19,16,13,18,15,20,14,15,16,15,16,20,13,15,18,15,13,18,15]
lista=[]
intervalos=[]
mclase=[]
frecuencia=[]
frelativa=[]
fabsoluta=[]
frab=[]
xmax=0
xmin=0
lectura=0
conten2 =' '
conten4=' '


print ("Realizado de Tablas de Frecuancias")
print("Como ingresara los datos?")
print("1. Uno a uno\n2. Leer un archivo de texto\n3. Generacion aleatoria")
lectura=int(input())

##Llenado de datos uno a uno
if lectura==1:
	while opcionA==1: 
		print("Ingrese el dato {}".format(contadorA+1))
		datx=int(input())
		lista.append(datx)
		contadorA+=1
		opcionA=int(input("Si desea ingresar otro dato presione 1\nEn caso contrario presione 0\n"))
elif lectura==2:
	##ruta='Users\leonm\Desktop\Tabla de Frecuencias\Entrada.txt'
	archi=open("Entrada.txt",'r')
	receptor=archi.readlines()
	for vlu in receptor:
		lista.append(int(vlu))
	archi.close()
##Llenado con datos aleatorios
elif lectura==3:
	print("Cuantos datos de sea que se generen?")
	q=int(input())
	print("Limite Inferior:")
	qmenor=int(input())
	print("Limite Superior:")
	qsuperior=int(input())
	lista=[0]*q
	for j in range(q):
		lista[j] = random.randint(qmenor,qsuperior)

lista.sort(reverse=True)
print(lista)

##Variables para determinar el numero de clases necesarias
aux1=len(lista) 
xmax=lista[0]
xmin=lista[aux1-1]
rango=xmax-xmin

##Escoger entre va discreta o continua
if lectura==3:
	print("Cuantas clases desea que se formen?")
	k=int(input())
else:
	print("La v.a. es...?")
	print("1. Discreta\n2. Continua")
	va=int(input())
	if(va==1):
		sturges=(1+(3.322*math.log10(aux1)))
		k=(int(sturges))
	else:
		print("Cuantas clases desea que se formen?")
		k=int(input())	
##Determinacion de amplitud e intervalos de las clases
amplitud=math.ceil(rango/k)
intervalos.append(xmin)
contadorA=1
while contadorA<=k:
	intervalos.append(intervalos[contadorA-1]+amplitud) 
	contadorA+=1
contadorA=0	
##Determinacion de marcas de clase
while contadorA<k: 
	mclase.append((intervalos[contadorA]+intervalos[contadorA+1])/2)
	contadorA+=1
contadorA=0
##Determinacion de frecuencia
while contadorA<k: 
	for i in lista:
		if contadorA==k-1:
			if i>=intervalos[contadorA] and i<=intervalos[contadorA+1]:
				contadorB+=1
		else:
			if i>=intervalos[contadorA] and i<intervalos[contadorA+1]:
				contadorB+=1
	frecuencia.append(contadorB)
	contadorB=0
	contadorA+=1
contadorA=0
##Determinacion de frecuencia relativa
while contadorA<len(frecuencia): 
	frelativa.append(frecuencia[contadorA]/len(lista))
	contadorA+=1
fabsoluta.append(frecuencia[0])
contadorA=1
##Determinacion de frecuencia absoluta
while contadorA<=len(frecuencia)-1:	
	fabsoluta.append(fabsoluta[contadorA-1]+frecuencia[contadorA])
	contadorA+=1
frab.append(frelativa[0])
contadorA=1
##Determinacion de frecuencia absoluta relativa
while contadorA<=len(frecuencia)-1: 
	frab.append(frab[contadorA-1]+frelativa[contadorA])
	contadorA+=1
	
print("Clase L.Inferior L.Superior MarcaClase Frecuencia FRelativa FA   FRA")
contadorA=0
##Creacion y muestra de la tabla de frecuencias
while contadorA<len(frecuencia):
	if(contadorA==0):
		print("1\t    {}\t    {}\t    {}\t    {}\t    {}\t    {}\t  {}".format(xmin,intervalos[contadorA+1],mclase[contadorA],frecuencia[contadorA],frelativa[contadorA],fabsoluta[contadorA],frab[contadorA]))
		contadorA+=1
	else:
		##break
		print("{}\t    {}\t    {}\t    {}\t    {}\t    {}    {}\t  {}".format(contadorA+1,intervalos[contadorA],intervalos[contadorA+1],mclase[contadorA],frecuencia[contadorA],frelativa[contadorA],fabsoluta[contadorA],frab[contadorA]))
		contadorA+=1

conten="Marca de clase: "
for v in mclase:
	conten2+=" "+str(v)
##conten2=" ".join(mclase)
conten3="Frecuencias:   "
##conten4=" ".join(frecuencia)
for v in frecuencia:
	conten4+=" "+str(v)
conten6="\n"
conten7=(conten+conten2+conten6+conten3+conten4)
archi=open("Salida.txt",'w')
archi.write(conten7)
