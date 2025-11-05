#include <iostream>
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

void merge(int a[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = new int[n1];
    int *R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            a[k++] = L[i++];
        else
            a[k++] = R[j++];
    }
    while (i < n1)
        a[k++] = L[i++];
    while (j < n2)
        a[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void mergeSort(int a[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int partition(int a[], int low, int high) {
    int pivot = a[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (a[j] < pivot) {
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    int temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;
    return (i + 1);
}

void quickSort(int a[], int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
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
