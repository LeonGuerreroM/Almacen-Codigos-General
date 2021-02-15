limiteA = 0

#funcion de conversion que funciona para ambos tipos de direcciones
def conversiones(opcion, direccion, limite): 
    byteSeparado = "" #variable que guarda el valor de un byte en decimal, de la direccion uno a la vez
    byteSeparadoNum = 0
    direccionbinaria = "" #aqui se guarda la direccion en binario
    contadorBytes = 0
    direccion = str(direccion)
    opcion = int(opcion)
    for i in direccion: #Recorre la direccion
        if i == '.' or i == '-': #si el elemento en i es un separador . o -
            if opcion==1: 
                byteSeparadoNum = int(byteSeparado) #convierte lo que tenga byteSeparado a decimal
                direccionbinaria = direccionbinaria + str(bin(byteSeparadoNum)[2:]) + '.'  #y lo agrega a la direccion binaria
            elif opcion==2:
                byteSeparadoNum = int(byteSeparado, 16)
                direccionbinaria = direccionbinaria + str(bin(byteSeparadoNum)[2:]) + '-'
            byteSeparado = "" #limpia byte separado para comenzar a recibir un nuevo byte
        else:
            byteSeparado = byteSeparado + i #si no es separador, entonces es numero. Lo anexa al byteSeparado que va guardando cada byte
            if i == direccion[len(direccion)-1]: #si resulta que es el ultimo caracter de la direcion, ya no habra separador
                if opcion==1: #asi que convierte y agrega al arreglo de convertidos pues ya no habra mas caracteres
                    byteSeparadoNum = int(byteSeparado) 
                elif opcion==2:    
                    byteSeparadoNum = int(byteSeparado, 16) 
                direccionbinaria = direccionbinaria + bin(byteSeparadoNum)[2:]
                byteSeparado = ""
            
    print("La dirección en binario es: " +direccionbinaria)
    direccionbinaria = ""
    contadorBytes = 0

while(1):
    print("¿Qué tipo de dirección desea convertir a binario?\n1. Dirección IP (Formato x.x.x.x)\n2. Dirección MAC (Formato x-x-x-x-x-x)")
    opcion = input()
    direccion = input("Ingrese la dirección\n")
    if opcion==1: #segun el tipo de direccion escogida define separador de bytes y limite
        limiteA = 3 #define el numero de veces que se pone el separador al reescribir la direccion
    elif opcion==2:
        limiteA = 5
        
    conversiones(opcion, direccion, limiteA)

