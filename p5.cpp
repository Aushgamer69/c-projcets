// Library and Bookstore Management System
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
using namespace std;

class MediaItem
{
private:
  string title;
  string author;
  string isbn;
  double price;

public:
  MediaItem(string t, string a, string i, double p)
  {
    title = t;
    author = a;
    isbn = i;
    price = p;

    ;
  }
  virtual ~MediaItem() = default;
  string getTtitle() const
  {
    return title;
  }
  string getauthor() const
  {
    return author;
  }
  string getisbn() const
  {
    return isbn;
  }
  double getprice() const
  {
    return price;
  }
  virtual void display() const = 0;
};

class book : public MediaItem
{
private:
  int stockquanity;
  bool isBorrowed;

public:
  book(string t, string a, string i, double p, int stock)
      : MediaItem(t, a, i, p)
  {
    stockquanity = stock;
    isBorrowed = false;
  }
  void display() const override
  {
    cout << "title" << getTtitle() << " Author " << getauthor() << "isbn" << getisbn() << " price " << getprice() << " stock " << stockquanity << endl;
  }
  bool checkavilability() const
  {
    return stockquanity > 0 && !isBorrowed;
  }
  void adjuststock(int amount)
  {
    stockquanity += amount;
  }
};

class user
{
private:
  int userid;
  string name;

public:
  user(int u1, string n1)
  {
    userid = u1;
    name = n1;
  }
  virtual void display() const = 0;
};

class patron : public user
{
private:
  vector<string> borrowedIsbn;

public:
  patron(int u1, string n1) : user(u1, n1) {}
  void borrowBook(const string &isbn)
  {
    borrowedIsbn.push_back(isbn);
  }
  void returnBook(const string &isbn)
  {
    borrowedIsbn.erase(remove(borrowedIsbn.begin(), borrowedIsbn.end(), isbn), borrowedIsbn.end());
  }
  void display() const override
  {
    cout << "patron Account" << endl;
  }
};

class customer : public user
{
private:
  double accountBalance;

public:
  customer(int u1, string n1, double balance) : user(u1, n1)
  {
    accountBalance = balance;
  }

  void makepurchase(double amount)
  {
    accountBalance -= amount;
  }
  void display() const override
  {
    cout << "customer balance : $ " << accountBalance << endl;
  }
};

class inventoryManager
{
private:
  vector<shared_ptr<MediaItem>> inventory;

public:
  void addItem(shared_ptr<MediaItem> item)
  {
    inventory.push_back(item);
  }
  void removeItem(const string &targetisbn)
  {
    inventory.erase(
        remove_if(inventory.begin(), inventory.end(),
                  [&targetisbn](const shared_ptr<MediaItem> &item)
                  {
                    return item->getisbn() == targetisbn;
                  }),
        inventory.end());
  }
  shared_ptr<MediaItem> searchByIsbn(const string &isbn)
  {
    for (const auto &item : inventory)
    {
      if (item->getisbn() == isbn)
      {
        return item;
      }
    }
    return nullptr;
  }
  void display()
  {
    for (const auto &item : inventory)
    {
      item->display();
    }
  }
};

int main()
{
  inventoryManager manager;
  int choice = 0;
  do
  {
    cout << "\n===================================\n";
    cout << "  LIBRARY & BOOKSTORE SYSTEM     \n";
    cout << "\n===================================\n";
    cout << "1. Add a books\n ";
    cout << "2. display all books\n";
    cout << "3. search book by isbn \n";
    cout << "4. exit\n";
    cout << " Enter choice : ";
    cin >> choice;
    if (choice == 1)
    {
      string t, a, i;
      double p;
      int stock;
      cout << " Enter the Title ";
      cin.ignore(10000, '\n');
      getline(cin, t);
      cout << " Enter the author ";
      getline(cin, a);
      cout << " Enter isbn ";
      cin >> i;
      cout << " Enter price ";
      cin >> p;
      cout << " Enter Stock Quantity ";
      cin >> stock;

      auto newbooks = make_shared<book>(t, a, i, p, stock);
      manager.addItem(newbooks);
      cout << "\n[Success] book added to the system! " << endl;
    }
    else if (choice == 2)
    {
      cout << "\n---Current inventory ---\n ";
      manager.display();
    }
    else if (choice == 3)
    {
      string searchisbn;
      cout << "Enter Isbn to srarch ";
      cin >> searchisbn;
      auto found = manager.searchByIsbn(searchisbn);
      if (found)
      {
        cout << "\n--[book found]: \n";
        found->display();
      }
      else
      {
        cout << "\n[error] book was not founeded " << endl;
      }
    }

  } while (choice != 4);
  {
    cout << "Exiting system goodbye" << endl;
  }

  return 0;
}