#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Inventory{
	private:
	string codeItem;
	string description;
	double price;

	public:
	Inventory(){  // Defaulty construction
		codeItem = "XXXX"; 
		description = " ";
		price = 00.00;
	}
	Inventory(string codeItem, string description, double price){
		this->codeItem = codeItem;
		this->description = description;
		this->price = price;
	}

	// Getters 
	string getCode(){
		return codeItem;
	}
	string getdescription(){
		return description;
	}

	double getPrice(){
		return price;
	}
};  // End of the class




// function prototypes
void displayObjects(Inventory [], int);
void bubbleSort(Inventory [], int);


int main(){

	const int size = 6;
	Inventory obj[size] = { Inventory("S15", "soap spoon",  2.35),
							Inventory("S12", "teaspoon",    3.35),
							Inventory("F15", "dinner fork", 4.35),
							Inventory("F09", "sallad fork", 7.35),
							Inventory("K33", "knife",       9.35),
							Inventory("K41", "steak knife", 10.35)
	};


    // Display onsorted obj
	cout << "\n\nHere is the unsorted obj\n\n";
	displayObjects(obj, size);


   bubbleSort(obj, size);
    // Display onsorted obj
	cout << "\n\nHere is the sorted obj\n\n";
	displayObjects(obj, size);





	return 0;
}


// Function definitions
void displayObjects(Inventory obj[], int size){
	for(size_t index = 0; index < size; index++){
		cout << setw(5) << left << obj[index].getCode()
		<< setw(13) << left << obj[index].getdescription()
		<< "$" << right << obj[index].getPrice() << endl;
	}
	cout << endl;
}


void bubbleSort(Inventory obj[], int size){
	Inventory temp;
	bool swap;
	do
	{
		swap = false;
		for(size_t index = 0; index < (size -1); index++){
			if(obj[index].getCode() > obj[index + 1].getCode()){
				temp = obj[index];
				obj[index] = obj[index +1];
				obj[index +1 ] = temp;
				swap = true;
			}
		}
	} while (swap);
}