#include <iostream>
using namespace std;
int main(){
    int n,i;
    cout << "Enter size of array\n";
    cin >> n;
    int a[n];
    cout << "Enter array elements\n";
    for(i=0; i<n; i++){
        cin >> a[i];
    }
    int low = 0, mid = 0, high = n-1;
    int temp;
    while(mid <= high){
        if(a[mid] == 0){
            temp = a[low];
            a[low] = a[mid];
            a[mid] = temp;
            low++;
            mid++;
        }
        else if(a[mid] == 1){
            mid++;
        }
        else{  
            temp = a[mid];
            a[mid] = a[high];
            a[high] = temp;
            high--;
        }
    }
    cout << "Sorted array: \n";
    for(i=0; i<n; i++){
        cout << a[i] << "\t";
    }
    cout << endl;
    return 0;
}
