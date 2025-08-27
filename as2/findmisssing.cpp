#include <iostream>
using namespace std;

int main() {
    int n,i;
    cout << "Enter size of array (with one number missing in sequence): ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements of the sorted array: ";
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Array entered: ";
    for (i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    for(i = 0; i < n; i++){
        
    }
    // int missing = ...
    // cout << "Missing number is: " << missing << endl;

    return 0;
}
