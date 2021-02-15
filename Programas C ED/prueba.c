#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void insercion(int *m, int n);
void seleccion(int *m, int n);
void quicksort(int *m, int inf, int sup);
void llamaqs(int *m, int n);
int busquedaSecuencial(int *m, int n, int l); //los elementos no deben estar repetidos y no necesitan estar ordenados
int busquedaBinaria(int *m, int n, int l);
	
int main(){
	int *a;
	int t;
	int i;
	clock_t start,end;
	printf("Indique el numero de casillas del arregalo\n");
	scanf("%d",&t);
	a=(int*)malloc(sizeof(int)*t);
	srand(time(NULL)); //funcion random
	for(i=0; i<t; i++){
		a[i]=rand();
}
	/*for(i=0; i<t; i++){
		printf("Posicion[%d]=%d\n",i,a[i]);
	}*/
	
	printf("-----------------\n");
	start=clock();
	insercion(a, t);
	end=clock();
	/*for(i=0; i<t; i++){
		printf("Posicion[%d]=%d\n",i,a[i]);
	}*/
return 0;
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

void seleccion(int *m, int n){
   //Solo hace un cambio por iteracion, el mas chico de todo el array lo mueve al inicio y el del inicio lo deja en donde estaba el mas chico. A	si iteracion con iteracion ira ordenando los datos. Es mas rapido que insercion pero menos eficaz que quicksort
	 //El mejor pivote y mas rapido sera el del centro
	 int i, j, sel, clave_sel, aux;
	 for(i=0; i<n; i++){
	 	sel=i;
	 	clave_sel=m[i];
	 	for(j=i+1;j<=n; j++){
	 		if(m[j]<clave_sel){
	 			clave_sel = m[j];
	 			sel=j;
			 }
		 }
		 aux=m[i];
		 m[i]=m[sel];
		 m[sel]=aux;
	 }	
}

void quicksort(int *m, int inf, int sup){
//todo con pivotes con menor a la izq mayor a la der. De os qs se hacen dos pequeñas listas a los lados del pivote y esas pequeñas listas se dividen en dos y esas dos se dividen de nuevo y... hasta que este ordenado
int izq = 0, der = 0;
int mitad=0, x=0;

izq=inf;
der=sup;
mitad=m[(izq+der)/2]; //como guarda en un int, aun si tiene .5 agarra el primer numero
do{
	while(m[izq]<mitad && izq<sup) izq++;
	while(mitad<m[der] && der>inf) der--;
	if(izq<=der){
		//sustitucion basica en cada metodo de ordenamiento
		x=m[izq];
		m[izq] = m[der];
		m[der] = x;
		izq++; 
		der--;
	}
}
while(izq<=der);
if(inf<der) quicksort(m, inf, der);

if(izq<sup) quicksort(m, izq, sup);


}

void llamaqs(int *m, int n){
	quicksort(m, 0, n-1);
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
