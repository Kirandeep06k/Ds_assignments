#include <iostream>
using namespace std;
int main(){
    int n,i,j,ind;
    cout<<"Enter the dimension of symmetric matrix\n";
    cin>>n;
    int s = n*(n+1)/2;
    int a[s];
    cout<<"Enter the lower triangular elements row wise\n";
    for(i=0;i<s;i++){
        cin>>a[i];
    }
    cout<<"Symmetric matrix :\n";
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i>=j){
                ind = (i*(i+1)) / 2 + j;
            }
            else{
                ind = (j*(j+1)) / 2 + i;
            }
            cout<<a[ind]<<"\t";
        }
        cout<<endl;
    }
    return 0;
}