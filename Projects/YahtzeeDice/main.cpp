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

//Executio Incipio

int main(int argc, char** argv) {
    //Initialize the random number seed
        srand(static_cast<unsigned int>(time(0)));
    //Declare Variables
        const int SIZE = 6;
        int die[SIZE] = {};//Yahtzee die
        char choice;//Choice for each turn
        short x;//Die to hold
        short count=1;//Amount of re-rolls
        short maxrnds = 13,//Maximum rounds per game
              round;       //Current round
        //For scoring validation
            bool screSlt[12];//Score slot
            for (int i=0; i<=12; i++){screSlt[i] = false;}
        //Menu inputs
            int aces = 0;
            int twos = 0;
            int threes = 0;
            int fours = 0;
            int fives = 0;
            int sixes = 0;
            int thKind = 0;//Three of a Kind
            int foKind = 0;//Four of a Kind
            int fHouse = 0;
            int sStr8 = 0;//Small straight
            int lStr8 = 0;//Large straight
            int yahtzee = 0;
            int chance = 0;
        //Totals
            short uTotal = 0,//Upper total
                  lTotal = 0,//Lower total
                  gTotal = 0;//Grand total
        while (round<maxrnds){
    //Initiate roll counter
            count = 1;
    //Add to round counter
            round += 1;
    //Loop for Die Roll
        for (int i=1; i<6; i++){
        die[i] = rand()%6+1;
        }
    //Output Die
        cout<<"Your role:"<<endl;
        for (int i=1; i<6; i++){
            cout<<"Dice"<<i;
            cout<<"  |"<<die[i]<<"|"<<endl;
        }
    //Ask if they would like to hold any die?
        cout<<endl;
        do {
        cout<<"Would you like to hold, roll again, or score? (H/R/S) ";
        cin>>choice;
    //Initiate Switch for chosen path
        switch(choice){
            case'h':
            case'H':
                cout<<"How many die would you like to hold?"<<endl;
                cin>>x;
                for (int i=1; i<=5-x; i++){
                    cout<<"Enter the die to reroll: ";
                    int c;
                    cin>>c;
                    die[c]=rand()%6+1;
                    cout<<die[c]<<endl;
                }
                //Output Die
                    cout<<"Your role:"<<endl;
                    for (int i=1; i<6; i++){
                        cout<<"Dice"<<i;
                        cout<<"  |"<<die[i]<<"|"<<endl;
                    } 
                    cout<<endl;
                    count+=1;
                break;
            case'r':
            case'R':
                //Loop for Die Roll
                    for (int i=1; i<6; i++){
                        do {die[i] = rand()%7;}
                        while (die[i]==0);
                    }
                //Output Die
                    cout<<"Your role:"<<endl;
                    for (int i=1; i<6; i++){
                        cout<<"Dice"<<i;
                        cout<<"  |"<<die[i]<<"|"<<endl;
                    }      
                    cout<<endl;
                count+=1;
                break;
            case's':
            case'S':
                count+=3;
                break;
            default:
                cout<<"You have broken my game"<<endl;
        }
        }while(count<=2);
        cout<<endl;
        //Score Card
        cout<<"Let's SCORE!"<<endl;
        cout<<"\n\nScoring Options: Enter number for category to enter score.\n" << endl;
        cout<<"************************"<<endl;
        cout<<"*****Upper Section******"<<endl;
        cout<<"************************"<<endl;
        cout<<"*1 *     Ones      *"<<setw(3)<<aces<<"*"<<endl;
        cout<<"*2 *     Twos      *"<<setw(3)<<twos<<"*"<<endl;
        cout<<"*3 *     Threes    *"<<setw(3)<<threes<<"*"<<endl;
        cout<<"*4 *     Fours     *"<<setw(3)<<fours<<"*"<<endl;
        cout<<"*5 *     Fives     *"<<setw(3)<<fives<<"*"<<endl;
        cout<<"*6 *     Sixes     *"<<setw(3)<<sixes<<"*"<<endl;
        cout<<"****     Total     *"<<setw(3)<<uTotal<<"*"<<endl;
        cout<<"************************"<<endl;
        cout<<"*****Lower Section******"<<endl;
        cout<<"************************"<<endl;
        cout<<"*7 * Four of a Kind*"<<setw(3)<<foKind<<"*"<<endl;
        cout<<"*8 *Three of a Kind*"<<setw(3)<<thKind<<"*"<<endl;
        cout<<"*9 *   Full House  *"<<setw(3)<<fHouse<<"*"<<endl;
        cout<<"*10* Small Straight*"<<setw(3)<<sStr8<<"*"<<endl;
        cout<<"*11* Large Straight*"<<setw(3)<<lStr8<<"*"<<endl;
        cout<<"*12*    YAHTZEE    *"<<setw(3)<<yahtzee<<"*"<<endl;
        cout<<"*13*    Chance     *"<<setw(3)<<chance<<"*"<<endl;
        cout<<"****    Total      *"<<setw(3)<<lTotal<<"*"<<endl;
        cout<<"************************"<<endl;
        cout<<"*                  *****"<<endl;
        cout<<"*   GRAND TOTAL    *"<<setw(3)<<gTotal<<"*"<<endl;
        cout<<"*                  *****"<<endl;
        cout<<"************************"<<endl;
        cout<<endl;
        
	int option;
	cout << "Option - ";
	cin >> option;

	switch (option) {
	case 1:
		if (screSlt[0] == true) cout << "pick another category" << endl;
		else
                    for (int h=1; h<=5; h++){
                        if (die[h]==1) {aces += die[h];} }
                    cout<<"Aces score = "<<aces<<endl;
                    screSlt[0] = true;
        break;
	case 2:
		if (screSlt[1] == true) cout << "pick another category" << endl;	
		else
                    for (int h=1; h<=5; h++){
                        if (die[h]==2) {twos += die[h];} }
                    cout<<"Twos score = "<<twos<<endl;
                    screSlt[1] = true;
        break;
	case 3:
		if (screSlt[2] == true) cout << "pick another category" << endl;
		else
                    for (int h=1; h<=5; h++){
                        if (die[h]==3) {threes += die[h];} }
                    cout<<"Threes score = "<<threes<<endl;
                    screSlt[2] = true;
        break;
	case 4:
		if (screSlt[3] == true) cout << "pick another category" << endl;
		else
                    for (int h=1; h<=5; h++){
                        if (die[h]==4) {fours += die[h];} }
                    cout<<"Fours score = "<<fours<<endl;
                    screSlt[3] = true;
        break;
	case 5:
		if (screSlt[4] == true) cout << "pick another category" << endl;
		else
                    for (int h=1; h<=5; h++){
                        if (die[h]==5) {fives += die[h];} }
                    cout<<"Fives score = "<<fives<<endl;
                    screSlt[4] = true;
        break;
	case 6:
		if (screSlt[5] == true) cout << "pick another category" << endl;
		else
                    for (int h=1; h<=5; h++){
                        if (die[h]==6) {sixes += die[h];} }
                    cout<<"Sixes score = "<<sixes<<endl;
                    screSlt[5] = true;		
        break;
	case 7:
		if (screSlt[6] == true) cout << "pick another category" << endl;
		else
                    cout << "Enter 3 of a Kind score.\n";
                    cin >> thKind;
                    screSlt[6] = true;
        break;
	case 8:
		if (screSlt[7] == true) cout << "pick another category" << endl;
		else
                    cout << "Enter 4 of a Kind score.\n";
                    cin >> foKind;
                    screSlt[7] = true;	
        break;
	case 9:
		if (screSlt[8] == true) cout << "pick another category" << endl;
		else
                    cout << "Enter Full House score.\n";
                    cin >> fHouse;
                    screSlt[8] = true;
        break;
	case 10:
		if (screSlt[9] == true) cout << "pick another category" << endl;
		else
                    cout << "Enter Small Straight score.\n";
                    cin >> sStr8;
                    screSlt[9] = true;
        break;
	case 11:
		if (screSlt[10] == true) cout << "pick another category" << endl;
		else
                    cout << "Enter Large Straight score.\n";
                    cin >> lStr8;
                    screSlt[10] = true;	
        break;
	case 12:
		if (screSlt[11] == true) cout << "pick another category" << endl;
		else
                    cout << "Enter Yahtzee score.\n";
                    cin >> yahtzee;
                    screSlt[11] = true;		
        break;
	case 13:
		if (screSlt[12] == true) cout << "pick another category" << endl;
		else
                    cout << "Enter Chance score.\n";
                    cin >> chance;
                    screSlt[12] = true;	
        break;
	default:
		cout << "Illegal choice made. Please choose another." << endl;
	}
        cout<<endl;
        uTotal = aces + twos + threes + fours + fives + sixes;
        lTotal = thKind + foKind + fHouse + sStr8 + lStr8 + yahtzee + chance;
        }
    //Executio Disicere
    return 0;
}