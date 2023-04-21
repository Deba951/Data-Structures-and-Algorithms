// C++ program to implement basic stack operations
#include <bits/stdc++.h>
using namespace std;

#define MAX 1000 	// Pre defined maximum value of stack.

class Stack {
	int top;

public:
	int a[MAX]; // Maximum size of Stack

	Stack() { top = -1; }
	bool push(int x);
	int pop();
	int peek();
	bool isEmpty();
};

bool Stack::push(int x){

	if (top >= (MAX - 1)) {
		cout << "Stack Overflow";
		return false;
	}
	
    else {
		a[++top] = x;
		cout << x << " pushed into stack\n";
		return true;
	}
}

int Stack::pop(){

	if (top < 0) {
		cout << "Stack Underflow";
		return 0;
	}
	
    else {
		int x = a[top--];
		return x;
	}
}

int Stack::peek(){

	if (top < 0) {
		cout << "Stack is Empty";
		return 0;
	}
	
    else {
		int x = a[top];
		return x;
	}
}

bool Stack::isEmpty(){
	return (top < 0);
}

// Driver program to test above functions
int main(){

	class Stack s;
	s.push(10);
	s.push(20);
	s.push(30);
	cout << s.pop() << " Popped from stack\n";
	//print all elements in stack :
	cout<<"Elements present in stack : ";
	
    while(!s.isEmpty()){
		// print top element in stack
		cout<<s.peek()<<" ";
		// remove top element in stack
		s.pop();
	}

	return 0;
}

/*Output : 

10 pushed into stack
20 pushed into stack
30 pushed into stack
30 Popped from stack
Top element is : 20
Elements present in stack : 20 10 

Pros: Easy to implement. Memory is saved as pointers are not involved. 
Cons: It is not dynamic. It doesn’t grow and shrink depending on needs at runtime.
*/





// C++ program for linked list implementation of stack
#include <bits/stdc++.h>
using namespace std;

// A structure to represent a stack
class StackNode {
public:
	int data;
	StackNode* next;
};

StackNode* newNode(int data){
	StackNode* stackNode = new StackNode();
	stackNode->data = data;
	stackNode->next = NULL;
	return stackNode;
}
// view function(get layoit_arraylist.layout)
int isEmpty(StackNode* root){
	return !root;
}

void push(StackNode** root, int data){
	StackNode* stackNode = newNode(data);
	stackNode->next = *root;
	*root = stackNode;
	cout << data << " pushed to stack\n";
}

int pop(StackNode** root){

	if (isEmpty(*root))
		return INT_MIN;
	
    StackNode* temp = *root;
	*root = (*root)->next;
	int popped = temp->data;
	free(temp);

	return popped;
}

int peek(StackNode* root){
	if (isEmpty(root))
		return INT_MIN;
	return root->data;
}

// Driver code
int main(){
	StackNode* root = NULL;

	push(&root, 10);
	push(&root, 20);
	push(&root, 30);

	cout << pop(&root) << " popped from stack\n";

	cout << "Top element is " << peek(root) << endl;
	
	cout<<"Elements present in stack : ";
	//print all elements in stack :
	
    while(!isEmpty(root)){
		// print top element in stack
		cout<<peek(root)<<" ";
		// remove top element in stack
		pop(&root);
	}

	return 0;
}

/* OUTPUT: 
10 pushed to stack
20 pushed to stack
30 pushed to stack
30 popped from stack
Top element is 20
Elements present in stack : 20 10 

Pros: The linked list implementation of a stack can grow and shrink according to the needs at runtime. 
Cons: Requires extra memory due to involvement of pointers. 
*/




//Stack in C++ STL:

#include <iostream>
#include <stack>
using namespace std;
int main() {
	stack<int> stack;
	stack.push(21);
	stack.push(22);
	stack.push(24);
	stack.push(25);
	
	stack.pop();
	stack.pop();

	while (!stack.empty()) {
		cout << ' ' << stack.top();
		stack.pop();
	}
}

//Output:  22 21