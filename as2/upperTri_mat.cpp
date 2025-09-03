#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "\nEnter dimension of Upper Triangular Matrix: ";
    cin >> n;
    int t = n*(n+1)/2;
    int L[t];
    cout << "Enter non-zero elements row-wise:\n";
    for(int i = 0; i < t; i++)
            cin >> L[i];
    
    cout << "Full Matrix:\n";
    int k = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j >= i) cout << L[k++] << "\t";
            else cout << "0\t";
        }
        cout << endl;
    }
    return 0;
}
