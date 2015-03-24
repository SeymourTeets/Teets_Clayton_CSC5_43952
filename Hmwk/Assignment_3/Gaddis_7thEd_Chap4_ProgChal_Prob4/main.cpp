/* 
 * File:   main.cpp
 * Author: Clayton Teets
 * Created on March 23, 2015, 10:06 AM
 *      Purpose: Area of rectangles
 */
//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;
//User Libraries

//Global Constants

//Function Prototypes

//Executio Incipio
int main(int argc, char** argv) {
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
    //Executio Disicere
    return 0;
}