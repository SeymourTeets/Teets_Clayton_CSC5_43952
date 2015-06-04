/*
 * File       : main.cpp
 * Author     : Clayton Teets
 * Created on : May 4, 2015, 4:25 PM
 * Purpose    : Yahtzee v2
 */
//System Libraries
#include <iostream> //Input/Output Library
#include <iomanip>  //Output Formatting
#include <ctime>    //Random #
#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;
//User Libraries
#include "Die.h"
#include "ScoreCard.h"
//Global Constants

//Function Prototypes

int compare(const void * a, const void * b) {
    return ( *(int*) a - *(int*) b);
}
//Executio Incipio

int main(int argc, char** argv) {

    //Output Yahtzee Graphic
    cout << "Let's play..." << endl;
    cout << "********************************************************************" << endl;
    cout << "* Y88b   d88P       888      888                               888 *" << endl;
    cout << "*  Y88b d88P        888      888                               888 *" << endl;
    cout << "*   Y88o88P         888      888                               888 *" << endl;
    cout << "*    Y888P  8888b.  88888b.  888888 88888888  .d88b.   .d88b.  888 *" << endl;
    cout << "*     888      '88b 888 '88b 888       d88P  d8P  Y8b d8P  Y8b 888 *" << endl;
    cout << "*     888  .d888888 888  888 888      d88P   88888888 88888888 Y8P *" << endl;
    cout << "*     888  888  888 888  888 Y88b.   d88P    Y8b.     Y8b.      '  *" << endl;
    cout << "*     888  'Y888888 888  888  'Y888 88888888  'Y8888   'Y8888  888 *" << endl;
    cout << "********************************************************************" << endl << endl;
    //Initialize the random number seed
    srand(static_cast<unsigned int> (time(0)));
    //Ask for player count
    char player;
    cout << "How many players? (1-4) ";
    cin>>player;
    while (player != '1' && player != '2' && player != '3' && player != '4') {
        cout << "Invalid Input." << endl;
        cout << "How many players? (1-4) ";
        cin>>player;
    }
    int players = player - 48;
    cout << endl;
    //Create player object
    Die d[players];
    ScoreCard s[players];
    //Zero round counter and card slots and prompt for player names
    for (int p = 0; p < players; p++) {
        cout<<"Enter player "<<p + 1<<"'s name: ";
        s[p].setName();
        s[p].startCount();
        s[p].setYCount();
        for (int i = 0; i < 13; i++) {
            s[p].unfillCard(i);
        }
        for (int i = 0; i < 16; i++) {
            s[p].zeroCard(i);
        }
    }
    cout<<endl;
    //Loop for 13 rounds
    while (s[players - 1].roundCount()) {
        for (int p = 0; p < players; p++) {
            cout << "Player - " << s[p].getName() << endl;
            cout << "Round  - " << s[p].getCount() << endl << endl;
            //Add to round counter
            s[p].addCount();
            //Loop for Die Roll
            d[p].roll();
            //Output Die
            d[p].printDie();
            //Zero die round counter
            d[p].setCount(0);
            do {
                char choice;
                cout << "Would you like to hold, roll again, or keep? (H/R/K) ";
                cin>>choice;
                while (choice != 'h' && choice != 'H' && choice != 'R' && choice != 'r' && choice != 'K' && choice != 'k' && choice != 'd') {
                    cout << "Would you like to hold, roll again, or keep? (H/R/K) ";
                    cin>>choice;
                }
                cout << endl;
                //Initiate Switch for chosen path
                switch (choice) {
                    case'h': //Hold die
                    case'H':
                        d[p].reRollset();
                        d[p].printDie();
                        break;
                    case'r': //Re roll all die
                    case'R':
                        d[p].roll();
                        d[p].printDie();
                        break;
                    case'k': //Keep all die and score
                    case'K':
                        d[p].setCount(3);
                        break;
                    case'd':
                        d[p].dev();
                        break;
                    default:
                        cout << "Type 'H' or 'h' to hold, 'R' or 'r' to re roll, 'K' or 'k' to keep die and score." << endl << endl;
                }
            } while (d[p].getCount()); //Counter to ensure that die are rolled no more than 3 times
            cout << endl;
            //Get die array
            int hand[5];
            unsigned short die[5];
            for (int i = 0; i < 5; i++) {
                hand[i] = d[p].getDie(i);
            }
            //Sort array;       
            qsort(hand, 5, sizeof (int), compare);
            //Reload array as unsigned short
            for (int i = 0; i < 5; i++) {
                die[i] = hand[i];
            }
            //Output Score Card
            cout << "Let's SCORE!" << endl;
            cout << "\nScoring Options: Enter number for category to enter score.\n" << endl;
            s[p].getscoreCard();

            bool input = true; //Set scoring input to loop until valid input
            do {
                //Prompt for scoring options
                char option;
                cout << "Option - ";
                cin >> option;
                cout << endl;
                int z = option - 49;
                //Select option
                switch (option) {
                    case '1': //Aces
                    case '2': //Twos
                    case '3': //Threes
                    case '4': //Fours
                    case '5': //Fives
                    case '6': //Sixes
                        if (s[p].notFilled(z)) {
                            if (s[p].upperAdder(die, z, option)) {
                                if (s[p].scratch(z)) {
                                    input = false;
                                }
                            } else input = false;
                        }
                        break;
                    case 't': //Three of a kind
                    case 'T':
                        if (s[p].notFilled(6)) {
                            if (s[p].threeKind(die)) {
                                if (s[p].scratch(6)) {
                                    input = false;
                                }
                            } else input = false;
                        }
                        break;
                    case 'f': //Four of a kind
                    case 'F':
                        if (s[p].notFilled(7))
                            if (s[p].fourKind(die)) {
                                if (s[p].scratch(7)) {
                                    input = false;
                                }
                            } else input = false;
                        break;
                    case 'h': //Full House
                    case 'H':
                        if (s[p].notFilled(8)) {
                            if (s[p].fullHouse(die)) {
                                if (s[p].scratch(8)) {
                                    input = false;
                                }
                            } else input = false;
                        }
                        break;
                    case 's': //Small Straight
                    case 'S':
                        if (s[p].notFilled(9)) {
                            if (s[p].smallStraight(die)) {
                                if (s[p].scratch(9)) {
                                    input = false;
                                }
                            } else input = false;
                        }
                        break;
                    case 'l': //Large Straight
                    case 'L':
                        if (s[p].notFilled(10)) {
                            if (s[p].largeStraight(die)) {
                                if (s[p].scratch(10)) {
                                    input = false;
                                }
                            } else input = false;
                        }
                        break;
                    case 'y': //Yahtzee
                    case 'Y':
                        if (s[p].yahtzee(die)) {
                            if (s[p].scratch(11)) {
                                input = false;
                            }
                        } else input = false;
                        break;
                    case 'c': //Chance
                    case 'C':
                        if (s[p].notFilled(12)) {
                            s[p].chance(die);
                            input = false;
                        }
                        break;
                    default:
                        cout << "Illegal choice made, please choose another." << endl << endl;
                }
            } while (input);
            cout << endl;
            //Add upper and lower totals
            s[p].addTotals();
            //Output updated score card
            cout << "  Updated Scorecard" << endl;
            s[p].getscoreCard();
        }
    }
    for (int p = 0; p < players; p++) {
        cout << "Player - " << s[p].getName() << endl;
        //Finalize scoring and output results
        s[p].bonus();
        //Add the grand total and output final scorecard
        s[p].finalScore();
        s[p].getscoreCard();
    }
    //Compare player score to high score
    for (int p = 0; p < players; p++) {
        s[p].setHScore();
    }
    cout << "Thanks for playing!" << endl;
    //Executio Disicere
    return 0;
}