/* 
 * File       : main.cpp
 * Author     : Clayton Teets
 * Created on : May 25, 2015, 4:56 PM
 * Purpose    : Triangle Display
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
    int f = 4;
    for (int i = 0; i<f; i++){
        for (int u = 0; u<i*2+1; u++){
            cout<<"*";
        }
        cout<<endl;
    }
    for (int i = 0; i<f-1; i++){
      for (int u = (2*f-2*i-3); u>0; u--){cout<<"*";} 
      cout<<endl;
    }
    
    //Executio Disicere
    return 0;
}
