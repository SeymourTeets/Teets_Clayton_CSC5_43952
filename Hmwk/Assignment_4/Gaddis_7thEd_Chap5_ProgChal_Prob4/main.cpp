/* 
 * File:   main.cpp
 * Author: Clayton Teets
 * Purpose: Celsius to Fahrenheit
 * Created on April 10, 2015 at 3:29 PM
 *      Purpose: Celsius to Fahrenheit
 */
//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;
//User Libraries

//Global Constants

//Function Prototypes

//Execution Incipio
int main(int argc, char** argv) {
    //Declare Variables
        float fhrnht;//Temperature in Fahrenheit
        float celsius;//Temperature in Celsius
        celsius = 0;
    //Calculation begins here with a loop!
        while (celsius <= 20){
        fhrnht=static_cast<float>((celsius*9)/5)+32;
        cout<<"When the temperature in celsius is "<<celsius<<", the temperature in fahrenheit is "<<fhrnht<<" degrees"<<endl;
        celsius++;
        }
    //Executio Incipio
    return 0;
}