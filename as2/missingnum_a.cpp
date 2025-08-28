#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    int arr[n-1];
    cout << "Enter " << n-1 << " sorted elements: ";
    for (int i = 0; i < n-1; i++) {
        cin >> arr[i];
    }
    int missing = n; 
    for (int i = 0; i < n-1; i++) {
        if (arr[i] != i+1) {
            missing = i+1;
            break;
        }
    }
    cout << "Missing number = " << missing << endl;
    return 0;
}
