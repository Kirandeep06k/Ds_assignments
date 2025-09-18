#include <iostream>
using namespace std;
int main(){
    int n,i;
    cout<<"Enter size of array\n";
    cin>>n;
    int a[n] ;
    cout << "Enter array elements\n";
    for(i=0; i<n; i++){
        cin>>a[i];
    }
    int twos = 0;
    for(i=0; i<n; i++){
        if(a[i]==2) 
        twos++;
    }
    int i1 = n-1;
    int j = n+twos-1;
    while(i1>=0){
        if(j<n) 
        a[j] = a[i1];
        if(a[i1]==2){
            j--;
            if(j<n) 
            a[j] = 2;
        }
        i1--;
        j--;
    }
    cout<<"Modified array: \n";
    for(i=0; i<n; i++){
        cout<<a[i]<<"\t";
    }
    cout<<endl ;
    return 0 ;
}
