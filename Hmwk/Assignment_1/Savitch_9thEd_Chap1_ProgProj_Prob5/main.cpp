/* 
 * File:   main.cpp
 * Author: Clayton Teets
 * Created on March 4, 2015, 9:35 AM
 *      Purpose: Large Block C
 */
//System Libraries
#include <iostream>//I/O System Libraries
using namespace std;//System Libraries using standard namespace

//User Libraries

//Global Constants

//Function Prototype

//Execution Incipit
int main(int argc, char** argv) {
    //Declare Variables
    char c;//Character to be used to display c
    //Prompt for letter C to be used
        cout<<"What letter would you like to use to create a large C?"<<endl;
        cin>>c;
    //Output Large C
        cout<<"\nHere is your C made of "<<c<<":"<<endl;
        cout<<"\n  "<<c<<c<<c<<endl;
        cout<<" "<<c<<"  "<<c<<endl;
        cout<<c<<endl;
        cout<<c<<endl;
        cout<<c<<endl;
        cout<<c<<endl;
        cout<<c<<endl;
        cout<<" "<<c<<"  "<<c<<endl;
        cout<<"  "<<c<<c<<c<<endl;
    return 0;
}

