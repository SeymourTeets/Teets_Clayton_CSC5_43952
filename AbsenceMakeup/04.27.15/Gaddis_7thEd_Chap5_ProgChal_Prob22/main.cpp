/* 
 * File       : main.cpp
 * Author     : Clayton Teets
 * Created on : May 25, 2015, 6:32 PM
 * Purpose    : Sales Bar Chart
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
    unsigned short one, two, three;
    //Prompt for sale inputs
    cout<<"Enter sales rounded to the nearest hundreds of dollars."<<endl<<endl;
    cout<<"Enter today's sales for store 1: ";
    cin>>one;
    while (one<0){
        cout<<"Enter sales, not loss. ";
        cin>>one;
    }
    one /= 100;
    cout<<"Enter today's sales for store 2: ";
    cin>>two;
    while (two<0){
        cout<<"Enter sales, not loss. ";
        cin>>two;
    }
    two /= 100;
    cout<<"Enter today's sales for store 3: ";
    cin>>three;
    while (three<0){
        cout<<"Enter sales, not loss. ";
        cin>>three;
    }
    three /= 100;
    cout<<endl;
    //Output sales bar chart
    cout<<"Daily Sales"<<endl;
    cout<<"(each * = $100)"<<endl;
    cout<<"Store 1: ";
    for(int i = one; i>0; i--){
        cout<<"*";
    }
    cout<<endl;
    cout<<"Store 2: ";
    for(int i = two; i>0; i--){
        cout<<"*";
    }
    cout<<endl;
    cout<<"Store 3: ";
    for(int i = three; i>0; i--){
        cout<<"*";
    }
    cout<<endl;
    //Executio Disicere
    return 0;
}
