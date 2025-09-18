#include <iostream>
using namespace std;
int* prevSmaller(int* A,int n1,int *len1){
    int i,j;
    *len1=n1;
    int *G=new int[n1];
    for(i=0;i<n1;i++){
        G[i]=-1;  
        for(j=i-1;j>=0;j--){
            if(A[j]<A[i]){
                G[i]=A[j];
                break;
            }
        }
    }
    return G;
}

int main(){
    int n,i;
    cout<<"Enter size of array\n";
    cin>>n;
    int a[n];
    cout<<"Enter array elements\n";
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    int len;
    int *G=prevSmaller(a,n,&len);
    cout<<"Nearest smaller elements: \n";
    for(i=0;i<len;i++){
        cout<<G[i]<<"\t";
    }
    cout<<endl;
    delete[] G;  
    return 0;
}
