//#include "Deck.h"
//
//#include "Card.h"
//
//#include <random>
//
//using namespace CBJCards;
//
//CBJCards::Deck::Deck()
//    : m_cards()
//{}
//
//CBJCards::Deck::Deck(const Deck& other)
//    : m_cards()
//{
//    deepCopy(other);
//}
//
//CBJCards::Deck::Deck(Deck&& other) noexcept
//    : m_cards(std::move(other.m_cards))
//{
//    other.m_cards.clear();
//}
//
//CBJCards::Deck::~Deck()
//{
//    clear();
//}
//
//void CBJCards::Deck::shuffle()
//{
//    std::random_device randomDevice;
//    std::mt19937 generator(randomDevice());
//    std::shuffle(
//        m_cards.begin(), 
//        m_cards.end(), 
//        generator
//    );
//}
//
//std::unique_ptr<Card> CBJCards::Deck::draw()
//{
//    if (m_cards.empty())
//    {
//        return nullptr;
//    }
//    std::unique_ptr<Card> card = std::move(m_cards.front());
//    m_cards.pop_front();
//    return card;
//}
//
//void CBJCards::Deck::addCardTop(std::unique_ptr<Card> card)
//{
//    card->setFaceUp(false);
//    m_cards.push_front(std::move(card));
//}
//
//void CBJCards::Deck::addCardBottom(std::unique_ptr<Card> card)
//{
//    card->setFaceUp(false);
//    m_cards.push_back(std::move(card));
//}
//
//void CBJCards::Deck::addCardRandom(std::unique_ptr<Card> card)
//{
//    card->setFaceUp(false);
//    std::random_device randomDevice;
//    std::mt19937 generator(randomDevice());
//    std::uniform_int_distribution<std::size_t> distribution(
//        0, 
//        m_cards.size()
//    );
//
//    m_cards.insert(
//        m_cards.begin() + distribution(generator), 
//        std::move(card)
//    );
//}
//
//void CBJCards::Deck::addDeckTop(Deck& deck)
//{
//    m_cards.insert(
//        m_cards.begin(),
//        deck.m_cards.begin(),
//        deck.m_cards.end()
//    );
//    deck.m_cards.clear();
//}
//
//void CBJCards::Deck::addDeckBottom(Deck& deck)
//{
//    m_cards.insert(
//        m_cards.end(),
//        deck.m_cards.begin(),
//        deck.m_cards.end()
//    );
//    deck.m_cards.clear();
//}
//
//void CBJCards::Deck::clear()
//{
//    for (std::unique_ptr<Card>& card : m_cards)
//    {
//        card.reset();
//    }
//    m_cards.clear();
//}
//
//Deck& CBJCards::Deck::operator=(const Deck& other)
//{
//    if (this != &other)
//    {
//        clear();
//        deepCopy(other);
//    }
//    return *this;
//}
//
//Deck& CBJCards::Deck::operator=(Deck&& other) noexcept
//{
//    if (this != &other)
//    {
//        clear();
//        m_cards = std::move(other.m_cards);
//        other.m_cards.clear();
//    }
//    return *this;
//}
//
//void CBJCards::Deck::deepCopy(const Deck& other)
//{
//    for (const std::unique_ptr<Card>& card : other.m_cards)
//    {
//        m_cards.push_back(
//            std::make_unique<Card>(*card)
//        );
//    }
//}
//
//Deck CBJCards::createStandardDeck(int numDecks, bool shuffle)
//{
//    Deck deck;
//
//    if (numDecks < 1)
//    {
//        return deck;
//    }
//
//    for (int i = 0; i < numDecks; ++i)
//    {
//        for (const auto& suit : ALL_SUITS)
//        {
//            for (const auto& rank : ALL_RANKS)
//            {
//                deck.addCardBottom(
//                    std::make_unique<Card>(suit, rank)
//                );
//            }
//        }
//    }
//
//    if (shuffle)
//    {
//        deck.shuffle();
//    }
//}
