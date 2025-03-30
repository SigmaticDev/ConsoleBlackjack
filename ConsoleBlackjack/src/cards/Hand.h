#pragma once

#include <memory>
#include <vector>

namespace CBJCards {
    class Card;

    class Hand {
    public:
        Hand();

        int size() const { return m_cards.size(); }
        bool empty() const { return m_cards.empty(); }

        void addCard(std::unique_ptr<Card> card);
        std::unique_ptr<Card> removeCard(int index);

        const std::vector<std::unique_ptr<Card>>& cards() const { 
            return m_cards;
        }

    private:
        int m_numFaceUp;
        std::vector<std::unique_ptr<Card>> m_cards;
    };
}