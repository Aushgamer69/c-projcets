//CLI Bank Account / ATM Simulator
#include <iostream>
using namespace std;

int main()
{
    double balance = 1289.54;
    int choice = 0;
    while (choice != 4)
    {
        cout << " 1 check balance " << endl;
        cout << " 2 deposit money " << endl;
        cout << " 3 withdraw money " << endl;
        cout << " 4 exist " << endl;
        cin >> choice;
        if (choice == 1)
        {
            cout << balance << endl;
        }
        else if (choice == 2)
        {
            double depositAmount;
            cin >> depositAmount;
            cout << depositAmount << endl;
            balance += depositAmount;
        }
        else if (choice == 3)
        {
            double withdrawAmount;
            cin >> withdrawAmount;
            cout << withdrawAmount << endl;
            if (withdrawAmount <= balance)
            {
                balance -= withdrawAmount;
            }
            else
            {

                cout << " insufficient  amount " << endl;
            }
        }
    }

    return 0;
}