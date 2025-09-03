#include <iostream>
using namespace std;
int main(){
    int n,i,j,f,l,m,missing;
    cout<<"Enter array size\n";
    cin>>n;
    int a[n-1];
    cout<<"Enter array " <<n-1<<" elements\n";
    for(i=0;i<n-1;i++){
        cin>>a[i];
    }
    f=0;
    l=n-2;
    missing=n;
    while(f<=l){
        m=(f+l)/2;
        if(a[m]!=m+1){
            missing=m+1;
            l=m-1;
        }
        else{
            f=m+1;
        }
    }
    cout<<"Missing number = "<<missing<<endl;
    return 0;
}