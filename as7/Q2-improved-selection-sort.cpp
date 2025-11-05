#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int a[n]; 
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "\nUnsorted array: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    int left = 0;
    int right = n - 1;
    while (left < right) {
        int minIndex = left;
        int maxIndex = left;
        for (int i = left; i <= right; i++) {
            if (a[i] < a[minIndex])
                minIndex = i;
            if (a[i] > a[maxIndex])
                maxIndex = i;
        }
        int temp = a[left];
        a[left] = a[minIndex];
        a[minIndex] = temp;
        if (maxIndex == left)
            maxIndex = minIndex;
        temp = a[right];
        a[right] = a[maxIndex];
        a[maxIndex] = temp;
        left++;
        right--;
    }

    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}
