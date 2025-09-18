#include <iostream>
using namespace std;
int main() {
 int T,i,j,l1,l2,k;
    string w1,w2;
    cout<<"Enter number of test cases\n";
    cin>>T;
    for(k=0; k<T; k++){
        cout<<"Enter strings\n";
        cin>>w1>>w2;
        l1 = w1.size();
        l2 = w2.size();

        char arr1[l1], arr2[l2];
        for(i=0; i<l1; i++){
            arr1[i] = w1[i];
        }
        for(i=0; i<l2; i++){
            arr2[i] = w2[i];
        }

        if(l1 == l2){
            for(i=0; i<l1-1; i++){
                for(j=0; j<l1-i-1; j++){
                    if(arr1[j] > arr1[j+1]){
                        char t = arr1[j];
                        arr1[j] = arr1[j+1];
                        arr1[j+1] = t;
                    }
                }
            }

            for(i=0; i<l2-1; i++){
                for(j=0; j<l2-i-1; j++){
                    if(arr2[j] > arr2[j+1]){
                        char t = arr2[j];
                        arr2[j] = arr2[j+1];
                        arr2[j+1] = t;
                    }
                }
            }

            int flag = 1;
            for(i=0; i<l1; i++){
                if(arr1[i] != arr2[i]){
                    flag = 0;
                    break;
                }
            }

            if(flag == 1){
                cout<<"Yes"<<endl;
            }
            else{
                cout<<"No"<<endl;
            }
        }

        else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}
