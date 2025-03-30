#include "Hand.h"

#include "Card.h"

using namespace CBJCards;

CBJCards::Hand::Hand()
    : m_numFaceUp(0)
    , m_cards()
{}

void CBJCards::Hand::addCard(std::unique_ptr<Card> card)
{
    if (card->isFaceUp())
    {
        m_cards.insert(
            m_cards.begin() + m_numFaceUp,
            std::move(card)
        );
        m_numFaceUp++;
    }
    else {
        m_cards.push_back(std::move(card));
    }
}

std::unique_ptr<Card> CBJCards::Hand::removeCard(int index)
{
    if (index < 0 || index >= m_cards.size())
    {
        return nullptr;
    }
    std::unique_ptr<Card> card = std::move(m_cards[index]);
    if (index < m_numFaceUp)
    {
        m_numFaceUp--;
    }
    m_cards.erase(m_cards.begin() + index);
    return card;
}
