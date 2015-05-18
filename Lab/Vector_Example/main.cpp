/* 
 * File       : main.cpp
 * Author     : Clayton Teets
 * Created on : May 18, 2015, 8:11 AM
 * Purpose    : 
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <bitset>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void filAray(vector<int> &,int);
void prntAry(vector<int> &,int,int);
void markSrt(vector<int> &,int);
int linSrch(vector<int> &,int n,int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Declare variables
    const int SIZE=100;
    vector<int> array(SIZE);
    //Fill the array
    filAray(array,SIZE);
    //Print the array
    prntAry(array,SIZE,10);
    //Sort the Array
    //markSrt(array,SIZE);
    sort(array.begin(),array.end());
    //Print the array
    prntAry(array,SIZE,10);
    //Find something
    int rndVal=rand()%90+10;
    //cout<<rndVal<<" was found at position "
    //    <<linSrch(array,SIZE,rndVal)<<endl;
    std::vector<int>::iterator it;
    it=find(array.begin(),array.end(),rndVal);
    if(it==array.end()){
        cout<<rndVal<<" is Not Found"<<endl;
    }else{
        cout<<rndVal<<" was found "<<endl;
    }
    //Exit Stage Right!
    return 0;
}

void prntAry(vector<int> &a,int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==perLine-1)cout<<endl;
    }
    cout<<endl;
}

void filAray(vector<int> &a,int n){
    for(int i=0;i<n;i++){
        a[i]=rand()%90+10;//2 digit numbers
    }
}

void markSrt(vector<int> &a,int n){
    for(int pos=0;pos<n-1;pos++){
        for(int lst=pos+1;lst<n;lst++){
            if(a[pos]>a[lst]){
                int temp=a[pos];
                a[pos]=a[lst];
                a[lst]=temp;
            }
        }
    }
}

int linSrch(vector<int> &a,int n,int val){
    for(int i=0;i<n;i++){
        if(a[i]==val)return i;
    }
    return -1;
}