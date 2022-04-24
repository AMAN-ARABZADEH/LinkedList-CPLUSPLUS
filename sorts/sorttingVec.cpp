#include <iostream>
#include <vector>

using namespace std;

//prototype
void display(vector<int>);
void sortVec(vector<int> &);
int binarySearch(vector<int> , int);


int main(){

	const int size = 6;
	vector<int> values(size);
	
	cout << "please enter " << size << " values to sort:\n";
	for(int i = 0; i < size; i++){
		cin >> values.at(i);
	}
       cout << "\nBefor sorting:\n";
	display(values);
	sortVec(values);
    cout << "\nfter sorting:\n";
	display(values);

	vector<int> myvec = {1,2,3,4,5,56,77};

	cout << "\n\n\nSearch for a value from the list: ";
	int search;
	cin >> search;


	int result = binarySearch(values, search);

	if(result == -1){
		cout << "The value " << search << " does not exist in the list:" << endl; 
	}else{
		cout << "We found value  " << search << "  at " << result <<   endl; 
	}


	return 0;
}


// definition
void display(vector<int> value){
	for(int val : value){
		cout << val << " ";
	}
	cout << endl;
}
void sortVec(vector<int> &values){
	int temp;
	bool swap;
	do
	{
	swap = false;
	for(int i = 0; i < (values.size() -1); i++){
		if(values.at(i) >values.at(i +1) ){
			temp = values.at(i);
			values.at(i) = values.at(i +1);
			values.at(i+1) = temp;
			swap = true;
		}
	}
	} while (swap);
}

int binarySearch(vector<int> vecValues, int target){
	int first = 0;
	int last = (vecValues.size() -1);
	int middle;
	int position = -1;
	bool found = false;
	while(!found && first <= last){
		middle = (first + last ) / 2;
		if(vecValues.at(middle) == target){
			position = middle;
			found = true;
		}else if(vecValues.at(middle) > target){
			last = middle - 1;
		}else{
			first = middle + 1;
		}
	}
    return position;
}