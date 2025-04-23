#include "Deck.h"

#include "Card.h"

#include <random>

using namespace CBJCards;

CBJCards::Deck::Deck()
    : m_cards()
{}

CBJCards::Deck::~Deck()
{
    m_cards.clear();
}

std::unique_ptr<Card> CBJCards::Deck::draw()
{
    if (m_cards.empty()) {
        return nullptr;
    }

    std::unique_ptr<Card> card = std::move(m_cards.front());
    m_cards.pop_front();

    return card;
}

std::vector<std::unique_ptr<Card>> CBJCards::Deck::draw(int numCards)
{
    std::vector<std::unique_ptr<Card>> stack{};

    while (!m_cards.empty() && numCards > 0) {
        stack.push_back(
            std::move(m_cards.front())
        );
        m_cards.pop_front();
        numCards--;
    }

    return stack;
}

Deck& CBJCards::Deck::cutFromTop()
{
    auto deck = new Deck();

    if (m_cards.empty()) return *deck;

    int half = m_cards.size() / 2;

    for (int i = 0; i < half; ++i) {
        deck->m_cards.push_back(
            std::move(m_cards.front())
        );
        m_cards.pop_front();
    }

    return *deck;
}

Deck& CBJCards::Deck::cutFromBottom()
{
    auto deck = new Deck();

    if (m_cards.empty()) return *deck;

    int half = m_cards.size() / 2;

    for (int i = 0; i < half; ++i) {
        deck->m_cards.push_front(
            std::move(m_cards.back())
        );
        m_cards.pop_back();
    }

    return *deck;
}

void CBJCards::Deck::shuffle()
{
    std::random_device randomDevice;
    std::mt19937 generator(randomDevice());

    std::shuffle(
        m_cards.begin(),
        m_cards.end(),
        generator
    );
}

void CBJCards::Deck::addCardTop(std::unique_ptr<Card> card)
{
    card->setFaceUp(false);
    m_cards.push_front(std::move(card));
}

void CBJCards::Deck::addCardBottom(std::unique_ptr<Card> card)
{
    card->setFaceUp(false);
    m_cards.push_back(std::move(card));
}

void CBJCards::Deck::addCardRandom(std::unique_ptr<Card> card)
{
    card->setFaceUp(false);

    std::random_device randomDevice;
    std::mt19937 generator(randomDevice());
    std::uniform_int_distribution<std::size_t> distribution(
        0,
        m_cards.size()
    );

    m_cards.insert(
        m_cards.begin() + distribution(generator),
        std::move(card)
    );
}

void CBJCards::Deck::addDeckTop(Deck& deck)
{
    while (!deck.empty()) {
        m_cards.push_front(std::move(deck.m_cards.back()));
        deck.m_cards.pop_back();
    }

    delete& deck;
}

void CBJCards::Deck::addDeckBottom(Deck& deck)
{
    while (!deck.empty()) {
        m_cards.push_back(std::move(deck.m_cards.front()));
        deck.m_cards.pop_front();
    }

    delete& deck;
}

Deck CBJCards::createStandardDeck(int numDecks, bool shuffle)
{
    Deck deck;

    if (numDecks < 1)
    {
        return deck;
    }

    for (int i = 0; i < numDecks; ++i)
    {
        for (const auto& suit : ALL_SUITS)
        {
            for (const auto& rank : ALL_RANKS)
            {
                deck.addCardBottom(
                    std::make_unique<Card>(suit, rank)
                );
            }
        }
    }

    if (shuffle)
    {
        deck.shuffle();
    }
}
