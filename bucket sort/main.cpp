#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

void BucketSort(float *array, int size){
	vector<float> bucket[size];      //Creamos un vector bucket
	
	//Ponemos los elementos de nuestro array a bucket
	for(int i = 0; i<size; i++){
		bucket[int(size*array[i])].push_back(array[i]);
	}
	
	//Ordenamos los elementos de bucket
	for(int i = 0; i<size; i++){
		sort(bucket[i].begin(), bucket[i].end());
	}
	
	//colocamos los elementos en nuestro arreglo original
	int index = 0;
	
	for(int i = 0; i<size; i++){
		while(!bucket[i].empty()){
			array[index++] = *(bucket[i].begin());
			bucket[i].erase(bucket[i].begin());
		}
	}
}

//Mostramos nuestros elementos de nuestro arreglo

void ShowArray(float *array, int size){
	for(int i = 0; i<size; i++)
		cout << array[i] << " ";
	cout << endl;
}

int main(int argc, char** argv) {
	
	srand(time(NULL));
	int n;
	
	cout<<"Ingrese el numero de elementos: "; cin>>n;
	float arr[n];
	cout<<"Ingrese los elementos: "<<endl;
	
	for(int i = 0; i<n; i++){
		cin>>arr[i];
	}
	
	system("cls");
	
	cout << "\n:::::::ARREGLO INGRESADO:::::::\n\n";
	ShowArray(arr,n);
	
	BucketSort(arr, n);
	
	cout << "\n\n:::::::ARREGLO ORDENADO:::::::\n\n";
	ShowArray(arr,n);
}
