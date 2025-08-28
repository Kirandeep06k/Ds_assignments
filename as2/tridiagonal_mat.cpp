#include <iostream>
using namespace std;
int main() {
     int n;
    cout << "\nEnter dimension of Tri-diagonal Matrix: ";
    cin >> n;
    int lower[n-1]; // lower diagonal
    int mainD[n];   // main diagonal
    int upper[n-1]; // upper diagonal

    cout << "Enter lower diagonal elements (" << n-1 << " elements): ";
    for(int i = 0; i < n-1; i++) 
        cin >> lower[i];

    cout << "Enter main diagonal elements (" << n << " elements): ";
    for(int i = 0; i < n; i++)
        cin >> mainD[i];

    cout << "Enter upper diagonal elements (" << n-1 << " elements): ";
    for(int i = 0; i < n-1; i++) 
        cin >> upper[i];

    cout << "\nFull Tri-diagonal Matrix:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i - j == 1) cout << lower[i-1] << " ";  
            else if(i == j) cout << mainD[i] << " ";    
            else if(i - j == -1) cout << upper[i] << " "; 
            else cout << "0 ";
        }
        cout << endl;
    }
    return 0;
}
