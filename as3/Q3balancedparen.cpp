#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;
    cout<<"Enter expression: "<<endl;
    cin>>s;
    char stack[100];
    int top=-1;
    bool flag=true;
    for(int i=0;i<s.length();i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            stack[++top]=s[i];
        }
        else if(s[i]==')' || s[i]=='}' || s[i]==']'){
            if(top==-1){
                flag=false;
                break;
            }
            char open=stack[top--];
            if( ( s[i]==')' && open!='(' ) || ( s[i]=='}' && open!='{' ) || ( s[i]==']' && open!='[') ) {
                flag=false;
                break;
            }
        }
    }
    if(top!=-1){
        flag=false;
    }
    if(flag){
        cout<<"Balanced\n";
    }
    else{
        cout<<"Not Balanced\n";
    }
    return 0;
}
