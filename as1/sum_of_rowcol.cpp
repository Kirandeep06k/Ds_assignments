#include <iostream>
using namespace std;

int main() {
    int n1, n2;

    cout << "Enter number of rows and columns: ";
    cin >> n1 >> n2;

    int a[n1][n2];

    cout << "Enter " << (n1 * n2) << " numbers:" << endl;
    for(int i = 0; i < n1; i++) {
        for(int j = 0; j < n2; j++) {
            cin >> a[i][j];
        }
    }

    cout << "Matrix:" << endl;
    for(int i = 0; i < n1; i++) {
        for(int j = 0; j < n2; j++) {
            cout << a[i][j] << "  ";
        }
        cout << endl;
    }

    for(int i = 0; i < n1; i++) {
        int sumr = 0;
        for(int j = 0; j < n2; j++) {
            sumr += a[i][j];
        }
        cout << "Sum of row no. " << (i + 1) << " is " << sumr << endl;
    }
     // Column sum
    for(int j = 0; j < n2; j++) {  // i is column
        int sum = 0;
        for(int i = 0; i < n1; i++) {  // j is row
            sum += a[i][j];  // column index fixed, row varies
        }
        cout << "Sum of column no. " << (j + 1) << " is " << sum << endl;
    }

    return 0;
}
