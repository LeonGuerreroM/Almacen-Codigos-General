import sys

def fraccion_a_binario(fraccion,precision): #espera un número decimal sin parte entera
    equivalente_binario = "" ##guarda el equivalente binario de la fraccion
    entero = 0 ##almacena la parte entera
    fraccionaria = 0.0 ##alamcena la parte fraccionaria
    
    for i in range(precision):
        fraccion = fraccion*2
        entero = int(fraccion)
        fraccion = abs(fraccion) - abs(int(fraccion))
        equivalente_binario = equivalente_binario + str(entero)
       
    return equivalente_binario
        
    
def decimal_a_Q88():
    numero_decimal = 0 ##recibe un número decimal del usuario
    bit_signo = 0 ##guarda el bit de signo
    parte_entera = 0 ##almacenar la parte entera del número recibido
    parte_decimal = 0.0 ##almacenar la parte fraccionaria del número recibido
    parte_entera_bin = 0 ##tiene la parte entera en binario
    parte_decimal_bin = 0.0 ##tiene la parte entera en decimal
    tamanio_parte_entera = 0 ##guarda el tamaño de la parte entera
    tamanio_parte_decimal = 0 ##guarda el tamaño de la parte decimal
    numero_en_formato = "" ##guarda el numero en formato Qmn
    
    numero_decimal = float(input("Introduce un número decimal entre -127.0 y 127.99\n"))
    
    if (numero_decimal<-128) or (numero_decimal>127.99):
        print("Número fuera de rango")
    
    if numero_decimal < 0:
        bit_signo = 1
    else:
        bit_signo = 0
    
    parte_entera = int(numero_decimal)
    parte_decimal = abs(numero_decimal)-abs(parte_entera)
    
    parte_entera_bin = (bin(parte_entera)[2:]).zfill(7)
    parte_decimal_bin = fraccion_a_binario(parte_decimal,8)
    
    numero_en_formato = str(bit_signo) + " " + parte_entera_bin + "." + parte_decimal_bin
    
    print("El número {0} en formato Q8.8 es {1}".format(numero_decimal, numero_en_formato))

def Q88_a_decimal():
    binario_entero = "" ##almacena la parte entera en binario
    binario_decimal = "" ##almacena la parte decimal en binario
    decimal_entero = 0 #almacena la parte entera de la conversion
    decimal_decimal = 0 #almacena la parte fraccionaria de la conversion
    contador_potencia = 7
    contador_potencia_negativa = 0 
    decimal = "" ##junta el resultado de la ocnversion
    cambio = 0 ##indica cuando agregar en entero y cuando en fraccionario
    iniciar = 0 #indica cuando iniciar a agregar
    
    numero_binario = input("Introduce el binario a convertir en formato x xxxxxxx.xxxxxxxx\n")
    
    for i in numero_binario:
        if i == " ":
            iniciar = 1
        if iniciar == 1:
            if i == " ":
                continue
            if i == ".":
                cambio = 1
            if cambio == 0:
                binario_entero = binario_entero + i
                #print(binario_entero)
            else:
                if i == ".":
                    continue
                else:
                    binario_decimal = binario_decimal + i
                    #print(binario_decimal)
    
    for i in binario_entero:
        contador_potencia = contador_potencia - 1
        if i == "1":
            decimal_entero = decimal_entero + 2**contador_potencia
    
    for i in binario_decimal:
        contador_potencia_negativa = contador_potencia_negativa - 1
        if i == "1":
            decimal_decimal = decimal_decimal + 2**contador_potencia_negativa
    
    decimal = decimal_entero + decimal_decimal
       
    print("El binario en formato Q8.8 {0} es {1} en decimal".format(numero_binario, str(decimal)))
    
def decimal_a_IEEE():
    binario_entero = "" ##almacena la parte entera en binario
    binario_decimal = "" ##almacena la parte decimal en binario
    decimal_entero = 0 #almacena la parte entera de la conversion
    decimal_decimal = 0 #almacena la parte fraccionaria de la conversion
    exponente = 0 #almacena el exponente para la conversión
    bit_signo = -1 #almacena el bit de signo
    lugares_recorridos = 0 #guarda los lugares que se recorrió el punto para quedar en formato 1.xxxx
    exponente_binario = 0 ##guarda el exponente convertido a binario
    mantisa = "" #almacena la mantisa 
    salto = 0 #indica si ya se efectuó el salto del primero número de la parte entera
    IEEE = "" #almacena la conversión final
    
    numero_decimal = float(input("Introduce un número decimal\n"))
    #print("ND: ",numero_decimal)
    if numero_decimal < 0:
        bit_signo = 1
    else:
        bit_signo = 0
    
    parte_entera = int(numero_decimal)
    #print("Parte entera: ",parte_entera)
    parte_decimal = abs(numero_decimal)-abs(parte_entera)
    #print("Parte decimal: ",parte_decimal)
    
    parte_entera_bin = (bin(parte_entera)[2:])
    #print("Parte entera bin: ",parte_entera_bin)
    parte_decimal_bin = fraccion_a_binario(parte_decimal,15)
    #print("Parte decimal bin: ",parte_decimal_bin)
    
    lugares_recorridos = len(parte_entera_bin) - 1
    #print("Lugares: ",lugares_recorridos)
    exponente = 127 + lugares_recorridos
    exponente_binario = bin(exponente)[2:]
    #print("Exponente : ",exponente_binario)
    
    for i in parte_entera_bin:
        if salto == 1:
            mantisa = mantisa + i
        if salto == 0:
            salto = 1
            continue
    
    for i in parte_decimal_bin:
        mantisa = mantisa + i
    
    mantisa = mantisa[:23]
    #print("la longitud de la mantisa es "+str(len(mantisa)))
    
    #print("Mantisa: ",mantisa)
    
    IEEE = str(bit_signo) + "-" + exponente_binario + "-" + mantisa
    print("El número {0} se representa como {1} en formato IEEE-754".format(numero_decimal, IEEE))
    
def IEEE_a_decimal():
    bit_signo = -1 #almacena el bit de signo del binario original
    signo = "" #almacena el signo del decimal
    numero_iteraciones = 0
    exponente_binario_original = "" #almacena el exponenete de la notacion IEEE
    exponente_original = 0 #conversion de la var anterior a decimal
    mantisa_original = "" #almacena la mantisa de la notacion IEEE
    exponente_base_dos = 0 #almacena el exponente de las veces que se recorrió el punto
    contador_potencia = 8
    binarios_del_entero = "1" #almacena los binarios de la mantisa que corresponden al numero entero 
    entero_decimal = 0 #almacena la parte entera del decimal 
    mantisa_fraccionaria = "" #almacena los bits ubicados en la mantisa correspondientes solamente al fraccionario 
    fraccion_decimal = 0 #almacena la parte fraccionaria en decimal 
    contador_potencia_negativa = 0
    decimal = 0 #almacena la conversión completa a decimal 
    
    mantisa_decimal = 0 #almacena el equivalente de la mantisa en número decimal 
    
    numero_binario = input("Introduce el binario en formato IEEE754 a convertir\n")
    bit_signo = int(numero_binario[0])
    #print("BS: ",bit_signo,"T: ",type(bit_signo))
    if bit_signo == 0:
        signo = " "
    elif bit_signo == 1:
        signo = "-"
    
    for i in numero_binario: #aqui se recupera el exponente E
        numero_iteraciones = numero_iteraciones + 1
        if numero_iteraciones > 1:
            exponente_binario_original = exponente_binario_original + i
        if numero_iteraciones >= 9:
            break
        
    numero_iteraciones = 0  
       
    for i in numero_binario: #aqui se recupera la mantisa
        numero_iteraciones = numero_iteraciones + 1
        if numero_iteraciones > 10:
            mantisa_original = mantisa_original + i
        if numero_iteraciones > 39:
            break 
    
    for i in exponente_binario_original: #Se convierte E a decimal
        contador_potencia = contador_potencia - 1
        if i == "1":
            exponente_original = exponente_original + 2**contador_potencia
    
    exponente_base_dos = exponente_original - 127
    
    numero_iteraciones = 0
    for i in mantisa_original: #Conversion de la mantisa en decimal 
        contador_potencia_negativa = contador_potencia_negativa - 1
        if i == "1":
            mantisa_decimal = mantisa_decimal + 2**contador_potencia_negativa
    
    decimal = ((-1)**bit_signo)*(1+mantisa_decimal)*(2**exponente_base_dos) #uso de la formula para calcular el número
    
    print("El número en formato IEEE {0} en decimal es: {1}".format(numero_binario,decimal))
    
    '''for i in mantisa_original: #recuperamos los elementos de la mantisa que corresponden al entero considerando el primer 1
        numero_iteraciones = numero_iteraciones + 1
        if numero_iteraciones <= exponente_original:
            binarios_del_entero = binarios_del_entero + i
        else:
            break 
    
    contador_potencia = exponente_base_dos + 1       
    for i in binarios_del_entero: #conversion de la parte entera en binario a decimal 
        contador_potencia = contador_potencia - 1
        if i == "1":
            entero_decimal = entero_decimal + 2**contador_potencia
    entero_decimal = int(entero_decimal)
    
    numero_iteraciones = 0
    for i in mantisa_original: #guardamos la parte de la mantisa que corresponde al fraccionario 
        numero_iteraciones = numero_iteraciones + 1
        if numero_iteraciones > exponente_base_dos:
            mantisa_fraccionaria = mantisa_fraccionaria + i
    
    for i in mantisa_fraccionaria: #la mantisa fraccionaria es practicamente la fraccion en binario, asi que solo la convertimos
        contador_potencia_negativa = contador_potencia_negativa - 1
        if i == "1":
            fraccion_decimal = fraccion_decimal + 2**contador_potencia_negativa
    
    decimal = entero_decimal + fraccion_decimal 
    print("El número en formato IEEE {0} en decimal es: {1}".format(numero_binario,signo+str(decimal)))'''
                       
        
        

print("Dispositivos programables. Grupo 4TM1. Semestre 2020/2021-2")
print("Ingeniería Telemática. UPIITA-IPN")
print("Mora Guerrero León Sergio")

while 1:
    opcion_valida = 0
    while opcion_valida == 0: 
        print("1. Conversión de decimal a Q8.8 con signo")
        print("2. Conversión de formato Q8.8 con signo a decimal")
        print("3. Conversión de decimal a formato IEEE-754")
        print("4. Conversión de formato IEEE-754 a decimal")
        print("5. Salir")
        opcion = int(input("Escoja la opción deseada\n"))
        
        if opcion>0 and opcion<5:
            opcion_valida = 1
            if opcion == 1:
                decimal_a_Q88()
            elif opcion == 2:
                Q88_a_decimal()
            elif opcion == 3:
                decimal_a_IEEE()
            elif opcion == 4:
                IEEE_a_decimal()
            elif opcion == 5:
                print("Hasta luego :D")
                sys.exit()
        else:
            print("Opción no valida")


         
    
    
        