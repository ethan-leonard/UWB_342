#ifndef CARD_H_
#define CARD_H_

#include <iostream>
#include <string>

using namespace std;

enum Suit {kHeart, kDiamond, kClub, kSpade};
const string kSUITS[4] = {"heart", "diamond", "club", "spade"};

class playingCard {
    private:
        int value_;
        Suit suit_;

    public:
        // Constructor
        playingCard();
        playingCard(int value, Suit suit);

        // Getters
        int getNumber() const;
        Suit getSuit() const;

        // Operator Overloads
        friend ostream& operator<<(ostream& stream, const playingCard& card);

};

#endif