#include <iostream>
using namespace std;

int main() {
    char s[100], result[100];
    cout << "Enter a string: ";
    cin.getline(s, 100);  
    int i = 0, j = 0;
    while (s[i] != '\0') {
        char ch = s[i];
        if (ch!='a' && ch!='e' && ch!='i' && ch!='o' && ch!='u' &&
            ch!='A' && ch!='E' && ch!='I' && ch!='O' && ch!='U') {
            result[j++] = ch;
        }
        i++;
    }
    result[j] = '\0';
    cout << "String without vowels: " << result << endl;
    return 0;
}
