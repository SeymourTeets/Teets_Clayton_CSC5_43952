/* 
 * File       : main.cpp
 * Author     : Clayton Teets
 * Created on : May 19, 2015, 2:26 PM
 * Purpose    : Lottery
 */
//System Libraries
#include <iostream> //Input/Output Library
#include <iomanip>  //Output Formatting
#include <ctime>
#include <cstdlib>
using namespace std;
//User Libraries

//Global Constants

//Function Prototypes

//Executio Incipio

int main(int argc, char** argv) {
    //Declare Variables
    short SIZE = 5;
    short same;
    int lottery[SIZE] = {};
    int player[SIZE] = {};
    //Initialize the random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Set lottery numbers
    for (int i=0; i<SIZE; i++){
        lottery[i] = (rand()%10);
    }
    //Prompt for user input
    cout<<"Enter 5 single digit lottery numbers, pressing enter after each digit."<<endl;
    for (int i=0; i<SIZE; i++){
        cin>>player[i];
        while (player[i]<0 || 9<player[i]){
            cout<<"Invalid Input. Enter 0-9"<<endl;
            cin>>player[i];
        }
    }
    //Compare both arrays and count similar elements
    for (int i=0; i<SIZE; i++){
        if (lottery[i]==player[i]){
            same += 1;
        }
    }
    //Output Results
    cout<<endl;
    cout<<"*****************************"<<endl;
    cout<<"*Lottery";
    for (int i=0; i<SIZE; i++){
        cout<<"* "<<lottery[i]<<" ";
    }
    cout<<"*"<<endl;
    cout<<"*****************************"<<endl;
    cout<<"*Player ";
    for (int i=0; i<SIZE; i++){
        cout<<"* "<<player[i]<<" ";
    }
    cout<<"*"<<endl;
    cout<<"*****************************"<<endl;
    cout<<endl;
    cout<<"You have "<<same<<" matching element(s)."<<endl;
    //Executio Disicere
    return 0;
}
