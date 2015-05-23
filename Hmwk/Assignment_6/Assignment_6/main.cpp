/* 
 * File       : main.cpp
 * Author     : Clayton Teets
 * Created on : May 19, 2015, 3:16 PM
 * Purpose    : Assignment 6
 */
//System Libraries
#include <iostream> //Input/Output Library
#include <iomanip>  //Output Formatting
#include <ctime>
#include <cstdlib>
#include <string>
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
int countPerfect(int[], int);
float tRain(float[], const short);
float aRain(float[], const short);
int dMonth(float[], const short);
int wMonth(float[], const short);
//Execution Begins Here

int main(int argc, char** argv) {
    //Declare menu variable choice
    char choice;
    //Repeat the menu
    do {
        //General Menu Format
        //Display the selection
        cout << "Type 0 (Perfect Scores)          to solve problem 1" << endl;
        cout << "Type 1 (Roman Numeral Converter) to solve problem 2" << endl;
        cout << "Type 2 (Chips and Salsa)         to solve problem 3" << endl;
        cout << "Type 3 (Monkey Business)         to solve problem 4" << endl;
        cout << "Type 4 (Rain or Shine)           to solve problem 5" << endl;
        cout << "Type 5 (Lottery)                 to solve problem 6" << endl;
        cout << "Type 6 (Rainfall Statistics)     to solve problem 7" << endl;
        cout << "Type 7 to solve problem " << endl;
        cout << "Type 8 to solve problem " << endl;
        cout << "Type 9 to solve problem " << endl;
        cout << "Type anything else to quit with no solutions." << endl << endl;
        //Read the choice
        cout << "Choice : ";
        cin>>choice;
        cout << endl;
        //Solve a problem that has been chosen.
        switch (choice) {
            case '0':problem0();
                break;
            case '1':problem1();
                break;
            case '2':problem2();
                break;
            case '3':problem3();
                break;
            case '4':problem4();
                break;
            case '5':problem5();
                break;
            case '6':problem6();
                break;
            case '7':problem7();
                break;
            case '8':problem8();
                break;
            case '9':problem9();
                break;
            default:cout << "Exit" << endl;
        };
    } while (choice >= '0' && choice <= '9');
    //Exit Stage right
    return 0;
}

//*******************         Problem 0           ********************/

void problem0() {
    //Declare Variable
    int SIZE = 10;
    int scores[SIZE] = {};
    int sCount = 0;
    //Prompt user for test scores
    cout << "Enter 10 test scores" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << "Test " << i + 1 << " = ";
        cin >> scores[i];
        while (scores[i] < 0 || 100 < scores[i]) {
            cout << "Invalid Input, Enter 0-100. ";
            cin >> scores[i];
        }
    }
    cout << endl;
    //Call perfect score counter
    sCount = countPerfect(scores, SIZE);
    cout << "You received " << sCount << " perfect scores" << endl << endl;
}

//*******************         Problem 1           ********************/

void problem1() {
    //Declare Variable
    int SIZE = 21;
    string rNum[SIZE] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X",
        "XI", "XII", "XIII", "XIV", "XV", "XVI", "XVII", "XIII", "XIX", "XX"};
    int input;
    //Prompt for input
    cout << "Enter numbers between 1-20 to convert to Roman numerals" << endl;
    cout << "Press 0 to quit" << endl << endl;
    while (input != 0) { //Do while input is not 0
        cout << "Number = ";
        cin>>input;
        while (0 > input || input > 20) { //Input Validation
            cout << "Invalid Input. Enter 1-20. ";
            cin>>input;
        }
        if (input == 0) {
        }//If input = 0, do nothing
        else { //If valid, output correct Roman numeral
            cout << "Roman Numeral = " << rNum[input] << endl << endl;
        }
    }
    cout << endl;
}

//*******************         Problem 2           ********************/

void problem2() {
    //Declare Variables
    int SIZE = 5;
    string sName[SIZE] = {"mild", "medium", "sweet", "hot", "zesty"};
    int sSold[SIZE] = {};
    int high, h;
    int low, l;
    //Prompt for input
    cout << "Enter sales for all 5 salsa types." << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << setw(7) << sName[i] << " = ";
        cin >> sSold[i];
    }
    cout << endl;
    //Output Sales
    cout << "Salsa Sales:" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << setw(7) << sName[i] << " = " << sSold[i] << endl;
    }
    cout << endl;
    //Find highest and lowest sales
    high = sSold[0];
    low = sSold[0];
    for (int i = 0; i < SIZE; i++) {
        if (sSold[i] > high) {
            high = sSold[i];
            h = i;
        }
        if (sSold[i] < low) {
            low = sSold[i];
            l = i;
        }
    }
    //Output highest and lowest sales
    cout << "The highest sales are " << sName[h] << " salsa, at " << sSold[h] << " sales." << endl;
    cout << "The lowest sales are " << sName[l] << " salsa, at " << sSold[l] << " sales." << endl;
    cout << endl;
}

//*******************         Problem 3           ********************/

void problem3() {
    //Declare Variables
    string weekday[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    string mName[3] = {"Jimbo", "Kong", "Ceaser"};
    int monkey[3][7] = {};
    float average;
    int high, hName, hFood;
    int low, lName, lFood;
    //Collect food eaten for the week
    cout << "Enter food data for each day, pressing enter for next entry." << endl;
    for (int i = 0; i < 3; i++) {
        cout << mName[i] << endl;
        for (int u = 0; u < 7; u++) {
            cout << setw(9) << weekday[u] << " : ";
            cin >> monkey[i][u];
            while (monkey[i][u] < 0) {
                cout << "Invalid Input. Enter a positive number. ";
                cin >> monkey[i][u];
            }
        }
        cout << endl;
    }
    //Calculate Average
    for (int i = 0; i < 3; i++) {
        for (int u = 0; u < 7; u++) {
            average += monkey[i][u];
        }
    }
    average /= 7;
    //Find most and least food eaten
    high = monkey[0][0];
    hName = 0;
    hFood = 0;
    low = monkey[0][0];
    lName = 0;
    lFood = 0;
    for (int i = 0; i < 3; i++) {
        for (int u = 0; u < 7; u++) {
            if (monkey[i][u] > high) {
                high = monkey[i][u];
                hName = i;
                hFood = u;
            }
            if (monkey[i][u] < low) {
                low = monkey[i][u];
                lName = i;
                lFood = u;
            }
        }
    }
    //Output average, high, and low
    cout << mName[hName] << " ate the most food (" << monkey[hName][hFood] << " lbs) on " << weekday[hFood] << "." << endl;
    cout << mName[lName] << " ate the least food (" << monkey[lName][lFood] << " lbs) on " << weekday[lFood] << "." << endl;
    cout << fixed << showpoint << setprecision(2);
    cout << "The monkey family ate an average of " << average << " lbs of food per day." << endl;
    cout << endl;
}

//*******************         Problem 4           ********************/

void problem4() {
    //Initialize the random number seed
    srand(static_cast<unsigned int> (time(0)));
    //Declare Variables
    int nMonths = 3; //Three months
    int days = 30; //Only collect for 30 days of each month
    char forcast[nMonths][days] = {}; //Array to store forecast
    int weather;
    int sCount[nMonths] = {}; //Sunny day counter
    int cCount[nMonths] = {}; //Cloudy day counter
    int rCount[nMonths] = {}; //Rainy day counter
    int sTotal = 0; //Total sunny days
    int cTotal = 0; //Total cloudy days
    int rTotal = 0; //Total rainy days
    int rHigh; //Highest rainy month
    int rLow; //Lowest rainy month
    short hMonth, lMonth;
    string month[nMonths] = {"June", "July", "August"};
    //Load random weather data for each day
    for (int i = 0; i < nMonths; i++) {
        cout << month[i] << ":" << endl;
        for (int u = 0; u < days; u++) {
            weather = (rand() % 3);
            if (weather == 0) {
                forcast[i][u] = 'S';
                cout << "Day " << setw(2) << u + 1 << " : ";
                cout << forcast[i][u] << endl;
                sCount[i] += 1;
            } else if (weather == 1) {
                forcast[i][u] = 'C';
                cout << "Day " << setw(2) << u + 1 << " : ";
                cout << forcast[i][u] << endl;
                cCount[i] += 1;
            } else if (weather == 2) {
                forcast[i][u] = 'R';
                cout << "Day " << setw(2) << u + 1 << " : ";
                cout << forcast[i][u] << endl;
                rCount[i] += 1;
            } else forcast[i][u] = 'E';
        }
        cout << endl;
    }
    //Add weather type totals
    for (int i = 0; i < nMonths; i++) {
        sTotal += sCount[i];
        cTotal += cCount[i];
        rTotal += rCount[i];
    }
    //Determine month with highest days of rain
    rHigh = rCount[0];
    hMonth = 0;
    if (rCount[1] > rHigh) {
        rHigh = rCount[1];
        hMonth = 1;
    } else if (rCount[2] > rHigh) {
        rHigh = rCount[2];
        hMonth = 2;
    }
    //Determine month with lowest days of rain
    rLow = rCount[0];
    lMonth = 0;
    if (rCount[1] < rLow) {
        rLow = rCount[1];
        lMonth = 1;
    } else if (rCount[2] < rLow) {
        rLow = rCount[2];
        lMonth = 2;
    }
    //Output totals for all three months
    cout << "The three month period contained " << sTotal << " sunny days, " << cTotal;
    cout << " cloudy days, " << rTotal << " rainy days." << endl << endl;
    //Output months with the most and least rainy days
    cout << month[hMonth] << " had the highest number of rainy days (" << rCount[hMonth] << ")." << endl;
    cout << month[lMonth] << " had the lowest number of rainy days (" << rCount[lMonth] << ")." << endl << endl;
    //Output totals for each day of each month
    for (int i = 0; i < nMonths; i++) {
        cout << month[i] << ":" << endl;
        cout << setw(3) << sCount[i] << " sunny day(s)" << endl;
        cout << setw(3) << cCount[i] << " cloudy day(s)" << endl;
        cout << setw(3) << rCount[i] << " rainy day(s)" << endl << endl;
    }
}

//*******************         Problem 5           ********************/

void problem5() {
    //Declare Variables
    short SIZE = 5;
    short same;
    int lottery[SIZE] = {};
    int player[SIZE] = {};
    //Initialize the random number seed
    srand(static_cast<unsigned int> (time(0)));
    //Set lottery numbers
    for (int i = 0; i < SIZE; i++) {
        lottery[i] = (rand() % 10);
    }
    //Prompt for user input
    cout << "Enter 5 single digit lottery numbers, pressing enter after each digit." << endl;
    for (int i = 0; i < SIZE; i++) {
        cin >> player[i];
        while (player[i] < 0 || 9 < player[i]) {
            cout << "Invalid Input. Enter 0-9" << endl;
            cin >> player[i];
        }
    }
    //Compare both arrays and count similar elements
    for (int i = 0; i < SIZE; i++) {
        if (lottery[i] == player[i]) {
            same += 1;
        }
    }
    //Output Results
    cout << endl;
    cout << "*****************************" << endl;
    cout << "*Lottery";
    for (int i = 0; i < SIZE; i++) {
        cout << "* " << lottery[i] << " ";
    }
    cout << "*" << endl;
    cout << "*****************************" << endl;
    cout << "*Player ";
    for (int i = 0; i < SIZE; i++) {
        cout << "* " << player[i] << " ";
    }
    cout << "*" << endl;
    cout << "*****************************" << endl;
    cout << endl;
    cout << "You have " << same << " matching element(s)." << endl;
    cout << endl;
}

//*******************         Problem 6           ********************/

void problem6() {
    //Declare Variables
    const short month = 12;
    float rain[month] = {};
    string mName[month] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    //Collect rainfall data for each month
    cout << "Enter rainfall data, pressing enter after each month." << endl;
    for (int i = 0; i < month; i++) {
        cout << setw(9) << mName[i] << " : ";
        cin >> rain[i];
    }
    cout << endl;
    //Output results
    cout << "Rain Report For a Region In Severe Drought:" << endl;
    cout << "Total rainfall           : " << tRain(rain, month) << " inches" << endl;
    cout << "Average monthly rainfall : " << aRain(rain, month) << " inches" << endl;
    cout << "The least rain fell in " << mName[dMonth(rain, month)] << " with " << rain[dMonth(rain, month)] << " inches." << endl;
    cout << "The most rain fell in " << mName[wMonth(rain, month)] << " with " << rain[wMonth(rain, month)] << " inches." << endl;
    cout << endl;
}

//*******************         Problem 7           ********************/

void problem7() {

}

//*******************         Problem 8           ********************/

class TestGrader {
public:
    char answers[20];

    void setKey(string test, const short max) {
        for (int i = 0; i < max; i++) {
            answers[i] = test[i];
        }
    }

    void grade(char *test, const short max) {
        int equal = 0;
        for (int i = 0; i < max; i++) {
            if (answers[i] == test[i]) {
                equal += 1;
            }
        }
        if (equal < 15) {
            cout << "You have failed your exam!" << endl;
            cout << equal << "/20";
        } else {
            cout << "You have passed!" << endl;
            cout << equal << "/20";
        }
    }
};

void problem8() {
    //Declare Variables
    short const max = 20;
    char input[max] = {};
    //Declare answers object and fill
    TestGrader a;
    a.setKey("BDAACABACDBCDADCCBDA", max);
    //Prompt for inputs
    cout << "Input answers here using caps-lock :" << endl;
    for (int i = 0; i < max; i++) {
        cout << setw(2) << i + 1 << ". ";
        cin >> input[i];
        while (input[i] != 'A' && input[i] != 'B' && input[i] != 'C' && input[i] != 'D') {
            cout << "Invalid input, answer must be A, B, C, or D. ";
            cin >> input[i];
        }
    }
    //Grade test and output pass or fail
    a.grade(input, max);
    cout<<endl<<endl;
}

//*******************         Problem 9           ********************/

class PayRoll {
private:
    float PayRate;
    float Hours;
public:

    void setPayRate(float i) {
        PayRate = i;
    }

    void setHours(float i) {
        Hours = i;
    }

    float getPayRate() {
        return PayRate;
    }

    float getHours() {
        return Hours;
    }

    float getGrossPay() {
        return PayRate * Hours;
    }
};

void problem9() {
    //Declare how many times the program will loop
    short nPeople;
    cout << "Enter number of employees to collect payroll information for : ";
    cin>>nPeople;
    cout << endl;
    //Declare Variabes
    PayRoll person[nPeople]; //Declare object array for people
    float PayRate[nPeople], Hours[nPeople];
    //Collect PayRate and hours worked for each employee
    for (int i = 0; i < nPeople; i++) {
        cout << "Employee " << i + 1 << ":" << endl;
        cout << "Hours Worked : ";
        cin >> Hours[i];
        cout << "Pay Rate     : ";
        cin >> PayRate[i];
        cout << endl;
    }
    //Call member functions to set data
    for (int i = 0; i < nPeople; i++) {
        person[i].setHours(Hours[i]);
        person[i].setPayRate(PayRate[i]);
    }
    //Call Member Functions to Output Data
    cout << "PayRoll Data:" << endl << endl;
    for (int i = 0; i < nPeople; i++) {
        cout << "Employee " << i + 1 << ":" << endl;
        cout << "Hours     : " << person[i].getHours() << endl;
        cout << "Pay Rate  : " << person[i].getPayRate() << endl;
        cout << "Gross Pay : " << person[i].getGrossPay() << endl;
        cout << endl;
    }
}

//Perfect score counter for problem 0

int countPerfect(int scores[], int SIZE) {
    //Declare Variables
    int sCount = 0;
    //Count perfect scores
    for (int i = 0; i < SIZE; i++) {
        if (scores[i] == 100) {
            sCount += 1;
        }
    }
    return sCount;
}

//Calculation functions for problem 6

float tRain(float rain[], const short month) {
    cout << fixed << setprecision(2) << showpoint;
    //Declare total variable for return
    float total = 0;
    //Calculate total rainfall
    for (int i = 0; i < month; i++) {
        total += rain[i];
    }
    return total;
}

float aRain(float rain[], const short month) {
    cout << fixed << setprecision(2) << showpoint;
    //Declare average variable for return
    float average = 0;
    //Add rainfall from each month
    for (int i = 0; i < month; i++) {
        average += rain[i];
    }
    //Divide by total of months to find average
    average /= month;
    return average;
}

int dMonth(float rain[], const short month) {
    //Declare dry and dMonth variable for return
    float dry = rain[0];
    int dMonth = 0;
    //Determine the driest month
    for (int i = 1; i < month; i++) {
        if (rain[i] < dry) {
            dry = rain[i];
            dMonth = i;
        }
    }
    return dMonth;
}

int wMonth(float rain[], const short month) {
    //Declare dry and dMonth variable for return
    float wet = rain[0];
    int wMonth = 0;
    //Determine the driest month
    for (int i = 1; i < month; i++) {
        if (rain[i] > wet) {
            wet = rain[i];
            wMonth = i;
        }
    }
    return wMonth;
}