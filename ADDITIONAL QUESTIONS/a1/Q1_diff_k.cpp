#include <iostream>
using namespace std;
int main(){
    int i,j,n,k,c=0;
    cout<<"Enter size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter "<<n<<" elements: ";
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter k: ";
    cin>>k;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(abs(arr[i]-arr[j])==k){
                c++;
            }
        }
    }
    cout<<"Total pairs with difference "<<k<<" = "<<c<<endl;
    return 0;
}
