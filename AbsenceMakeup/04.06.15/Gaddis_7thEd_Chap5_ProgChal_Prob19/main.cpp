/* 
 * File       : main.cpp
 * Author     : Clayton Teets
 * Created on : May 25, 2015, 4:42 PM
 * Purpose    : Diamond Display
 */
//System Libraries
#include <iostream> //Input/Output Library
#include <iomanip>  //Output Formatting
using namespace std;
//User Libraries

//Global Constants

//Function Prototypes

//Executio Incipio

int main(int argc, char** argv) {
    int f = 5;
    for (int i = 0; i<f; i++){
        for (int o = 0; o<(f-i-1); o++){cout<<" ";}
        for (int u = 0; u<(2*i+1); u++){cout<<"*";}
        cout<<endl;
    }
    for (int i = 0; i<f-1; i++){
        for (int o = 0; o<=i; o++){cout<<" ";}
        for (int u = (2*f-2*i-3); u>0; u--){cout<<"*";}
        cout<<endl;
    }
    //Executio Disicere
    return 0;
}
