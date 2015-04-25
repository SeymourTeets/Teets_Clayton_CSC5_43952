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
float calcRet(float, float);              //<- Problem 1
float celsius(int);                       //<- Problem 2
float fallDis(int);                       //<- Problem 3
float kEnergy(float, float);              //<- Problem 4
float getSale(float);                     //<- Problem 5
void highSal(float, float, float, float); //<- Problem 5
float pValue(int, int, float);            //<- Problem 10
int popSize(unsigned short, float, float);//<- Problem 15
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
            //case '5':problem5();break;
            //case '6':problem6();break;
            //case '7':problem7();break;
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
float calcRet(float wCost, float markup){
    float rPrice;//Retail Price
    markup /= 100;//Convert % to decimal
    rPrice = (wCost + (wCost * markup));//Calculate Retail Price
    return rPrice;}

//*******************         Problem 1           ********************/
void problem1(){
    //Declare Variables
        int f;//Fahrenheit
    //Loop Output x20
        cout<<"Fahrenheit = Celsius"<<endl;
        for (f=0; f<=20; f++) {cout<<setw(10)<<right<<f<<" = ";
                               cout<<celsius(f)<<endl;}
        cout<<endl;                                             }
float celsius(int f) {
    float celsius;
    celsius = (static_cast<float>(5)*(f-32))/9;
    return celsius;}

//*******************         Problem 2           ********************/
void problem2(){
    //Declare Variables
        int t;//Time in Seconds
    //Loop Output x10
        for (t=1; t<=10; t++) {cout<<"At "<<t<<" seconds, the object has fallen ";
                               cout<<fallDis(t)<<" meters"<<endl;}   
                               cout<<endl;  }
float fallDis(int t) {
    float distnce;
    distnce = (.5f * GRAVITY * (pow(t,2)));//Calculate Distance Fallen
    return distnce;     }

//*******************         Problem 3           ********************/
void problem3(){
    //Declare Variables
        float mass, velocty;
    //Prompt for Inputs
        cout<<"Given mass and velocity, I will calculate kinetic energy."<<endl;
        cout<<"Mass     (kg) : ";
        cin>>mass;
        cout<<"Velocity (m/s): ";
        cin>>velocty;
    //Call kEnergy
        cout<<"The kinetic energy of "<<mass<<" kg travelling at "<<velocty<<" m/s ";
        cout<<"is "<<kEnergy(mass, velocty)<<" joules."<<endl;
}
float kEnergy(float mass, float velocty) {
    float ke;//Kinetic Energy
    ke = (.5f * mass * (pow(velocty,2)));//Calculate Kinetic Energy
    return ke;      }

//*******************         Problem 4           ********************/
void problem4(){
    //Declare Variables
        float ne, nw, se, sw, x;
    //Prompt User for Inputs
        cout<<fixed<<setprecision(2)<<showpoint;
        cout<<"Enter the quarterly sales for each branch."<<endl;
        cout<<"Northeast : ";
        ne = getSale(x);
        cout<<"Northwest : ";
        nw = getSale(x);
        cout<<"Southeast : ";
        se = getSale(x);
        cout<<"Southwest : ";
        sw = getSale(x);
        cout<<endl;
    //Output Results
        highSal(ne, nw, se, sw);        }
float getSale(float x) {
    cout<<"Enter your quarterly sales $";
    cin>>x;//Validation Placeholder
    while (x<0) {cout<<"Enter a positive value or you're fired! $";
                 cin>>x;                                            }
    return x;   }
void highSal(float ne, float nw, float se, float sw) {
    if      (ne<nw && nw<se && se<sw) {cout<<"Southwest has the highest sales at $"<<sw<<endl;}
    else if (nw<se && se<ne && ne<sw) {cout<<"Southwest has the highest sales at $"<<sw<<endl;}
    else if (se<ne && ne<nw && nw<sw) {cout<<"Southwest has the highest sales at $"<<sw<<endl;}
    else if (sw<ne && ne<nw && nw<se) {cout<<"Southeast has the highest sales at $"<<se<<endl;}
    else if (nw<sw && sw<ne && ne<se) {cout<<"Southeast has the highest sales at $"<<se<<endl;}
    else if (ne<nw && nw<sw && sw<se) {cout<<"Southeast has the highest sales at $"<<se<<endl;} 
    else if (se<sw && sw<ne && ne<nw) {cout<<"Northwest has the highest sales at $"<<nw<<endl;}
    else if (sw<ne && ne<se && se<nw) {cout<<"Northwest has the highest sales at $"<<nw<<endl;}
    else if (ne<se && se<sw && sw<nw) {cout<<"Northwest has the highest sales at $"<<nw<<endl;}    
    else if (nw<se && se<sw && sw<ne) {cout<<"Northeast has the highest sales at $"<<ne<<endl;}
    else if (se<sw && sw<nw && nw<ne) {cout<<"Northeast has the highest sales at $"<<ne<<endl;}
    else if (nw<nw && nw<se && se<ne) {cout<<"Northeast has the highest sales at $"<<ne<<endl;}     }

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
    //Declare Variables
        int nYears, fBalnce;
        float interest;
    //Prompt User for Inputs
        cout<<"Enter the following to calculate what you need to save."<<endl;
        cout<<"Future Balance : ";
        cin>>fBalnce;
        cout<<"Years to Save  : ";
        cin>>nYears;
        cout<<"Interest Rate  : ";
        cin>>interest;
    //Call pValue Function and Output Present Value
        cout<<"To acquire $"<<fBalnce<<" in "<<nYears<<" years with and interest ";
        cout<<"rate of %"<<interest<<", you must credit your savings account $";
        cout<<fixed<<setprecision(2)<<showpoint;
        cout<<pValue(fBalnce, nYears, interest)<<endl;
        cout<<endl;}
float pValue(int fBalnce, int nYears, float interest) {
    float add;//$'s to save
    interest /= 100;//Convert % to decimal form
    add = fBalnce / (pow((1+interest),nYears));//Calculate $'s to save
    return add;
}

//*******************         Problem 9           ********************/
void problem9(){
   //Declare Variables
        unsigned short pop, years;
        float bRate, dRate;
    //Prompt for input
        cout<<"I will calculate the the population size over a given amount of years"<<endl;
        cout<<"Initial Population : ";
        cin>>pop;
        cout<<"Birth Rate         : ";
        cin>>bRate;
        cout<<"Death Rate         : ";
        cin>>dRate;
        cout<<"Year(s)            : ";
        cin>>years;
        cout<<endl;
    //Setup Loop and Output Population
        for (int i=1; i<=years; i++) {
            pop += popSize(pop, bRate, dRate);
            cout<<"The population after "<<i<<" year(s) is "<<pop<<endl;}
        cout<<endl;     }
int popSize(unsigned short pop, float bRate, float dRate) {
    float newpop;//New Population
    bRate /= 100;//Convert Birth Rate to decimal form
    dRate /= 100;;//Convert Death Rate to decimal form
    newpop = (pop * ((1+bRate) * (1-dRate)));//Calculate New Population
    newpop += .5f;//Correct Decimal Approximation
    return newpop;
}
