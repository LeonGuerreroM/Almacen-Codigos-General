def EA(mod, asker):
    '''Funcion que realiza el algoritmo de Euclides
    Entradas
      mod => modulo 
      asker => número del que se desea conocer el inverso
    Salidas
      quotiens => Lista con los cocientes obtenidos en cada iteración
      previousResidue => Ultimo residuo diferente de 0 calculado en el algoritmo, es decir, el gcd'''

    quotients = [] 
    residue = -1
    previousResidue = -1
    i = 0
    
    if mod%asker == 0: #verifica si asker es el gcd, si lo es, no tiene caso hacer el EA
        return quotients, asker
    else: #Si no, realiza el EA
        while(residue != 0): #Se detendrá cuando el residuo sea 0
            quotients.append(int(mod/asker)) #Calcula la parte entera del cociente y lo guarda en la lista de cocientes
            previousResidue = residue #Guarda el registro anterior en caso de que el residuo en esta iteración sea 0, pues de serlo, el anterior será el gcd
            residue = mod%asker #Calcula el residuo 
            mod = asker #Preparacion para la proxima iteración, el número mas pequeño se hace el mas grande...
            asker = residue #...y el residuo se hace el mas pequeño
        return quotients, previousResidue

def EEA(quotients, gcd):
    '''Funcion que realiza el algoritmo extendido de Euclides
    Entradas
      quotiens => Lista con los cocientes obtenidos en el EA
      gcd => gcd obtenido en el EA
    Salidas
      x => última x calculada en el EEA que representa el inverso previo a la operacion módulo'''

    stopper = len(quotients)-1 #Condición para detener el algoritmo, no se llegará al ultimo indice de los cocientes q
    i = 0
    previouspreviousX = 0
    previousX = 1
    x = 0
    
    while i<stopper: #se utiliza menor que porque la lista de coeficientes empieza en 0 en lugar de en 1 como en los ejercicios
        x = -1*quotients[i]*previousX + previouspreviousX #cálculo de x, donde x(i-1) es previousX y x(i-2) es previouspreviousX
        previouspreviousX = previousX #Preparación para la próxima iteración. PreviousPreviousX avanza una posicion...
        previousX = x #...y previousX avanza otra posicion, siendo para la proxima iteración la x que se calculó en esta iteración
        i = i + 1
    return x 


# def inverseMultiplicative(s1, s2):
s1 = 18
s2 = 45
'''Funcion principal
Entradas
    s1 => Número entero 
    s1 => Número entero 
Salidas
    Impresión del inverso multiplicativo'''
quotients = []
gcd = 0

mod = max(s1, s2)
asker = min(s1, s2)
quotients, gcd = EA(mod, asker) #Obtiene los cocientes y el gcd

if gcd != 1: #Si el gcd no fue 1...
    print("El gcd = {}. No existe un inverso multiplicativo".format(gcd)) #... no hay inverso multiplicativo
else: #Si lo fué...
    x = EEA(quotients, gcd) #Realiza algoritmo extendido de euclides
    inverse = x%mod #EL resultado se ajusta al conjunto con la operacion modulo
    print("El inverso multiplicativo de {} es {}".format(asker, inverse))