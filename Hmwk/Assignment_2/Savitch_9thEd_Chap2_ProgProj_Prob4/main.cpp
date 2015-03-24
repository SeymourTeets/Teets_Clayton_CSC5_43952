/* 
 * File:   main.cpp
 * Author: Clayton Teets
 * Date: 05 March 2015
 *      Purpose: Mad Lib
 * Created on March 5, 2015, 2:43 PM
 */
#include <iostream>
#include <string>
using namespace std;
//System Libraries

//Global Constants

//Function Prototypes

//Execution Incipit
int main(int argc, char** argv) {
    //Declare Variables
        string instnme, urname, food, adj, color, animal;
        unsigned int temp;
    //Prompt for Mad Lib Inputs
        cout<<"Lets play a Mad Lib!"<<endl;
        cout<<"To play, answer the following questions:"<<endl;
        cout<<"What is the last name of your instructor"<<endl;
            cin>>instnme;
        cout<<"What is your name?"<<endl;
            cin>>urname;
        cout<<"Tell me a food"<<endl;
            cin>>food;
        cout<<"Give me a number between 100 and 120"<<endl;
            cin>>temp;
        cout<<"Tell me an adjective"<<endl;
            cin>>adj;
        cout<<"What is your favorite color?"<<endl;
            cin>>color;
        cout<<"what is your favorite animal?"<<endl;
            cin>>animal;
    //Output Mad Lib
        cout<<"\nHere you go!"<<endl;
        cout<<"\nDear Instructor, "<<instnme<<endl;
        cout<<"\nI am sorry that I am unable to turn in my homework at this time."<<endl;
        cout<<"First, I ate a rotten "<<food<<", which made me turn "<<color<<" and"<<endl;
        cout<<"extremely ill. I came down with a fever of "<<temp<<". Next, my "<<endl;
        cout<<adj<<" pet "<<animal<<" must have smelled the remains of the "<<endl;
        cout<<food<<" on my homework, because he ate it. I am currently rewriting my "<<endl;
        cout<<"homework and hope you will accept it late."<<endl;
        cout<<"\n";
        cout<<"Sincerely,\n";
        cout<<urname;
    return 0;
}

