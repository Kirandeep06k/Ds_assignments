#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int main() {
    int n,i;
    cout<<"Enter size of queue\n";
    cin>>n;
    queue<int> q;
    cout<<"Enter elements of queue\n";
    for(i=0; i<n; i++){
        int x;
        cin >> x;
        q.push(x);
    }
    stack<int> st;
    int expected = 1;
    bool possible = true;
    while(!q.empty() || !st.empty()){
        if(!q.empty() && q.front() == expected){
            q.pop();
            expected++;
        }
        else if(!st.empty() && st.top() == expected){
            st.pop();
            expected++;
        }
        else if(!q.empty()) {
            if(!st.empty() && q.front() > st.top()){
                possible = false;
                break;
            }
            st.push(q.front());
            q.pop();
        }
        else{
            possible = false;
            break;
        }
    }
    if(possible) 
    cout<<"Yes\n";
    else 
    cout<<"No\n";
    return 0;
}
