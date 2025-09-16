#include <iostream>
using namespace std;
int main() {
                int m,n,i,j,k,q,p;
                cout << "Enter array 1 size: ";
                cin >> m >> n;
                int a[m][n];
                cout << "Enter array elements:" << endl;
                for(i = 0; i < m; i++) {
                    for(j = 0; j < n; j++){
                        cin >> a[i][j];
                    }
                }
                cout << "Enter array 2 size: ";
                cin >> q >> p;
                int b[q][p];
                cout << "Enter array elements:" << endl;
                for(i = 0; i < q; i++) {
                    for(j = 0; j < p; j++){
                        cin >> b[i][j];
                    }
                }
                int c[m][q];
                if(n!=q){
                    cout << "Invalid size for multipication" << endl;
                    return 0;
                }
                cout<<"After multiplication : " << endl;
                for(i=0; i<m; i++){
                    for(j=0; j<p; j++){
                        c[i][j] = 0;
                        for(k=0; k<n; k++){
                            c[i][j] = c[i][j] + a[i][k] * b[k][j];
                        }
                        cout << c[i][j] << '\t';
                    }
                    cout << endl;
                }
            return 0;
 }
