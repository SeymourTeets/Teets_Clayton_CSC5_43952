/* 
 * File       : main.cpp
 * Author     : Clayton Teets
 * Created on : May 25, 2015, 12:33 PM
 * Purpose    : The Speed of Sound
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
    float feet, time;
    //Menu and Length Prompt
    cout<<"This will calculate the time it takes in seconds to travel through a specified medium given a distance in feet."<<endl<<endl;
    cout<<"Press 'A' for Air    (1,100  fps)"<<endl;
    cout<<"Press 'W' for Water  (4,900  fps)"<<endl;
    cout<<"Press 'S' for Steel  (16,400 fps)"<<endl<<endl;
    cout<<"Medium = ";
    cin>>choice;
    while (choice != 'a' && choice != 'A' && choice != 'w' && choice != 'W' && choice != 's' && choice != 'S'){
        cout<<"Invalid Input. Try again. ";
        cin>>choice;
    }
    cout<<endl;
    cout<<"Distance (feet) = ";
    cin>>feet;
    while (feet<0){
        cout<<"Enter a positive distance. ";
        cin>>feet;
    }
    cout<<endl;
    //Menu Switch
    switch(choice){
        case'a':
        case'A':
            time = feet/1100;
            break;
        case'w':
        case'W':
            time = feet/4900;
            break;
        case's':
        case'S':
            time = feet/16400;
            break;
        default:
            break;
    }
    //Output Time
    cout<<"The sound wave will travel "<<feet<<" feet in "<<fixed<<setprecision(4)<<showpoint<<time<<" seconds."<<endl;
    //Executio Disicere
    return 0;
}
