#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node* up;
    Node* down;

    Node(int val) {
        data = val;
        next = prev = up = down = nullptr;
    }
};

class MatrixToDLL {
public:
    Node*** grid;
    int n, m;

    MatrixToDLL(int rows, int cols) {
        n = rows;
        m = cols;
        grid = new Node**[n];
        for (int i = 0; i < n; i++) {
            grid[i] = new Node*[m];
        }
    }

    void createFromInput() {
        cout << "Enter " << n * m << " elements for the matrix:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int val;
                cin >> val;
                grid[i][j] = new Node(val);
            }
        }
    }

    void linkAll() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                
                if (j < m - 1)
                    grid[i][j]->next = grid[i][j + 1];
               
                if (j > 0)
                    grid[i][j]->prev = grid[i][j - 1];
                
                if (i > 0)
                    grid[i][j]->up = grid[i - 1][j];
                
                if (i < n - 1)
                    grid[i][j]->down = grid[i + 1][j];
            }
        }
    }

    void displayMatrixUsingNextDown() {
        cout << "\nMatrix in DLL form:\n";
        Node* row = grid[0][0];
        while (row != nullptr) {
            Node* col = row;
            while (col != nullptr) {
                cout << col->data << " ";
                col = col->next;
            }
            cout << endl;
            row = row->down;
        }
    }
};

int main() {
    int n, m;
    cout << "Enter number of rows and columns: ";
    cin >> n >> m;

    MatrixToDLL obj(n, m);
    obj.createFromInput();
    obj.linkAll();

    obj.displayMatrixUsingNextDown();

    return 0;
}
