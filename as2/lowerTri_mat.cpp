#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "\nEnter dimension of Lower Triangular Matrix: ";
    cin >> n;
    int L[n*(n+1)/2];
    cout << "Enter non-zero elements row-wise:\n";
    int k = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j <= i; j++)
            cin >> L[k++];
    
    cout << "Full Matrix:\n";
    k = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j <= i) cout << L[k++] << "\t";
            else cout << "0\t";
        }
        cout << endl;
    }
    return 0;
}
