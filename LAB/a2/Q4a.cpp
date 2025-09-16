#include <iostream>
using namespace std;
int main() {
    char s1[100], s2[100], result[200];
    cout << "Enter first string: ";
    cin.getline(s1, 100);
    cout << "Enter second string: ";
    cin.getline(s2, 100);
    int i = 0, j = 0, k = 0;
    while (s1[i] != '\0') {
        result[k++] = s1[i++];
    }
    while (s2[j] != '\0') {
        result[k++] = s2[j++];
    }
    result[k] = '\0'; 
    cout << "Concatenated string: " << result << endl;
    return 0;
}
