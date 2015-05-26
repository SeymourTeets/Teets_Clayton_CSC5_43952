/* 
 * File       : main.cpp
 * Author     : Clayton Teets
 * Created on : May 26, 2015, 8:44 AM
 * Purpose    : Clothing Sizes
 */
//System Libraries
#include <iostream> //Input/Output Library
#include <iomanip>  //Output Formatting
using namespace std;
//User Libraries

//Global Constants

//Function Prototypes

//Executio Incipio

float hatSize(float weight, float height){
    return (weight/height)*2.9f;
}

float jacketSize(float height, float weight, int age){
    float size;
    size = (height * weight)/288;
    if (age>30){
            age -= 30;
            age /= 10;
            size += age/8.0f;
    }
    return size;
}

float waistSize(float weight, int age){
    weight /= 5.7f;
    if (age>28){
            age -= 28;
            age /= 2;
            weight += (age/10.0f);
    }
    return weight;
}

int main(int argc, char** argv) {
    //Declare Variables
    unsigned short height, weight, age;
    //Prompt for inputs
    cout<<"Enter the following to calculate clothing sizes."<<endl;
    cout<<"What is your age? ";
    cin>>age;
    while (age<0 || 115<age){
        cout<<"Enter a valid age. ";
        cin>>age;
    }
    cout<<"What is your weight? (lbs) ";
    cin>>weight;
    while (weight<5 || 800<weight){
        cout<<"Enter a valid weight (5-800 lbs). ";
        cin>>weight;
    }
    cout<<"What is your height? (inches) ";
    cin>>height;
    while (height<12 || 96<height){
        cout<<"Enter a valid height (12-96 inches). ";
        cin>>height;
    }
    //Calculate sizes
    cout<<endl;
    cout<<"Your clothing sizes : "<<endl;
    cout<<"Hat size    : "<<hatSize(weight, height)<<endl;
    cout<<"Jacket size : "<<jacketSize(height, weight, age)<<endl;
    cout<<"Waist size  : "<<waistSize(weight, age)<<endl;
    //Executio Disicere
    return 0;
}
