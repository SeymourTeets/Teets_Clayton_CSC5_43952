/* 
 * File       : main.cpp
 * Author     : Clayton Teets
 * Created on : May 18, 2015, 5:59 PM
 * Purpose    : Monkey Business
 */
//System Libraries
#include <iostream> //Input/Output Library
#include <iomanip>  //Output Formatting
#include <string>
using namespace std;
//User Libraries

//Global Constants

//Function Prototypes

//Executio Incipio

int main(int argc, char** argv) {
    //Declare Variables
    string weekday[7] = {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
    string mName[3] = {"Jimbo","Kong","Ceaser"};
    int monkey[3][7] = {};
    int average;
    //Collect food eaten for the week
    for (int i=0; i<3; i++){
        cout<<mName[i]<<":"<<endl;
        for (int u=0; u<7; u++){
            cout<<weekday[u]<<":";
            cin>>monkey[i][u];
        }
        cout<<endl;
    }
    //Calculate Average
    for (int i=0; i<3; i++){
        for (int u=0; u<7; u++){
            average += monkey[i][u];
        }
    }
    average /= 7;
    //Find most food eaten
    
    //Executio Disicere
    return 0;
}
