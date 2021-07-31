#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <cmath>

using namespace std;

void ShowArray(int *array, int size) {
	for(int i = 0; i<size; i++)
		cout << array[i] << " ";
	cout << endl;
}
void RadixSort(int *arr, int n, int max) {
	
	int i, j, m, p = 1, index, temp, count = 0;
   
	list<int> pocket[10];      
	for(i = 0; i< max; i++) {
		m = pow(10, i+1);
		p = pow(10, i);
		for(j = 0; j<n; j++) {
			temp = arr[j]%m;
			index = temp/p;      
			pocket[index].push_back(arr[j]);
		}
		count = 0;
		for(j = 0; j<10; j++) {
         
			while(!pocket[j].empty()) {
				arr[count] = *(pocket[j].begin());
				pocket[j].erase(pocket[j].begin());
            	count++;
        	}
    	}
	}
}

int Number_Random(int ini, int fin){
	return rand()%(fin-ini+1)+ini; //Generador de numeros aleatorios
}

int main(int argc, char** argv) {
	
	srand(time(NULL));
	int n, max;
	cout << "Ingrese la cantidad de Elementos: ";
	cin >> n;
	cout << "Ingrese el maximo numero de Digitos: ";
	cin >> max;
	int arr[n]; //Creamos un nuevo arreglo de n elementos
	
	for(int i = 0; i<n; i++) {
		arr[i] = Number_Random(1,1000);
	}
	cout << "\n:::::::ARREGLO INGRESADO:::::::\n\n";
	ShowArray(arr, n);
   
	RadixSort(arr, n, max);
   
	cout << "\n\n:::::::ARREGLO ORDENADO:::::::\n\n";
	ShowArray(arr, n);
   
}
