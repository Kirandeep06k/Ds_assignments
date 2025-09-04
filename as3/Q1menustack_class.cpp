#include <iostream>
using namespace std;

class Stack{
    private:
    int* a;
    int top;
    int s;

    public:
    Stack(int maxsize){
        s = maxsize;
        a = new int[s];
        top = -1;
    }

    bool isEmpty(){
        return top==-1;
    }

    bool isFull(){
        return top==s-1;
    }

    void push(int num){
        if(isFull()){
            cout << "Stack Overflow. Can't push " << num << endl;
        }
        else{
            a[++top] = num;
            cout << "Pushed " << num << " to stack." << endl;
        }
    }

    void pop(){
        if (isEmpty()) {
        cout << "Stack Underflow. Can't pop." << endl;
        } 
	    else {
        cout << "Popped item: " << a[top--] << endl;
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
		    cout<<a[i]<<endl;
	        }
	    }
    }

    void peek(){
	    if(isEmpty()){
		cout << "Stack is Empty!" << endl;
	    }
	    else{
		cout << "Element at top is " << a[top] << endl;
	    }
    }
};

int main(){
    int size;
    cout << "Enter size of stack\n";
    cin >> size;
    if(size<1){
        cout << "Invalid size\n";
        return 0;
    }
    Stack s(size);

    int c,n;
    //switch menu
    do{
        cout << "\nStack Menu:\n";
        cout << "1. Push\n2 Pop\n3 isEmpty\n4 isFull\n5 Display\n6 Peek\n7 Exit\n";
        cout << "Enter your choice (1-7): ";
        cin >> c;

        switch(c){
            case 1 :
            cout << "Enter the number to push: ";
            cin >> n;
            s.push(n);
            break;

            case 2 :
            s.pop();
            break;

            case 3 :
            if(s.isEmpty())
            cout << "Stack is empty." << endl;
            else
            cout << "Stack is not empty." << endl;
            break;
            
            case 4 :
            if(s.isFull())
            cout << "Stack is full." << endl;
            else
            cout << "Stack is not full." << endl;
            break;

            case 5 :
            s.display();
            break;

            case 6 :
            s.peek();
            break;

            case 7 :
            cout << "----------Exiting program----------" << endl;
            break;

            default :
            cout << "Invalid choice ! Try again\n";
        }

    }while(c!=7);

    return 0;
}