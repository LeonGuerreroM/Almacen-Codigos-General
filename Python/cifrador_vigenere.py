def generador_tabla():
    alfabeto = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
    tabla_vigenere = [] #guarda la tabla vigenere
    fila_temporal = [] #guarda la fila que se va a generar para añadirse
    letra_inicio = 0 #guardará la letra en la que tiene que iniciar la siguiente fila
    longitud_fila = 0 #para validar que la fila mide 26 letras
    indice = 0 #indice del alfabeto
    for i in range(26): #fila
        for j in range(26): #columna
            if indice > 25:
                indice = 0
            fila_temporal.append(alfabeto[indice])
            indice = indice + 1
        
        letra_inicio = letra_inicio + 1
        indice = letra_inicio
        tabla_vigenere.append(fila_temporal)
        fila_temporal = []
    return tabla_vigenere

def cifrador(texto_plano, clave):
    tabla_vigenere = [] #guarda la tabla vigenere
    cifrado = '' #guarda el texto cifrado
    condicion_clave = 0 #comprueba que la clave sea de cierta longitud
    repeticion_completa = 0 #el numero de veces que la palabra se replica completa
    letras_sobrantes = 0 #letras que se deben de tomar de la palabra para completar la replica de clave
    texto_plano_limpio = '' #texto plano sin espacios
    sobrantes = '' #almacena el pedazo de clave que se pondrá al final
    clave_repetida = '' #donde se almacena la clave repetida segun la longitud del texto 

    texto_plano = texto_plano.lower()
    clave = clave.upper()

    #quitando espacios del texto plano
    for i in texto_plano:
        if i == ' ': #identifica si es espacio y pasa la iteracion
            continue
        else:
            texto_plano_limpio = texto_plano_limpio + i #si no es, lo añade a un nuevo string

    #repeticion de la clave
    repeticion_completa = int(len(texto_plano_limpio)/len(clave)) #numero de veces que se va a repetir
    letras_sobrantes = len(texto_plano_limpio)%len(clave) #cuantas letras de clave faltarán
    sobrantes = clave[:letras_sobrantes] #se obtienen esas letras que van a faltar
    for i in range(repeticion_completa):
        clave_repetida = clave_repetida + clave #se repite la clave ese numero de veces
    clave_repetida = clave_repetida + sobrantes #a lo anterior se le suma las letras adicionales

    #generando tabla vigenere
    tabla_vigenere = generador_tabla()

    #cifrado
    for i in range(len(texto_plano_limpio)): #para recorrer texto y clave
        letra_plana = texto_plano_limpio[i] #escoge una letra del texto y clave
        letra_clave = clave_repetida[i] #en python se puede acceder a los strings con indices como arreglos
        for j in range(26):
            if tabla_vigenere[0][j] == letra_plana: #obtiene en que columna está a partir de la primera
                y = j
            if tabla_vigenere[j][0].upper() == letra_clave: #en que fila está a partir de la primera columna  
                x = j
        cifrado = cifrado + tabla_vigenere[y][x] #agrega la letra que corresponde a un string que guarda el texto cifrado

    cifrado = cifrado.upper()
                
    return cifrado

def descifrador(texto_cifrado, clave):
    tabla_vigenere = [] #guarda la tabla vigenere
    condicion_clave = 0 #comprueba que la clave sea de cierta longitud
    repeticion_completa = 0 #el numero de veces que la palabra se replica completa
    letras_sobrantes = 0 #letras que se deben de tomar de la palabra para completar la replica de clave
    sobrantes = '' #almacena el pedazo de clave que se pondrá al final
    clave_repetida = '' #donde se almacena la clave repetida segun la longitud del texto
    descifrado = '' #guarda el texto descifrado

    texto_cifrado = texto_cifrado.lower()
    clave = clave.upper()

    #repeticion de la clave
    repeticion_completa = int(len(texto_cifrado)/len(clave)) #numero de veces que se va a repetir
    letras_sobrantes = len(texto_cifrado)%len(clave) #cuantas letras de clave faltarán
    sobrantes = clave[:letras_sobrantes] #se obtienen esas letras que van a faltar
    for i in range(repeticion_completa):
        clave_repetida = clave_repetida + clave #se repite la clave ese numero de veces
    clave_repetida = clave_repetida + sobrantes #a lo anterior se le suma las letras adicionales

    #generando tabla vigenere
    tabla_vigenere = generador_tabla()

    #descifrado
    for i in range(len(texto_cifrado)): #para recorrer texto y clave
        letra_cif = texto_cifrado[i] #escoge una letra del texto y clave
        letra_clave = clave_repetida[i] #en python se puede acceder a los strings con indices como arreglos
        for j in range(26):
            if tabla_vigenere[0][j].upper() == letra_clave: #obtiene en que columna está a partir de la primera
                for k in range(26):
                    if tabla_vigenere[k][j] == letra_cif:
                        y = k 

        descifrado = descifrado + tabla_vigenere[y][0] #agrega la letra que corresponde a un string que guarda el texto cifrado

    return descifrado

def frecuencias(texto_cifrado):
    letras_cifrado = [] #guarda las letras presentes en el mensaje cifrado solamente una vez
    frecuencias = [] #almacena las frecuencias de las letras  que estuvieron presentes
    repetido = 0 #bandera de repetición
    repeticiones = 0 #almacena el numero de repeticiones de cada letra

    texto_cifrado = input("Ingrese el mensaje cifrado: ")

    for i in texto_cifrado: #toma una letra del texto
        for j in letras_cifrado: #recorre las letras ya agregadas a la lista
            if i == j: #si la letra ya fue agregada, indica que está repetida
                repetido = 1
        if repetido == 0: #en caso de que no esté repetida, la agrega
            letras_cifrado.append(i) 
        repetido = 0
        
    letras_cifrado.sort() 

    for i in letras_cifrado: #toma una letra de la lista de las que aparecen
        for j in texto_cifrado: #revisará el texto letra por letra
            if i == j: #en cada ocasion que encuentre la letra i en el texto, se aumentará una repetición
                repeticiones = repeticiones + 1 
        frecuencias.append(repeticiones) 
        repeticiones = 0 #poniendolo al final me ahorro una instruccion innecesaria la primera vez, porque ya está inicializado

    return letras_cifrado, frecuencias

def frecuencias_grupos(texto_cifrado): 

    tamanio_grupo = [2, 3, 4, 5, 6, 7, 8] #guarda los posibles tamaños de los grupos
    grupo = '' #va guardando el grupo temporal
    grupo2 = '' #guarda el grupo temporal que compara 
    inicio_formacion_grupo = 0 #contador de donde van los inicios de grupo en el texto cifrado 
    contador2 = 1 #contador de cuanto hay que sumar al contador inicial
    inicio_grupo_busqueda = 0 #contador que indica donde va la busqueda 
    grupos = [] #donde se guardan los grupos
    repeticion = -1 #guarda temporalmente el numero de repeticiones
    frecuencias = [] #donde van las frecuencias de los grupos
    unido = 0 #verifica si el grupo no ha sido unido a la lista de grupos
    aniadido = 0 #para saber que ese grupo debe pasar a la fase de conteo de frecuencias
    espaciado = 0 #indica el espacio que hay entre repeticiones
    espaciados = [] #guarda los espaciados de las repeticiones
    condicion = 0

    texto_cifrado = input("Ingrese el mensaje cifrado: ")
    for i in tamanio_grupo: #determina de cuanto serán los grupos
        #que pasa cuando los rangos se superan
        for j in range(len(texto_cifrado)): #recorre el texto cifrado para formar un grupo
            if inicio_formacion_grupo<len(texto_cifrado): #por si el indice ya es mayor que las letras que hay
                grupo = texto_cifrado[inicio_formacion_grupo] #empieza el grupo con la letra siguiente a donde se quedó
            else:
                grupo = ""
            for k in range(i-1): #se repite el tamaño del grupo - 1
                if inicio_formacion_grupo+contador2>=len(texto_cifrado): #validación de que el numero que le voy a sumar no salga del tamaño 
                    continue #del string, si es asi, ese grupo ya no se considera
                grupo = grupo + texto_cifrado[inicio_formacion_grupo+contador2] #para agregar las letras faltantes y juntar el grupo de ese tamaño
                contador2 = contador2 + 1 #este guarda lo que hay que sumarle, es decir, cuanto va avanzando mas allá de donde se quedo el inicio 
            if grupo != "": #solo agrega si el grupo no es vacio
                for n in grupos: #recorre para buscar si el grupo ya fue unido
                    if n == grupo:
                        unido = 1
                        break
                if unido == 0 and len(grupo)==i: #si no lo fue y si es un grupo de la longitud que marca la i
                    grupos.append(grupo) #agrega el grupo a la lista de grupos
                    aniadido = 1
            inicio_formacion_grupo = inicio_formacion_grupo + 1
            contador2 = 1
            unido = 0
            if grupo != "" and aniadido == 1:
                aniadido = 0
                for l in range(len(texto_cifrado)): #inicia la busqueda del grupo en el texto cifrado
                    if inicio_grupo_busqueda<len(texto_cifrado):
                        grupo2 = texto_cifrado[inicio_grupo_busqueda] #inicia un grupo para comparar en donde se quedo este indice
                        if repeticion > -1:
                            espaciado = espaciado + 1
                    else:
                        grupo2 = ""
                    for m in range(i-1): #se repite el numero de veces del tamaño del grupo - 1
                        if inicio_grupo_busqueda+contador2>=len(texto_cifrado):
                            continue
                        grupo2 = grupo2 + texto_cifrado[inicio_grupo_busqueda+contador2] #le suma las letras siguientes necesarias
                        contador2 = contador2 + 1
                        #espaciado = espaciado + 1
                    #hasta aqui, se formó un grupo de prueba
                    if grupo == grupo2: #si este grupo es el mismo que el agregado al arreglo de grupos, agrega una a esa repeticion
                        repeticion = repeticion + 1
                        if condicion == 0 and repeticion > 0:
                            espaciados.append(espaciado-2)
                            espaciado = 0
                            condicion = 1
                    inicio_grupo_busqueda = inicio_grupo_busqueda + 1  #en cualquier caso, añade uno y vuelve a formar otro grupo  
                    contador2 = 1
                frecuencias.append(repeticion)
                if repeticion < 1:
                    espaciados.append(-1)
                espaciado = 0
                condicion = 0
                inicio_grupo_busqueda = 0 
                repeticion = -1
        inicio_formacion_grupo = 0
    return grupos, frecuencias, espaciados