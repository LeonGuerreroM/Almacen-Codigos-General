#include<stdio.h>
#include<stdlib.h>


int busquedaSecuencial(int *m, int n, int l); //los elementos no deben estar repetidos y no necesitan estar ordenados
int busquedaBinaria(int *m, int n, int l);
void insercion(int *m, int n);
int main(){
	int n = 6;
	int i;
	int array[]={12,543,76,34,65,78};
	
	int x= busquedaSecuencial(array, 65, n);
	if(x!=-1){
		printf("El numero esta en la posicion %d \n",x);
	}else{
		printf("El numero no se encontro\n");
	}
	printf("--------------\n");
	x=busquedaBinaria(array, 65, n);
	if(x!=-1){
		printf("El numero esta en la posicion %d \n",x);
	}else{
		printf("El numero no se encontro\n");
	}
	
	return 0;
}

int busquedaSecuencial(int *m, int n, int l){ //tambien lineal. Es una busqueda comun uno por uno en todo el arreglo para saber donde esta...si es que esta
//si tiene numeros repetidos te dara la posicion del primer numero de ese tipo que encuentre. El repetido no
	int i;
	int aux;
	for(i=0; i<l; i++){
		if(n==m[i]){
			return i;
			aux=i;
			break;
		}else aux=-1; //mas eficaz
	}
	return aux;
	
	/*if(n==m[l-1]){ //comprabacion 
		return l-1;
	}else{
		return -1;
	}*/
}

int busquedaBinaria(int *m, int n, int l){
	//debe estar ordenada y el espacio de busqueda se acorta porque va de dos en dos
	//si tiene numeros repetidos te dara la posicion del primer numero de ese tipo que encuentre. El repetido no

	insercion(m,l);
	int mitad, inf=0, sup=l-1;
	do{
		mitad = (inf+sup)/2;
		if(n>m[mitad])
			inf = mitad+1;
		else
			sup=mitad-1;
	}
	while(m[mitad]!=n&&inf<=sup);
	if(m[mitad]==n){
		return mitad;
	}
	else
	 	return -1;
}

void insercion(int *m, int n){
	//esta cosa es como burbuja pero en una iteracion, si el que seleccionaste es el mas chico comparado con sus ateriores lo deja hasta donde debe. Varios intercambios por oteracion segun lo que yo necesiite mover mi numero chiquito. Se tarda mas que seleccion
	int k, i;
	int x;
	//desde el segundo elemento
	for(i=1; i<n; i++){
		x = m[i];
		k = i-1;
		//para k=-1, se ha alcanzado el extremo izquierdo
		while(k>=0 && x<m[k]){
			m[k+1] = m[k];
			k--;
		}
		m[k+1]=x;
	}
}
