/* 
 * File       : main.cpp
 * Author     : Clayton Teets
 * Created on : May 25, 2015, 6:05 PM
 * Purpose    : Population
 */
//System Libraries
#include <iostream> //Input/Output Library
#include <iomanip>  //Output Formatting
#include <cmath>    //Power Function
using namespace std;
//User Libraries

//Global Constants

//Function Prototypes

//Executio Incipio

int main(int argc, char** argv) {
    //Declare Variables
    int current, days, future;
    float inc;
    //Prompt for input
    cout<<"This will predict the future population of organisms."<<endl<<endl;
    cout<<"What is the initial population? ";
    cin>>current;
    while (current<2){
        cout<<"Enter a population of two or more. ";
        cin>>current;
    }
    cout<<"What is the average daily population increase (xx.xx%)? ";
    cin>>inc;
    while (inc<0){
        cout<<"Enter a positive percentage. ";
        cin>>inc;
    }
    cout<<"How many days will they multiply? ";
    cin>>days;
    while (days<1){
        cout<<"Enter 1 or more days. ";
        cin>>days;
    }
    //Calculate future population
    future = current * pow(1 + inc/100, days);
    //Output data
    cout<<endl;
    cout<<"Current population                : "<<current<<endl;
    cout<<"Average daily population increase : "<<inc<<"%"<<endl;
    cout<<"Number of days to multiply        : "<<days<<endl;
    cout<<"Future population                 : "<<future<<endl;
    //Executio Disicere
    return 0;
}
