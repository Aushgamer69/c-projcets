#include <iostream>
using namespace std;

int main()
{
    double balance = 1050.50;
    int choice = 0;
    while (choice != 4)
    {
        cout << " 1 check balance " << endl;
        cout << " 2 deposit money " << endl;
        cout << " 3 withdraw money " << endl;
        cin >> choice;
        if (choice == 1)
        {
            cout << balance << endl;
        }
        else if (choice == 2)
        {
             double depositAmount;
            cin>>depositAmount;
            cout<<depositAmount<<endl;
            
        }
        else if (choice  == 3)
        {
            
        }
    }

    return 0;
}