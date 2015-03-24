/* 
 * File:   main.cpp
 * Author: Clayton Teets
 * Created on March 23, 2015, 3:12 PM
 *      Purpose: Geometry Calculator
 */
//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;
//User Libraries

//Global Constants
float PI = 3.14159;//Mathematical expression pi
//Function Prototypes

//Executio Incipio
int main(int argc, char** argv) {
    //Declare Variables
    char number;//Number for menu
    float var1, var2;//Inputs for each 3 calculations
    float aCircle, aRect, aTrian;//Area totals
    //Prompt Menu
    cout<<"Geometry Calculator"<<endl;
    cout<<"1. Calculate the Area of a Circle"<<endl;
    cout<<"2. Calculate the Area of a Rectangle"<<endl;
    cout<<"3. Calculate the Area of  a Triangle"<<endl;
    cout<<"4. Quit"<<endl;
    cout<<endl;
    cout<<"Enter (1-4) : ";
    cin>>number;
    //Prompt for inputs to declared calculation
    switch (number) {
        case '1' : cout<<"I will calculate the area of a circle"<<endl;
            //Collect circle dimensions
                cout<<"Enter the radius of the circle: ";
                cin>>var1;
            //Calculate the area of a circle
                aCircle = PI * var1 * var1;
            //Output circle area
                cout<<"The area of the circle is "<<aCircle<<endl;
                break;
        case '2' : cout<<"I will calculate the area of a rectangle"<<endl;
            //Collect rectangle dimensions
                cout<<"Enter the base length of the rectangle: ";
                cin>>var1;
                cout<<"Enter the side length of the rectangle: ";
                cin>>var2;
            //Calculate the area of the rectangle
                aRect = var1 * var2;
            //Output the area of the rectangle
                cout<<"The area of the rectangle is "<<aRect<<endl;
                break;
        case '3' : cout<<"I will calculate the area of a triangle"<<endl;
            //Collect the dimensions of the triangle
                cout<<"Enter the base length of the triangle: ";
                cin>>var1;
                cout<<"Enter the side length of the triangle: ";
                cin>>var2;
            //Calculate the area of the triangle
                aTrian = (.5f) * var1 * var2;
            //Output the area of the triangle
                cout<<"The area of the triangle is "<<aTrian<<endl;
                break;
        case '4' : cout<<"Good-Bye"<<endl;
                break;
        default : cout<<"Invalid Input";
    }
    return 0;
}

