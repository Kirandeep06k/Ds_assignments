#include <iostream>
using namespace std;
int main() {
    int n,i,j,c=0;
    cout<<"Enter array size(n)"<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter "<<n<<" numbers"<<endl;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"Array :"<<endl;
    for(i=0;i<n;i++){
        cout<<a[i]<<"\t";
    }
    cout<<endl;
    for(i=0;i<n;i++){
        int f=1;
        for(j=0;j<i;j++){
            if(a[i]==a[j]){
                f=0;
                break;
            }
        }
        if(f==1){
            c++;
        }
    }
    cout<<"Distinct count = "<<c<<endl;
    return 0;
}
