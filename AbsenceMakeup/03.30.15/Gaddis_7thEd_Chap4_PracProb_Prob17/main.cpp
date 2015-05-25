/* 
 * File       : main.cpp
 * Author     : Clayton Teets
 * Created on : May 25, 2015, 1:21 PM
 * Purpose    : The Speed of Sounds in Gasses
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
    char choice;
    float meters, time;
    //Menu and Length Prompt
    cout<<"This will calculate the distance traveled in meters given the gas medium and time traveled in seconds."<<endl<<endl;
    cout<<"Press 'C' for Carbon dioxide (258.0  mps)"<<endl;
    cout<<"Press 'A' for Air            (331.5  mps)"<<endl;
    cout<<"Press 'E' for Helium         (972.0  mps)"<<endl;
    cout<<"Press 'Y' for Hydrogen       (1270.0 mps)"<<endl<<endl;
    cout<<"Medium = ";
    cin>>choice;
    while (choice != 'c' && choice != 'C' && choice != 'A' && choice != 'a' && choice != 'E' && choice != 'e' && choice != 'y' && choice != 'Y'){
        cout<<"Invalid Input. Try again. ";
        cin>>choice;
    }
    cout<<endl;
    cout<<"Time traveled (seconds) = ";
    cin>>time;
    while (time < 0 || 30 < time){
        cout<<"Enter time between 0-30 ";
        cin>>time;
    }
    cout<<endl;
    //Menu Switch
    switch(choice){
        case'c':
        case'C':
            meters = time * 258;
            break;
        case'a':
        case'A':
            meters = time * 331.5;
            break;
        case'e':
        case'E':
            meters = time * 972;
            break;
        case'y':
        case'Y':
            meters = time * 1270;
            break;
        default:
            break;
    }
    //Output Time
    cout<<"The sound wave will travel "<<meters<<" meters in "<<time<<" seconds."<<endl;
    //Executio Disicere
    return 0;
}
