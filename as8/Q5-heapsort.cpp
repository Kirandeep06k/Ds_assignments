#include <iostream>
#include <algorithm>
using namespace std;
//  n size
void heapify(int a[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest])
        largest = left;
    if (right < n && a[right] > a[largest])
        largest = right;

    if (largest != i)
    {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void buildHeap(int a[], int n)
{
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(a, n, i);
}

void heapSort(int a[], int n)
{
    //buildHeap(a, n);

    for (int i = n - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        // i size
        heapify(a, i, 0);
    }
}

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int a[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    buildHeap(a, n);
    cout << "\nHeap after building: ";
    printArray(a, n);

    heapSort(a, n);
    cout << "After Heap Sort: ";
    printArray(a, n);

    return 0;
}
