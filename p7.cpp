//PolyLedger: Multi-Account Banking Engine\n
//(Highlights your use of polymorphism and ledger tracking)

//VaultCore Console Banking Suite

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <ctime>
using namespace std;

class transaction
{
    int transactionId;
    string timestamp;
    double amount;
    string Type;

public:
    string getType() const { return Type; }
    transaction(int id, string time, double amt, string Type)
        : transactionId(id), timestamp(time), amount(amt), Type(Type) {}

    int getid() const { return transactionId; }
    string getTimestamp() const { return timestamp; }
    double getAmount() const { return amount; }
};

class account
{
protected:
    double balance;
    string accountNumber;
    string accountHolderName;
    vector<transaction> history;

public:
    account(string accNum, string name, double initiabalance)
        : accountNumber(accNum), accountHolderName(name), balance(initiabalance) {}
    virtual void withdrawal(double amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
            time_t now = time(0);
            string dt = ctime(&now);
            history.push_back(transaction(history.size() + 1, dt, amount, "withdrawal"));
        }
        else
        {
            cout << " insufficient  amount " << endl;
        }
    }
    virtual void deposit(double amount)
    {
        balance += amount;
        time_t now = time(0);
        string dt = ctime(&now);
        history.push_back(transaction(history.size() + 1, dt, amount, "deposit"));
    };

    virtual void displayinfo() const = 0;
    void printTransactionHistory() const
    {
        for (const auto &t : history)
        {
            cout << "Id: " << t.getid()
                 << "| Time " << t.getTimestamp()
                 << "| Amount:  " << t.getAmount()
                 << "| Type " << t.getType() << endl;
        }
    }
};

class savingAccount : public account
{
public:
    savingAccount(string accNum, string name, double initiabalance)
        : account(accNum, name, initiabalance) {}
    void displayinfo() const override { cout << "[Savings Account] "
                                             << accountNumber << "| Hoder: " << accountHolderName << "| Balance " << balance << "\n"; }
};

class CurrentAccount : public account
{
public:
    CurrentAccount(string accNum, string name, double initiabalance)
        : account(accNum, name, initiabalance) {}
    void displayinfo() const override { cout << "[Current Account] "
                                             << accountNumber << "| Hoder: " << accountHolderName << "| Balance " << balance << "\n"; }
};

class LedgerManager
{
public:
    vector<unique_ptr<account>> accounts;
};

int main()
{
    int choice = 0;
    int activeAccount = 0;

    LedgerManager manager;
    manager.accounts.push_back(make_unique<savingAccount>("Sa101", "Ayush", 50000.50));
    manager.accounts.push_back(make_unique<CurrentAccount>("Ed123", "raj", 35400.50));

    cout << "== Select Account === " << endl;
    cout << " 1. Ayush (Saving) " << endl;
    cout << " 2. Raj (currnt) " << endl;
    cout << " Enter your choice  " << endl;
    cin >> activeAccount;

    activeAccount--;

    if (activeAccount < 0 || activeAccount >= manager.accounts.size())
    {
        cout << " invalid account indax Defauting to 0 \n " << endl;
        activeAccount = 0;
    }

    cout << "\nYou selected:\n";
    manager.accounts[activeAccount]->displayinfo();
    cout << endl;

    manager.accounts[activeAccount]->printTransactionHistory();
    while (choice != 5)
    {
        cout << " 1 check balance " << endl;
        cout << " 2 deposit money " << endl;
        cout << " 3 withdraw money " << endl;
        cout << " 4 View transaction history " << endl;
        cout << " 5 Exit " << endl;
        cin >> choice;
        if (choice == 1)
        {
            manager.accounts[activeAccount]->displayinfo();
        }
        else if (choice == 2)
        {
            double depositAmount;
            cout << "Enter the amount to deposit" << endl;
            cin >> depositAmount;
            manager.accounts[activeAccount]->deposit(depositAmount);
                }
        else if (choice == 3)
        {
            double withdrawAmount;
            cout << "Enter amount to withdraw " << endl;
            cin >> withdrawAmount;
            manager.accounts[activeAccount]->withdrawal(withdrawAmount);
        }
        else if (choice == 4)
        {
            manager.accounts[activeAccount]->printTransactionHistory();
        }

        else if (choice == 5)
        {
            return 0;
        }
        else
        {
            cout << " insufficient  amount " << endl;
        }
    }

    return 0;
}
