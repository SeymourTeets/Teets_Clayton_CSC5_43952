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

using namespace std;
//User Libraries

//Global Constants

//Function Prototypes

int compare(const void * a, const void * b) {
    return ( *(int*) a - *(int*) b);
}
//Executio Incipio

class die {
private:
    unsigned short die[5];
    unsigned short counter;
public:

    unsigned short getDie(int i) {
        return die[i];
    }

    void zeroCount() {
        counter = 0;
    }

    void endCount() {
        counter = 3;
    }

    void roll() {
        //Loop for Die Roll
        for (int i = 0; i < 5; i++) {
            do {
                die[i] = rand() % 6 + 1;
            } while (die[i] == 0);
        }
        counter += 1;
    }

    void printDie() {
        //Output Die
        cout << "Your role:" << endl;
        for (int i = 0; i < 5; i++) {
            cout << "Dice " << i + 1;
            cout << " - |" << die[i] << "|" << endl;
        }
        cout << endl;
    }

    void reRollset() {
        char x;
        cout << "How many die would you like to re roll? ";
        cin>>x;
        while (x != '1' && x != '2' && x != '3' && x != '4' && x != '5') {
            cout << "How many die would you like to re roll? ";
            cin>>x;
        }
        int y = x - 48;
        cout << endl;
        //Loop for die not held
        for (int i = 0; i <= y - 1; i++) {
            int c;
            cout << "Enter the die to re roll: ";
            cin>>c;
            die[c - 1] = rand() % 6 + 1;
            cout << "Dice " << c;
            cout << " - |" << die[c - 1] << "|" << endl << endl;
        }
        counter += 1;
    }

    void setDie(int hand[], int i) {
        die[i] = hand[i];
    }

    bool roundCount() {
        if (counter < 2) {
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
    string name[4];

public:

    int getCount() {
        return counter;
    }

    string getFilled(unsigned short i) {
        string x[2] = {"Open", "Filled"};
        if (scoreBox[i] == false) {
            return x[0];
        } else return x[1];
    }

    string getName(unsigned short players) {
        return name[players];
    }

    void setName(unsigned short players) {
        cout << "Enter player " << players + 1 << " name: ";
        cin >> name[players];
        cout << endl;
    }

    void setYCount() {
        ycount = 0;
    }

    void startCount() {
        counter = 1;
    }

    void addCount() {
        counter += 1;
    }

    void zeroCard(int i) {
        score[i] = 0;
    }

    void unfillCard(int i) {
        scoreBox[i] = false;
    }

    void getscoreCard() {
        //Output Score Card
        cout << "*********************************" << endl;
        cout << "******Upper Section**************" << endl;
        cout << "*********************************" << endl;
        cout << "* 1 *     Ones      *" << setw(3) << score[0] << "*" << setw(7) << getFilled(0) << "*" << endl;
        cout << "* 2 *     Twos      *" << setw(3) << score[1] << "*" << setw(7) << getFilled(1) << "*" << endl;
        cout << "* 3 *     Threes    *" << setw(3) << score[2] << "*" << setw(7) << getFilled(2) << "*" << endl;
        cout << "* 4 *     Fours     *" << setw(3) << score[3] << "*" << setw(7) << getFilled(3) << "*" << endl;
        cout << "* 5 *     Fives     *" << setw(3) << score[4] << "*" << setw(7) << getFilled(4) << "*" << endl;
        cout << "* 6 *_____Sixes_____*" << setw(3) << score[5] << "*" << setw(7) << getFilled(5) << "*" << endl;
        cout << "*****     Total     *" << setw(3) << score[13] << "*********" << endl;
        cout << "*********************************" << endl;
        cout << "******Lower Section**************" << endl;
        cout << "*********************************" << endl;
        cout << "* T *Three of a Kind*" << setw(3) << score[6] << "*" << setw(7) << getFilled(6) << "*" << endl;
        cout << "* F * Four of a Kind*" << setw(3) << score[7] << "*" << setw(7) << getFilled(7) << "*" << endl;
        cout << "* H *   Full House  *" << setw(3) << score[8] << "*" << setw(7) << getFilled(8) << "*" << endl;
        cout << "* S * Small Straight*" << setw(3) << score[9] << "*" << setw(7) << getFilled(9) << "*" << endl;
        cout << "* L * Large Straight*" << setw(3) << score[10] << "*" << setw(7) << getFilled(10) << "*" << endl;
        cout << "* Y *    YAHTZEE    *" << setw(3) << score[11] << "*" << "Count" << setw(2) << ycount << "*" << endl;
        cout << "* C *____Chance_____*" << setw(3) << score[12] << "*" << setw(7) << getFilled(12) << "*" << endl;
        cout << "*****     Total     *" << setw(3) << score[14] << "*********" << endl;
        cout << "*********************************" << endl;
        cout << "*********************************" << endl;
        cout << "*****  GRAND TOTAL  *" << setw(3) << score[15] << "*********" << endl;
        cout << "*********************************" << endl;
        cout << "*********************************" << endl << endl;
    }

    void addTotals() {
        score[13] = score[0] + score[1] + score[2] + score[3] + score[4] + score[5];
        score[14] = score[6] + score[7] + score[8] + score[9] + score[10] + score[11] + score[12];
    }

    void bonus() {
        if (score[13] >= 63) {
            score[13] += 35;
            cout << "You received a 35 point bonus for having a";
            cout << "n Upper Score of 63 or greater, giving you a";
            cout << " new Upper Score of " << score[13] << endl << endl;
        }
    }

    void finalScore() {
        score[15] = score[13] + score[14];
        cout << "The game is complete and your Grand Total = " << score[15] << endl << endl;
        cout << "    Final Scorecard" << endl;
    }

    bool roundCount() {
        if (counter <= 13) {
            return true;
        } else {
            return false;
        }
    }

    bool notFilled(int i) {
        if (scoreBox[i] == true) {
            cout << "Category filled, please choose another." << endl << endl;
            return false;
        } else return true;
    }

    bool scratch(int i) {
        //Declare Variables
        char q;
        bool input;
        //Input Validation
        do {
            //Prompt for input
            cin>>q;
            //Switch for yes or no
            switch (q) {
                case'y':
                case'Y':
                    zeroCard(i);
                    scoreBox[i] = true;
                    input = false;
                    return true;
                    break;
                case'n':
                case'N':
                    input = false;
                    return false;
                    break;
                default: cout << "Invalid input" << endl;
                    input = true;
            }
        } while (input);
    }

    bool upperAdder(unsigned short die[], int i, char x) {

        for (int h = 0; h < 5; h++) {
            if (die[h] == i + 1) {
                score[i] += die[h];
            }
        }
        if (score[i] == 0) {
            cout << "You didn't roll a " << x << ", would you like to scratch? (Y/N) ";
            return true;
        } else {
            cout << "Category " << x << " score = " << score[i] << endl;
            scoreBox[i] = true;
            return false;
        }
    }

    bool threeKind(unsigned short die[]) {
        //Validate if the player has three of a kind
        if (die[1] == die[2] && die[2] == die[3]) {
            score[6] = die[1] + die[2] + die[3];
            cout << "3 of a Kind Score = " << score[6] << endl;
            scoreBox[6] = true;
            return false;
        } else if (die[2] == die[3] && die[3] == die[4]) {
            score[6] = die[2] + die[3] + die[4];
            cout << "3 of a Kind Score = " << score[6] << endl;
            scoreBox[6] = true;
            return false;
        } else if (die[0] == die[1] && die[1] == die[2]) {
            score[6] = die[0] + die[1] + die[2];
            cout << "3 of a Kind Score = " << score[6] << endl;
            scoreBox[6] = true;
            return false;
        } else {
            cout << "You do not have 3 of a kind, would you like to scratch? (Y/N) ";
            return true;
        }
    }

    bool fourKind(unsigned short die[]) {
        //Validate if the player has four of a kind
        if (die[0] == die[1] && die[1] == die[2] && die[2] == die[3]) {
            score[7] = die[0] + die[1] + die[2] + die[3];
            cout << "4 of a Kind Score = " << score[7] << endl;
            scoreBox[7] = true;
            return false;
        } else if (die[1] == die[2] && die[2] == die[3] && die[3] == die[4]) {
            score[7] = die[1] + die[2] + die[3] + die[4];
            cout << "4 of a Kind Score = " << score[7] << endl;
            scoreBox[7] = true;
            return false;
        } else {
            cout << "You do not have 4 of a kind, would you like to scratch? (Y/N) ";
            return true;
        }
    }

    bool fullHouse(unsigned short die[]) {
        //Validate if the player has a full house
        if (die[0] == die[1] && die[2] == die[3] && die[3] == die[4]) {
            score[8] = 25;
            cout << "Full House = " << score[8] << endl;
            scoreBox[8] = true;
            return false;
        } else if (die[0] == die[1] && die[1] == die[2] && die[3] == die[4]) {
            score[8] = 25;
            cout << "Full House = " << score[8] << endl;
            scoreBox[8] = true;
            return false;
        } else {
            cout << "You do not have a full house, would you like to scratch? (Y/N) ";
            return true;
        }
    }

    bool smallStraight(unsigned short die[]) {
        //Validate if the player has a small straight
        if (die[0] == die[1] && die[1] + 1 == die[2] && die[2] + 1 == die[3] && die[3] + 1 == die[4]) {
            score[9] = 30;
            cout << "Small Straight Score = " << score[9] << endl;
            scoreBox[9] = true;
            return false;
        } else if (die[0] + 1 == die[1] && die[1] == die[2] && die[2] + 1 == die[3] && die[3] + 1 == die[4]) {
            score[9] = 30;
            cout << "Small Straight Score = " << score[9] << endl;
            scoreBox[9] = true;
            return false;
        } else if (die[0] + 1 == die[1] && die[1] + 1 == die[2] && die[2] == die[3] && die[3] + 1 == die[4]) {
            score[9] = 30;
            cout << "Small Straight Score = " << score[9] << endl;
            scoreBox[9] = true;
            return false;
        } else if (die[0] + 1 == die[1] && die[1] + 1 == die[2] && die[2] + 1 == die[3] && die[3] == die[4]) {
            score[9] = 30;
            cout << "Small Straight Score = " << score[9] << endl;
            scoreBox[9] = true;
            return false;
        } else if (die[0] + 1 == die[1] && die[1] + 1 == die[2] && die[2] + 1 == die[3]) {
            score[9] = 30;
            cout << "Small Straight Score = " << score[9] << endl;
            scoreBox[9] = true;
            return false;
        } else if (die[1] + 1 == die[2] && die[2] + 1 == die[3] && die[3] + 1 == die[4]) {
            score[9] = 30;
            cout << "Small Straight Score = " << score[9] << endl;
            scoreBox[9] = true;
            return false;
        } else {
            cout << "You do not have a small straight, would you like to scratch? (Y/N) ";
            return true;
        }
    }

    bool largeStraight(unsigned short die[]) {
        //Validate if the player has a large straight
        if (die[0] == die[1] - 1 && die[1] == die[2] - 1 && die[2] == die[3] - 1 && die[3] == die[4] - 1) {
            score[10] = 40;
            cout << "Large Straight Score = " << score[10] << endl;
            scoreBox[10] = true;
            return false;
        } else {
            cout << "You do not have a large straight, would you like to scratch? (Y/N) ";
            return true;
        }
    }

    bool yahtzee(unsigned short die[]) {
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
            return false;
        } else {
            cout << "You do not have a yahtzee, would you like to scratch? (Y/N) ";
            return true;
        }
    }

    bool chance(unsigned short die[]) {
        for (int h = 0; h < 5; h++) {
            score[12] += die[h];
        }
        cout << "Chance score = " << score[12] << endl;
        scoreBox[12] = true;
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
    die d[players];
    scoreCard s[players];
    //Zero round counter and card slots and prompt for player names
    for (int p = 0; p < players; p++) {
        s[p].setName(p);
        s[p].startCount();
        s[p].setYCount();
        for (int i = 0; i < 13; i++) {
            s[p].unfillCard(i);
        }
        for (int i = 0; i < 16; i++) {
            s[p].zeroCard(i);
        }
    }
    //Loop for 13 rounds
    while (s[players - 1].roundCount()) {
        for (int p = 0; p < players; p++) {
            cout << "Player - " << s[p].getName(p) << endl;
            cout << "Round  - " << s[p].getCount() << endl << endl;
            //Add to round counter
            s[p].addCount();
            //Loop for Die Roll
            d[p].roll();
            //Output Die
            d[p].printDie();
            //Zero die round counter
            d[p].zeroCount();
            do {
                char choice;
                cout << "Would you like to hold, roll again, or keep? (H/R/K) ";
                cin>>choice;
                while (choice != 'h' && choice != 'H' && choice != 'R' && choice != 'r' && choice != 'K' && choice != 'k') {
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
                        d[p].endCount();
                        break;
                    default:
                        cout << "Type 'H' or 'h' to hold, 'R' or 'r' to re roll, 'K' or 'k' to keep die and score." << endl << endl;
                }
            } while (d[p].roundCount()); //Counter to ensure that die are rolled no more than 3 times
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
        cout << "Player - " << p + 1 << endl;
        //Finalize scoring and output results
        s[p].bonus();
        //Add the grand total and output final scorecard
        s[p].finalScore();
        s[p].getscoreCard();
    }
    cout << "Thanks for playing!" << endl;
    //Executio Disicere
    return 0;
}