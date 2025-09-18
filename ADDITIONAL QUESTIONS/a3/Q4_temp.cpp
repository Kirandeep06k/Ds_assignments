#include <iostream>
using namespace std;
int main(){
    int n,i,j;
    cout<<"Enter number of days\n";
    cin>>n;
    int t[n],a[n];
    cout<<"Enter temperatures\n";
    for(i=0; i<n; i++)
        cin>>t[i];
    for(i=0; i<n; i++)
        a[i]=0;
    for(i=n-2; i>=0; i--){
        j=i+1;
        while(j<n){
            if(t[j]>t[i]){
                a[i]=j-i;
                break;
            }
            else if(a[j]==0){
                a[i]=0;
                break;
            }
            else{
                j=j+a[j];
            }
        }
    }
    cout<<"Days to wait for warmer temperature:\n";
    for(i=0; i<n; i++){
        cout<<a[i]<<"\t";
    }
    cout<<endl;
    return 0;
}
