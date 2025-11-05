#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int a[1000], o[1000], c[10000] = {0};

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int mx = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > mx) mx = a[i];

    for (int i = 0; i < n; i++)
        c[a[i]]++;

    for (int i = 1; i <= mx; i++)
        c[i] += c[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        o[c[a[i]] - 1] = a[i];
        c[a[i]]--;
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << o[i] << " ";

    return 0;
}
