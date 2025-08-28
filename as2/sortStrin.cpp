#include <iostream>
#include <cstring>
using namespace std;
int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    cin.ignore(); 

    char arr[100][100];
    cout << "Enter " << n << " strings (with spaces allowed):\n";
    for (int i = 0; i < n; i++) {
        cin.getline(arr[i], 100); 
    }

    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-1-i; j++) {
            if (strcmp(arr[j], arr[j+1]) > 0) { 
                char temp[100];
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j+1]);
                strcpy(arr[j+1], temp);
            }
        }
    }
    cout << "Strings in alphabetical order:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }

    return 0;
}
