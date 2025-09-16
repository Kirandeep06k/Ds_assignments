#include <iostream>
using namespace std;

int main() {
    char s[100];
    cout << "Enter a string: ";
    cin.getline(s, 100);  
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    for (int i = 0; i < len/2; i++) {
        char temp = s[i];
        s[i] = s[len-1-i];
        s[len-1-i] = temp;
    }
    cout << "Reversed string: " << s << endl;
    return 0;
}
