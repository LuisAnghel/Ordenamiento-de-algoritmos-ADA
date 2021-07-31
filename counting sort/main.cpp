#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;

void ShowArray(int *array, int size) {
	for(int i = 1; i<=size; i++)
		cout << array[i] << " ";
	cout << endl;
}

int GetMax(int array[], int size) {
	int max = array[1];
	for(int i = 2; i<=size; i++) {
		if(array[i] > max)
			max = array[i];
	}
	
	return max; //Retorna el maximo elemento del arreglo
}
void CountSort(int *array, int size) {
	int output[size+1];
	int max = GetMax(array, size);
	int count[max+1];     //Creamos un nuevo arreglo
	for(int i = 0; i<=max; i++)
		count[i] = 0;     //Inicializamos el todo el arreglo en cero
   
	for(int i = 1; i <=size; i++)
		count[array[i]]++;     //Ingresamos los valores de i al arreglo
   	
	for(int i = 1; i<=max; i++)
		count[i] += count[i-1]; //Sumamos +1 a cada posicion del arreglo
   	
	for(int i = size; i>=1; i--) {	
		output[count[array[i]]] = array[i];
		count[array[i]] -= 1; //Cuando el numero se repite disminuimos
	}
   	
	for(int i = 1; i<=size; i++) {
		array[i] = output[i]; //Pasamos el arreglo ordenado a nuestra matriz
	}
}

int Number_Random(int ini, int fin){
	return rand()%(fin-ini+1)+ini; //Generador de numeros aleatorios
}

int main(int argc, char** argv) {
	
	srand(time(NULL));
	int n;
	cout << "Ingrese la cantidad de Elementos: "; cin >> n;
	
	int arr[n+1]; 
	
	for(int i = 1; i<=n; i++) {
		arr[i] = Number_Random(1,1000);
	}
	cout << "\n:::::::ARREGLO INGRESADO:::::::\n\n";
	ShowArray(arr, n);
	
	CountSort(arr, n);
	
	cout << "\n\n:::::::ARREGLO ORDENADO:::::::\n\n";
	ShowArray(arr, n);
}
