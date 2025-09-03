#include <iostream>
using namespace std;

int main() {
    int m, n, size1, size2;
    cout << "Enter rows and columns of the matrices: ";
    cin >> m >> n;

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

    // Adding
    int sp_sum[size1 + size2][3];
    int i1 = 0, i2 = 0, size_sum = 0;

    while (i1 < size1 && i2 < size2){
        if (sp1[i1][0] < sp2[i2][0] || 
           (sp1[i1][0] == sp2[i2][0] && sp1[i1][1] < sp2[i2][1])) {
            sp_sum[size_sum][0] = sp1[i1][0];
            sp_sum[size_sum][1] = sp1[i1][1];
            sp_sum[size_sum][2] = sp1[i1][2];
            i1++; size_sum++;
        }
        else if (sp1[i1][0] > sp2[i2][0] || 
            (sp1[i1][0] == sp2[i2][0] && sp1[i1][1] > sp2[i2][1])) {
            sp_sum[size_sum][0] = sp2[i2][0];
            sp_sum[size_sum][1] = sp2[i2][1];
            sp_sum[size_sum][2] = sp2[i2][2];
            i2++; size_sum++;
        }
        else {
            // Same row and column
            int s = sp1[i1][2] + sp2[i2][2];
            if (s != 0) {
                sp_sum[size_sum][0] = sp1[i1][0];
                sp_sum[size_sum][1] = sp1[i1][1];
                sp_sum[size_sum][2] = s;
                size_sum++;
            }
            i1++; i2++;
        }
    }

    // Adding remaining elements
    while (i1 < size1) {
        sp_sum[size_sum][0] = sp1[i1][0];
        sp_sum[size_sum][1] = sp1[i1][1];
        sp_sum[size_sum][2] = sp1[i1][2];
        i1++; size_sum++;
    }
    while (i2 < size2) {
        sp_sum[size_sum][0] = sp2[i2][0];
        sp_sum[size_sum][1] = sp2[i2][1];
        sp_sum[size_sum][2] = sp2[i2][2];
        i2++; size_sum++;
    }

    cout << "Addition in Sparse form:\n";
    cout << m << "\t" << n << "\t" << size_sum << endl;
    for (int i = 0; i < size_sum; i++) {
        cout << sp_sum[i][0] << "\t" << sp_sum[i][1] << "\t" << sp_sum[i][2] << endl;
    }
    return 0;
}
