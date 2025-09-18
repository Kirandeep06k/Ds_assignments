#include <iostream>
#include <vector>
using namespace std;
int countStudents(vector<int>& students, vector<int>& sandwiches){
    int count[2] = {0, 0};  
    int i;
    int n = students.size();
    for(i=0; i<n; i++)
        count[students[i]]++;

    for(i=0; i<n; i++) {
        int top = sandwiches[i];
        if(count[top]>0)
            count[top]--;
        else
            break;
    }
    return count[0]+count[1]; 
}

int main() {
    int n,i;
    cout<<"Enter number of students or sandwiches: ";
    cin>>n;
    vector<int> students(n), sandwiches(n);
    cout << "Enter student preferences : 0 for circular and 1 for square):\n";
    for(i=0; i<n; i++)
        cin>>students[i];
    cout<<"Enter sandwiches in stack order (top first):\n";
    for(i=0; i<n; i++)
        cin>>sandwiches[i];
    int unable=countStudents(students, sandwiches);
    cout<<"Number of students unable to eat: "<<unable<<endl;
    return 0;
}
