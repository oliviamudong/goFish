// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS

#include "player.h"
#include "deck.h"
#include "card.h"

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);




int main( )
{
    int numCards = 5;
    int flag =0;

    Player p1("Joe");
    Player p2("Jane");

    Deck d;  //create a deck of cards
    d.shuffle();

    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);

    cout << p1.getName() <<" has : " << p1.showHand() << endl;
    cout << p2.getName() <<" has : " << p2.showHand() << endl;
    Card c;
    Card c2;
    int pTurn = 1;
    int p1Score =0;
    int p2Score =0;


    while(flag == 0){

        if(p1.checkHandForPair(c, c2))
        {
            p1.bookCards(c, c2);
            p1.removeCardFromHand(c);
            p1.removeCardFromHand(c2);
        }
        if(p2.checkHandForPair(c, c2))
        {
            p2.bookCards(c, c2);
            p2.removeCardFromHand(c);
            p2.removeCardFromHand(c2);
        }
        if(p1.checkHandForPair(c, c2))
        {
            p1.bookCards(c, c2);
            p1.removeCardFromHand(c);
            p1.removeCardFromHand(c2);
        }
        if(p2.checkHandForPair(c, c2))
        {
            p2.bookCards(c, c2);
            p2.removeCardFromHand(c);
            p2.removeCardFromHand(c2);
        }

        while(pTurn == 1){

            if(p1.getHandSize()==0){
                if(d.size() != 0){
                    p1.addCard(d.dealCard());
                }
            }
            if(p1.getBookSize() == 10)
            {
                cout<<"Winner WINNER Winner chicken breakfast is " << p1.getName() << endl;
                flag = 1;
                break;

            }
            c = p1.chooseCardFromHand();
            cout <<p1.getName() << " asks - Do you have a "<< c.getRanker()<< endl;

            if(p2.rankInHand(c)){
                cout<< p2.getName() <<" says - Yes I have a " << c.getRanker()<< endl;
                c2 = p2.removeCardFromHand(c);
                p1.addCard(c2);
                cout << p1.getName() <<" books the " << c.getRanker() <<"s "<< endl;
                p1.bookCards(c, c2);
                p1Score++;
                p1.removeCardFromHand(c);
                p1.removeCardFromHand(c2);

                /*cout << p1.getName() << p1.showHand() << p1.showBooks();
                cout << p2.getName() << p2.showHand() << p2.showBooks();*/



            }
            else {

                cout << p2.getName() << " says - GO FISH CHUMP" << endl<< endl;
                if(d.size() != 0 ){
                    p1.addCard(d.dealCard());
                }


                if(p1.checkHandForPair(c, c2))
                {
                    p1.bookCards(c, c2);
                    p1.removeCardFromHand(c);
                    p1.removeCardFromHand(c2);
                }
                pTurn = 2;
            }

        }

        while(pTurn == 2)
        {
            if(p2.getHandSize()==0){
                if(d.size() != 0 ){
                    p2.addCard(d.dealCard());
                }

            }

            if(p2.getBookSize() == 10)
            {
                cout<<"Winner WINNER Winner chicken breakfast is " << p2.getName() << endl;
                flag = 1;
                break;

            }
            c = p2.chooseCardFromHand();
            cout <<p2.getName() << " asks - Do you have a "<< c.getRanker()<< endl;

            if(p1.rankInHand(c)) {


                cout << p1.getName() << " says - Yes I have a " << c.getRanker() << endl;
                c2 = p1.removeCardFromHand(c);
                p2.addCard(c2);
                cout << p2.getName() <<" books the " << c.getRanker()<< "s"<< endl;
                p2.bookCards(c, c2);
                p2Score++;
                p2.removeCardFromHand(c);
                p2.removeCardFromHand(c2);



            }

            else
                {
                pTurn = 1;
                cout << p1.getName() << " says - Im so sorry ): go fish (: " << endl<<endl;
                if(d.size() != 0){
                    p2.addCard(d.dealCard());
                }

                if(p2.checkHandForPair(c, c2))
                {
                    p2.bookCards(c, c2);
                    p2.removeCardFromHand(c);
                    p2.removeCardFromHand(c2);
                }
                //Turn == 1;
            }

        }





    }


    return EXIT_SUCCESS;
}



void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}
   


