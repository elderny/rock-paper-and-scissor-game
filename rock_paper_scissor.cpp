/*

Author: Elderny/Faris
Purpose: Practice
Data: 17-06-2021 / 4:00pm (5:30+ utc)
Telegram: elderny1

*/

#include <iostream>
#include <time.h>
#include <conio.h>

using namespace std;

//Some variables
string pn, get[] = {"Rock", "Paper", "Scissor"};
int ps = 0, cs = 0, trial, game, random;
char gv;

//Just point function
void points()
{
    cout << "Player Points: " << ps << endl;
    cout << "Computer Points: " << cs << endl;
}

//Creating Function for checking winner
void check_win(char a, int r)
{
    switch (a)
    {
    case 'r':
        if (random == 0)
        {
            cout << "Round " << r + 1 << ": Draw both selected Rock!";
            cout << "\n\n-- Round " << r + 1 << ": Points --\n"
                 << endl;
            points();
        }
        else if (random == 1)
        {
            cout << "Round " << r + 1 << ": Lost, Computer grabbed the rock with paper!";
            cs += 1;
            cout << "\n\n-- Round " << r + 1 << ": Points --\n"
                 << endl;
            points();
        }
        else if (random == 2)
        {
            cout << "Round " << r + 1 << ": Won, You broke the computers Scissor!";
            ps += 1;
            cout << "\n\n-- Round " << r + 1 << ": Points --\n"
                 << endl;
            points();
        }
        break;
    case 'p':
        if (random == 0)
        {
            cout << "Round " << r + 1 << ": Won, as you grabbed the computers Rock!";
            ps += 1;
            cout << "\n\n-- Round " << r + 1 << ": Points --\n"
                 << endl;
            points();
        }
        else if (random == 1)
        {
            cout << "Round " << r + 1 << ": Draw both selected Paper!";
            cout << "\n\n-- Round " << r + 1 << ": Points --\n"
                 << endl;
            points();
        }
        else if (random == 2)
        {
            cout << "Round " << r + 1 << ": Lost, as the computer cutted your Paper!";
            cs += 1;
            cout << "\n\n-- Round " << r + 1 << ": Points --\n"
                 << endl;
            points();
        }
        break;
    case 's':
        if (random == 0)
        {
            cout << "Round " << r + 1 << ": Lost, Computer broke your Scissor with Rock!";
            cout << "\n\n-- Round " << r + 1 << ": Points --\n"
                 << endl;
            points();
        }
        else if (random == 1)
        {
            cout << "Round " << r + 1 << ": Won, you cutted the computers Paper!";
            ps += 1;
            cout << "\n\n-- Round " << r + 1 << ": Points --\n"
                 << endl;
            points();
        }
        else if (random == 2)
        {
            cout << "Round " << r + 1 << ": Draw both selected Scissor!";
            cout << "\n\n-- Round " << r + 1 << ": Points --\n"
                 << endl;
            points();
        }
        break;

    default:
            cout<<"Unkown, key Pressed!"<<endl;
        break;
    }
}

//Creating Function for End game
void win()
{
    if (ps > cs)
    {
        cout << "\n##################" << endl
             << pn << ", Won the Game" << endl;
        cout << "You have: " << ps - cs << " more points" << endl;
        cout << "\n<--Total Points-->\n";
        points();
        cout << "-!-!-!-!-!" << endl
             << endl;
    }
    else if (ps < cs)
    {
        cout << "\n##################" << endl
             << pn << ", Lost the Game" << endl;
        cout << "You needed: " << cs - ps << " more points to Win" << endl;
        cout << "\n<--Total Points-->\n";
        points();
        cout << "\n##################" << endl
             << endl;
    }
    else if (ps == cs)
    {
        cout << "\n##################" << endl
             << pn << ", got Draw Game" << endl;
        cout << "You both have: " << ps << " points" << endl;
        cout << "\n<--Total Points-->\n";
        points();
        cout << "\n##################" << endl
             << endl;
    }
}
int main()
{
    system("cls");
    cout << "Welcome to the rock, paper and scissor game" << endl;
    cout << "Enter your name\nName: ";
    cin >> pn;
    system("cls");

    cout << "How many times you want to play\nTimes: ";
    cin >> game;
    system("cls");

    cout << "How many trails you want to have\nTrails: ";
    cin >> trial;

    int trials = trial;

    //First loop running according to number of games!
    for (int i = 0; i < game;)
    {
        system("cls");
        cout << "Game No: " << i + 1 << endl;
        
        //Second Loop running according to number of trials!
        for (int j = 0; j < trial + 1;)
        {
            //getting random number between 0 - 2
            srand(time(NULL));
            random = rand() % 3;

            cout << "\n---" << pn << "'s Turn ---" << endl;
            cout << "\nType 'r', 'p' or 's' ->" << endl
                 << endl;
            cout << "r for Rock" << endl;
            cout << "p for Paper" << endl;
            cout << "s for Scissor\nType here: ";
            cin >> gv;

            system("cls");
            cout << "---Computer's Turn---" << endl
                 << endl;
            cout << "Computer Selected: " << get[random] << endl
                 << endl;
            cout << "\n<-- Results -->\n\n";
            
            //running deciding function 
            check_win(gv, j);
            cout << "Trails Left: " << trials << endl;
            j++;
            trials = trials - 1;
        }
        win();
        //resetting everything as it was before just to make sure that it doesn't clashs next time the loop is called
        trials = trial;
        ps = 0;
        cs = 0;
        cout << "Press any key, to continue!\n";
        getch();
        i++;
    }
    cout << "\n\n << GAME CLOSING - made by elderny >>";
    return 0;
}
