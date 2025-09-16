#include <iostream>
using namespace std;
int main() {
                int m,n,i,j;
                cout << "Enter array size: ";
                cin >> m >> n;
                int a[m][n];
                cout << "Enter array elements:" << endl;
                for(i = 0; i < m; i++) {
                    for(j = 0; j < n; j++){
                        cin >> a[i][j];
                    }
                }
                cout<<"Before : " << endl;
                for(i = 0; i < m; i++) {
                    for(j = 0; j < n; j++){
                        cout << a[i][j] <<"\t";
                    }
                    cout<<endl;
                }
                int t[n][m];
                for(i=0; i<n; i++){
                    for(j=0; j<m; j++){
                        t[i][j] = a[j][i];
                    }
                }
                cout<<"After : " << endl;
                for(i = 0; i < n; i++) {
                    for(j = 0; j < m; j++){
                        cout << t[i][j] <<"\t";
                    }
                    cout<<endl;
                }
    return 0;
}