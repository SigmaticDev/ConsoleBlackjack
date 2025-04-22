#include "Player.h"

using namespace CBJGame;

CBJGame::Player::Player()
	: m_name("unnamed")
	, m_hand()
	, m_chips(0)
{}

CBJGame::Player::Player(std::string playerName)
	: m_name(
		(playerName.length() > 0
			&& playerName.length() <= PLAYER_NAME_MAX_LENGTH)
		? playerName : "unnamed")
	, m_hand()
	, m_chips(0)
{}

void CBJGame::Player::setName(std::string name)
{
	if (name.length() > 0 && 
		name.length() <= PLAYER_NAME_MAX_LENGTH) {
		m_name = name;
	}
}

void CBJGame::Player::drawCard(CardPointer card)
{
	m_hand.addCard(std::move(card));
}

Player::CardPointerVector CBJGame::Player::discardHand()
{
	CardPointerVector cards = CardPointerVector();

	while (!m_hand.empty()) {
		cards.push_back(std::move(m_hand.removeCard(0)));
	}

	return cards;
}
