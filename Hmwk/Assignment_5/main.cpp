/* 
 * File       : main.cpp
 * Author     : Clayton Teets
 * Created on : April 23, 2015, 8:54 PM
 * Purpose    : Assignment 5
 */
//System Libraries
#include <iostream> //Input/Output Library
#include <iomanip>  //Output Formatting
#include <cmath>    //C Math
using namespace std;
//User Libraries

//Global Constants
float GRAVITY = 9.8f;
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
float calcRet(float, float);//<- Problem 1
float celsius(int);//<- Problem 2
float fallDis(int);//<- Problem 3
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
            //case '3':problem3();break;
            //case '4':problem4();break;
            //case '5':problem5();break;
            //case '6':problem6();break;
            //case '7':problem7();break;
            //case '8':problem8();break;
            //case '9':problem9();break;
            default :cout<<"Exit?"<<endl;
        };
    }while(choice>='0'&&choice<='9');
    //Exit Stage right
    return 0;
}

//*******************         Problem 0           ********************/
void problem0(){
    //Declare Variables
        float wCost,//Wholesale Cost
              markup,//Markup %
              rPrice;//Retail Price
    //Prompt for Inputs
        cout<<"Enter the wholesale cost and the mark up percentage (don't include '%')"<<endl;
        cout<<"Wholesale cost : ";
        cin>>wCost;
        cout<<"Markup : ";
        cin>>markup;
    //$ Formatting
        cout<<fixed<<setprecision(2)<<showpoint;
    //Output Retail Price
        cout<<"If an item's wholesale cost is "<<wCost<<" and its markup percentage"
            <<" is "<<markup<<"%, then the items retail price is $"<<calcRet(wCost, markup)<<endl;      }

//*******************         Problem 1           ********************/
void problem1(){
    //Declare Variables
        int f;//Fahrenheit
    //Loop Output x20
        cout<<"Fahrenheit = Celsius"<<endl;
        for (f=0; f<=20; f++) {cout<<setw(10)<<right<<f<<" = ";
                               cout<<celsius(f)<<endl;}         }

//*******************         Problem 2           ********************/
void problem2(){
    //Declare Variables
        int t;//Time in Seconds
    //Loop Output x10
        for (t=1; t<=10; t++) {cout<<"At "<<t<<" seconds, the object has fallen ";
                               cout<<fallDis(t)<<" meters"<<endl;}         }

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

float calcRet(float wCost, float markup){
    float rPrice;//Retail Price
    markup /= 100;//Convert % to decimal
    rPrice = (wCost + (wCost * markup));//Calculate Retail Price
    return rPrice;}

float celsius(int f) {
    float celsius;
    celsius = (static_cast<float>(5)*(f-32))/9;
    return celsius;}

float fallDis(int t) {
    //Declare Variables
    float distnce;
    //Calculate Distance Fallen
    distnce = (.5f * GRAVITY * (pow(t,2)));
    return distnce;
}