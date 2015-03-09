/* 
 * File:   main.cpp
 * Author: Clayton Teets
 * Created on March 2, 2015, 7:50 PM
 *      Purpose: Change Calculator
 */

#include <iostream>//I/O System Libraries
using namespace std;//System Libraries using standard namespace

//User Libraries

//Global Constants
    const char qrtr=2.5e1f;
    const char dime=1.0e1f;
    const char nckl=0.5e1f;
    const char hundrd=1.0e2f;
//Function Prototype

//Execution begins here

int main(int argc, char** argv) {
    //Declare Variables
        unsigned int x,y,z,qvalue,dvalue,nvalue;
        float total,dtotal;
        //Prompt for quarter amount
            cout<<"How many quarter(s) do you have?"<<endl;
            cout<<"Input value as xxx."<<endl;
            cin>>x;
        //Prompt for dime amount
            cout<<"How many dime(s) do you have?"<<endl;
            cout<<"Input value as xxx."<<endl;
            cin>>y;
        //Prompt for nickel amount
            cout<<"How many nickel(s) do you have?"<<endl;
            cout<<"Input value as xxx."<<endl;
            cin>>z;
    //Calculate Total
            qvalue=qrtr*x;//Change in quarters
            dvalue=dime*y;//Change in dimes
            nvalue=nckl*z;//Change in nickels
            total=qvalue+dvalue+nvalue;//Total change
            dtotal=total/hundrd;//Total in dollars
            
    //Output Results
            cout<<"You have "<<total<<" cents"<<endl; 
            cout<<"You have "<<dtotal<<" dollars"<<endl;
        return 0;
}

