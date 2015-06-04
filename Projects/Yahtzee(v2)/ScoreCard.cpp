#include "ScoreCard.h"
#include <iomanip>
#include <string>
#include <fstream>

int ScoreCard::getCount() {
    return counter;
}

int ScoreCard::getFScore() {
    return score[15];
}

string ScoreCard::getFilled(unsigned short i) {
    string x[2] = {"Open", "Filled"};
    return (scoreBox[i] == false)?(x[0]):(x[1]);
}

string ScoreCard::getName() {
    return name;
}

void ScoreCard::setName() {
    cin >> name;
}

void ScoreCard::setHScore() {
    ifstream high;
    high.open("highscore.txt");
    high >> hScore >> hName;
    high.close();
    if (hScore < score[15]) {
        ofstream high;
        high.open("highscore.txt");
        high<<score[15]<<endl;
        high<<name<<endl;
        high.close();
        cout<<name<<" has the new high score of "<<score[15]<<endl;
        cout<<"Congratulations, you beat "<<hName<<"'s high score by "<<score[15]-hScore<<endl;
    }
}

void ScoreCard::setYCount() {
    ycount = 0;
}

void ScoreCard::startCount() {
    counter = 1;
}

void ScoreCard::addCount() {
    counter += 1;
}

void ScoreCard::zeroCard(int i) {
    score[i] = 0;
}

void ScoreCard::unfillCard(int i) {
    scoreBox[i] = false;
}

void ScoreCard::getscoreCard() {
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

void ScoreCard::addTotals() {
    score[13] = score[0] + score[1] + score[2] + score[3] + score[4] + score[5];
    score[14] = score[6] + score[7] + score[8] + score[9] + score[10] + score[11] + score[12];
}

void ScoreCard::bonus() {
    if (score[13] >= 63) {
        score[13] += 35;
        cout << "You received a 35 point bonus for having a";
        cout << "n Upper Score of 63 or greater, giving you a";
        cout << " new Upper Score of " << score[13] << endl << endl;
    }
}

void ScoreCard::finalScore() {
    score[15] = score[13] + score[14];
    cout << "The game is complete and your Grand Total = " << score[15] << endl << endl;
    cout << "    Final Scorecard" << endl;
}

bool ScoreCard::roundCount() {
    if (counter <= 13) {
        return true;
    } else {
        return false;
    }
}

bool ScoreCard::notFilled(int i) {
    if (scoreBox[i] == true) {
        cout << "Category filled, please choose another." << endl << endl;
        return false;
    } else return true;
}

bool ScoreCard::scratch(int i) {
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

bool ScoreCard::upperAdder(unsigned short die[], int i, char x) {

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

bool ScoreCard::threeKind(unsigned short die[]) {
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

bool ScoreCard::fourKind(unsigned short die[]) {
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

bool ScoreCard::fullHouse(unsigned short die[]) {
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

bool ScoreCard::smallStraight(unsigned short die[]) {
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

bool ScoreCard::largeStraight(unsigned short die[]) {
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

bool ScoreCard::yahtzee(unsigned short die[]) {
    //Validate if the player has yahtzee
    if (die[0] == die[1] && die[1] == die[2] && die[2] == die[3] && die[3] == die[4]) {
        if (ycount == 0) {
            score[11] += 50;
            ycount += 1;
            cout << "Yahtzee Score = " << score[11] << endl;
        } else if (ycount >= 1) {
            score[11] += 100;
            ycount += 1;
            cout << "Yahtzee Score = " << score[11] << endl;
        }
        return false;
    } else {
        cout << "You do not have a yahtzee, would you like to scratch? (Y/N) ";
        return true;
    }
}

bool ScoreCard::chance(unsigned short die[]) {
    for (int h = 0; h < 5; h++) {
        score[12] += die[h];
    }
    cout << "Chance score = " << score[12] << endl;
    scoreBox[12] = true;
}