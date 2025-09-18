#include <iostream>
using namespace std;
int main(){
    int T,n,i,j,k;
    cout<<"Enter number of test cases\n";
    cin>>T;
    cout<<"Enter the strings :\n";
    while(T--){
        string s;
        cin>>s;
        n=s.size();
        bool ok=false;
        for(i=1; i<n-1 && !ok; i++){ 
            for(j=i; j<n && !ok; j++){ 
                char mid=s[j];
                bool left=false, right=false;
                for(k=0;k<i;k++){
                    if(s[k]==mid){
                        left=true;break;
                    }
                }
                
                for(k=j+1;k<n;k++){
                    if(s[k]==mid){
                        right=true;
                        break;
                    }
                }
                if(left && right) 
                ok=true;
            }
        }
        if(ok) 
        cout<<"Yes"<<endl;
        else 
        cout<<"No"<<endl;
    }
    return 0;
}
