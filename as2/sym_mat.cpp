#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of symmetric matrix (n x n): ";
    cin >> n;
    int size = n * (n + 1) / 2;
    int a[size];

    cout << "Enter elements of the lower triangular part (row by row):\n";
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> a[k++];
        }
    }

    cout << "The symmetric matrix is:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int index;
            if (i >= j) { 
                index = i * (i + 1) / 2 + j;
            } else { 
                index = j * (j + 1) / 2 + i;
            }
            cout << a[index] << " ";
        }
        cout << endl;
    }

    return 0;
}
