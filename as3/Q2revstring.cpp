#include <iostream>
#include <string>
using namespace std;
int main(){
    int size,i,top = -1;
    string s;
    cout << "Enter a string!: "<< endl;
    getline(cin,s);
    size = s.length();
    char a[size];
    for(i=0;i<size;i++){
        a[++top] = s[i];
    }
    for(i=top;i>=0;i--){
        cout << a[i];
    }
    cout<<endl;
    return 0;
}