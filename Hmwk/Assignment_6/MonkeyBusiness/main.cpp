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
    float average;
    int high, hName, hFood;
    int low, lName, lFood;
    //Collect food eaten for the week
    for (int i=0; i<3; i++){
        cout<<mName[i]<<endl;
        for (int u=0; u<7; u++){
            cout<<setw(9)<<weekday[u]<<" : ";
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
    //Find most and least food eaten
    high = monkey[0][0];
    hName = 0;
    hFood = 0;
    low = monkey[0][0];
    lName = 0;
    lFood = 0;
    for (int i=0; i<3; i++){
        for (int u=0; u<7; u++){
            if (monkey[i][u]>high){
                high = monkey[i][u];
                hName = i;
                hFood = u;
            }
            if (monkey[i][u]<low){
                low = monkey[i][u];
                lName = i;
                lFood = u;
            }
        }
    }
    //Output average, high, and low
    cout<<mName[hName]<<" ate the most food ("<<monkey[hName][hFood]<<" lbs) on "<<weekday[hFood]<<"."<<endl;
    cout<<mName[lName]<<" ate the least food ("<<monkey[lName][lFood]<<" lbs) on "<<weekday[lFood]<<"."<<endl;
    cout<<fixed<<showpoint<<setprecision(2);
    cout<<"The monkey family ate an average of "<<average<<" lbs of food per day."<<endl;
    //Executio Disicere
    return 0;
}
