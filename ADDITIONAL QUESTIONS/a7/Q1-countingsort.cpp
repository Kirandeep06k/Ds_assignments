#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int a[n];
    cout << "Enter " << n << " non-negative elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int k = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > k)
            k = a[i];

    int count[k + 1];
    for (int i = 0; i <= k; i++)
        count[i] = 0;

    for (int i = 0; i < n; i++)
        count[a[i]]++;

    for (int i = 1; i <= k; i++)
        count[i] += count[i - 1];

    int b[n];
    for (int i = n - 1; i >= 0; i--)
        b[--count[a[i]]] = a[i];

    for (int i = 0; i < n; i++)
        a[i] = b[i];

    cout << "Array after Counting Sort: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}
