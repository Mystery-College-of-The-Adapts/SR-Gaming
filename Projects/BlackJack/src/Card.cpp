#include "Card.h"

std::unordered_map<const char *, sf::Texture> Card::_Textures = std::unordered_map<const char *, sf::Texture>();

Card::Card(Suit suit, Value val) : _Suit(suit), _Value(val), _Played(false) {
    _ImagePath = _Suit + _Value + ".png";
    sf::Texture texture;
    if (!texture.loadFromFile(_ImagePath)) printf("Failed to load %s", _ImagePath.c_str());
    _Textures.insert(std::pair<const char *, sf::Texture>(_ImagePath.c_str(), texture));
}

Card::~Card() {
    //dtor
}

Card::Suit Card::GetSuit() {
    return _Suit;
}

Card::Value Card::GetValue() {
    return _Value;
}

Card::Suit Card::IntToSuit(unsigned int suit) {
    switch (suit) {

        case DIAMONDS: return DIAMONDS;
        case SPADES:   return SPADES;
        case CLUBS:    return CLUBS;
        case HEARTS:   return HEARTS;
        default:       return SERROR;

    }
}

Card::Value Card::IntToValue(unsigned int value) {
    switch (value) {

        case ACE:   return ACE;
        case TWO:   return TWO;
        case THREE: return THREE;
        case FOUR:  return FOUR;
        case FIVE:  return FIVE;
        case SIX:   return SIX;
        case SEVEN: return SEVEN;
        case EIGHT: return EIGHT;
        case NINE:  return NINE;
        case TEN:   return TEN;
        case JACK:  return JACK;
        case QUEEN: return QUEEN;
        case KING:  return KING;
        default:    return VERROR;

    }
}
