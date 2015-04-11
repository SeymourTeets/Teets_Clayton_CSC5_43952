/* 
 * File:   main.cpp
 * Author: Clayton Teets
 * Created on April 10, 2015, 2:51 PM
 *      Purpose: Sum of Numbers
 */
//System Libraries
#include <iostream>
using namespace std;
//User Libraries

//Global Constants

//Function Prototypes

//Executio Incipio
int main(int argc, char** argv) {
    //Declare Variables
        unsigned int x, sum;
    //Prompt user for input
        cout<<"I will calculate the sum of the numbers from one to the number of you choose."<<endl;
        cout<<"Please enter a number: ";
        cin>>x;
    if (x>0){
    //Begin loop
        while (x>0){
            sum+=x;
            x--;
        }
    //Output the results
        cout<<sum<<endl;
    }
    else cout<<"You did not input a positive number";
    //Executio Disicere
    return 0;
}

