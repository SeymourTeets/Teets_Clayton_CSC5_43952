/* 
 * File:   main.cpp
 * Author: Clayton Teets
 * Created on April 10, 2015, 5:41 PM
 *      Purpose: The Greatest and Least of These
 */
//System Libraries
#include <iostream>
using namespace std;
//User Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
        int num;
    //Input
        cout << "How many numbers would you like to enter?" << endl;
        cin >> num;
        cout << "You would like to enter "<< num <<" numbers"<<endl;
        cout << "Please enter your numbers: "<<endl;
    //Output
        int highNum;
        cin >> highNum;// save 1st value as highest
        int inNum;// for reading the rest of the values
    //Looping
        for(int i = 2; i <= num; ++i )
        {
            cin >> inNum;// read input
            if( inNum > highNum ){// compare to highest yet
                highNum = inNum;}// replace highest
            if(inNum < lowNum){
                
            }
        }
    cout << "The highest number entered was: " << highNum;
    return 0;
}
