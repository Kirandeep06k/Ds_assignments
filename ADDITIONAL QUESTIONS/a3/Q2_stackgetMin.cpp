#include <iostream>
using namespace std;
int main(){
    int n,i;
    cout<<"Enter number of operations\n";
    cin>>n;
    int *stack=new int[n];
    int top=-1;
    int minEle=0;
    cout<<"Operations: 1 push, 2 pop, 3 peek, 4 getMin\n";

    for(i=0;i<n;i++){
        int op;
        cout<<"\nEnter operation: ";
        cin>>op;
        if(op==1){  
            int x;
            cout<<"Enter number: ";
            cin>>x;

            if(top==-1){
                top++;
                stack[top]=x;
                minEle=x;
            }
            else{
                top++;

                if(x>=minEle) 
                stack[top]=x;

                else{
                    stack[top]=2*x - minEle; 
                    minEle=x;
                }
            }
        }

        else if(op==2){ 
            if(top>=0){
                int t=stack[top];
                top--;
                if(t<minEle) minEle=2*minEle - t; 
            }
        }
        else if(op==3){ 
            if(top>=0){
                int t=stack[top];
                if(t>=minEle) cout<<t<<"\n";
                else cout<<minEle<<"\n";
            }
            else cout<<"-1\n";
        }
        else if(op==4){ 
            if(top>=0) cout<<minEle<<"\n";
            else cout<<"-1\n";
        }
    }
    delete [] stack;
    return 0;
}
