#include<iostream>
using namespace std;
int main() {
    int size;
    cout << "Enter stack size: ";
    cin >> size;
    int queue1[size], queue2[size];
    int front1 = -1;
    int rear1 = -1;
    int front2 = -1;
    int rear2 = -1;
    cout << "1. Push\n2. Pop\n3. Display\n4. Exit\n";

    while(true){
        int c;
        cout << "Enter choice: ";
        cin >> c;

        //Push
        if(c == 1){
            if(rear1 == size-1){
                cout << "Stack full!\n";
                continue;
            }
            int value;
            cout << "Enter value: ";
            cin >> value;
            
            if(front1 == -1){
                front1 = rear1 = 0;
                queue1[rear1] = value;
            }
            else{
                int tempFront = front1, tempRear = rear1;
                front2 = rear2 = -1;
                while(tempFront <= tempRear) {
                    if(front2 == -1) {
                        front2 = rear2 = 0;
                    }
                    else{
                        rear2++;
                    }
                    queue2[rear2] = queue1[tempFront];
                    tempFront++;
                }
                front1 = rear1 = 0;
                queue1[rear1] = value;
                tempFront = front2;
                while(tempFront <= rear2) {
                    rear1++;
                    queue1[rear1] = queue2[tempFront];
                    tempFront++;
                }
            }
            cout << value << " pushed to stack\n";
            
        }

        //Pop
        else if(c == 2){
            if(front1 == -1) {
                cout << "Stack empty!\n";
            } else {
                cout << "Popped: " << queue1[front1] << endl;
                if(front1 == rear1) {
                    front1 = rear1 = -1;
                } else {
                    front1++;
                }
            }
        }

        //Display
        else if(c == 3){
            if(front1 == -1){
                cout << "Stack empty!\n";
            }
            else{
                cout << "Stack: ";
                for(int i = front1; i <= rear1; i++) {
                    cout << queue1[i] << " ";
                }
                cout << endl;
            }   
        }
        
        else if(c == 4){
            cout<<"Exiting"<<endl;
            break;
        }

    }
    return 0;
}