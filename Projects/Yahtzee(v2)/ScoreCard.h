/* 
 * File:   ScoreCard.h
 * Author: Clayton
 *
 * Created on June 1, 2015, 9:49 AM
 */

#ifndef SCORECARD_H
#define	SCORECARD_H
#include <iostream>
using namespace std;

class ScoreCard {
private:
    unsigned short score[16];
    unsigned short counter;
    unsigned short ycount;
    unsigned short hScore;
    bool scoreBox[13];
    string name;
    string hName;

public:
    int getCount();
    int getFScore();
    int getHScore();
    string getHName();
    string getFilled(unsigned short i);
    string getName();
    void setName();
    void setHScore();
    void setYCount();
    void startCount();
    void addCount();
    void zeroCard(int i);
    void unfillCard(int i);
    void getscoreCard();
    void addTotals();
    void bonus();
    void finalScore();
    bool roundCount();
    bool notFilled(int i);
    bool scratch(int i);
    bool upperAdder(unsigned short die[], int i, char x);
    bool threeKind(unsigned short die[]);
    bool fourKind(unsigned short die[]);
    bool fullHouse(unsigned short die[]);
    bool smallStraight(unsigned short die[]);
    bool largeStraight(unsigned short die[]);
    bool yahtzee(unsigned short die[]);
    bool chance(unsigned short die[]);
};

#endif	/* SCORECARD_H */

