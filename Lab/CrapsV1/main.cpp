/* 
 * File       : main.cpp
 * Author     : Clayton Teets
 * Created on : April 29, 2015, 11:40 AM
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
unsigned char roll(unsigned char,unsigned char);
//Executio Incipio

int main(int argc, char** argv) {
    //Initialize the random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Declare variables
    int win=0,lose=0,nThrows=0,nGames=200;
    int thwGame=0,maxNThw=0;
    //Loop on the games and take stats
    for(int game=1;game<=nGames;game++){
        int sum=roll(2,6);
        nThrows++;
        thwGame=1;
        if(sum==2||sum==3||sum==12)lose++;
        else if(sum==7||sum==11)win++;
        else{
            //Keep throwing
            bool rollAgn;
            do{
                rollAgn=true;
                int sum2=roll(2,6);
                nThrows++;
                thwGame++;
                if(sum2==sum){
                    win++;
                    rollAgn=false;
                }else if(sum2==7){
                    lose++;
                    rollAgn=false;
                }
            }while(rollAgn);
            if(thwGame>maxNThw)maxNThw=thwGame;
        }
    }
    //Output wins and losses
    cout<<"Total number of Games = "<<nGames<<endl;
    cout<<"Total number of wins  = "<<win<<endl;
    cout<<"Total number losses   = "<<lose<<endl;
    cout<<"Total win + lose      = "<<win+lose<<endl;
    cout<<"Percentage win        = "
            <<100.0f*win/nGames<<"%"<<endl;
    cout<<"Percentage loss       = "
            <<100.0f*lose/nGames<<"%"<<endl;
    cout<<"Number of throws      = "<<nThrows<<endl;
    cout<<"Average throw/game    = "<<1.0f*nThrows/nGames<<endl;
    cout<<"Max throws in any game= "<<maxNThw<<endl;
    //Exit stage right
    return 0;
}

unsigned char roll(unsigned char nDie,unsigned char sides){
    unsigned char sum=0;
    for(int die=1;die<=nDie;die++){
        sum+=(rand()%sides+1);
    }
    return sum;
}
