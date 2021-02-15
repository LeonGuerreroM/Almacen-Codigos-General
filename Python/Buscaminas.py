#import numpy as np
from random import randint
from colorama import Back, init
init()

def crear_tablero():
    try:
        tablero = []
        columna_aleatoria = 0
        fila_aleatoria = 0
        minados = []
        lugarMinado = ()
        repetido = 0
        minas_colocadas = 0
        var = 1
        
        #tablero = np.zeros((10,10)) #Crea la matriz
        for i in range(10):
            tablero.append([0,0,0,0,0,0,0,0,0,0])
        
        while(minas_colocadas < 20): #se completará cuando se llegue a 20 minas colocadas
            fila_aleatoria = randint(0, 9) #Genera fila y columna aleatoria
            columna_aleatoria = randint(0, 9)
            lugarMinado = (fila_aleatoria, columna_aleatoria) #Se crea la tupla lugar minado
            for j in minados: #Se comprueba si lugar minado no está en la lista de lugares minados
                if j == lugarMinado:
                    repetido = 1 #Si lo está, hace repetedio 1 y termina la comprobacion de si el lugar fue repetido
                    break
            if repetido == 0: #Si no se repitio
                tablero[fila_aleatoria][columna_aleatoria] = 1 #pone una mina en las coordenadas
                minados.append(lugarMinado) #y agrega esas coordenadas a la lista de lugares minados
                minas_colocadas = minas_colocadas + 1 #se aumenta el contador de minas
            else:
                repetido = 0 #se resetea el comprobador de repeticion
                continue #se pasa esta iteración del while sin aumentar el número de minas colocadas pues ninguna fue puesta.
        #print(tablero)
        '''for i in range(10):
            print(tablero[i])
        print("---------")
        for i in range(10):
            for j in range(10):
                if tablero[i][j] == '1':
                    print(Back.RED+tablero[i][j], end = "   ")
                else:
                    print(tablero[i][j], end = "   ")
            print()'''
        return tablero
    except:
        print("Entrada no valida. Intenta de nuevo") 

def jugar():
    try:
        jugador = 1 #indicará si el jugador está vivo
        nombre = "" #nombre del jugador
        inicio = 0 #el jugador iniciará por el inicio o el final
        primer_fila = 0 #coloca la primer fila del jugador
        avance = 1  #si el jugador empieza a jugar al inicio es 1, si empieza por el renglon del final es -1
        columna_inicio = 11 #indica la columna en la que el jugador comenzará el juego
        columna_inicio_num = -1 #pasado a numero
        direccion_mov_columna = 1 #indica en que dirección se moverá el jugador
        mov_columna = 1 #se escoge en cada iteración para movimientos de izquierda  (-1) o derecha (1).
        turnos = 0 #contador del numero de turnos 
        tablero = crear_tablero()
        campo_descubierto = 0 #obtendrá el valor del campo que descubrió el jugador 
        campo = [] #simulará el campo escondido, mismo que se irá modificando con cada lugar que pise el jugador
        for i in range(10):
            campo.append(['*','*','*','*','*','*','*','*','*','*'])
        posicionX = 0 #guarda la posicion en x (columnas) del jugador
        posicionY = 0 #guarda la posicion en y (filas) del jugador
        
        nombre = input("Hola jugador. ¿Cómo te llamas?\n")
        while inicio != '1' and inicio != '2':
            inicio = input("¿Quieres iniciar el recorrido por el inicio o el final?\n1. El inicio e ir bajando\n2. El final e ir subiendo\n") 
            if inicio != '1' and inicio != '2':
                print("Ingrese una opcion válida")
        while columna_inicio < 1 or columna_inicio > 10:
            columna_inicio = input("¿En que columna deseas iniciar tu recorrido? (Del 1 al 10)\n")
            columna_inicio = int(columna_inicio)
            if columna_inicio < 1 or columna_inicio > 10:
                print("Ingrese una posicion válida")
        posicionX = int(columna_inicio)-1 #para que coincida con los indices de la matriz
        
        if inicio == '1': #asigna el avance segun donde el jugador decidiera empezar el recorrido
            avance = 1
            posicionY = 0
        elif inicio == '2':
            avance = -1
            posicionY = 9
        
        campo_descubierto = tablero[posicionY][posicionX] #Segun los valores de inicio se obtiene lo que hay ahi en el tablero
        campo[posicionY][posicionX] = campo_descubierto #Lo obtenido se descubre en el tablero de asteriscos
        
        for i in range(10): #Se imprime el campo con la posicion ya descubierta
            print(campo[i])
        
        if campo_descubierto == 1: #si desde el principio cayó en una mina, termina el juego
            jugador = 0
            print("¡PERDISTE ENTRANDO AL CAMPO! Juego terminado")
            print("CAMPO DESBLOQUEADO:")
            for i in tablero:
                print(i)
            return nombre, turnos+1
        
        while turnos < 9 and jugador == 1: #mientras no haya llegado al final (controlado por turnos) y no haya encontrado mina
            #print("Turnos = {}".format(turnos))
            direccion_mov_columna = input("¿Irás a la izquierda, (1) a la derecha (2) o te quedarás en esta columna (0)?\n")
            
            if direccion_mov_columna == '1': #asigna el movimiento segun la direccion de la columna a la que se quiera mover el jugador
                mov_columna = -1
            elif direccion_mov_columna == '2': #recuerda que todo lo que entra por input es string
                mov_columna = 1
            elif direccion_mov_columna == '0':
                mov_columna = 0
            
            if posicionX+mov_columna > 9: #validacion de que aun haya campo para moverse
                print("Has llegado al límite derecho del campo. Ingresa una opcion diferente")
                continue #esta iteracion se deja pasar
            elif posicionX+mov_columna < 0:
                print("Has llegado al límite izquierdo del campo. Ingresa una opcion diferente")
                continue
            
            posicionY = posicionY+avance #reasigna posiciones para moverse, lo anterior mas el movimiento
            posicionX = posicionX+mov_columna
                
            campo_descubierto = tablero[posicionY][posicionX] #busca el valor del campo en el tablero
            campo[posicionY][posicionX] = campo_descubierto #lo asigna al campo
            
            for i in range(10): #imprime el campo para que el jugador vea el resultado
                print(campo[i])
                
            if campo_descubierto == 1: #si cayó en una mina, termina el juego
                jugador = 0
                print("¡PERDISTE! Juego terminado")
                print("CAMPO DESBLOQUEADO:")
                for i in tablero:
                    print(i)
                return nombre, turnos + 2
            
            turnos = turnos + 1
            
        if jugador == 1: #si ya llego al final y el jugador sigue vivo
            return nombre, 20
    except:
        print("Entrada no valida. Intenta de nuevo") 
try:
    nombre = "" #almacena nombre del jugador
    turno_derrota = 0 #almacena el turno en el que el jugador perdió
    i = 0
    registros = [] #Guarda el nombre del jugador y el turno en el que perdió
    while i < 20:
        nombre, turno_derrota = jugar() #llama 20 juegos
        if turno_derrota != 20: #añade los resultados del juego de la iteración a los registros
            registros.append((nombre, turno_derrota))
        else:
            registros.append((nombre, "GANADOR"))
            print("¡¡¡GANASTE!!!")
        i = i + 1

    print("RESULTADOS") 
    print("|Nombre||Turno de derrota|") 
    for i in registros:
        print(i)     
except:
    print("Entrada no valida. Intenta de nuevo")   
    
''' esta función recorre la matriz para contar los 1, es como en C
for i in range(10):
    for j in range(10):
        if tablero[i][j] == 1:
            x = x + 1
print(x)'''