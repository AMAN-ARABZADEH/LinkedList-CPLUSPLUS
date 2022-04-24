#include <iostream>

using namespace std;

// function prototypes

void bubbleSort(int [], int);
void printArr(int [], int);




// Bubble sort is inafficiant, lets apply selection sort now
void selectionSort(int [], int);


int main(){
     
	int arr[] = {1,9,-9,3,1,8,6,4,5,6,7,4,22,34,-7,32,21,1,2,4,5,65,32,1,2,3,21,1,1,2,1,7,8,9,0,8,-9,-666,-5544,9229,2,01,92,38,2221,-23,
	   				1,2,3,9,8,7,6,5,43,2,2,3,4,5,43,2,1,1,0,9,8,7,5,4,3,2,2,4,2,1,1,1,1,1,1,0,-4,4,2,2,2};
					   
	int length = sizeof(arr) / sizeof(int);

    cout << "The size of the array is: " << length << endl << endl;
	printArr(arr, length);
	cout << "\n\n\n\nSelection sort is being performed." << endl << endl;

	// Selection sort is being performed now
	selectionSort(arr, length);
    printArr(arr, length);


	return 0;
}




void bubbleSort(int arr[], int size){
	int temp;
	bool swap;
	do
	{
	 swap = false;
	 for(size_t i = 0; i < (size -1); i++){
		 if(arr[i] > arr[i+1]){
			 temp = arr[i];
			 arr[i] = arr[i+1];
			 arr[i+1] = temp;
			 swap = true;
		 }
	 }
	} while (swap);
	

}
void printArr(int arr[], int size){
	cout << "Array being printed: " << endl;
	for(size_t i = 0; i < size; i++){
		cout << arr[i] << "   ";
	}
	cout << endl;

}


// Selection sort

void selectionSort(int arr[], int size){
	int startScan, minValue, minIndex;
	for(startScan = 0; startScan <(size -1); startScan++){
		minIndex = startScan;
		minValue = arr[startScan];
		for(size_t index = startScan + 1; index <size; index++){
			if(arr[index] < minValue){
				minValue = arr[index];
				minIndex = index;
			}
		}
		arr[minIndex] = arr[startScan];
		arr[startScan] = minValue;
	}
}


