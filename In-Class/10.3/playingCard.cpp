#include <iostream>
#include <string>
#include "playingCard.h"

using namespace std;

playingCard::playingCard() : value_(1), suit_(kSpade) {}

playingCard::playingCard(int value, Suit suit) : value_(value), suit_(suit) {
    if ((value < 1) || (value > 13)) {
        value_ = 1;
    }
}

int playingCard::getNumber() const {
    return value_;
}

Suit playingCard::getSuit() const {
    return suit_;
}

ostream& operator<<(ostream& stream, const playingCard& card) {
    string card_value, card_suit;
    card_suit = kSUITS[card.getSuit()];

    switch (card.getNumber()) {
        case 1:
            card_value = "ace";
            break;
        case 11:
            card_value = "jack";
            break;
        case 12: card_value = "queen";
            break;
        case 13:
            card_value = "king";
            break;
        default:
            card_value= to_string(card.getNumber());
    }

    stream << card_value << " of " << card_suit;
    return stream;
}