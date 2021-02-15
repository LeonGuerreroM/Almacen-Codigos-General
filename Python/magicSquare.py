import numpy as np

magic_square = []
auxiliar_vector = []
matrix_order = 0
central_column = 0
counter = 0
next_column = 0
next_row = 0


while(1):

    while(1):
        print("Ingrese el orden de la matriz impar")
        matrix_order = int(input())
        if matrix_order%2 == 0:
            print("El orden de la matriz debe ser impar")
        elif matrix_order%2 == 1:
            break

    magic_square = np.zeros((matrix_order,matrix_order)) #Crea la matriz
            
    for i in range(matrix_order*matrix_order):
        i = i + 1
        if i == 1:
            central_column, r = divmod(matrix_order/2, 1)
            magic_square[matrix_order-1][int(central_column)] = 1
            
            next_column = int(central_column)
            
            if next_column+1 < matrix_order:
                next_column = next_column+1
            else:
                next_column = 0
            int(next_column)    
            int(next_row)     
        else:
            if magic_square[next_row][next_column] == 0:
                magic_square[next_row][next_column] = i
            else:
                next_row = next_row-1
                next_column = next_column-2
                magic_square[next_row][next_column] = i
            
            if next_column+1 < matrix_order:
                next_column = next_column + 1
            else:
                next_column = 0
            
            if next_row + 1 < matrix_order:
                next_row = next_row + 1
            else:
                next_row = 0
            int(next_column)    
            int(next_row) 
    
    print("Cuadrado mágico de {} orden".format(matrix_order))  
    print(magic_square)
