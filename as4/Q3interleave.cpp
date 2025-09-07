#include<iostream>
using namespace std;
int main() {
    int n,i;
    cout << "Enter the size of array (must be even): ";
    cin >> n;
    if(n % 2 != 0) {
        cout << "Array size must be even!" << endl;
        return 0;
    }
    int arr[n];
    cout << "Enter " << n << " elements: ";
    for(i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Original array: \n";
    for(i = 0; i < n; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
    
    //Interleaved :
    int inter[n];
    int half = n / 2;
    int index = 0;
    for(i = 0; i < half; i++) {
        inter[index++] = arr[i];        
        inter[index++] = arr[i + half];  
    }
    cout << "Interleaved array: \n";
    for(i = 0; i < n; i++) {
        cout << inter[i] << "\t";
    }
    cout << endl;
    return 0;
}