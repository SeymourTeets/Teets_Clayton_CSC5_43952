/* 
 * File       : main.cpp
 * Author     : Clayton Teets
 * Created on : May 25, 2015, 5:24 PM
 * Purpose    : Rectangle Display
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
    //Declare Variables
    unsigned short a, b;
    //Prompt for inputs
    cout<<"Enter two numbers between 2 and 10."<<endl;
    cout<<"First input:  ";
    cin>>a;
    while (a<2 || 10<a){
        cout<<"Enter a value between 2 and 10. ";
        cin>>a;
    }
    cout<<"Second input: ";
    cin>>b;
    while (b<2 || 10<b){
        cout<<"Enter a value between 2 and 10. ";
        cin>>b;
    }
    //Output rectangle
    if (a<b) {
    for (int i = 0; i<a; i++){
        for (int u = 0; u<b; u++){
            cout<<"X";
        }
        cout<<endl;
    }
    }
    else if (b<a) {
    for (int i = 0; i<b; i++){
        for (int u = 0; u<a; u++){
            cout<<"X";
        }
        cout<<endl;
    }
    }
    //Executio Disicere
    return 0;
}
