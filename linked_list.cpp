#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include  <climits>
#include <stack>
#include <cstring>
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
} *head = nullptr, *second = nullptr, *third = nullptr;



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


// Creating linked list array2

void creat2(int A[], size_t sizeOfArray){
	node *temp, *tail;
	second = new node;
	second->data = A[0];
	second->next = nullptr;
	tail = second;
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

// Searching linked list logic linear search slow )= 
 node *sLearch(node *head, int key){
	while(head != nullptr){
		if(head->data == key){
			return head;
		}
		head = head->next;
	}
	return nullptr;
}


// Now searching recursivly 
node *LsearchR(node *head, int key){
	// Terminating logic
	if(head == nullptr){
		return nullptr;
	}else if( key == head->data){
		return head;
	}
	return LsearchR(head->next, key);
}

/// search  a bit faster by using temp node, and 
// modifying the head temp->next = head->next
// it changes the osition of found nod to the first index in the list 
// Lets see the code 

node *searchTransposnode(node *PHead, int key){
	node *tail = nullptr;
	while(PHead != nullptr){
		if(key == PHead->data){
			tail->next = PHead->next;
			PHead->next = head;
			head = PHead;
		    return PHead;
		}
		tail = PHead;
		PHead = PHead->next;
	}
	return nullptr;
}

void insert(int val, int pos){
	node *temp_node, *current_node;
	if(pos == 0){
		temp_node->data = val;
		temp_node->next = head;
		head = temp_node;
	} current_node = head;
	for(size_t index = 0; index < pos -1 && current_node != nullptr; index++){
		current_node = current_node->next;
	}
	if(current_node != nullptr){
	temp_node  = new node;
	temp_node->data = val;
    temp_node->next = current_node->next;
	current_node->next = temp_node;
	}
}



// Lets reverse the list 
// For reversing we need three nodes, *current, *prev, and *next

void reverseList(){
	node *current, *prev, *next;
	current = head;
	prev = nullptr;
	while(current != nullptr){
		next = current->next;    //   next is the value of next value node
		current->next = prev; 
		prev = current;   // To null change pointer   
		current = next;  // now prev has the address current
	}
	// Out of loop afte we reach nullptr
	head = prev;  // we are end of list, head should be prev last element
}

// Inserting at any position in linked list ex 1

void Insert(node *p, int pos, int x){
	if(pos < 0 or pos > size(p) ){
		std::cerr << "Invalid position!:::::::::" << std::endl;
		return;
	}
	node *temp = new node;
	temp->data = x;

	if(pos == 0){
		temp->next = head;
		head = temp;
	}else if(pos > 0){
		for(int i = 0; i < pos - 1; i++){
			p = p->next;
		}
	    if(p != nullptr){
			temp->next = p->next;
			p->next = temp;
		}
	}
}


/// now insert return head
node *inserts(node *head, int value){
	node *current = new node;
	current->data = value;
	current->next = nullptr;
	if(head == nullptr){
		head = current;
	}else{
		node *current_node = head;
		while(current_node != nullptr){
			current_node = current_node->next;
			current_node->next = current;
		}
	}
	return head;
}


// Insert in a sorted list 
void insert_in_sorted_list(node *node_name, int value){
	node *current, *temp_node = nullptr;
	current = new node;
	current->data = value;
	current->next = nullptr; 
	if(head == nullptr)
	{
		head = current;
	}
	else
	{
		while(node_name != nullptr && node_name->data < value)
		{
			temp_node = node_name;
			node_name = node_name->next;
		}
		if(node_name == head)
		{
			current->next = head;
			head = current;
		}
		else
		{
			current->next = temp_node->next;
			temp_node->next = current;
		}
	}

}
























// Check for balanced parentheses using stack 


bool parenthesisChecker(char  arr[]){
	int size = strlen(arr);  // Takes the size of the input
	std::stack<char> stk;
	for(size_t i = 0; i < size; i++){
		if(arr[i]== '(' or arr[i] == '[' or arr[i]  == '{' ){
			stk.push(arr[i]);
		}else if(arr[i] ==  ')' or arr[i] == ']' or arr[i] == '}' ){
			if(stk.empty()){
				return false;
			}else{
				stk.pop();
		    }
	    }    
	}
	if(stk.empty()){
		return true;
	}
	return false;
}


void removeDuplicate(node *current){
	node *next_node = current->next;
	while(next_node != nullptr){
		if(current->data != next_node->data){
			current = next_node;
			next_node = next_node->next;
		}else{
			current->next = next_node->next;
			delete next_node;
			next_node = current->next;
		}

	}
}

// reversing using temp array
void reverseUsingArr(node *p){
	int *A, i = 0;
	node *q =p;
	A = (int*)malloc(sizeof(int)*size(p));
	while(q != nullptr){
		A[i] = q->data;
		q = q->next;
		i++;
	}
	q = p;
     i--;
	while(q != nullptr){
		q->data = A[i];
		q= q->next;
		i--;
	}
}




/// Reverse the linked list
void reverseingList(node *p){
	node *q = nullptr;
	node *r = nullptr;

	while (p != nullptr)
	{
		r = q;
		q = p;
		p = p->next;
		q->next = r;
	}
	head = q;
	
}



void reverserecurise(node *q, node *p){
	if(p != nullptr){
		 reverserecurise(p, p->next);
		 p->next = q;
	}
    else
	head = q;

}



void concat(node *first, node *second){
	third = first;
	while(first->next != nullptr){
		first = first->next;
	}
	first->next = second;

}

void Merge(node *p, node *q){
	node *last;
	if(p->data < q->data){
		third = last = p;
		p = p->next;
		third->next = nullptr;
	}else{
		third = last = p;
		p = p->next;
		third->next = nullptr;
	}


	while(p != nullptr && q != nullptr){
		if(p->data < q->data){
			last->next = p;
			last = p;
			p = p->next;
			last->next = nullptr;
		}else{
			last->next = q;
			last = q;
			q = q->next;
			last->next = nullptr;
		}
	}
	if(p != nullptr){
		last->next = p;
	}
	if(q != nullptr){
		last->next = q;
	}
}



/*
  Here I implement circular linked list
  ****
**

*/


void displayCircular(node *p){
	do  // We need do while loop because we don't want to get out of loop first time
	{
		cout << p->data << " ";
		p = p->next;
	} while (p != head);	
		cout << endl;
}

// Now using recursion to print the lists
// We need a temp
void displayCircularRecursion(node *p){
static bool flag = false;
	if(p != head or flag == false){
		flag = true;
		cout << p->data << " ";
		displayCircularRecursion(p->next);
	}    
	cout << endl;
}


// Now creating circular linke dlist type atrray in n size
void creatCircular(int A[], int n){
	node *current, *last;
	head = new node;
	head->data = A[0];
	head->next = head;
	last = head;
	for(size_t i = 1; i < n; i++){
		current = new node;
		current->data = A[i];
		current->next = last->next;
		last->next = current;
		last = current;
	}
}

int main(){
	/*

int A[] = {1,2,3,4,5,2000,999,-222,6,7,8,9,10,0,4, -1111};
	size_t length = sizeof(A)/sizeof(int);
	cout << " lngth is  " << length << endl;
	int t = 0;
	for(int i = 0; i < length; i++){
		t += A[i];
	}
	// cout << "The total sum of linked list is:  " << t << endl;
	creat(A, length);
	display(head);
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
	cout << "Max element in list is recursivlly with ? : operator :   " << RFindMin_T(head) << endl;
	node *searchNode, *searchNodeR, *searchNodeFaster;
	searchNode =sLearch(head, 2);
	searchNodeR = LsearchR(head, 999);
	searchNodeFaster = searchTransposnode(head, -1111);
	searchNodeFaster = searchTransposnode(head, 999);
	searchNodeFaster = searchTransposnode(head, 6);
	
	if(searchNode != nullptr){
		cout << "Searching result found........  " <<   searchNode->data << endl; 
	}else{
		cout << "Note fount!........ " << endl;
	}
	if(LsearchR != nullptr){
		cout << "Searching result recursivlly found........  " << searchNodeR->data   << endl;
	}else{
		cout << "Note fount!........ " << endl;
	}
	if(searchNodeFaster != nullptr){
		cout << "Searching result recursivlly found........  " << searchNodeFaster->data   << endl;
	}else{
		cout << "Note fount!........ " << endl;
	}

    node *temp = nullptr;

    reverseList();
   display(head);


 char  par[] = "[][][](()[])";


bool checkIF = parenthesisChecker(par);

if(checkIF == true){
	cout << "The list is even" << endl;
}else{
	cout << "List is not even" << endl;
}



	*/


int A[] = {-111,2,3,4,5,5,6,7,8,9,9,10,10};
int B[] = {9,2,3,4,5,5,6,7,8,9,66,200, 333};
int siz = sizeof(A) / sizeof(int);
 
creatCircular(A, siz);
displayCircularRecursion(head);



	return 0;
}