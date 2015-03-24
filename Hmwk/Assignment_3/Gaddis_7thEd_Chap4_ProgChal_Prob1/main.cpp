/* 
 * File:   main.cpp
 * Author: Clayton Teets
 * Created on March 23, 2015, 10:06 AM
 *      Purpose: Min/Max
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
        float var1, var2;
    //Input Variables
        cout<<"Enter the first number: ";
        cin>>var1;
        cout<<endl;
        cout<<"Enter the second number: ";
        cin>>var2;
        cout<<endl;
    //Determine which number is larger and output results
        if (var1 > var2)
            cout<<var1<<" is the larger than "<<var2<<" ."<<endl;
        else if (var1 < var2)
            cout<<var2<<" is the larger than "<<var1<<" ."<<endl;
        else
            cout<<var1<<" and "<<var2<<" are equal."<<endl;
    //Executio Disicere
    return 0;
}

