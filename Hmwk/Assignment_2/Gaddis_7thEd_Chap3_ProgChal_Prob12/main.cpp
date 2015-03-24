/* 
 * File:   main.cpp
 * Author: Clayton Teets
 * Created on March 18, 2015, 10:39 PM
 *      Purpose: Converting Money
 */
//System Libraries
#include <iostream>
using namespace std;
//User Libraries

//Global Constants

//Function Prototypes

//Executio Incipo!
int main(int argc, char** argv) {
    //Declare Variables
        float CONVDTY=.952;
        float CONVDTE=.7175;
        float nUSD;//Number of USD
        float nYENpd;//Number of Yen per dollar
        float nEURpd;//Number of Euro's per dollar
    //Prompt User for inputs
        cout<<"Enter the amount of USD here:"<<endl;
        cin>>nUSD;
    //Calculations begin here!
        nYENpd=nUSD*CONVDTY;
        nEURpd=nUSD*CONVDTE;
    //Output
        cout<<"Here are the equivalent values in YEN and EUR"<<endl;
        cout<<nYENpd<<" YEN and "<<nEURpd<<" EUR"<<endl;
    //Executio Incipo!
    return 0;
