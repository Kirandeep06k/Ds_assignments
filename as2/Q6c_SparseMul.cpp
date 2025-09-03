#include <iostream>
using namespace std;
int main() {
    int m, n, p, q;
    cout << "Enter rows and columns of matrix 1: ";
    cin >> m >> n;
    cout << "Enter rows and columns of matrix 2: ";
    cin >> p >> q;

    if (n != p) {
        cout << "Matrix multiplication not possible!\n";
        return 0;
    }

    int size1, size2;
    cout << "Enter number of non-zero elements in matrix 1: ";
    cin >> size1;
    int sp1[size1][3];
    cout << "Enter triplet form (row col value) for matrix 1:\n";
    for (int i = 0; i < size1; i++) {
        cin >> sp1[i][0] >> sp1[i][1] >> sp1[i][2];
    }

    cout << "Enter number of non-zero elements in matrix 2: ";
    cin >> size2;
    int sp2[size2][3];
    cout << "Enter triplet form (row col value) for matrix 2:\n";
    for (int i = 0; i < size2; i++) {
        cin >> sp2[i][0] >> sp2[i][1] >> sp2[i][2];
    }

    // Transpose B
    int sp2T[size2][3];
    for (int i = 0; i < size2; i++) {
        sp2T[i][0] = sp2[i][1]; // row becomes col
        sp2T[i][1] = sp2[i][0]; // col becomes row
        sp2T[i][2] = sp2[i][2];
    }

    //Sorting transpose
    for (int i = 0; i < size2 - 1; i++) {
        for (int j = i + 1; j < size2; j++) {
            if (sp2T[i][0] > sp2T[j][0] || 
               (sp2T[i][0] == sp2T[j][0] && sp2T[i][1] > sp2T[j][1])) {
                for (int k = 0; k < 3; k++) {
                    int temp = sp2T[i][k];
                    sp2T[i][k] = sp2T[j][k];
                    sp2T[j][k] = temp;
                }
            }
        }
    }


    //MUL
    int sp_mul[size1 * size2][3];
    int size_mul = 0;

    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (sp1[i][1] == sp2T[j][1]) {
                int r = sp1[i][0];        
                int c = sp2T[j][0];       
                int val = sp1[i][2] * sp2T[j][2];

                bool found = false;
                for (int k = 0; k < size_mul; k++) {
                    if (sp_mul[k][0] == r && sp_mul[k][1] == c) {
                        sp_mul[k][2] += val;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    sp_mul[size_mul][0] = r;
                    sp_mul[size_mul][1] = c;
                    sp_mul[size_mul][2] = val;
                    size_mul++;
                }
            }
        }
    }

    cout << "\nMultiplication in Sparse form:\n";
    cout << m << "\t" << q << "\t" << size_mul << endl;
    for (int i = 0; i < size_mul; i++) {
        cout << sp_mul[i][0] << "\t" << sp_mul[i][1] << "\t" << sp_mul[i][2] << endl;
    }

    return 0;
}
