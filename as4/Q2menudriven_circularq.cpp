#include<iostream>
using namespace std;
int front = -1;
int rear = -1;
int size;

bool isEmpty(){
    return(front == -1 && rear == -1);
}

bool isFull(){
    return((rear + 1) % size == front);
}

void enqueue(int queue[], int val) {
    if(isFull()) {
        cout << "Queue is full! Cannot enqueue " << val << endl;
        return;
    }
    if(isEmpty()) {
        front = rear = 0;
    }
    else{
        rear = (rear + 1) % size;
    }
    queue[rear] = val;
    cout << val << " enqueued" << endl;
}

void dequeue(int queue[]) {
    if(isEmpty()) {
        cout << "Queue is empty! Cannot dequeue" << endl;
        return;
    }
    cout << queue[front] << " dequeued" << endl;
    if(front == rear) {
        front = rear = -1;
    }
    else{
        front = (front + 1) % size;
    }
}

void display(int queue[]){
    if(isEmpty()){
        cout << "Queue is empty!" << endl;
        return;
    }
    cout << "Queue elements: ";
    int i = front;
    while(true) {
        cout << queue[i] << " ";
        if(i == rear) break;
        i = (i + 1) % size;
    }
    cout << endl;
}

void peek(int queue[]){
    if(isEmpty()) {
        cout << "Queue is empty! No element to peek." << endl;
        return;
    }
    cout << "Front element: " << queue[front] << endl;
}

int main(){
    int c, val;
    cout << "Enter the size of the queue: ";
    cin >> size;
    int queue[size];
    while(true){
        cout << "\nMenu:" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Check if Empty" << endl;
        cout << "4. Check if Full" << endl;
        cout << "5. Display Queue" << endl;
        cout << "6. Peek Front" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> c;
        
        switch(c){
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> val;
                enqueue(queue, val);
                break;
                
            case 2:
                dequeue(queue);
                break;
                
            case 3:
                if(isEmpty()) {
                    cout << "Queue is empty." << endl;
                } else {
                    cout << "Queue is not empty." << endl;
                }
                break;
                
            case 4:
                if(isFull()) {
                    cout << "Queue is full." << endl;
                } else {
                    cout << "Queue is not full." << endl;
                }
                break;
                
            case 5:
                display(queue);
                break;
                
            case 6:
                peek(queue);
                break;
                
            case 7:
                cout << "Exiting program" << endl;
                return 0;
                
            default:
                cout << "Invalid choice!" << endl;
        }
    }
}