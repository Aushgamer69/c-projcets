// dungeon and dragon
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(time(0));

    int knight = 100;
    int drangon = 150;
    int potion = 6;
    int knightchoice = 0;
    cout << " battle start" << endl;
    while (knight > 0 && drangon > 0)
    {

        cout << "knight hp " << knight << endl;
        cout << "drangons hp " << drangon << endl;
        cout << "1. light attack \n 2 . heavy attack\n 3. drink potion \n 4. run away" << endl
             << endl;
        cin >> knightchoice;

        int lightattack = (rand() % 6) + 10;
        int HeavyAttack = (rand() % 5) + 30;

        int drangonchoice = (rand() % 2) + 1;
        int drangonclaw = (rand() % 6) + 15;
        int drangonfire = (rand() % 5) + 35;

        switch (knightchoice)
        {
        case 1:
            drangon -= lightattack;
            cout << "you have used light attack " << endl;
            break;

        case 2:
        {
            int missroll = rand() % 100;

            if (missroll < 80)

            {

                drangon -= HeavyAttack;
                cout << " you have a critical hit   " << endl;
                cout << "you have used heavy attack " << endl;
            }
            else
            {
                cout << "you have miss critical hit " << endl;
            }

            break;
        }
        case 3:
            if (knight > 100)
            {
            }

            if (potion > 0)
            {

                knight += 30;
                potion--;
                knight = 100;
                cout << "you have used potion " << endl;
            }

            else
            {

                cout << "you have no potion" << endl;
            }
            break;

        case 4:
            cout << " you have fled " << endl;
            return 0;

        default:
            cout << " charge knight " << endl;

            break;
        }

        if (drangon <= 0)
        {
            cout << "you won " << endl;
            break;
        }

        switch (drangonchoice)
        {
        case 1:
            knight -= drangonclaw;
            cout << "you have been wounded " << endl;
            break;

        case 2:
            knight -= drangonfire;
            cout << "you have been fatally wounded " << endl;
            break;

        default:
            cout << " dragon getting stronger " << endl;
            break;
        }
    }
    if (knight <= 0)
    {
        cout << "you have lost " << endl;
    }
    return 0;
}
