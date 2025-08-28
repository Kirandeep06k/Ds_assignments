#include <iostream>
using namespace std;
int find(int a[], int n, int e){
    int i;
    for(i=0; i<n; i++){
        if(a[i] == e){
            return 1;
            break;
        }
    }
    return 0;
}
int main() {
    int n,i;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements of the sorted array: ";
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Array entered: ";
    for (i = 0; i < n; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
    int f = arr[0];
    int l = arr[n-1];
    int bl = l-f+1;
    int b[bl];
    int c=0;
    for(i = f; i <= l; i++){
        b[c++] = i;
    }
    cout<<"Missing num are : "<<endl;
    for(i=0;i<bl;i++){
        if( find(arr,n, b[i]) == 0){
            cout<<b[i]<<"\t" ;
        }
    }
    return 0;
}
