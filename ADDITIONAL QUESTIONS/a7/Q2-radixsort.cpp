#include <iostream>
using namespace std;

int getMax(int a[], int n) {
    int mx = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > mx)
            mx = a[i];
    return mx;
}

void countSort(int a[], int n, int e) {
    int b[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(a[i] / e) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--)
        b[--count[(a[i] / e) % 10]] = a[i];

    for (int i = 0; i < n; i++)
        a[i] = b[i];
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int a[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int m = getMax(a, n);
    for (int e = 1; m / e > 0; e *= 10)
        countSort(a, n, e);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}
