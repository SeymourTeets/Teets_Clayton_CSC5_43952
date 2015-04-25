/* 
 * File:   main.cpp
 * Author: Clayton
 *
 * Created on April 1, 2015, 8:48 AM
 */
//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
//User Libraries

//Global Constants

//Function Libraries

//Executio Incipio
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Declare  Variables
    unsigned int nGames, door, prize, doorOpn, othDoor;
    unsigned int win=0;
    unsigned int loss=0;
    char stay;
    //Prompt user for inputs
    cout<<"This is the Monty Hall Game, Let's make a deal"<<endl;
    cout<<"How many games would you like to play?: ";
    cin>>nGames;
    cout<<"Are you going to stay when given the opportunity? Type 'S' to stay"<<endl;
    cout<<"Type anything else to choose another door"<<endl;
    cin>>stay;
    //Loop for all games
    for (int game=1;game<=nGames;game++){
        //Randomly choose the door to open
        door=rand()%3+1;
        //Randomly choose the prize door
        prize=rand()%3+1;
        //Randomly choose a door to open
            do{
                doorOpn=rand()%3+1;
            }while((door==doorOpn)||(prize==doorOpn));//Can't be the same
            //What is the other door
            do{
                othDoor=rand()%3+1;
            }while(othDoor==doorOpn||othDoor==door);//Can't be the same
            //cout<<"D = "<<door<<" OthD = "<<othDoor<<" OpnD = "<<doorOpn<<" Prize = "<<prize<<endl;
            //Swap doors if given the opportunity
            if (stay!='S'||stay!='s'){
                door=othDoor;
            }
            //Now statistically count how many wins and losses
            if(door==prize)win++;
            else loss++;
    }
    //Output results
    cout<<"Out of "<<nGames<<" played!"<<endl;
    cout<<"I win by staying --> "<<win<<" times"<<endl;
    cout<<"vs losing "<<loss<<" times!"<<endl;
    //Executio Disicere
    return 0;
}

