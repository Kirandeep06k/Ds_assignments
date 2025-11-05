#include <iostream>
using namespace std;

int getMax(int a[], int n) {
    int m = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > m)
            m = a[i];
    return m;
}

void countSort(int a[], int n, int e) {
    int o[100], c[10] = {0};

    for (int i = 0; i < n; i++)
        c[(a[i] / e) % 10]++;

    for (int i = 1; i < 10; i++)
        c[i] += c[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        int d = (a[i] / e) % 10;
        o[c[d] - 1] = a[i];
        c[d]--;
    }

    for (int i = 0; i < n; i++)
        a[i] = o[i];
}

void radixSort(int a[], int n) {
    int m = getMax(a, n);
    for (int e = 1; m / e > 0; e *= 10)
        countSort(a, n, e);
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int a[100];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    radixSort(a, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}
