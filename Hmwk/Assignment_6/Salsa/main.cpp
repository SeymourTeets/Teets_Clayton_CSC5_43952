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
    int high, h;
    int low, l;
    //Prompt for input
    cout<<"Enter sales for all 5 salsa types."<<endl;
    for (int i=0; i<SIZE; i++){
        cout<<setw(7)<<sName[i]<<" = ";
        cin>>sSold[i];
    }
    cout<<endl;
    //Output Sales
    cout<<"Salsa Sales:"<<endl;
    for (int i=0; i<SIZE; i++){
        cout<<setw(7)<<sName[i]<<" = "<<sSold[i]<<endl;
    }
    cout<<endl;
    //Find highest and lowest sales
    high = sSold[0];
    low = sSold[0];
    for (int i=0; i<SIZE; i++){
        if (sSold[i] > high) {
            high = sSold[i];
            h=i;
        }
        if (sSold[i] < low) {
            low = sSold[i];
            l=i;
        }
    }
    //Output highest and lowest sales
    cout<<"The highest sales are "<<sName[h]<<" salsa, at "<<sSold[h]<<" sales."<<endl;
    cout<<"The lowest sales are "<<sName[l]<<" salsa, at "<<sSold[l]<<" sales."<<endl;
    //Executio Disicere
    return 0;
}
