#include <iostream>
using namespace std;
int main(){
    int m,n,i,j,k,size;
    cout<<"Enter rows, cols and number of non-zero elements: ";
    cin>>m>>n>>size;
    int sp[size][3];
    cout<<"Enter triplet form (row col value):\n";
    for(int i=0; i<size; i++) {
        cin>>sp[i][0]>>sp[i][1]>>sp[i][2];
    }
    cout << "\nTriplet form you entered:\n";
    cout<<m<<"\t"<<n<<"\t"<<size<<endl;
    for(int i=0; i<size; i++) {
        cout<<sp[i][0]<<"\t"<<sp[i][1]<<"\t"<<sp[i][2]<<endl;
    }

    //Transpose
    int t[size][3];
    for(i=0;i<size;i++){
        t[i][0] = sp[i][1];
        t[i][1] = sp[i][0];
        t[i][2] = sp[i][2];
    }

    //sorting
    for(i=0;i<size-1;i++){
        for(j=i+1;j<size;j++){
            if ( t[i][0]>t[j][0] || ( (t[i][0]==t[j][0]) && (t[i][1]>t[j][1]) ) ){
                for(k=0;k<3;k++){
                int tem = t[i][k];
                t[i][k] = t[j][k];
                t[j][k] = tem;
                }
            }
        }
    }
     cout << "\nTriplet form transpose :\n";
    cout<<n<<"\t"<<m<<"\t"<<size<<endl;
    for(int i=0; i<size; i++) {
        cout<<t[i][0]<<"\t"<<t[i][1]<<"\t"<<t[i][2]<<endl;
    }
    return 0;
}