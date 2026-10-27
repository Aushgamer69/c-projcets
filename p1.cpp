#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));

    int wins = 0;
    int losses = 0;
    int ties = 0;
    int uesr;
    char playagsin = 'y';

    while (playagsin == 'y')
    {
        cout << "pick rock peper Scissors ";

        int computerchoice = rand() % 3 + 1;

        cin >> uesr;
        cout << "computer chose : ";
        if (computerchoice = 1)
        {
            cout << " rock ";
        }
        else if (computerchoice = 2)
        {
            cout << " peper  ";
        }
        else
        {
            cout << " scissors ";
        }
        cout << endl;

        cout << computerchoice << endl;

        if (uesr == computerchoice)
        {
            cout << "it tie \n ";
            ties++;
        }
        else if ((uesr == 1 && computerchoice == 3) ||
                 (uesr == 2 && computerchoice == 1) ||
                 (uesr == 3 && computerchoice == 2))
        {
            cout << "you win \n";
            wins++;
        }
        else
        {
            cout << "you lose\n";
            losses++;
        }
        cout << wins << " " << " " << losses << " " << ties << endl;
        cin >> playagsin;
    };

    return 0;
}