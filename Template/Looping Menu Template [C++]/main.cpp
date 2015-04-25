/* 
 * File   : main.cpp
 * Author : Clayton Teets
 * Purpose: 
 */
//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;
//User Libraries

//Global Constants

//Function Prototypes
void problem0();
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
void problem7();
void problem8();
void problem9();
//Execution Begins Here
int main(int argc, char** argv) {
    //Declare menu variable choice
    char choice;
    //Repeat the menu
    do{
        //General Menu Format
        //Display the selection
        cout<<"Type 0 to solve problem "<<endl;
        cout<<"Type 1 to solve problem "<<endl;
        cout<<"Type 2 to solve problem "<<endl;
        cout<<"Type 3 to solve problem "<<endl;
        cout<<"Type 4 to solve problem "<<endl;
        cout<<"Type 5 to solve problem "<<endl;
        cout<<"Type 6 to solve problem "<<endl;
        cout<<"Type 7 to solve problem "<<endl;
        cout<<"Type 8 to solve problem "<<endl;
        cout<<"Type 9 to solve problem "<<endl;
        cout<<"Type anything else to quit with no solutions."<<endl;
        //Read the choice
        cin>>choice;
        //Solve a problem that has been chosen.
        switch(choice){
            case '0':problem0();break;
            case '1':problem1();break;
            case '2':problem2();break;
            case '3':problem3();break;
            case '4':problem4();break;
            case '5':problem5();break;
            case '6':problem6();break;
            case '7':problem7();break;
            case '8':problem8();break;
            case '9':problem9();break;
            default :cout<<"Exit?"<<endl;
        };
    }while(choice>='0'&&choice<='9');
    //Exit Stage right
    return 0;
}

//*******************         Problem 0           ********************/
void problem0(){
    
}

//*******************         Problem 1           ********************/
void problem1(){

}

//*******************         Problem 2           ********************/
void problem2(){

}

//*******************         Problem 3           ********************/
void problem3(){

}

//*******************         Problem 4           ********************/
void problem4(){

}

//*******************         Problem 5           ********************/
void problem5(){
    
}

//*******************         Problem 6           ********************/
void problem6(){
    
}

//*******************         Problem 7           ********************/
void problem7(){
    
}

//*******************         Problem 8           ********************/
void problem8(){
    
}

//*******************         Problem 9           ********************/
void problem9(){
    
}
