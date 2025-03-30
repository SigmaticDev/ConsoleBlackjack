#include "Card.h"

using namespace CBJCards;

/**
 * @details
 * 
 * The constructor for the Card class. It initializes the card with the given
 * suit and rank, and sets it face down.
 * 
 * @param suit The suit of the card.
 * @param rank The rank of the card.
 */
CBJCards::Card::Card(
    Suit suit,
    Rank rank)
    : m_faceUp{ false }
    , m_suit{ suit }
    , m_rank{ rank }
{
}

/**
 * @details
 * 
 * The toString function returns the string representation of the card. The
 * string is in the format "Rank of Suit".
 * 
 * @return The string representation of the card.
 */
std::string CBJCards::Card::toString() const
{
    return rankToString(m_rank) + " of " + suitToString(m_suit);
}

/**
 * @details
 *
 * The toSymbol function returns the symbol representation of the card. The
 * symbol is in the format "RankSuit".
 *
 * @return The symbol representation of the card.
 */
std::string CBJCards::Card::toSymbol() const
{
    return rankToSymbol(m_rank) + suitToSymbol(m_suit);
}

/**
 * @details
 *
 * The suitToString function returns the string representation of the given
 * suit. 
 * 
 * Valid suits are:
 * @li Suit::HEARTS which returns "Hearts".
 * @li Suit::DIAMONDS which returns "Diamonds".
 * @li Suit::CLUBS which returns "Clubs".
 * @li Suit::SPADES which returns "Spades".
 * 
 * If an invalid suit is supplied, the function returns "Unknown".
 * 
 * @param suit The suit to convert.
 * @return The string representation of the given suit.
 */
std::string CBJCards::Card::suitToString(Suit suit)
{
    switch (suit)
    {
    case Suit::HEARTS:
        return "Hearts";
    case Suit::DIAMONDS:
        return "Diamonds";
    case Suit::CLUBS:
        return "Clubs";
    case Suit::SPADES:
        return "Spades";
    default:
        return "Unknown";
    }
}

/**
 * @details
 *
 * The suitToSymbol function returns a symbol representing the given suit.
 *
 * Valid suits are:
 * @li Suit::HEARTS which returns "♥".
 * @li Suit::DIAMONDS which returns "♦".
 * @li Suit::CLUBS which returns "♣".
 * @li Suit::SPADES which returns "♠".
 *
 * If an invalid suit is supplied, the function returns "?".
 *
 * @param suit The suit to convert.
 * @return A symbol representing the given suit as a string.
 */
std::string CBJCards::Card::suitToSymbol(Suit suit)
{
    switch (suit)
    {
    case Suit::HEARTS:
        return "\x03";
    case Suit::DIAMONDS:
        return "\x04";
    case Suit::CLUBS:
        return "\x05";
    case Suit::SPADES:
        return "\x06";
    default:
        return "?";
    }
}

/**
 * @details
 *
 * The rankToString function returns the string representation of the given
 * rank.
 *
 * Valid ranks are:
 * @li Rank::ACE which returns "Ace".
 * @li Rank::TWO which returns "Two".
 * @li Rank::THREE which returns "Three".
 * @li Rank::FOUR which returns "Four".
 * @li Rank::FIVE which returns "Five".
 * @li Rank::SIX which returns "Six".
 * @li Rank::SEVEN which returns "Seven".
 * @li Rank::EIGHT which returns "Eight".
 * @li Rank::NINE which returns "Nine".
 * @li Rank::TEN which returns "Ten".
 * @li Rank::JACK which returns "Jack".
 * @li Rank::QUEEN which returns "Queen".
 * @li Rank::KING which returns "King".
 *
 * If an invalid rank is supplied, the function returns "Unknown".
 *
 * @param rank The rank to convert.
 * @return The string representation of the given rank.
 */
std::string CBJCards::Card::rankToString(Rank rank)
{
    switch (rank)
    {
    case Rank::ACE:
        return "Ace";
    case Rank::TWO:
        return "Two";
    case Rank::THREE:
        return "Three";
    case Rank::FOUR:
        return "Four";
    case Rank::FIVE:
        return "Five";
    case Rank::SIX:
        return "Six";
    case Rank::SEVEN:
        return "Seven";
    case Rank::EIGHT:
        return "Eight";
    case Rank::NINE:
        return "Nine";
    case Rank::TEN:
        return "Ten";
    case Rank::JACK:
        return "Jack";
    case Rank::QUEEN:
        return "Queen";
    case Rank::KING:
        return "King";
    default:
        return "Unknown";
    }
}

/**
 * @details
 *
 * The rankToSymbol function returns a symbol representing the given rank.
 *
 * Valid ranks are:
 * @li Rank::ACE which returns "A".
 * @li Rank::TWO which returns "2".
 * @li Rank::THREE which returns "3".
 * @li Rank::FOUR which returns "4".
 * @li Rank::FIVE which returns "5".
 * @li Rank::SIX which returns "6".
 * @li Rank::SEVEN which returns "7".
 * @li Rank::EIGHT which returns "8".
 * @li Rank::NINE which returns "9".
 * @li Rank::TEN which returns "10".
 * @li Rank::JACK which returns "J".
 * @li Rank::QUEEN which returns "Q".
 * @li Rank::KING which returns "K".
 *
 * If an invalid rank is supplied, the function returns "?".
 *
 * @param rank The rank to convert.
 * @return A symbol representing the given rank as a string.
 */
std::string CBJCards::Card::rankToSymbol(Rank rank)
{
    switch (rank)
    {
    case Rank::ACE:
        return "A";
    case Rank::TWO:
        return "2";
    case Rank::THREE:
        return "3";
    case Rank::FOUR:
        return "4";
    case Rank::FIVE:
        return "5";
    case Rank::SIX:
        return "6";
    case Rank::SEVEN:
        return "7";
    case Rank::EIGHT:
        return "8";
    case Rank::NINE:
        return "9";
    case Rank::TEN:
        return "10";
    case Rank::JACK:
        return "J";
    case Rank::QUEEN:
        return "Q";
    case Rank::KING:
        return "K";
    default:
        return "?";
    }
}
