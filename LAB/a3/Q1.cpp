#include <iostream>
using namespace std;
#define MAX 100
int stack[MAX];
int top = -1;
int maxSize;

bool isEmpty() {
    return top == -1;
}

bool isFull() {
    return top == maxSize - 1;
}

void push(int x) {
    if (isFull()) {
        cout << "Stack Overflow. Can't push " << x << endl;
    } 
	else {
        stack[++top] = x;
        cout << "Pushed " << x << " to stack." << endl;
    }
}

void pop() {
    if (isEmpty()) {
        cout << "Stack Underflow. Can't pop." << endl;
    } 
	else {
        cout << "Popped item: " << stack[top--] << endl;
    }
}

void display(){
	if(isEmpty()){
		cout << "Stack is Empty!" << endl;
	}
	else{
		int i;
		cout << "Stack from top to bottom"<<endl;
     	    for(i=top; i>=0; i--){
		    cout<<stack[i]<<endl;
	        }
	}
}

void peek(){
	if(isEmpty()){
		cout << "Stack is Empty!" << endl;
	}
	else{
		cout << "Element at the top is " << stack[top] << endl;
	}
}

int main() {
    cout << "Enter the size of the stack (max " << MAX << "): ";
    cin >> maxSize;
    if (maxSize > MAX || maxSize <= 0) {
        cout << "Invalid size!" << endl;
        return 0;
    }
    int choice, element;
    do {
        cout << "\nStack Menu:\n";
        cout << "1. Push\n2 Pop\n3 isEmpty\n4 isFull\n5 Display\n6 Peek\n7 Exit\n";
        cout << "Enter your choice (1-7): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the element to push: ";
                cin >> element;
                push(element);
                break;
            case 2:
                pop();
                break;
            case 3:
                if (isEmpty())
                    cout << "Stack is empty." << endl;
                else
                    cout << "Stack is not empty." << endl;
                break;
            case 4:
                if (isFull())
                    cout << "Stack is full." << endl;
                else
                    cout << "Stack is not full." << endl;
                break;
            case 5:
                display();
                break;
            case 6:
                peek();
                break;
            case 7:
                cout << "------------Exiting program--------------" << endl;
                break;
            default:
                cout << "Invalid choice! Enter a number between 1-7." << endl;
        }
    } while (choice != 7);
    return 0;
}
