#include <iostream>
#include <string>
using namespace std;
int main() {
    string infix;
    cout<<"Enter infix: ";
    cin>>infix;

    string st="", postfix="";

    for(int i=0;i<infix.length();i++){
        char c=infix[i];

        if((c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='0'&&c<='9')){
            postfix+=c;
        }

        else if(c=='('){
            st.push_back(c);
        }

        else if(c==')'){
            while(!st.empty() && st.back()!='('){
                postfix+=st.back();
                st.pop_back();
            }
            if(!st.empty())
               st.pop_back();
        }
        else{
            int prec;
            if(c=='^') prec=3;
            else if(c=='*'||c=='/') prec=2;
            else if(c=='+'||c=='-') prec=1;
            else prec=-1;

            while(!st.empty()){
                int tprec;
                if(st.back()=='^') tprec=3;
                else if(st.back()=='*'||st.back()=='/') tprec=2;
                else if(st.back()=='+'||st.back()=='-') tprec=1;
                else tprec=-1;

                if(tprec>=prec){
                    postfix+=st.back();
                    st.pop_back();
                } else break;
            }
            st.push_back(c);
        }
    }

    while(!st.empty()){
        postfix+=st.back();
        st.pop_back();
    }

    cout<<"Postfix: "<<postfix;
    return 0;
}
