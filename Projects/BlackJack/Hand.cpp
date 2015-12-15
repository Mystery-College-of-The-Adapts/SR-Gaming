#include "Hand.h"

Hand::Hand(Deck *deck) : _Deck(deck) { }

Hand::~Hand() { }

void Hand::Render() {
    // TODO
    float offset = Card::CardWidth + 3, x = (900 / 2) - ((_Cards.size() * offset) / 2);
    for (unsigned long i = 0; i < _Cards.size(); i++) {
        Card *c = _Cards.at(i);
        c->Coords[0] = x;
        c->Coords[1] = 400;
        c->Render();
        x += offset;
    }
}

void Hand::Draw() {
    _Cards.push_back(_Deck->Draw());
}

int Hand::Count() {
    int count = 0, aces = 0;
    for (Card *card : _Cards) {
        if (card->GetValue() == Card::ACE)
            aces++;
        else
            count += (card->GetValue() + 1);
    }
    while (aces > 0) {

        if (11 + count <= 21)
            count += 11;
        else
            count++;
        aces--;

    }
    return count;
}
