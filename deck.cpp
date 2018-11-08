#include <iostream>
#include <ctime>
#include "deck.h"
#include "card.h"


using namespace std;

Deck::Deck()           // pristine, sorted deck
{

    int ranker;
    Card::Suit suiter;
    for(int i = 0; i< 4; i++){
        switch(i){
            case 0:
                suiter = Card::spades;
                break;
            case 1:
                suiter = Card::hearts;
                break;
            case 2:
                suiter = Card::diamonds;
                break;
            case 3:
                suiter = Card::clubs;
                break;
        }
        for(int k = 0; k< 13; k++){
            ranker = k+1;
//            Card c;
            this->myCards[myIndex] = Card(ranker, suiter);
            myIndex++;
        }
    }
}

void Deck::shuffle()   // shuffle the deck
{
    unsigned int currentTime = (unsigned)time(0);
    srand(currentTime);
    int idx1;
    int idx2;
    int numCards;

    for(int i= 0; i< 104; i++){
        idx1 = rand() % myIndex;
        idx2 = rand() % myIndex;
        cardSwapper(idx1, idx2);
    }

}

void Deck::cardSwapper(int c1, int c2){
    Card temp;
    temp = myCards[c1];
    myCards[c1]=myCards[c2];
    myCards[c2] = temp;

}

Card Deck::dealCard()   // get a card, after 52 are dealt, fail
{
    if (myIndex<1){
        exit(1);
    }
    Card c;
    c=myCards[myIndex-1];
    myIndex--;
    return c;

}

int  Deck::size() const // # cards left in the deck
{
    return (myIndex);
}