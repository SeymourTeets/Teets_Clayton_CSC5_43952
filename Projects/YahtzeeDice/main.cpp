/* 
 * File       : main.cpp
 * Author     : Clayton Teets
 * Created on : May 4, 2015, 4:25 PM
 * Purpose    : 
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
bool prompt();
//Die sorter for scoring algorithms

int compare(const void * a, const void * b) {
    return ( *(int*) a - *(int*) b);
}
//Executio Incipio

int main(int argc, char** argv) {
    cout << "************************************************************************************************************************************************" << endl;
    cout << "* YYYYYYY       YYYYYYY               hhhhhhh                     tttt                                                                    !!!  *" << endl;
    cout << "* Y:::::Y       Y:::::Y               h:::::h                  ttt:::t                                                                   !!:!! *" << endl;
    cout << "* Y:::::Y       Y:::::Y               h:::::h                  t:::::t                                                                   !:::! *" << endl;
    cout << "* Y::::::Y     Y::::::Y               h:::::h                  t:::::t                                                                   !:::! *" << endl;
    cout << "* YYY:::::Y   Y:::::YYYaaaaaaaaaaaaa   h::::h hhhhh      ttttttt:::::ttttttt    zzzzzzzzzzzzzzzzz    eeeeeeeeeeee        eeeeeeeeeeee    !:::! *" << endl;
    cout << "*    Y:::::Y Y:::::Y   a::::::::::::a  h::::hh:::::hhh   t:::::::::::::::::t    z:::::::::::::::z  ee::::::::::::ee    ee::::::::::::ee  !:::! *" << endl;
    cout << "*     Y:::::Y:::::Y    aaaaaaaaa:::::a h::::::::::::::hh t:::::::::::::::::t    z::::::::::::::z  e::::::eeeee:::::ee e::::::eeeee:::::ee!:::! *" << endl;
    cout << "*      Y:::::::::Y              a::::a h:::::::hhh::::::htttttt:::::::tttttt    zzzzzzzz::::::z  e::::::e     e:::::ee::::::e     e:::::e!:::! *" << endl;
    cout << "*       Y:::::::Y        aaaaaaa:::::a h::::::h   h::::::h     t:::::t                z::::::z   e:::::::eeeee::::::ee:::::::eeeee::::::e!:::! *" << endl;
    cout << "*        Y:::::Y       aa::::::::::::a h:::::h     h:::::h     t:::::t               z::::::z    e:::::::::::::::::e e:::::::::::::::::e !:::! *" << endl;
    cout << "*        Y:::::Y      a::::aaaa::::::a h:::::h     h:::::h     t:::::t              z::::::z     e::::::eeeeeeeeeee  e::::::eeeeeeeeeee  !!:!! *" << endl;
    cout << "*        Y:::::Y     a::::a    a:::::a h:::::h     h:::::h     t:::::t    tttttt   z::::::z      e:::::::e           e:::::::e            !!!  *" << endl;
    cout << "*        Y:::::Y     a::::a    a:::::a h:::::h     h:::::h     t::::::tttt:::::t  z::::::zzzzzzzze::::::::e          e::::::::e                *" << endl;
    cout << "*     YYYY:::::YYYY  a:::::aaaa::::::a h:::::h     h:::::h     tt::::::::::::::t z::::::::::::::z e::::::::eeeeeeee   e::::::::eeeeeeee   !!!  *" << endl;
    cout << "*     Y:::::::::::Y   a::::::::::aa:::ah:::::h     h:::::h       tt:::::::::::ttz:::::::::::::::z  ee:::::::::::::e    ee:::::::::::::e  !!:!! *" << endl;
    cout << "*     YYYYYYYYYYYYY    aaaaaaaaaa  aaaahhhhhhh     hhhhhhh         ttttttttttt  zzzzzzzzzzzzzzzzz    eeeeeeeeeeeeee      eeeeeeeeeeeeee   !!!  *" << endl;
    cout << "************************************************************************************************************************************************" << endl;
    cout << endl << endl;
    //Initialize the random number seed
    srand(static_cast<unsigned int> (time(0)));
    //Declare Variables
    const int SIZE = 6; //Six Sided Die
    int die[SIZE] = {}; //Yahtzee Die
    char choice; //Choice for each turn
    bool q; //Yes/No input for scratch option
    short x; //Die to hold
    short count = 1; //Amount of re-rolls
    short maxrnds = 13, //Maximum rounds per game
            round; //Current round
    //For scoring validation
    bool screSlt[12]; //Score slot
    for (int i = 0; i <= 12; i++) {
        screSlt[i] = false;
    }
    //Menu inputs
    int aces = 0;
    int twos = 0;
    int threes = 0;
    int fours = 0;
    int fives = 0;
    int sixes = 0;
    int thKind = 0; //Three of a Kind
    int foKind = 0; //Four of a Kind
    int fHouse = 0;
    int sStr8 = 0; //Small straight
    int lStr8 = 0; //Large straight
    int yahtzee = 0;
    int chance = 0;
    //Totals
    short uTotal = 0, //Upper total
            lTotal = 0, //Lower total
            gTotal = 0; //Grand total
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
            cout << "  |" << die[i] << "|" << endl;
        }
        //Ask if they would like to hold any die?
        cout << endl;
        do {
            cout << "Would you like to hold, roll again, or score? (H/R/S) ";
            cin>>choice;
            //Initiate Switch for chosen path
            switch (choice) {
                case'h':
                case'H':
                    cout << "How many die would you like to hold?" << endl;
                    cin>>x;
                    for (int i = 1; i <= 5 - x; i++) {
                        cout << "Enter the die to re roll: ";
                        int c;
                        cin>>c;
                        die[c] = rand() % 6 + 1;
                        cout << die[c] << endl;
                    }
                    //Output Die
                    cout << "Your role:" << endl;
                    for (int i = 1; i < 6; i++) {
                        cout << "Dice " << i;
                        cout << "  |" << die[i] << "|" << endl;
                    }
                    cout << endl;
                    count += 1;
                    break;
                case'r':
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
                        cout << "  |" << die[i] << "|" << endl;
                    }
                    cout << endl;
                    count += 1;
                    break;
                case's':
                case'S':
                    count += 3;
                    break;
                default:
                    cout << "You have broken my game" << endl;
            }
        } while (count <= 2);
        cout << endl;
        //Sort Die
        qsort(die, 6, sizeof (int), compare);
        //Output Score Card
        cout << "Let's SCORE!" << endl;
        cout << "\n\nScoring Options: Enter number for category to enter score.\n" << endl;
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
        cout << "*                  *****" << endl;
        cout << "*   GRAND TOTAL    *" << setw(3) << gTotal << "*" << endl;
        cout << "*                  *****" << endl;
        cout << "************************" << endl;
        cout << endl;

        bool input = true;
        do {
            //Prompt for scoring options
            int option;
            cout << "Option - ";
            cin >> option;
            //Select option
            switch (option) {
                case 1:
                    if (screSlt[0] == true) cout << "Category filled, please choose another." << endl;
                    else {
                        for (int h = 1; h <= 5; h++) {
                            if (die[h] == 1) {
                                aces += die[h];
                            }
                        }
                        cout << "Aces score = " << aces << endl;
                        screSlt[0] = true;
                        input = false;
                        if (aces == 0) {
                            q = prompt();
                            if (!q) {
                                screSlt[0] = false;
                                input = true;
                            }
                        }
                    }
                    break;
                case 2:
                    if (screSlt[1] == true) cout << "Category filled, please choose another." << endl;
                    else {
                        for (int h = 1; h <= 5; h++) {
                            if (die[h] == 2) {
                                twos += die[h];
                            }
                        }
                        cout << "Twos score = " << twos << endl;
                        screSlt[1] = true;
                        input = false;
                        if (twos == 0) {
                            q = prompt();
                            if (!q) {
                                screSlt[1] = false;
                                input = true;
                            }
                        }
                    }
                    break;
                case 3:
                    if (screSlt[2] == true) cout << "Category filled, please choose another." << endl;
                    else {
                        for (int h = 1; h <= 5; h++) {
                            if (die[h] == 3) {
                                threes += die[h];
                            }
                        }
                        cout << "Threes score = " << threes << endl;
                        screSlt[2] = true;
                        input = false;
                        if (threes == 0) {
                            q = prompt();
                            if (!q) {
                                screSlt[2] = false;
                                input = true;
                            }
                        }
                    }
                    break;
                case 4:
                    if (screSlt[3] == true) cout << "Category filled, please choose another." << endl;
                    else {
                        for (int h = 1; h <= 5; h++) {
                            if (die[h] == 4) {
                                fours += die[h];
                            }
                        }
                        cout << "Fours score = " << fours << endl;
                        screSlt[3] = true;
                        input = false;
                        if (fours == 0) {
                            q = prompt();
                            if (!q) {
                                screSlt[3] = false;
                                input = true;
                            }
                        }
                    }
                    break;
                case 5:
                    if (screSlt[4] == true) cout << "Category filled, please choose another." << endl;
                    else {
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
                            if (!q) {
                                screSlt[4] = false;
                                input = true;
                            }
                        }
                    }
                    break;
                case 6:
                    if (screSlt[5] == true) cout << "Category filled, please choose another." << endl;
                    else {
                        for (int h = 1; h <= 5; h++) {
                            if (die[h] == 6) {
                                sixes += die[h];
                            }
                        }
                        cout << "Sixes score = " << sixes << endl;
                        screSlt[5] = true;
                        input = false;
                        if (sixes == 0) {
                            q = prompt();
                            if (!q) {
                                screSlt[5] = false;
                                input = true;
                            }
                        }
                    }
                    break;
                case 7:
                    if (screSlt[6] == true) cout << "Category filled, please choose another." << endl;
                    else {
                        if (die[1] == die[2] && die[2] == die[3]) {
                            thKind = die[1] + die[2] + die[3];
                            screSlt[6] = true;
                            input = false;
                        } else if (die[2] == die[3] && die[3] == die[4]) {
                            thKind = die[2] + die[3] + die[4];
                            screSlt[6] = true;
                            input = false;
                        } else if (die[3] == die[4] && die[4] == die[5]) {
                            thKind = die[3] + die[4] + die[5];
                            screSlt[6] = true;
                            input = false;
                        } else cout << "You do not have 3 of a kind, choose another category" << endl;
                    }
                    break;
                case 8:
                    if (screSlt[7] == true) cout << "Category filled, please choose another." << endl;
                    else {
                        if (die[1] == die[2] && die[2] == die[3] && die[3] == die[4]) {
                            foKind = die[1] + die[2] + die[3] + die[4];
                            screSlt[7] = true;
                            input = false;
                        } else if (die[2] == die[3] && die[3] == die[4] && die[4] == die[5]) {
                            foKind = die[2] + die[3] + die[4] + die[5];
                            screSlt[7] = true;
                            input = false;
                        } else cout << "You do not have 4 of a kind, choose another category" << endl;
                    }
                    break;
                case 9:
                    if (screSlt[8] == true) cout << "Category filled, please choose another." << endl;
                    else {
                        if (die[1] == die[2] && die[3] == die[4] && die[4] == die[5]) {
                            fHouse = 25;
                            screSlt[8] = true;
                            input = false;
                        } else if (die[1] == die[2] && die[2] == die[3] && die[4] == die[5]) {
                            fHouse = 25;
                            screSlt[8] = true;
                            input = false;
                        } else cout << "You do not have a full house, choose another category" << endl;
                    }

                    break;
                case 10:
                    if (screSlt[9] == true) cout << "Category filled, please choose another." << endl;
                    else {
                        cout << "Enter Small Straight score.\n";
                        cin>>sStr8;
                        screSlt[9] = true;
                        input = false;
                    }
                    break;
                case 11:
                    if (screSlt[10] == true) cout << "Category filled, please choose another." << endl;
                    else {
                        if (die[1] == die[2] + 1 && die[2] == die[3] + 1 && die[3] == die[4] + 1 && die[4] == die[5] + 1) {
                            lStr8 = 40;
                            screSlt[10] = true;
                            input = false;
                        } else cout << "You do not have a large straight, choose another category" << endl;
                    }
                    break;
                case 12:
                    if (die[1] == die[2] && die[2] == die[3] && die[4] == die[5] && die[5] == die[6]) {
                        yahtzee = 50;
                        input = false;
                    } else cout << "You do not have a yahtzee, choose another category" << endl;
                    break;
                case 13:
                    if (screSlt[12] == true) cout << "Category filled, please choose another." << endl;
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
                    cout << "Illegal choice made. Please choose another." << endl;
            }
        } while (input);
        cout << endl;
        //Add upper and lower totals
        uTotal = aces + twos + threes + fours + fives + sixes;
        lTotal = thKind + foKind + fHouse + sStr8 + lStr8 + yahtzee + chance;
        //Output updated score card
        cout << "  Updated Score Card" << endl;
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
        cout << "*                  *****" << endl;
        cout << "*   GRAND TOTAL    *" << setw(3) << gTotal << "*" << endl;
        cout << "*                  *****" << endl;
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
    gTotal = uTotal + lTotal;
    cout << "The game is complete and your Grand Total = " << gTotal << endl << endl;
    cout << "    Final Score Card" << endl;
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
    cout << "*                  *****" << endl;
    cout << "*   GRAND TOTAL    *" << setw(3) << gTotal << "*" << endl;
    cout << "*                  *****" << endl;
    cout << "************************" << endl;
    cout << endl;
    //Executio Disicere
    return 0;
}

//Yes/No reader

bool prompt() {
    //Declare Variables
    char q;
    bool input; //Input validation
    bool output; //Return
    //Input Validation
    do {
        //Prompt for input
        cout << "You do not have any die for this category, would you like to scratch? (Y/N) ";
        cin>>q;
        //Switch
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
    return output;
}