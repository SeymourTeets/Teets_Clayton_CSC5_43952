/* 
 * File       : main.cpp
 * Author     : Clayton Teets
 * Created on : May 18, 2015, 9:51 AM
 * Purpose    : 
 */
//System Libraries
#include <iostream> //Input/Output Library
#include <string> //Stores Roman Numerals
using namespace std;
//User Libraries

//Global Constants

//Function Prototypes

//Executio Incipio

int main(int argc, char** argv) {
    //Declare Variable
    int SIZE = 21;
    string rNum[SIZE] = {"","I","II","III","IV","V","VI","VII","VIII","IX","X", 
                         "XI","XII","XIII","XIV","XV","XVI","XVII","XIII","XIX","XX"};
    int input;
    //Prompt for input
    cout<<"Enter numbers between 1-20 to convert to Roman numerals"<<endl;
    cout<<"Press 0 to quit"<<endl<<endl;
    while (input != 0){ //Do while input is not 0
        cout<<"Number = ";
        cin>>input;
        while (0>input || input>20){ //Input Validation
            cout<<"Invalid Input. Enter 1-20. ";
            cin>>input;
        }
        if (input == 0) {} //If input = 0, do nothing
        else { //If valid, output correct Roman numeral
            cout<<"Roman Numeral = "<<rNum[input]<<endl<<endl;
        }
    }
    //Executio Disicere
    return 0;
}
