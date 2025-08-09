#include <iostream>
using namespace std;
int main() {
    int size = 60;
    int i, a[size], n, change, done = 0;
      do {
        cout << "\nMenu:\n";
        cout << "1. Create Array\n";
        cout << "2. Display Array\n";
        cout << "3. Insert Element\n";
        cout << "4. Delete Element\n";
        cout << "5. Search Element\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> change;
    
        switch(change){
                case 1:
                cout << "Enter array size: ";
                cin >> n;
                cout << "Enter array elements:" << endl;
                for(i = 0; i < n; i++) {
                    cin >> a[i];
                }
                done = 1;
                break;
                
                case 2:
                if(done==0){
                    cout<<"Please create the array first!" << endl;
                    break;
                }
                cout<<"Array : " << endl;
                for(i = 0; i < n; i++) {
                    cout<< a[i] << endl;
                }
                break;
                
                case 3:{
                    if(done==0){
                    cout<<"Please create the array first!" << endl;
                    break;
                }
                int x, pos;
                cout << "Enter element to be inserted and its position: ";
                cin >> x >> pos;
                pos--; // convert to 0-index
                if (pos < 0 || pos > n) {
                    cout << "Invalid position!" << endl;
                    break;
                }
                for(i = n; i > pos; i--) {
                    a[i] = a[i - 1];
                }
                a[pos] = x;
                n++;
                cout << "Array after insertion:" << endl;
                for(i = 0; i < n; i++) {
                    cout << a[i] << endl;
                }
                break;
                }
                
                case 4: {
                    if(done==0){
                    cout<<"Please create the array first!" << endl;
                    break;
                }
                int y, position;
                cout << "Enter element to be deleted and its position: ";
                cin >> y >> position;
                position--;
                if (position < 0 || position >= n) {
                    cout << "Invalid position!" << endl;
                    break;
                }
                for(i = position; i < n - 1; i++) {
                    a[i] = a[i + 1];
                }
                n--;
                cout << "Array after deletion:" << endl;
                for(i = 0; i < n; i++) {
                    cout << a[i] << endl;
                }
                break;
               }
            
               case 5:
               {
                   if(done==0){
                    cout<<"Please create the array first!" << endl;
                    break;
                }
                int search, f = 0;
                cout << "Enter element to be searched: ";
                cin >> search;
                for(i = 0; i < n; i++) {
                    if(a[i] == search) {
                        f = 1;
                        cout << "Element found at position " << i + 1 << endl;
                        break;
                    }
                }
                if(f == 0) {
                    cout << "Element not found" << endl;
                }
                break;
            }
                case 6:
                cout << "-----------EXIT-----------" << endl;
                break;

                default:
                cout << "Please enter a valid number from the menu!" << endl;
        }
      }while(change!=6);
    return 0;
}