#include<iostream>
using namespace std;

int main(){
    int number1 , number2;
    char op;
    cout<<"enter number 1 : "<<endl;
    cin>>number1;
    cout<<"+ , - , * ,/ , % : "<<endl;
    cin>> op;
    cout<<"enter number 2 :"<<endl;
    cin>>number2;

    switch (op)
    {
    case '+':
        cout<<number1+number2<<endl;
        break;

    case '-':
        cout<<number1-number2<<endl;
        break;
    
    case '*':
        cout<<number1*number2<<endl;
        break;
    
    case '/':
        if (number2 !=0)
        {
            cout<< number1 / number2<<endl;
        }else
        {
            cout<<"error divison by zero!"<<endl;
        }
         
        break;
    case '%':
       if (number2 !=0)
        {
            cout<< number1 % number2<<endl;
        }else
        {
            cout<<"error percentile by zero!"<<endl;
        }
        break;
    
    default:
    cout<<"invalid operator"<<endl;
     break;
    }


    return 0;
}