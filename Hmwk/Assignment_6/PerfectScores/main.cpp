/* 
 * File       : main.cpp
 * Author     : Clayton Teets
 * Created on : May 18, 2015, 9:01 AM
 * Purpose    : Perfect Scores
 */
//System Libraries
#include <iostream> //Input/Output Library
#include <iomanip>  //Output Formatting
using namespace std;
//User Libraries

//Global Constants

//Function Prototypes
int countPerfect(int[], int);
//Executio Incipio

int main(int argc, char** argv) {
    //Declare Variable
    int SIZE = 10;
    int scores[SIZE]={};
    int sCount = 0;
    //Prompt user for test scores
    cout<<"Enter 10 test scores"<<endl;
    for (int i=0; i<SIZE; i++){
        cout<<"Test "<<i+1<<" = ";
        cin>>scores[i];
        if (scores[i]<0 || 100<scores[i]) {
            cout<<"Invalid Input, Enter 0-100. ";
            cin>>scores[i];
        }
    }
    cout<<endl;
    //Call perfect score counter
    sCount = countPerfect(scores, SIZE);
    cout<<"You received "<<sCount<<" perfect scores"<<endl;
    //Executio Disicere
    return 0;
}

int countPerfect(int scores[], int SIZE){
    //Declare Variables
    int sCount = 0;
    //Count perfect scores
    for (int i=0; i<SIZE; i++){
        if (scores[i]==100) {sCount += 1;}
    }
    return sCount;
}