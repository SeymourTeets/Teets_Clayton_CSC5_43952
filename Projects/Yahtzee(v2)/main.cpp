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

using namespace std;
//User Libraries

//Global Constants

//Function Prototypes

//Executio Incipio

class die {
private:
    unsigned short die[5];
    unsigned short counter;
public:

    void roll() {
        //Loop for Die Roll
        for (int i = 0; i < 5; i++) {
            do {
                die[i] = rand() % 6 + 1;
            } while (die[i] == 0);
        }
        counter += 1;

    }

    void showDie() {
        //Output Die
        cout << "Your role:" << endl;
        for (int i = 0; i < 5; i++) {
            cout << "Dice " << i;
            cout << " - |" << die[i] << "|" << endl;
        }
    }

    void reRollset() {
        cout << "How many die would you like to re roll? ";
        int x;
        cin>>x;
        cout << endl;
        //Loop for die not held
        for (int i = 0; i <= x - 1; i++) {
            cout << "Enter the die to re roll: ";
            int c;
            cin>>c;
            die[c - 1] = rand() % 6 + 1;
            cout << "Dice " << c;
            cout << " - |" << die[c - 1] << "|" << endl << endl;
        }
        counter += 1;
    }

    bool roundCount() {
        if (counter <= 2) {
            return true;
        } else {
            return false;
        }
    }
};

class scoreCard {
private:
    unsigned short score[16];
    unsigned short counter;
    unsigned short ycount;
    bool scoreBox[13];

public:

    void getscoreCard() {
        //Output Score Card
        cout << "*************************" << endl;
        cout << "******Upper Section******" << endl;
        cout << "*************************" << endl;
        cout << "* 1 *     Ones      *" << setw(3) << score[0] << "*" << endl;
        cout << "* 2 *     Twos      *" << setw(3) << score[1] << "*" << endl;
        cout << "* 3 *     Threes    *" << setw(3) << score[2] << "*" << endl;
        cout << "* 4 *     Fours     *" << setw(3) << score[3] << "*" << endl;
        cout << "* 5 *     Fives     *" << setw(3) << score[4] << "*" << endl;
        cout << "* 6 *_____Sixes_____*" << setw(3) << score[5] << "*" << endl;
        cout << "*****     Total     *" << setw(3) << score[13] << "*" << endl;
        cout << "*************************" << endl;
        cout << "******Lower Section******" << endl;
        cout << "*************************" << endl;
        cout << "* F *Three of a Kind*" << setw(3) << score[6] << "*" << endl;
        cout << "* T * Four of a Kind*" << setw(3) << score[7] << "*" << endl;
        cout << "* H *   Full House  *" << setw(3) << score[8] << "*" << endl;
        cout << "* S * Small Straight*" << setw(3) << score[9] << "*" << endl;
        cout << "* L * Large Straight*" << setw(3) << score[10] << "*" << endl;
        cout << "* Y *    YAHTZEE    *" << setw(3) << score[11] << "*" << endl;
        cout << "* C *____Chance_____*" << setw(3) << score[12] << "*" << endl;
        cout << "*****     Total     *" << setw(3) << score[14] << "*" << endl;
        cout << "*************************" << endl;
        cout << "*************************" << endl;
        cout << "*****  GRAND TOTAL  *" << setw(3) << score[15] << "*" << endl;
        cout << "*************************" << endl;
        cout << "*************************" << endl << endl;
    }

    void lowAdder(unsigned int die[], int i) {
        for (int h = 0; h < 5; h++) {
            if (die[h] == i) {
                score[i - 1] += die[h];
            }
        }
    }

    bool isFilled(int i) {
        if (scoreBox[i] == true) {
            cout << "Category filled, please choose another." << endl << endl;
        } else return true;
    }

    bool scratch(int i) {
        //Declare Variables
        char q;
        bool input; //Input validation
        bool output; //Return
        //Input Validation
        do {
            //Prompt for input
            cout << "You do not have any die for this category, would you like to scratch? (Y/N) ";
            cin>>q;
            //Switch for yes or no
            switch (q) {
                case'y':
                case'Y':
                    output = true;
                    input = false;
                    break;
                case'n':
                case'N':
                    output = false;
                    input = false;
                    break;
                default: cout << "Invalid input" << endl;
                    input = true;
            }
        } while (input);
        return output; //Returns true or false    
    }

    bool roundCount() {
        if (counter <= 13) {
            return true;
        } else {
            return false;
        }
    }

    bool threeKind(unsigned int die[]) {
        //Validate if the player has three of a kind
        if (die[1] == die[2] && die[2] == die[3]) {
            score[6] = die[1] + die[2] + die[3];
            cout << "3 of a Kind Score = " << score[6] << endl;
            scoreBox[6] = true;
        } else if (die[2] == die[3] && die[3] == die[4]) {
            score[6] = die[2] + die[3] + die[4];
            cout << "3 of a Kind Score = " << score[6] << endl;
            scoreBox[6] = true;
        } else if (die[0] == die[1] && die[1] == die[2]) {
            score[6] = die[0] + die[1] + die[2];
            cout << "3 of a Kind Score = " << score[6] << endl;
            scoreBox[6] = true;
        } else {
            cout << "You do not have 3 of a kind, would you like to scratch?" << endl;
            return true;
        }
    }

    bool fourKind(unsigned int die[]) {
        //Validate if the player has four of a kind
        if (die[0] == die[1] && die[1] == die[2] && die[2] == die[3]) {
            score[7] = die[0] + die[1] + die[2] + die[3];
            cout << "4 of a Kind Score = " << score[7] << endl;
            scoreBox[7] = true;
        } else if (die[1] == die[2] && die[2] == die[3] && die[3] == die[4]) {
            score[7] = die[1] + die[2] + die[3] + die[4];
            cout << "4 of a Kind Score = " << score[7] << endl;
            scoreBox[7] = true;
        } else {
            cout << "You do not have 4 of a kind, would you like to scratch?" << endl;
            return true;
        }
    }

    bool fullHouse(unsigned int die[]) {
        //Validate if the player has a full house
        if (die[1] == die[2] && die[3] == die[4] && die[4] == die[5]) {
            score[8] = 25;
            cout << "Full House = " << score[8] << endl;
            scoreBox[8] = true;
        } else if (die[1] == die[2] && die[2] == die[3] && die[4] == die[5]) {
            score[8] = 25;
            cout << "Full House = " << score[8] << endl;
            scoreBox[8] = true;
        } else {
            cout << "You do not have a full house, would you like to scratch?" << endl;
            return true;
        }
    }

    bool smallStraight(unsigned int die[]) {
        //Validate if the player has a small straight
        if (die[0] == die[1] && die[1] + 1 == die[2] && die[2] + 1 == die[3] && die[3] + 1 == die[4]) {
            score[9] = 30;
            cout << "Small Straight Score = " << score[9] << endl;
            scoreBox[9] = true;
        } else if (die[0] + 1 == die[1] && die[1] == die[2] && die[2] + 1 == die[3] && die[3] + 1 == die[4]) {
            score[9] = 30;
            cout << "Small Straight Score = " << score[9] << endl;
            scoreBox[9] = true;
        } else if (die[0] + 1 == die[1] && die[1] + 1 == die[2] && die[2] == die[3] && die[3] + 1 == die[4]) {
            score[9] = 30;
            cout << "Small Straight Score = " << score[9] << endl;
            scoreBox[9] = true;
        } else if (die[0] + 1 == die[1] && die[1] + 1 == die[2] && die[2] + 1 == die[3] && die[3] == die[4]) {
            score[9] = 30;
            cout << "Small Straight Score = " << score[9] << endl;
            scoreBox[9] = true;
        } else if (die[0] + 1 == die[1] && die[1] + 1 == die[2] && die[2] + 1 == die[3]) {
            score[9] = 30;
            cout << "Small Straight Score = " << score[9] << endl;
            scoreBox[9] = true;
        } else if (die[1] + 1 == die[2] && die[2] + 1 == die[3] && die[3] + 1 == die[4]) {
            score[9] = 30;
            cout << "Small Straight Score = " << score[9] << endl;
            scoreBox[9] = true;
        } else {
            cout << "You do not have a small straight, would you like to scratch?" << endl;
            return true;
        }
    }

    bool largeStraight(unsigned int die[]) {
        //Validate if the player has a large straight
        if (die[1] == die[2] - 1 && die[2] == die[3] - 1 && die[3] == die[4] - 1 && die[4] == die[5] - 1) {
            score[10] = 40;
            cout << "Large Straight Score = " << score[10] << endl;
            scoreBox[10] = true;
        } else {
            cout << "You do not have a large straight, would you like to scratch?" << endl;
            return true;
        }
    }

    bool yahtzee(unsigned int die[]) {
        //Validate if the player has yahtzee
        if (die[0] == die[1] && die[1] == die[2] && die[2] == die[3] && die[3] == die[4]) {
            if (ycount == 0) {
                score[11] += 50;
                ycount += 1;
                cout << "Yahtzee Score = " << score[11] << endl;
            } else if (ycount > 1) {
                score[11] += 100;
                cout << "Yahtzee Score = " << score[11] << endl;
            }
        } else {
            cout << "You do not have a yahtzee, would you like to scratch?" << endl;
            return true;
        }
    }

};

int main(int argc, char** argv) {
//Output Yahtzee Graphic
    cout << "********************************************************************" << endl;
    cout << "* Y88b   d88P       888      888                               888 *" << endl;
    cout << "*  Y88b d88P        888      888                               888 *" << endl;
    cout << "*   Y88o88P         888      888                               888 *" << endl;
    cout << "*    Y888P  8888b.  88888b.  888888 88888888  .d88b.   .d88b.  888 *" << endl;
    cout << "*     888      '88b 888 '88b 888       d88P  d8P  Y8b d8P  Y8b 888 *" << endl;
    cout << "*     888  .d888888 888  888 888      d88P   88888888 88888888 Y8P *" << endl;
    cout << "*     888  888  888 888  888 Y88b.   d88P    Y8b.     Y8b.      '  *" << endl;
    cout << "*     888  'Y888888 888  888  'Y888 88888888  'Y8888   'Y8888  888 *" << endl;
    cout << "********************************************************************" << endl;
    cout << endl << endl;
    //Initialize the random number seed
    srand(static_cast<unsigned int> (time(0)));
    //Create player object
    die a;
    scoreCard a;
    //Declare Variables
    const int SIZE = 6; //Six Sided Die
    int die[SIZE] = {}; //Yahtzee Die
    char choice; //Choice for each turn
    bool q; //Yes/No input for scratch option
    short x; //Die to hold
    short count = 1; //Amount of re-rolls
    const short maxrnds = 13; //Maximum rounds per game
    short round = 0; //Current round
    unsigned short ycount = 0; //Yahtzee counter
    int score[16];
    //For scoring validation
    bool screSlt[13]; //Score slot
    for (int i = 0; i <= 12; i++) {
        screSlt[i] = false;
    }
    for (int i = 0; i <= 15; i++) {
        score[i] = 0;
    }
    //Totals
    short uTotal = 0, //Upper total
            lTotal = 0, //Lower total
            gTotal = 0; //Grand total
    //Loop for 13 rounds
    while (round < maxrnds) {
        //Initiate roll counter
        count = 1;
        //Add to round counter
        round += 1;
        cout << "(ROUND " << round << ")" << endl << endl;
        //Loop for Die Roll
        for (int i = 1; i < 6; i++) {
            die[i] = rand() % 6 + 1;
        }
        //Output Die
        cout << "Your role:" << endl;
        for (int i = 1; i < 6; i++) {
            cout << "Dice " << i;
            cout << " - |" << die[i] << "|" << endl;
        }
        //Ask if they would like to hold any die?
        cout << endl;
        do {
            cout << "Would you like to hold, roll again, or keep? (H/R/K) ";
            cin>>choice;
            cout << endl;
            //Initiate Switch for chosen path
            switch (choice) {
                case'h': //Hold die
                case'H':
                    cout << "How many die would you like to re roll? ";
                    cin>>x;
                    cout << endl;
                    //Loop for die not held
                    for (int i = 1; i <= x; i++) {
                        cout << "Enter the die to re roll: ";
                        int c;
                        cin>>c;
                        die[c] = rand() % 6 + 1;
                        cout << "Dice " << c;
                        cout << " - |" << die[c] << "|" << endl << endl;
                    }
                    //Output Die
                    cout << "Your role:" << endl;
                    for (int i = 1; i < 6; i++) {
                        cout << "Dice " << i;
                        cout << " - |" << die[i] << "|" << endl;
                    }
                    cout << endl;
                    count += 1;
                    break;
                case'r': //Re roll all die
                case'R':
                    //Loop for Die Roll
                    for (int i = 1; i < 6; i++) {
                        do {
                            die[i] = rand() % 7;
                        } while (die[i] == 0);
                    }
                    //Output Die
                    cout << "Your role:" << endl;
                    for (int i = 1; i < 6; i++) {
                        cout << "Dice " << i;
                        cout << " - |" << die[i] << "|" << endl;
                    }
                    cout << endl;
                    count += 1;
                    break;
                case'k': //Keep all die and score
                case'K':
                    count += 3;
                    break;
                default:
                    cout << "You have broken my game" << endl << endl;
            }
        } while (count <= 2); //Counter to ensure that die are rolled no more than 3 times
        cout << endl;

        //Sort Die
        qsort(die, 6, sizeof (int), compare);

        //Output Score Card
        cout << "Let's SCORE!" << endl;
        cout << "\nScoring Options: Enter number for category to enter score.\n" << endl;
        

        bool input = true; //Set scoring input to loop until valid input
        do {
            //Prompt for scoring options
            char option;
            cout << "Option - ";
            cin >> option;
            cout << endl;
            //Select option
            switch (option) {
                case '1': //Aces
                    if (screSlt[0] == true) cout << "Category filled, please choose another." << endl << endl;
                    else {
                        //Add all die equaling 1
                        for (int h = 1; h <= 5; h++) {
                            if (die[h] == 1) {
                                aces += die[h];
                            }
                        }
                        cout << "Aces score = " << aces << endl;
                        screSlt[0] = true;
                        input = false;
                        //If no die equal 1, offer scratch
                        if (aces == 0) {
                            q = prompt();
                            if (!q) {
                                screSlt[0] = false;
                                input = true;
                            }
                        }
                    }
                    break;
                case '2': //Twos
                    if (screSlt[1] == true) cout << "Category filled, please choose another." << endl << endl;
                    else {
                        //Add all die equaling 2
                        for (int h = 1; h <= 5; h++) {
                            if (die[h] == 2) {
                                twos += die[h];
                            }
                        }
                        cout << "Twos score = " << twos << endl;
                        screSlt[1] = true;
                        input = false;
                        //If no die equal 2, offer scratch
                        if (twos == 0) {
                            q = prompt();
                            if (!q) {
                                screSlt[1] = false;
                                input = true;
                            }
                        }
                    }
                    break;
                case '3': //Threes
                    if (screSlt[2] == true) cout << "Category filled, please choose another." << endl << endl;
                    else {
                        //Add all die equaling 3
                        for (int h = 1; h <= 5; h++) {
                            if (die[h] == 3) {
                                threes += die[h];
                            }
                        }
                        cout << "Threes score = " << threes << endl;
                        screSlt[2] = true;
                        input = false;
                        //If no die equal 3, offer scratch
                        if (threes == 0) {
                            q = prompt();
                            if (!q) {
                                screSlt[2] = false;
                                input = true;
                            }
                        }
                    }
                    break;
                case '4': //Fours
                    if (screSlt[3] == true) cout << "Category filled, please choose another." << endl << endl;
                    else {
                        //Add all die equaling 4
                        for (int h = 1; h <= 5; h++) {
                            if (die[h] == 4) {
                                fours += die[h];
                            }
                        }
                        cout << "Fours score = " << fours << endl;
                        screSlt[3] = true;
                        input = false;
                        //If no die equal 4, offer scratch
                        if (fours == 0) {
                            q = prompt();
                            if (!q) {
                                screSlt[3] = false;
                                input = true;
                            }
                        }
                    }
                    break;
                case '5': //Fives
                    if (screSlt[4] == true) cout << "Category filled, please choose another." << endl << endl;
                    else {
                        //Add all die equaling 5
                        for (int h = 1; h <= 5; h++) {
                            if (die[h] == 5) {
                                fives += die[h];
                            }
                        }
                        cout << "Fives score = " << fives << endl;
                        screSlt[4] = true;
                        input = false;
                        if (fives == 0) {
                            q = prompt();
                            //If no die equal 5, offer scratch
                            if (!q) {
                                screSlt[4] = false;
                                input = true;
                            }
                        }
                    }
                    break;
                case '6': //Sixes
                    if (screSlt[5] == true) cout << "Category filled, please choose another." << endl << endl;
                    else {
                        //Add all die equaling 6
                        for (int h = 1; h <= 5; h++) {
                            if (die[h] == 6) {
                                sixes += die[h];
                            }
                        }
                        cout << "Sixes score = " << sixes << endl;
                        screSlt[5] = true;
                        input = false;
                        //If no die equal 6, offer scratch
                        if (sixes == 0) {
                            q = prompt();
                            if (!q) {
                                screSlt[5] = false;
                                input = true;
                            }
                        }
                    }
                    break;
                case 't': //Three of a kind
                case 'T':
                    if (screSlt[6] == true) cout << "Category filled, please choose another." << endl << endl;
                    else {
                        if (die[1] == die[2] && die[2] == die[3]) {
                            thKind = die[1] + die[2] + die[3];
                            cout << "3 of a Kind Score = " << thKind << endl;
                            screSlt[6] = true;
                            input = false;
                        } else if (die[2] == die[3] && die[3] == die[4]) {
                            thKind = die[2] + die[3] + die[4];
                            cout << "3 of a Kind Score = " << thKind << endl;
                            screSlt[6] = true;
                            input = false;
                        } else if (die[3] == die[4] && die[4] == die[5]) {
                            thKind = die[3] + die[4] + die[5];
                            cout << "3 of a Kind Score = " << thKind << endl;
                            screSlt[6] = true;
                            input = false;
                        } else {
                            cout << "You do not have 3 of a kind, choose another category" << endl;
                            q = prompt();
                            if (q) {
                                screSlt[6] = true;
                                input = false;
                            }
                        }
                    }
                    break;
                case 'f': //Four of a kind
                case 'F':
                    if (screSlt[7] == true) cout << "Category filled, please choose another." << endl << endl;
                    else {
                        if (die[1] == die[2] && die[2] == die[3] && die[3] == die[4]) {
                            foKind = die[1] + die[2] + die[3] + die[4];
                            cout << "4 of a Kind Score = " << foKind << endl;
                            screSlt[7] = true;
                            input = false;
                        } else if (die[2] == die[3] && die[3] == die[4] && die[4] == die[5]) {
                            foKind = die[2] + die[3] + die[4] + die[5];
                            cout << "4 of a Kind Score = " << foKind << endl;
                            screSlt[7] = true;
                            input = false;
                        } else {
                            cout << "You do not have 4 of a kind, choose another category" << endl;
                            q = prompt();
                            if (q) {
                                screSlt[7] = true;
                                input = false;
                            }
                        }
                    }
                    break;
                case 'h': //Full House
                case 'H':
                    if (screSlt[8] == true) cout << "Category filled, please choose another." << endl << endl;
                    else {
                        //Validate if the player has a full house
                        if (die[1] == die[2] && die[3] == die[4] && die[4] == die[5]) {
                            fHouse = 25;
                            cout << "Full House = " << fHouse << endl;
                            screSlt[8] = true;
                            input = false;
                        } else if (die[1] == die[2] && die[2] == die[3] && die[4] == die[5]) {
                            fHouse = 25;
                            cout << "Full House = " << fHouse << endl;
                            screSlt[8] = true;
                            input = false;
                        } else {
                            //If not, offer scratch
                            cout << "You do not have a full house, choose another category" << endl;
                            q = prompt();
                            if (q) {
                                screSlt[8] = true;
                                input = false;
                            }
                        }
                    }
                    break;
                case 's': //Small Straight
                case 'S':
                    if (screSlt[9] == true) cout << "Category filled, please choose another." << endl << endl;
                    else {
                        //Validate if the player has a small straight
                        if (die[1] == die[2] && die[2] + 1 == die[3] && die[3] + 1 == die[4] && die[4] + 1 == die[5]) {
                            sStr8 = 30;
                            cout << "Small Straight Score = " << sStr8 << endl;
                            screSlt[9] = true;
                            input = false;
                        } else if (die[1] + 1 == die[2] && die[2] == die[3] && die[3] + 1 == die[4] && die[4] + 1 == die[5]) {
                            sStr8 = 30;
                            cout << "Small Straight Score = " << sStr8 << endl;
                            screSlt[9] = true;
                            input = false;
                        } else if (die[1] + 1 == die[2] && die[2] + 1 == die[3] && die[3] == die[4] && die[4] + 1 == die[5]) {
                            sStr8 = 30;
                            cout << "Small Straight Score = " << sStr8 << endl;
                            screSlt[9] = true;
                            input = false;
                        } else if (die[1] + 1 == die[2] && die[2] + 1 == die[3] && die[3] + 1 == die[4] && die[4] == die[5]) {
                            sStr8 = 30;
                            cout << "Small Straight Score = " << sStr8 << endl;
                            screSlt[9] = true;
                            input = false;
                        } else if (die[1] + 1 == die[2] && die[2] + 1 == die[3] && die[3] + 1 == die[4]) {
                            sStr8 = 30;
                            cout << "Small Straight Score = " << sStr8 << endl;
                            screSlt[9] = true;
                            input = false;
                        } else if (die[2] + 1 == die[3] && die[3] + 1 == die[4] && die[4] + 1 == die[5]) {
                            sStr8 = 30;
                            cout << "Small Straight Score = " << sStr8 << endl;
                            screSlt[9] = true;
                            input = false;
                        }
                        else {
                            //If not, offer scratch
                            cout << "You do not have a small straight, choose another category" << endl;
                            q = prompt();
                            if (q) {
                                screSlt[9] = true;
                                input = false;
                            }
                        }
                    }
                    break;
                case 'l': //Large Straight
                case 'L':
                    if (screSlt[10] == true) cout << "Category filled, please choose another." << endl << endl;
                    else {
                        //Validate if the player has a large straight
                        if (die[1] == die[2] - 1 && die[2] == die[3] - 1 && die[3] == die[4] - 1 && die[4] == die[5] - 1) {
                            lStr8 = 40;
                            cout << "Large Straight Score = " << lStr8 << endl;
                            screSlt[10] = true;
                            input = false;
                        } else {
                            //If not, offer scratch
                            cout << "You do not have a large straight, choose another category" << endl;
                            q = prompt();
                            if (q) {
                                screSlt[10] = true;
                                input = false;
                            }
                        }
                    }
                    break;
                case 'y': //Yahtzee
                case 'Y':
                    //Validate if the player has yahtzee
                    if (die[1] == die[2] && die[2] == die[3] && die[3] == die[4] && die[4] == die[5]) {
                        if (ycount == 0) {
                            yahtzee += 50;
                            ycount += 1;
                            cout << "Yahtzee Score = " << yahtzee << endl;
                            input = false;
                        } else if (ycount > 1) {
                            yahtzee += 100;
                            cout << "Yahtzee Score = " << yahtzee << endl;
                            input = false;
                        }
                    } else {
                        //If not, offer scratch
                        cout << "You do not have a yahtzee, choose another category" << endl;
                        q = prompt();
                        if (q) {
                            ycount += 1;
                            screSlt[11] = true;
                            input = false;
                        }
                    }
                    break;
                case 'c': //Chance
                case 'C':
                    if (screSlt[12] == true) cout << "Category filled, please choose another." << endl << endl;
                    else {
                        for (int h = 1; h <= 5; h++) {
                            chance += die[h];
                        }
                        cout << "Chance score = " << chance << endl;
                        screSlt[12] = true;
                        input = false;
                    }
                    break;
                default:
                    cout << "Illegal choice made, please choose another." << endl << endl;
            }
        } while (input);
        cout << endl;

        //Add upper and lower totals
        uTotal = aces + twos + threes + fours + fives + sixes;
        lTotal = thKind + foKind + fHouse + sStr8 + lStr8 + yahtzee + chance;
        //Output updated score card
        cout << "  Updated Scorecard" << endl;
        cout << "************************" << endl;
        cout << "*****Upper Section******" << endl;
        cout << "************************" << endl;
        cout << "*1 *     Ones      *" << setw(3) << aces << "*" << endl;
        cout << "*2 *     Twos      *" << setw(3) << twos << "*" << endl;
        cout << "*3 *     Threes    *" << setw(3) << threes << "*" << endl;
        cout << "*4 *     Fours     *" << setw(3) << fours << "*" << endl;
        cout << "*5 *     Fives     *" << setw(3) << fives << "*" << endl;
        cout << "*6 *_____Sixes_____*" << setw(3) << sixes << "*" << endl;
        cout << "****     Total     *" << setw(3) << uTotal << "*" << endl;
        cout << "************************" << endl;
        cout << "*****Lower Section******" << endl;
        cout << "************************" << endl;
        cout << "*7 * Four of a Kind*" << setw(3) << foKind << "*" << endl;
        cout << "*8 *Three of a Kind*" << setw(3) << thKind << "*" << endl;
        cout << "*9 *   Full House  *" << setw(3) << fHouse << "*" << endl;
        cout << "*10* Small Straight*" << setw(3) << sStr8 << "*" << endl;
        cout << "*11* Large Straight*" << setw(3) << lStr8 << "*" << endl;
        cout << "*12*    YAHTZEE    *" << setw(3) << yahtzee << "*" << endl;
        cout << "*13*____Chance_____*" << setw(3) << chance << "*" << endl;
        cout << "****     Total     *" << setw(3) << lTotal << "*" << endl;
        cout << "************************" << endl;
        cout << "************************" << endl;
        cout << "****  GRAND TOTAL  *" << setw(3) << gTotal << "*" << endl;
        cout << "************************" << endl;
        cout << "************************" << endl;
        cout << endl;
    }

    //Finalize scoring and output results
    if (uTotal >= 63) {
        uTotal += 35;
        cout << "You received a 35 point bonus for having a";
        cout << "n Upper Score of 63 or greater, giving you a";
        cout << " new Upper Score of " << uTotal << endl << endl;
    }
    //Add the grand total and output final scorecard
    gTotal = uTotal + lTotal;
    cout << "The game is complete and your Grand Total = " << gTotal << endl << endl;
    cout << "    Final Scorecard" << endl;
    cout << "*************************" << endl;
    cout << "******Upper Section******" << endl;
    cout << "*************************" << endl;
    cout << "* 1 *     Ones      *" << setw(3) << aces << "*" << endl;
    cout << "* 2 *     Twos      *" << setw(3) << twos << "*" << endl;
    cout << "* 3 *     Threes    *" << setw(3) << threes << "*" << endl;
    cout << "* 4 *     Fours     *" << setw(3) << fours << "*" << endl;
    cout << "* 5 *     Fives     *" << setw(3) << fives << "*" << endl;
    cout << "* 6 *_____Sixes_____*" << setw(3) << sixes << "*" << endl;
    cout << "*****     Total     *" << setw(3) << uTotal << "*" << endl;
    cout << "*************************" << endl;
    cout << "******Lower Section******" << endl;
    cout << "*************************" << endl;
    cout << "* F * Four of a Kind*" << setw(3) << foKind << "*" << endl;
    cout << "* T *Three of a Kind*" << setw(3) << thKind << "*" << endl;
    cout << "* H *   Full House  *" << setw(3) << fHouse << "*" << endl;
    cout << "* S * Small Straight*" << setw(3) << sStr8 << "*" << endl;
    cout << "* L * Large Straight*" << setw(3) << lStr8 << "*" << endl;
    cout << "* Y *    YAHTZEE    *" << setw(3) << yahtzee << "*" << endl;
    cout << "* C *____Chance_____*" << setw(3) << chance << "*" << endl;
    cout << "*****     Total     *" << setw(3) << lTotal << "*" << endl;
    cout << "*************************" << endl;
    cout << "*************************" << endl;
    cout << "*****  GRAND TOTAL  *" << setw(3) << gTotal << "*" << endl;
    cout << "*************************" << endl;
    cout << "*************************" << endl;
    cout << endl;
    cout << "Thanks for playing!" << endl;
    //Executio Disicere
    return 0;
}