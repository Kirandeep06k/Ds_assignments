#include <iostream>
using namespace std;
int main(){
    int n,i;
    cout<<"Enter n\n";
    cin>>n;
    int size = 2*n; 
    string q[size];
    int front=0, rear=0;
    q[rear++] = "1";
    cout<<"Binary numbers from 1 to "<<n<<":\n";
    for(i=1; i<=n; i++){
        string s = q[front++];  
        cout<<s<<endl;
        q[rear++] = s + "0";   
        q[rear++] = s + "1";
    }
    cout<<endl;
    return 0;
}
