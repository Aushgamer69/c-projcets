#include <iostream>
#include <cmath>
using namespace std;
class simplecalculatoer
{
protected:
    double number1, number2;

public:
    simplecalculatoer()
    {
        number1 = 0;
        number2 = 0;
    }
    char op;

    simplecalculatoer(double a, double b)
    {
        number1 = a;
        number2 = b;
    }
    void setSimpleData()
    {
        cout << " Enter first number for Simple Calc" << endl;
        cin >> number1;
        cout << " Enter secend number for Simple Calc" << endl;
        cin >> number2;
    }
    void displaysimple()
    {
        cout << " +  , - , * , /  " << endl;
        cin >> op;
        switch (op)
        {
        case '+':
            cout << number1 + number2 << endl;
            break;
        case '-':
            cout << number1 - number2 << endl;
            break;
        case '*':
            cout << number1 * number2 << endl;
            break;
        case '/':
            if (number2 != 0)
            {
                cout << number1 / number2 << endl;
            }
            else
            {
                cout << "error divison by zero!" << endl;
            }

            break;
        default:
            break;
        }
    }
};

class scientificcalculator
{
private:
    double scnumber1, scnumber2;

public:
    scientificcalculator()
    {
        scnumber1 = 0;
        scnumber2 = 0;
    }
    char scop;
    scientificcalculator(double a, double b)
    {
        scnumber1 = a;
        scnumber2 = b;
    }
    void scientificcalData()
    {
        cout << " Enter first number for scientificcal Calc" << endl;
        cin >> scnumber1;
        cout << " Enter secend number for scientificcal Calc" << endl;
        cin >> scnumber2;
    }
    void displaysc()
    {
        cout << " Press 1 for sin, 2 for cos, 3 for tan, 4 for log: " << endl;
        cin >> scop;
        switch (scop)
        {
        case '1':
            cout << sin(scnumber1) << endl;
            cout << sin(scnumber2) << endl;
            break;
        case '2':
            cout << cos(scnumber1) << endl;
            cout << cos(scnumber2) << endl;
            break;
        case '3':
            cout << tan(scnumber1) << endl;
            cout << tan(scnumber2) << endl;
            break;
        case '4':
            cout << log(scnumber1) << endl;
            cout << log(scnumber2) << endl;

            break;
        default:
            break;
        }
    }
};

class HybridCalculator : public simplecalculatoer, public scientificcalculator
{
};

int main()
{
    HybridCalculator cl;
    cl.setSimpleData();
    cl.displaysimple();

    cl.scientificcalData();
    cl.displaysc();
    return 0;
}