#include <iostream>
using std::cout;
using std::endl;
#include  <climits>

/*
*  Auther: Aman Arabzadeh
*  This is just for excersize purpose, please use this code if you feel like you need it, 
*  However mention the source, and authers name.
*
*
***********************************************************/

struct node{
	int data;
	node *next;
} *head = nullptr;



// Creating linked list array

void creat(int A[], size_t sizeOfArray){
	node *temp, *tail;
	head = new node;
	head->data = A[0];
	head->next = nullptr;
	tail = head;
	for(size_t index{1}; index < sizeOfArray; ++index){
		temp = new node;
		temp->data = A[index];
		temp->next = nullptr;
		tail->next = temp;
		tail = temp;
	}
}


// printing the list
void display(node *head){
	 node *temp = new node;
	 temp = head;
	 while(temp){ // same as temp != nullptr
	   cout << temp->data << "  ";
	   temp = temp->next;
	 }
	 cout << endl;
}

// Displaying recursivllly
void DisplayRec(node *head){
	if(head == nullptr){
		return;
	}else{
		DisplayRec(head->next);
		cout << head->data << "  ";     	
	}


	// Or you could just do so
	/*
	if(head !0 nullptr){
	    cout << head->data << "  ";
        (head->next);
	}
	cout << endl;     is easier to read
	}
	*/
}


// Counting the numbers of nodes in linked list 
size_t size(node *head){
	size_t counter{0};
	while(head){
		head = head->next;
		counter++;
	}
	return counter;
}

// Sum of the nodes data in linked list

size_t add(node *head){
	size_t total{0};
	while(head != nullptr){
		total+= head->data;
		head = head->next;
	}
	return total;
}

// Sum of the linked list nodes using recursion
size_t addRecursive(node *head){
	size_t total {0};
	if(head != nullptr){
	return 	addRecursive(head->next) +  head->data;
	}else{
		return 0;
	}

}

// finding the maximum element in linked list

int findMax(node *head){
	int maxElement = INT_MIN;
	while (head != nullptr){
		if(head->data > maxElement){
             maxElement = head->data;
		}
		head = head->next;
	}
	return maxElement;
}

// Finding maximum element using recursive 
int RFindMax(node *head){
	int maxElement = 0;
	if(head == nullptr){
		return INT_MIN;
	}else{
		maxElement = RFindMax(head->next);
		if(maxElement > head->data){
			return maxElement;
		} else{
			return head->data;
		}
	}
}


// Anotother way to find recursivlly maximum data is using tenerry operation ? : for easier to read
int RFindMax_T(node *head){
	int maxElement = 0;
	if(head == nullptr){
		return INT_MIN;
	}
	maxElement = RFindMax_T(head->next);
	return maxElement > head->data ? maxElement : head->data;
}


// Now we find the minumum in a linked list
int findMinimum(node *head){
	int minElement = INT_MAX;
	while(head != nullptr){
		if(head->data < minElement){
			minElement = head->data;
		}
		head = head->next;
	}
	return minElement;
}

// Finding minimum element using recursive 
int RFindMin(node *head){
	int minElement = 0;
	if(head == nullptr){
		return INT_MAX;
	}else{
		minElement = RFindMin(head->next);
		if(minElement < head->data){
			return minElement;
		} else{
			return head->data;
		}
	}
}

// Anotother way to find recursivlly min data is using tenerry operation ? : for easier to read
int RFindMin_T(node *head){
	int minElement = 0;
	if(head == nullptr){
		return INT_MAX;
	}
	minElement = RFindMin_T(head->next);
	return minElement < head->data ? minElement : head->data;
}




int main(){
	int A[] = {1,2,3,4,5,2000,999,-222,6,7,8,9,10,0,4, -1111};
	size_t length = sizeof(A)/sizeof(int);
	cout << " lngth is  " << length << endl;
	int t = 0;
	for(int i = 0; i < length; i++){
		t += A[i];
	}
	cout << "The total sum of linked list is:  " << t << endl;
	creat(A, length);
	display(head);
    cout << endl;
	DisplayRec(head);
	cout << endl;
	cout << "The size of linked list is:  " << size(head) << endl;
	cout << "The total sum of linked list is:  " << add(head) << endl;
	cout << endl;
	cout << "The total sum of linked list is:  " << addRecursive(head) << endl;
	cout << "Max element in list is:   " << findMax(head) << endl;
	cout << "Minimum number in integer is:  " << INT_MIN << endl;
	cout << "Max element in list is recursivlly:   " << RFindMax_T(head) << endl;
	cout << endl;
	cout << "Min element in list is:   " << findMinimum(head) << endl;
	cout << "Max number in integer is:  " << INT_MAX << endl;
	cout << "Min element in list is recursivlly:   " << RFindMin(head) << endl;
	cout << "Max element in list is recursivlly with ? : operator:   " << RFindMin_T(head) << endl;




	return 0;
}