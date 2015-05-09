/* 
 * File       : main.cpp
 * Author     : Clayton Teets
 * Created on : April 29, 2015, 9:40 AM
 * Purpose    : 
 */
//System Libraries
#include <iostream> //Input/Output Library
#include <iomanip>  //Output Formatting
#include <ctime>
#include <cstdlib>
using namespace std;
//User Libraries

//Global Constants

//Function Prototypes
unsigned char roll(unsigned char, unsigned char);

//Executio Incipio
int main(int argc, char** argv) {
    //Declare Variables
    const int SIZE = 15;//Size larger than needed
    int freq[SIZE] = {};//Setting whole array to zero
    int nThrows = 3.6e4f;//Number of throws
    unsigned int sum = 0;//Add up the number of throws
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Loop, throw the dice, take the stats
    for (int throws=1; throws<=nThrows; throws++){
        freq[roll(2,6)]++;
    }
    //Print the results
    for(int value=0; value<SIZE; value++){
        sum += freq[value];
        cout<<value<<" was thrown "<<freq[value]<<" times!"<<endl;
    }
    cout<<"The dice were thrown "<<nThrows<<" = "<<sum<<endl;
    //Executio Disicere
    return 0;
}

unsigned char roll(unsigned char nDie, unsigned char sides){
    unsigned char sum=0;
    for(int die=1; die<=nDie; die++){
        sum += (rand()%sides+1);
    }
    return sum;
}