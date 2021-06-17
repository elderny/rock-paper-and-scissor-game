/*

Author: Elderny
Purpose: Practice
Data: 16-06-2021
Telegram: elderny1

*/

#include <iostream>
#include <time.h>
#include <conio.h>

using namespace std;

string pn, get[] = {"Rock", "Paper", "Scissor"};
int ps = 0, cs = 0, trial, game, random;
char gv;

void points()
{
    cout << "Player Points: " << ps << endl;
    cout << "Computer Points: " << cs << endl;
}
void check_win(int a, int r)
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
        break;
    }
}
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

    for (int i = 0; i < game;)
    {
        system("cls");
        cout << "Game No: " << i + 1 << endl;
        for (int j = 0; j < trial + 1;)
        {
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
            check_win(gv, j);
            cout << "Trails Left: " << trials << endl;
            j++;
            trials = trials - 1;
        }
        win();
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