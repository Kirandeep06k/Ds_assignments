#include <iostream>
using namespace std;
int main(){
    int n,i,j;
    cout<<"Enter size of queue\n";
    cin>>n;
    int q[n];
    cout<<"Enter elements of queue\n";
    for(i=0;i<n;i++){
        cin>>q[i];
    }
    
    for(i=0; i<n; i++){
        int minIndex=i;
        for(j=i+1; j<n; j++){
            if(q[j] < q[minIndex]){
                minIndex=j;
            }
        }
        // swap min element to front of unsorted part
        int temp=q[i];
        q[i]=q[minIndex];
        q[minIndex]=temp;
    }
    cout<<"Sorted queue: \n";
    for(i=0; i<n; i++){
        cout<<q[i]<<"\t";
    }
    cout<<endl;
    return 0;
}
