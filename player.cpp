//#include <iostream>
#include "player.h"
#include <iterator>
#include <ctime>
#include <string>

using namespace std;

Player::Player() {
    myName = "Roger";

}


void Player::addCard(Card c)
{
    myHand.push_back(c);
}


void Player::bookCards(Card c1, Card c2){
    myBook.push_back(c1);
    myBook.push_back(c2);

}


//this function will check a players hand for a pair.
//If a pair is found, it returns true and populates the two variables with the cards that make the pair.
bool Player::checkHandForBook(Card &c1, Card &c2) {
    int numCards = 0;
    for (vector<Card>::const_iterator it = myHand.begin(); it != myHand.end(); ++it) {
        numCards++;
    }
    for (int i = 0; i < numCards; i++) {
        for (int k = 0; k < numCards; k++) {
            if (myHand[i].getRank() == myHand[k].getRank()) {
                if (!myHand[i].sameSuitAs(myHand[k])) {
                    c1 = myHand[i];
                    c2 = myHand[k];
                    return true;
                }
            }
        }
    }

        return false;


    }

//OPTIONAL
// comment out if you decide to not use it
//Does the player have a card with the same rank as c in her hand?
bool Player::rankInHand(Card c) const{                                           //Since f(const) const_iterator
   //vector<Card>::iterator it =  myHand;
   for(vector<Card>::const_iterator it = myHand.begin() ; it != myHand.end(); ++it){
       if(it->getRank() == c.getRank()){
           return true;
       }
   }
    return false;

}

Card Player::chooseCardFromHand() const{
    unsigned int currentTime = (unsigned)time(0);
    srand(currentTime);
    int rando;
    Card c;

    int numCards =0;
    for(vector<Card>::const_iterator it = myHand.begin() ; it != myHand.end(); ++it){
        numCards++;
    }

    rando = rand() % numCards;
    c = myHand[rando];
    return c;


}

//Does the player have the card c in her hand?
bool Player::cardInHand(Card c) const{
    int numCards =0;
    for(vector<Card>::const_iterator it = myHand.begin() ; it != myHand.end(); ++it){
        numCards++;
    }
    for(int i =0; i< numCards; i++){
        if (myHand[i].getRank() == c.getRank()){
            return true;
        }
    }
    return false;

}

//Remove the card c from the hand and return it to the caller
Card Player::removeCardFromHand(Card c){
    Card temp;
    int numCards =0;
    for(vector<Card>::const_iterator it = myHand.begin() ; it != myHand.end(); ++it){
        numCards++;
    }
    for(int i =0; i< numCards; i++){
        if (myHand[i].getRank() == c.getRank()){
            temp = myHand[i];
            myHand.erase(myHand.begin() + i);
            return temp;
        }
    }


}

string Player::showHand() const{
    string hand;
    int numCards =0;
    for(vector<Card>::const_iterator it = myHand.begin() ; it != myHand.end(); ++it){
        numCards++;
    }
    for(int i =0; i< numCards; i++){
        //cout << myHand[i] << endl;
        //hand += to_string(myHand[i].getRanker());
        //hand += suitString(myHand[i]);
        //hand += myHand[i].mySuit;
        hand += myHand[i].toString();
        hand += " ";
    }

    //string hands(myHand.begin(), myHand.end());
    //return hands;
    string jerk;
    return hand;

}
string Player::showBooks() const{
    //string books(myBook.begin(), myBook.end());
    string hand;
    int numCards =0;
    for(vector<Card>::const_iterator it = myBook.begin() ; it != myBook.end(); ++it){
        numCards++;
    }
    for(int i =0; i< numCards; i++){
        //cout << myHand[i] << endl;
        //hand += to_string(myHand[i].getRanker());
        //hand += suitString(myHand[i]);
        //hand += myHand[i].mySuit;
        hand += myBook[i].toString();
        hand += " ";
    }

    //string hands(myHand.begin(), myHand.end());
    //return hands;
    string jerk;
    return hand;


}

int Player::getHandSize() const{

    int numCards =0;
    for(vector<Card>::const_iterator it = myHand.begin() ; it != myHand.end(); ++it){
        numCards++;
    }

    return numCards;

}
int Player::getBookSize() const{

    int numCards =0;
    for(vector<Card>::const_iterator it = myBook.begin() ; it != myBook.end(); ++it){
        numCards++;
    }

    return numCards;


}

//OPTIONAL
// comment out if you decide to not use it
//this function will check a players hand for a pair.
//If a pair is found, it returns true and populates the two variables with the cards tha make the pair.

bool Player::checkHandForPair(Card &c1, Card &c2){

    int numCards = 0;
    for (vector<Card>::const_iterator it = myHand.begin(); it != myHand.end(); ++it) {
        numCards++;
    }
    for (int i = 0; i < numCards; i++) {
        for (int k = 0; k < numCards; k++) {
            if (myHand[i].getRank() == myHand[k].getRank()) {
                if (!myHand[i].sameSuitAs(myHand[k])) {
                    c1 = myHand[i];
                    c2 = myHand[k];
                    return true;
                }
            }
        }
    }

    return false;


}




//OPTIONAL
// comment out if you decide to not use it
//Does the player have a card with the same rank as c in her hand?
//e.g. will return true if the player has a 7d and the parameter is 7c

bool Player::sameRankInHand(Card c) const
{
    return true;

};
