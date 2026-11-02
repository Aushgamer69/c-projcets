#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
class student
{
private:
    int rollnamber;
    string name;
    double maths;
    double physics;
    double chemistry;
    double english;
    double bio;

public:
    student(int a, string b, double c, double d, double e, double f, double g)
    {
        rollnamber = a;
        name = b;
        maths = c;
        physics = d;
        chemistry = e;
        english = f;
        bio = g;
    }
    double getTotal()
    {
        return maths + physics + chemistry + english + bio;
    }
    double getpercentage()
    {
        return (getTotal() / 500.0) * 100;
    }
    string tocsv()
    {
        ostringstream ss;
        ss << rollnamber << "," << name << ","

           << maths << "," << physics << "," <<

            chemistry << "," << english << "," << bio << "\n";
            return ss.str();
    }
};

int main()
{
    student s1(4, " Ayush Raj Singh ", 67.5, 76.3, 54.3, 88.4, 70.7);
    cout << "total : " << s1.getTotal() << endl;
    cout << "prercentage : " << s1.getpercentage() << "%" << endl;
    cout << "csv line : " << s1.tocsv() << endl;

    ofstream outfile("58students.txt", ios::app);
    if (!outfile.is_open())
    {
        cout << " error could not open 58students.txt for writing ! <<endl; " << endl;

        return 1;
    }
    outfile << s1.tocsv();
    outfile.close();
    cout << " Student record successfully saved to students.txt! " << endl;

    return 0;
}