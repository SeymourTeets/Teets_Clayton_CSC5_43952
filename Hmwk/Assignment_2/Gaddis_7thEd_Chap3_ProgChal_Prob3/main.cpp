/* 
 * File:   main.cpp
 * Author: Clayton Teets
 * Created on March 12, 2015, 9:34 PM
 *      Purpose: Monthly Costs
 */
//System Libraries
#include <iostream>//I//O System Libraries
using namespace std;
//User Libraries

//Function Prototypes

//Global Constants

//Executio Incipio
int main(int argc, char** argv) {
    //Declare Variables
        float rent;
        float utilities; 
        float phone;
        float cable;
    //Input Answers
        cout<<"Enter your rent of mortgage payment for this month:"<<endl;
        cin>>rent;
        cout<<"Enter your utilities amount for this month:"<<endl;
        cin>>utilities;
        cout<<"Enter your phone bill amount for this month:"<<endl;
        cin>>phone;
        cout<<"Enter your cable amount for this month:"<<endl;
        cin>>cable;
    //Output Amounts
        cout<<"Your total monthly cost is "<<rent+utilities+phone+cable<<endl;
        cout<<"Your total annual cost is "<<(rent+utilities+phone+cable)*12<<endl;
    //Executio Disicere
    return 0;
}

