/* 
 * File       : main.cpp
 * Author     : Clayton Teets
 * Created on : May 18, 2015, 10:33 AM
 * Purpose    : 
 */
//System Libraries
#include <iostream> //Input/Output Library
#include <string>  //Holds salsa names
#include <iomanip>
using namespace std;
//User Libraries

//Global Constants

//Function Prototypes

//Executio Incipio

int main(int argc, char** argv) {
    //Declare Variables
    int SIZE = 5;
    string sName[SIZE] = {"mild","medium","sweet","hot","zesty"};
    int sSold[SIZE] = {};
    //Prompt for input
    cout<<"Enter sales for all 5 salsa types"<<endl;
    for (int i=0; i<SIZE; i++){
        cout<<setw(7)<<sName[i]<<" = ";
        cin>>sSold[i];
    }
    cout<<endl;
    //Output Sales
    for (int i=0; i<SIZE; i++){
        cout<<setw(7)<<sName[i]<<" = "<<sSold[i]<<endl;
    }
    //Executio Disicere
    return 0;
}
