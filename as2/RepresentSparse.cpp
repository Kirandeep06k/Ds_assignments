#include <iostream>
using namespace std;
int main(){
    int m,n,i,j,size=0;
    cout<<"Enter matrix dimensions\n";
    cin>>m>>n;
    int a[m][n];
    cout<<"Enter array elements\n";
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(a[i][j]!=0){
                size++;
            }
        }
    }
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            cout<<a[i][j]<<"\t";
        }
        cout<<endl;
    }
    int s = 3;
    int r = 0;
    int sp[size][s];
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(a[i][j]!=0){
                sp[r][0] = i;
                sp[r][1] = j;
                sp[r][2] = a[i][j];
                r++;
            }
        }
    }
    cout<<"\nSparse matrix : \n";
    cout<<m<<"\t"<<n<<"\t"<<size<<endl;
    for(i=0;i<size;i++){
        for(j=0;j<s;j++){
            cout<<sp[i][j]<<"\t";
        }
        cout<<endl;
    }
    return 0;
}