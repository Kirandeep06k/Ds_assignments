#include <iostream>
using namespace std;

int main()
{
    int size;
    cout<<"Enter stack size: ";
    cin>>size;
    int queue[size];
    int front=-1, rear=-1;
    int choice, value;
    cout<<"\n1. Push\n2. Pop\n3. Display\n4. Exit\n";
    while(true)
    {
        cout<<"Enter choice: ";
        cin>>choice;

        if(choice==1) // Push
        {
            if(rear==size-1)
            {
                cout<<"Stack full!\n";
                continue;
            }
            cout<<"Enter value: ";
            cin>>value;

            if(front==-1) 
            {
                front=rear=0;
                queue[rear]=value;
            }
            else
            {
                rear++;
                queue[rear]=value;
                int count=rear-front;
                for(int i=0;i<count;i++)
                {
                    int temp=queue[front];
                    for(int j=front;j<rear;j++)
                        queue[j]=queue[j+1];
                    queue[rear]=temp;
                }
            }
            cout<<value<<" pushed to stack\n";
        }

        else if(choice==2) // Pop
        {
            if(front==-1)
                cout<<"Stack empty!\n";
            else
            {
                cout<<"Popped: "<<queue[front]<<"\n";
                if(front==rear)
                    front=rear=-1;
                else
                    front++;
            }
        }

        else if(choice==3) // Display
        {
            if(front==-1)
                cout<<"Stack empty!\n";
            else
            {
                cout<<"Stack: ";
                for(int i=front;i<=rear;i++)
                    cout<<queue[i]<<" ";
                cout<<"\n";
            }
        }

        else if(choice==4) // Exit
        {
            cout<<"Exiting"<<endl;
            break;
        }

        else
            cout<<"Invalid choice!\n";
    }
    return 0;
}
