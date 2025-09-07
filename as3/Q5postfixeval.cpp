#include <iostream>
#include <string>
using namespace std;
int main() {
    string postfix;
    cout << "Enter postfix: ";
    cin >> postfix;
    int stack[100];
    int top = -1;
    for(int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];
        if(isdigit(c)){
            stack[++top] = c - '0';
        }
        else{
            int b = stack[top--];
            int a = stack[top--];
            if (c == '+') stack[++top] = a + b;
            else if (c == '-') stack[++top] = a - b;
            else if (c == '*') stack[++top] = a * b;
            else if (c == '/') stack[++top] = a / b;
        }
    }
    cout << "Result: " << stack[top] << endl;
    return 0;
}
