
plain_text = "" #almacena la entrada de texto sin cifrar
plain_text_limpio = "" #guarda el plain text sin espacios
key = 0 #guarda la cantidad de filas del cifrador
numero_linea = 0 #indica la linea a la que se agrega la letra
aumento = 1 #indica si la linea va aumentado o decreciendo
lineas = [] #almacena las lineas con letras 
cipher_text = "" #almacena el texto cifrado final 
indice = 0 

plain_text = input("Ingresa el texto a cifrar\n") #elwarzonealas9
key = int(input("Ingrese la clave\n"))
indice=0

for i in range(key):
    lineas.append("")

for i in plain_text: #quitamos los espacios del plain_text
    if i != " ":
        plain_text_limpio = plain_text_limpio + i

for i in plain_text_limpio:
    if numero_linea == 1:
        aumento = 1
    elif numero_linea == key:
        aumento = 0
    
    if aumento == 1:
        numero_linea = numero_linea + 1
    elif aumento == 0:
        numero_linea = numero_linea - 1
    
    lineas[numero_linea-1] = lineas[numero_linea-1] + i

for i in lineas:
    lineas[indice] = lineas[indice] + " "
    indice = indice + 1

for i in lineas:
    cipher_text = cipher_text + i
    
print("El texto cifrado es: ",cipher_text)

saltos = (key - numero_linea) + (key-numero_linea-1) 