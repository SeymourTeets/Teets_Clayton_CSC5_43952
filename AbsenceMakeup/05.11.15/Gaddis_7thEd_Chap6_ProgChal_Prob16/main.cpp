/* 
 * File       : main.cpp
 * Author     : Clayton Teets
 * Created on : May 26, 2015, 2:49 PM
 * Purpose    : Transient Population
 */
//System Libraries
#include <iostream> //Input/Output Library
#include <iomanip>  //Output Formatting
using namespace std;
//User Libraries

//Global Constants

//Function Prototypes

//Executio Incipio
int popSize(unsigned short pop, float bRate, float dRate, unsigned short moved, unsigned short left) {
    bRate /= 100;//Convert Birth Rate to decimal form
    dRate /= 100;;//Convert Death Rate to decimal form
    return ((pop + moved - left) * ((1+bRate) * (1-dRate)));//Calculate New Population
}
int main(int argc, char** argv) {
   //Declare Variables
        unsigned short pop, years, moved, left;
        float bRate, dRate, newpop = 0;
    //Prompt for input
        cout<<"I will calculate the the population size over a given amount of years"<<endl;
        cout<<"Initial Population    : ";
        cin>>pop;
        cout<<"Birth Rate            : ";
        cin>>bRate;
        cout<<"Death Rate            : ";
        cin>>dRate;
        cout<<"Moved to the city     : ";
        cin>>moved;
        cout<<"Moved out of the city : ";
        cin>>left;
        cout<<"Year(s)               : ";
        cin>>years;
        cout<<endl;
    //Setup Loop and Output Population
        for (int i=1; i<=years; i++) {
            newpop += popSize(pop, bRate, dRate, moved, left);
            cout<<"The population after "<<i<<" year(s) is "<<newpop<<endl;}
        cout<<endl;
    //Executio Disicere
    return 0;
}
