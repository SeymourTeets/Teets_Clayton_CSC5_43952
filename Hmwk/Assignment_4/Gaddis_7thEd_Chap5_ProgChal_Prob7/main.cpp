/* 
 * File:   main.cpp
 * Author: Clayton Teets
 * Created on April 10, 2015, 2:51 PM
 *      Purpose: Pennies for Pay
 */
//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;
//User Libraries

//Global Constants

//Function Prototypes

//Executio Incipio
int main(int argc, char** argv) {
    //Declare Variables
    unsigned int days, number;
    float penny, salary;
    penny = 1e-2;
    number = 1;
    //Prompt for inputs
    cout<<"How many days did you work this week? ";
    cin>>days;
    //Set for dollars precision
    cout<<fixed<<showpoint<<setprecision(2);
    //Loop
    if (days>=0 && days<=31){
        while (number <= days){
            cout<<"On day "<<number<<" you made "<<penny<<" dollars"<<endl;
            salary += penny;
            penny *= 2;
            number++;
        }
        cout<<"Your total salary for this month is "<<salary<<endl;
    }
    else cout<<"The value you have entered is outside the parameters of a month. Please try again.";
    //Executio Disicere
    return 0;
}