#include <iostream>
using namespace std;
int main() {
    int n,i,j;
    cout<<"Enter size of array\n";
    cin>>n;
    int a[n], b[n]; 
    cout<<"Enter array elements\n";
    for(i=0; i<n; i++){
        cin>>a[i];
    }

    for(i=0; i<n; i++){
        b[i] = -1;
        for(j= (i+1); j<n; j++){
            if(a[j]>a[i]) {
                b[i]=a[j];
                break;  
            }
        }
    }
    
    cout<<"Next Greater Elements:\n";
    for(i=0; i<n; i++)
        cout<<b[i]<<"\t";
    cout<<endl;
    return 0;
}
