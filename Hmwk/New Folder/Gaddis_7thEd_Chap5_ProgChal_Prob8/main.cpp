/* 
 * File:   main.cpp
 * Author: Clayton Teets
 * Created on April 10, 2015, 4:46 PM
 *      Purpose: Calories Burned
 */
//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;
//User Libraries

//Global Constants

//Function Prototypes

//Executio Incipio
int main(int argc, char** argv) {
    //Declare Variables
        int calories = 3.9; 
        int calburn;
    //Output
        for (int minutes = 10; minutes < 30; minutes += 5){
            calburn= calories * minutes;
           cout<<"Calories burned in "<<minutes<<" minutes: "<<calburn<<endl; 
    }
    //Executio Disicere
    return 0;
}


