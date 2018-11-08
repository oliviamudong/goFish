#include <iostream>
#include "string.h"
#include "card.h"

using namespace std;


Card::Card(){                                       //Initialize it to the Ace of spades - default constructor
    myRank = 1;
    mySuit = spades;}

Card::Card(int rank, Suit s) {

    myRank = rank;
    mySuit = s;
}


string Card::toString()const{

    string ranker;
    if(myRank == 11)
    {
        ranker = "J";
    }
    if(myRank== 12)
    {
        ranker = "Q";

    }
    if(myRank == 13)
    {
        ranker = "K";

    }
    if(myRank == 1)
    {
        ranker = "A";
    }

    if(myRank > 1 && myRank < 11)
    {
        ranker = to_string(myRank);
    }

    //ranker = to_string(myRank);
    string suiter;
    suiter = suitString(mySuit);
    string totalCarder;

    totalCarder = ranker + suiter;
    return totalCarder;

}


bool Card::sameSuitAs(const Card& c)const {                              //bool expressions already written
    if(this->mySuit == c.mySuit){
        return true;
    }
    else return false;
}


int  Card::getRank()const{
    return myRank;
}
string  Card::getRanker()const{
    string ranker;
    if(myRank == 11)
    {
        ranker = "J";
        return ranker;
    }
    if(myRank== 12)
    {
        ranker = "Q";
        return ranker;
    }
    if(myRank == 13)
    {
        ranker = "K";
        return ranker;
    }
    if(myRank == 1)
    {
        ranker = "A";
        return ranker;
    }

    ranker =  to_string(myRank);
    return ranker;
}



string Card::suitString(Suit s)const{
    string suiter;
    switch(mySuit){
        case spades:
            suiter = "s";
            break;
        case hearts:
            suiter = "h";
            break;
        case diamonds:
            suiter = "d";
            break;
        case clubs:
            suiter = "c";
            break;
    }
    return suiter;

}

string Card::rankString(int r)const{
    string ranker;
    ranker = to_string(myRank);
    return ranker;

}

bool Card::operator==(const Card &rhs) const{
    if (this->myRank == rhs.myRank){
        if(this->mySuit == rhs.mySuit){
            return true;
        }
        else return false;
    }
    else return false;
}

bool Card::operator!=(const Card &rhs) const {
    if ((this->myRank != rhs.myRank) || (this->mySuit != rhs.mySuit)){
        return true;

    }
    else return false;
}





