#include "playingCard.h"

playingCard::playingCard() : value_(1), suit_(kSpade) {

}

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