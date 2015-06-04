/* 
 * File       : main.cpp
 * Author     : Clayton Teets
 * Created on : June 3, 2015, 8:36 AM
 * Purpose    : 
 */
//System Libraries
#include <iostream> //Input/Output Library
#include <iomanip>  //Output Formatting
using namespace std;
//User Libraries
#include "Table.h"

//Global Constants

//Function Prototypes
Table *filAray(int,int);
void prntAry(const Table *);
void destroy(Table *);

//Execution Begins Here
int main(int argc, char** argv) {
    //Create the array
    int rows=13,cols=13;
    Table *array=filAray(rows,cols);
    //Print the array
    prntAry(array);
    //Deallocate the array
    destroy(array);
    //Exit stage right
    return 0;
}

void destroy(Table *a){
    //Loop and destroy the columns
    for(int i=0;i<a->rows;i++){
        delete [] a->data[i];
    }
    //Destroy the rows
    delete []a->data;
    delete []a;
}

void prntAry(const Table *a){
    //Print the headings
    cout<<"THIS IS YOUR MULTIPLICATION TABLE!!!"<<endl;
    cout<<endl<<setw(8)<<0;
    for(int i=1;i<a->cols;i++){
        cout<<setw(4)<<i;
    }
    cout<<endl;
    //Print the array
    for(int i=0;i<a->rows;i++){
        cout<<setw(4)<<i;
        for(int j=0;j<a->cols;j++){
            cout<<setw(4)<<a->data[i][j];
        }
        cout<<endl;
    }
}

Table *filAray(int row,int col){
    //Allocate the table
    Table *table = new Table;
    table->cols=col;
    table->rows=row;
    //Create the number of rows
    table->data=new int*[table->cols];
    //Loop and create the columns
    for(int i=0;i<table->rows;i++){
        table->data[i]=new int[table->cols];
    }
    //Fill the array
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            table->data[i][j]=i*j;
        }
    }
    //Return the array
    return table;
}
