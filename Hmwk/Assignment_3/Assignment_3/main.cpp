/* 
 * File:   main.cpp
 * Author: Clayton Teets
 * Created on March 23, 2015, 10:06 AM
 *      Purpose: Min/Max
 */
//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;
//User Libraries

//Global Constants
float PI = 3.14159f;
//Function Prototypes

//Executio Incipio
int main(int argc, char** argv) {
    cout<<"Type 0 to solve problem 1  (Minimum/Maximum)"<<endl;
    cout<<"Type 1 to solve problem 4  (Areas of Rectangles)"<<endl;
    cout<<"Type 2 to solve problem 9  (Software Sales)"<<endl;
    cout<<"Type 3 to solve problem 11 (Geometry Calculator)"<<endl;
    cout<<"Type 4 to solve problem 14 (BMI)"<<endl;
    cout<<"Type anything else to quit with no solutions."<<endl;
    cout<<endl;
    //Read the choice
    char choice;
    cout<<"I would like to solve problem: ";
    cin>>choice;
    cout<<endl;
    //Solve a problem that has been chosen.
    switch(choice){
            case '0':{
                //Declare Variables
                    float var1, var2;
                //Input Variables
                    cout<<"Enter the first number: ";
                    cin>>var1;
                    cout<<endl;
                    cout<<"Enter the second number: ";
                    cin>>var2;
                    cout<<endl;
                //Determine which number is larger and output results
                    if (var1 > var2)
                        cout<<var1<<" is the larger than "<<var2<<" ."<<endl;
                    else if (var1 < var2)
                        cout<<var2<<" is the larger than "<<var1<<" ."<<endl;
                    else
                        cout<<var1<<" and "<<var2<<" are equal."<<endl;
            break;
            }
            case '1':{
                //Declare Variables
                    float base1, height1, area1, base2, height2, area2;
                //Input Variables
                    cout<<"You will enter the dimensions of two rectangles, and I will output the "
                        <<"area of both and determine which area is larger."<<endl;
                    cout<<endl;
                    cout<<"Rectangle 1"<<endl;
                    cout<<"Enter the base length of the first rectangle: ";
                    cin>>base1;
                    cout<<"Enter the height length of the first rectangle: ";
                    cin>>height1;
                    cout<<endl;
                    cout<<"Rectangle 2"<<endl;
                    cout<<"Enter the base length of the second rectangle: ";
                    cin>>base2;
                    cout<<"Enter the height length of the second rectangle: ";
                    cin>>height2;
                    cout<<endl;
                //Calculate Area of the two rectangles and output the results
                    area1 = base1 * height1;//Area of the first rectangle
                    cout<<"The area of the first rectangle is "<<area1<<endl;
                    area2 = base2 * height2;//Area of the second rectangle
                    cout<<"The area of the second rectangle is "<<area2<<endl;
                //Determine which number is larger and output results
                    if (area1 > area2)
                        cout<<area1<<" is the larger than "<<area2<<" ."<<endl;
                    else if (area1 < area2)
                        cout<<area2<<" is the larger than "<<area1<<" ."<<endl;
                    else
                        cout<<"The area of both rectangles are equal"<<endl;
            break;
            }
            case '2':{
                //Declare Variables
                    char bCost;//Standard price of the software
                    bCost = 9.9e1;
                    unsigned int quant;//Quantity of purchases
                    float price;//Total price
                //Prompt for units purchased
                    cout<<"Given the quantity of units purchased, I will determine the final cost "
                        <<"of the purchase and notify you of the bulk discount received (if available)"<<endl;
                    cout<<"Enter quantity of purchased units: ";
                    cin>>quant;
                //Specify 2 decimal points for dollars and cents
                    cout<<fixed<<showpoint<<setprecision(2);
                //Determine final price
                    if ((quant >= 0)&&(quant <= 9)){
                        price = bCost * quant;
                        cout<<"You did not receive a discount and the total price is $"<<price<<endl;
                    }
                    else if ((quant >= 10)&&(quant <= 19)){
                        price = (bCost * .8f) * quant;
                        cout<<"You received a discount of 20% and the total price is $"<<price<<endl;
                    }
                    else if ((quant >= 20)&&(quant <= 49)){
                        price = (bCost * .7f) * quant;
                        cout<<"You received a discount of 30% and the total price is $"<<price<<endl;
                    }
                    else if ((quant >= 50)&&(quant <= 99)){
                        price = (bCost * .6f) * quant;
                        cout<<"You received a discount of 40% and the total price is $"<<price<<endl;
                    }
                    else if (quant >= 100){
                        price = (bCost * .5f) * quant;
                        cout<<"You received a discount of 50% and the total price is $"<<price<<endl;
                    }
            break;
            }  
            case '3':{
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
            break;
            }
            case '4':{
                //Declare Variables
                    float bmi, weight, height;
                //Prompt for Inputs
                    cout<<"I will calculate your Body Mass Index and inform you of the status of your weight."<<endl;
                    cout<<"Enter height in inches: ";
                    cin>>height;
                    cout<<"Enter weight in pounds: ";
                    cin>>weight;
                    cout<<endl;
                //Calculate BMI
                    bmi = weight * (7.03e2f / (height * height));
                //Tell user of their BMI and their weight status
                    if ((bmi >= 1.85e1f)&&(bmi <= 2.5e1f))
                        cout<<"Your BMI is "<<bmi<<" and you are optimal weight."<<endl;
                    else if (bmi < 1.85e1f)
                        cout<<"Your BMI is "<<bmi<<" and you are underweight."<<endl;
                    else
                        cout<<"Your BMI is "<<bmi<<" and you are overweight."<<endl;
            break;
            }
            default:{
                    cout<<"Exit?"<<endl;
            }
    };
    return 0;
}