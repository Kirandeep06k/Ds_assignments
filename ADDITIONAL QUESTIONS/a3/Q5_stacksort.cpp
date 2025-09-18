#include <iostream>
using namespace std;
int main() {
	int t,i,j;
    cout<<"Enter number of test cases\n";
    cin>>t;
    while(t--){
        int n;
        cout<<"Enter size of array\n";
        cin>>n;
        int a[n];   
        cout<<"Enter array elements\n";

        for(i=0;i<n;i++){
            cin>>a[i];
        }

        int s[n];        
        int top=-1;
        int next=1;      
        bool possible=true;

        for(i=0;i<n;i++){
            while(top>=0 && s[top]==next){
                top--;
                next++;
            }
            if(a[i]==next){
                next++;
            }
            else{
                if(top>=0 && s[top]<a[i]){
                    possible=false;
                    break;
                }
                s[++top]=a[i];
            }
        }

        while(top>=0){
            if(s[top]!=next){
                possible=false;
                break;
            }
            top--;
            next++;
        }

        if(possible){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    return 0;
}
