//#pragma once
//
//#include "Card.h"
//
//#include <deque>
//#include <memory>
//
//namespace CBJCards {
//
//    class Deck
//    {
//    public:
//        Deck();
//        Deck(const Deck& other);
//        Deck(Deck&& other) noexcept;
//
//        ~Deck();
//
//        int size() const { return m_cards.size(); }
//        bool empty() const { return m_cards.empty(); }
//
//        void shuffle();
//        std::unique_ptr<Card> draw();
//
//        void addCardTop(std::unique_ptr<Card> card);
//        void addCardBottom(std::unique_ptr<Card> card);
//        void addCardRandom(std::unique_ptr<Card> card);
//        void addDeckTop(Deck& deck);
//        void addDeckBottom(Deck& deck);
//
//        void clear();
//
//        Deck& operator=(const Deck& other);
//        Deck& operator=(Deck&& other) noexcept;
//    private:
//        void deepCopy(const Deck& other);
//
//        std::deque<std::unique_ptr<Card>> m_cards;
//    };
//
//    static Deck createStandardDeck(int numDecks = 1, bool shuffle = true);
//}