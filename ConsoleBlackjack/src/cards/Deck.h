#pragma once

#include <deque>
#include <memory>
#include <vector>

namespace CBJCards {

    class Card;

    class Deck {
    public:
        Deck();

        ~Deck();

        int size() const { return m_cards.size(); }
        bool empty() const { return m_cards.empty(); }

        std::unique_ptr<Card> draw();
        std::vector<std::unique_ptr<Card>> draw(int numCards);
        Deck& cutFromTop();
        Deck& cutFromBottom();

        void shuffle();

        void addCardTop(std::unique_ptr<Card> card);
        void addCardBottom(std::unique_ptr<Card> card);
        void addCardRandom(std::unique_ptr<Card> card);

        void addDeckTop(Deck& deck);
        void addDeckBottom(Deck& deck);

    private:

        std::deque<std::unique_ptr<Card>> m_cards;
    };

    static Deck createStandardDeck(
        int numDecks = 1,
        bool shuffle = true
    );
}
