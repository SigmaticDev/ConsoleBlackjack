#pragma once

#include <array>
#include <string>

namespace CBJCards {

    /**
     * @brief The Suit enum represents the suit of a card.
     * 
     * This enum class arbitrarily assigns integer values to the suits of a 
     * standard deck of playing cards. By associating integer values to each 
     * Suit value, it becomes possible to compare the suits so that cards have 
     * an order.
     * 
     * Values are as follows:
     */
    enum class Suit : int {
        HEARTS = 0, /**<
            The suit of hearts, equivalent to @c 0. Represented by the ♥ 
            character when supplied to the static function 
            Card::suitToSymbol.*/
        DIAMONDS, /**<
            The suit of diamonds, equivalent to @c 1. Represented by the ♦
            character when supplied to the static function
            Card::suitToSymbol.*/
        CLUBS, /**<
            The suit of clubs, equivalent to @c 2. Represented by the ♣
            character when supplied to the static function
            Card::suitToSymbol.*/
        SPADES /**<
            The suit of spades, equivalent to @c 3. Represented by the ♠
            character when supplied to the static function
            Card::suitToSymbol.*/
    };
    /**
     * @brief An array of all defined suits.
     * 
     * This array is provided by CBJCards for convenience. It is a static
     * constant array of all defined suits in the Suit enum class. It is
     * useful for iterating over all suits.
     */
    constexpr static std::array<Suit, 4> ALL_SUITS = { 
        Suit::HEARTS, 
        Suit::DIAMONDS, 
        Suit::CLUBS, 
        Suit::SPADES
    };

    /**
     * @brief The Rank enum represents the rank of a card.
     * 
     * This enum class assigns integer values to the ranks of a standard deck
     * of playing cards. The value of @c ACE is set to @c 1, and subsequent
     * ranks are assigned incrementally. This allows for easy comparison of 
     * ranks so that cards have an order.
     *
     * Additionally, this scheme means that ranks from @c TWO to @c TEN can
     * always be cast to an integer to get their numeric value.
     */
    enum class Rank : int {
        ACE = 1, /**<
            The rank of an ace, equivalent to @c 1. Represented by the 
            string @c A when supplied to the Card class's static function
            rankToSymbol. Aces can have a numeric value of either @c 1 or 
            @c 11, depending on the context.*/
        TWO, /**<
            The rank of a two, equivalent to @c 2. Represented by the string
            @c 2 when supplied to the Card class's static function 
            rankToSymbol.*/
        THREE, /**<
            The rank of a three, equivalent to @c 3. Represented by the
            string @c 3 when supplied to the Card class's static function
            rankToSymbol.*/
        FOUR, /**<
            The rank of a four, equivalent to @c 4. Represented by the
            string @c 4 when supplied to the Card class's static function
            rankToSymbol.*/
        FIVE, /**<
            The rank of a five, equivalent to @c 5. Represented by the
            string @c 5 when supplied to the Card class's static function
            rankToSymbol.*/
        SIX, /**<
            The rank of a six, equivalent to @c 6. Represented by the string
            @c 6 when supplied to the Card class's static function
            rankToSymbol.*/
        SEVEN, /**<
            The rank of a seven, equivalent to @c 7. Represented by the
            string @c 7 when supplied to the Card class's static function
            rankToSymbol.*/
        EIGHT, /**<
            The rank of an eight, equivalent to @c 8. Represented by the
            string @c 8 when supplied to the Card class's static function
            rankToSymbol.*/
        NINE, /**<
            The rank of a nine, equivalent to @c 9. Represented by the
            string @c 9 when supplied to the Card class's static function
            rankToSymbol.*/
        TEN, /**<
            The rank of a ten, equivalent to @c 10. Represented by the
            string @c 10 when supplied to the Card class's static function
            rankToSymbol.*/
        JACK, /**<
            The rank of a jack, equivalent to @c 11. Represented by the
            string @c J when supplied to the Card class's static function
            rankToSymbol.*/
        QUEEN, /**<
            The rank of a queen, equivalent to @c 12. Represented by the
            string @c Q when supplied to the Card class's static function
            rankToSymbol.*/
        KING /**<
            The rank of a king, equivalent to @c 13. Represented by the
            string @c K when supplied to the Card class's static function
            rankToSymbol.*/
    };
    /**
     * @brief An array of all defined ranks.
     *
     * This array is provided by CBJCards for convenience. It is a static
     * constant array of all defined ranks in the Rank enum class. It is
     * useful for iterating over all ranks.
     */
    constexpr static std::array<Rank, 13> ALL_RANKS = {
        Rank::ACE,
        Rank::TWO,
        Rank::THREE,
        Rank::FOUR,
        Rank::FIVE,
        Rank::SIX,
        Rank::SEVEN,
        Rank::EIGHT,
        Rank::NINE,
        Rank::TEN,
        Rank::JACK,
        Rank::QUEEN,
        Rank::KING
    };

    /**
     * @brief The Card class represents a playing card.
     *
     * The Card class is the primary class of the CBJCards library. It
     * represents a playing card with a suit, rank.
     * 
     * Additionally, cards can either be face up or face down.
     */
    class Card {
    public:
        /**
         * @brief Constructs a card with the given suit and rank face down.
         */
        Card(Suit suit, Rank rank);

        /**
         * @brief Returns whether the card is face up.
         *
         * @return @c true if the card is face up, @c false otherwise.
         */
        bool isFaceUp() const { return m_faceUp; }
        /**
         * @brief Returns the suit of the card.
         *
         * @return The suit of the card.
         */
        Suit suit() const { return m_suit; }
        /**
         * @brief Returns the rank of the card.
         *
         * @return The rank of the card.
         */
        Rank rank() const { return m_rank; }

        /**
         * @brief Sets the card to be face up or face down.
         *
         * @param faceUp @c true if the card should be face up, @c false
         * otherwise.
         */
        void setFaceUp(bool faceUp) { m_faceUp = faceUp; }

        /**
         * @brief Returns the string represeentation of the card.
         */
        std::string toString() const;
        /**
         * @brief Returns the symbol representation of the card.
         */
        std::string toSymbol() const;

        /**
         * @brief Returns the string representation of the given suit.
         */
        static std::string suitToString(Suit suit);
        /**
         * @brief Returns a symbol representing the given suit.
         */
        static std::string suitToSymbol(Suit suit);
        /**
         * @brief Returns the string representation of the given rank.
         */
        static std::string rankToString(Rank rank);
        /**
         * @brief Returns a symbol representing the given rank.
         */
        static std::string rankToSymbol(Rank rank);

    private:
        bool m_faceUp; /**<
            Whether the card is face up or face down represented by @c true
            and @c false respectively.*/
        Suit m_suit; /**<
            The suit of the card.*/
        Rank m_rank; /**<
            The rank of the card.*/
    };
}