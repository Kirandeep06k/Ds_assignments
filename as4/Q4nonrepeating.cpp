#include<iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter number of characters: ";
    cin >> n;
    char chars[n];
    cout << "Enter " << n << " characters: ";
    for(int i = 0; i < n; i++) {
        cin >> chars[i];
    }
    for(int i = 0; i < n; i++) {
        char firstNonRepeat = '-';
        bool found = false;
        for(int j = 0; j <= i; j++) {
            char currentChar = chars[j];
            bool isRepeating = false;
            for(int k = 0; k <= i; k++) {
                if(k != j && chars[k] == currentChar) {
                    isRepeating = true;
                    break;
                }
            }
            if(!isRepeating) {
                firstNonRepeat = currentChar;
                found = true;
                break;
            }
        }
        if(found) {
            cout << firstNonRepeat << " ";
        } else {
            cout << "-1 ";
        }
    }
    return 0;
}