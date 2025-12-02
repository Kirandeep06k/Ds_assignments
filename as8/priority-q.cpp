#include <iostream>
#include <algorithm>
using namespace std;

int *H;      
int s = -1;  
int capacity; 
int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) {
    return 2 * i + 1;
}

int rightChild(int i) {
    return 2 * i + 2;
}

void shiftUp(int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

void shiftDown(int i) {
    int maxIdx = i;
    int left = leftChild(i);
    int right = rightChild(i);
    
    if (left <= s && H[left] > H[maxIdx]) {
        maxIdx = left;
    }
    if (right <= s && H[right] > H[maxIdx]) {
        maxIdx = right;
    }
    
    if (maxIdx != i) {
        swap(H[i], H[maxIdx]);
        shiftDown(maxIdx);
    }
}

void push(int val) {
    if (s >= capacity - 1) {
        cout << "Heap is full!" << endl;
        return;
    }
    s++;
    H[s] = val;
    shiftUp(s);
}

int pop() {
    if (s == -1) {
        cout << "Heap is empty!" << endl;
        return -1;
    }
    
    int maxVal = H[0];
    H[0] = H[s];
    s--;
    
    if (s >= 0) {
        shiftDown(0);
    }
    
    return maxVal;
}

int top() {
    if (s == -1) {
        cout << "Heap is empty!" << endl;
        return -1;
    }
    return H[0];
}

bool isEmpty() {
    return s == -1;
}

int size() {
    return s + 1;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    capacity = n;
    H = new int[capacity];

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        push(val);
    }
    
    cout << "\nTop element (highest priority): " << top() << endl;
    cout << "Size of priority queue: " << size() << endl;
    
    cout << "\nElements in priority order (highest to lowest):" << endl;
    while (!isEmpty()) {
        cout << pop() << " ";
    }
    cout << endl;
    delete[] H;
    return 0;
}
