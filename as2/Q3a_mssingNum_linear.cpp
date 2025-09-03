#include <iostream>
using namespace std;
int main() {
    int n;
    cout<<"Enter n: ";
    cin>>n;
    int a[n-1];
    cout << "Enter " << n-1 << " sorted elements (with one missing): ";
    for(int i=0;i<n-1;i++){
        cin>>a[i];
    }
    int missing = n; 
    for(int i=0;i<n-1;i++){
        if(a[i] != i+1){
            missing = i+1;
            break;
        }
    }
    cout << "Missing number is: " << missing << endl;
    return 0;
}
