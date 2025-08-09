#include <iostream>
using namespace std;
void del(int a[],int *n,int j){
    int k;
    for(k=j; k<(*n); k++){
        a[k] = a[k+1];
    }
    (*n)--;
}
int main() {
                int n,i,j;
    
                cout << "Enter array size: ";
                cin >> n;
                int a[n];
                cout << "Enter array elements:" << endl;
                for(i = 0; i < n; i++) {
                    cin >> a[i];
                }
                 cout<<"Before : " << endl;
                for(i = 0; i < n; i++) {
                    cout<< a[i] << "\t";
                }
                for(i=0; i<n; i++){
                    for(j=i+1; j<n;){
                        if(a[i] == a[j]){
                            del(a,&n,j);
                        }
                        else{
                            j++;
                        }
                    }
                }
                cout<<"New Array : " << endl;
                for(i = 0; i < n; i++) {
                    cout<< a[i] << "\t";
                }
                
    return 0;
}