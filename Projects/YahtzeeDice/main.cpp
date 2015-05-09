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
    int die[SIZE] = {};
    char choice;
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
    //Ask if they would like to hold any die?
    cout<<endl<<endl;
    cout<<"Would you like to hold, roll again, or score? (H/R/S)"<<endl;
    cin>>choice;
    //Initiate Switch for chosen path
    switch(choice){
        case'h':
            for (int u=1; u<=5; u++){
            cout<<"How many die would you like to hold?"<<endl;
            short x;
            cin>>x;
            for (int i=1; i<=5-x; i++){
                cout<<"Enter the die to reroll: ";
                int c;
                cin>>c;
                do {die[c]=rand()%7;}
                while (die[c]==0);
                cout<<die[c]<<endl;
            }
            //Output Die
            cout<<"Your role:"<<endl;
            for (int i=1; i<6; i++){
                cout<<"Dice"<<i;
                cout<<"  |"<<die[i]<<"|"<<endl;
            }
    }
            break;
        case'H':
            break;
        case'r':
            break;
        case'R':
            break;
        case's':
            break;
        case'S':
            break;
        default:
            cout<<"You have broken my game"<<endl;
    }

    //Executio Disicere
    return 0;
}
