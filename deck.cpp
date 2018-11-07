#include <iostream>
#include "deck.h"
#include "card.h"


using namespace std;

Deck::Deck()           // pristine, sorted deck
{

    int ranker;
    Card::Suit suiter;
    for(int i = 1; i< 5; i++){
        switch(i){
            case 1:
                suiter = Card::spades;
                break;
            case 2:
                suiter = Card::hearts;
                break;
            case 3:
                suiter = Card::diamonds;
                break;
            case 4:
                suiter = Card::clubs;
                break;
        }
        for(int k = 0; k< 13; k++){
            ranker = k+1;
            Card c;
            c = Card(ranker, suiter);
        }
    }
}

void Deck::shuffle()   // shuffle the deck
{

}

Card Deck::dealCard()   // get a card, after 52 are dealt, fail
{

}

int  Deck::size() const // # cards left in the deck
{
}