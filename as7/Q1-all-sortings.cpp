#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;
void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min])
                min = j;
        }
        int t = a[min];
        a[min] = a[i];
        a[i] = t;
    }
}

void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int current = a[i];
        int j = i - 1;
        while (j >= 0 && current < a[j]) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = current;
    }
}

void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void merge(int a[], int l, int r, int m) {
    int size = r - l + 1;
    int* t = new int[size];

    int left = l;
    int right = m + 1;
    int i = 0;

    while (left <= m && right <= r) {
        if (a[left] <= a[right]) {
            t[i++] = a[left++];
        }
        else {
            t[i++] = a[right++];
        }
    }
    while (left <= m)
        t[i++] = a[left++];
    while (right <= r)
        t[i++] = a[right++];

    i = 0;
    while (l <= r) {
        a[l++] = t[i++];
    }

    delete[] t;
}

void mergeSort(int a[], int l, int r) {
    if (l == r) return;
    int m = l + (r - l) / 2; 
    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);
    merge(a, l, r, m);
}

 int partition(int a[], int low, int high) {
    int pivot = a[high];  
    int i = low - 1;           

    for (int j = low; j < high; j++) {
        if (a[j] <= pivot) {
            i++;

            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]); 
    return i + 1;                
}

void quickSort(int a[], int low, int high) {
        if(low>=high)
        return;
        int p = partition(a, low, high); 
        quickSort(a, low, p-1);
        quickSort(a, p, high);
    }


void display(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main() {
    cout << "1. Selection Sort\n";
    cout << "2. Insertion Sort\n";
    cout << "3. Bubble Sort\n";
    cout << "4. Merge Sort\n";
    cout << "5. Quick Sort\n";
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int a[n]; 
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int choice;
    cout << "\nChoose Sorting Technique (1-5): ";
    cin >> choice;

    switch (choice) {
        case 1:
            selectionSort(a, n);
            cout << "\nArray after Selection Sort: ";
            display(a, n);
            break;
        case 2:
            insertionSort(a, n);
            cout << "\nArray after Insertion Sort: ";
            display(a, n);
            break;
        case 3:
            bubbleSort(a, n);
            cout << "\nArray after Bubble Sort: ";
            display(a, n);
            break;
        case 4:
            mergeSort(a, 0, n - 1);
            cout << "\nArray after Merge Sort: ";
            display(a, n);
            break;
        case 5:
            quickSort(a, 0, n - 1);
            cout << "\nArray after Quick Sort: ";
            display(a, n);
            break;
        default:
            cout << "Invalid choice!\n";
    }
    return 0;
}
