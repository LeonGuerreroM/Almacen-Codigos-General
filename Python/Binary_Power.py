def binary_method(base, exponent, module):
    '''Funcion que realiza la potenciación modular con el método binario
    Entradas
        base => base de la potencia
        exponent => exponente de la potencia
        module => módulo de la potenciación modular
    Salidas
        C => resultado de la potenciación modular '''
    
    binary_exp = 0 #Guarda el equivalente binario de la potencia
    #is_first = 1 #Indicador que se está trabjando con el bit mas significativo
    first_bit = 0
    C = 0
    
    if module == 0:
        print("El módulo no es válido") 
        return -1
    elif module == 1:
        return 0 
    
    #if exponent == 0: 
     #   if module == 1: #quedo cubierto con mod 1
       #     return 0
      #  else: #queda cubierto con C=1. Este es mas directo pero el otro sigue el algoritmo
       #     return 1
    
    binary_exp = bin(exponent)[2:] #Convierte el exponente a binario, como str
    first_bit = binary_exp[:1]
    binary_exp = binary_exp[1:]
    if first_bit == '1': #Si el mas significativo es 1
        C = base 
    else: #Si es 0, C = 1, a menos que sea mod 1, pero ese caso ya se cubrió
        C = 1
    
    #print(first_bit)
    #print(binary_exp)
    #print(C) 
    
    for i in binary_exp: #Recorre comenzando por el más significativo
        '''if is_first == 1: #En caso de que sea el mas significativo
            is_first = 0    Normalmente habría hecho esto, pero se desperdicia procesamiento preguntando a todos
            if i == 1:      Cuando simplemente se podría hacer fuera del for y no tomar el primer bit
                C = M       Hacer ese slice sería menos gasto de recursos que una validación por iteración
            else:           Despues del slice ya solo tenemos que hacer lo que si compete a este for
                C = 1       Aprendizaje: Si solo tienes que hacer algo en la primera o ultima iteración, hazlo afuera
                            ya sea antes o despues y empieza o termina la iteración despúes o antes '''
        C = C**2         #Siempre se eleva C al cuadrado
        if C > module-1: #Si excede el campo del módulo se saca el residuo
            C = C%module
            
        if i == '1': #Si el bit es 1
            #print("entré")
            C = C*base #se multiplica por M
            if C > module-1: #Si excede el campo del módulo se saca el residuo
                C = C%module
    
    #print("El resultado de {}^{} mod {} es {C}".format(base, exponent, module, C))
    return C
        
result = binary_method(3, 158215211234689, 53)
if result != -1:
    print("El resultado es {}".format(result))