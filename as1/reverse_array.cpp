#include <iostream>
using namespace std;

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
                for(i=0; i<n/2; i++){
                    int t = a[i];
                    a[i] = a[n-i-1];
                    a[n-i-1] = t;
                }
                cout<<"New Array : " << endl;
                for(i = 0; i < n; i++) {
                    cout<< a[i] << "\t";
                }
                
    return 0;
}