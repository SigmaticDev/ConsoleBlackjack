#pragma once

#include "Card.h"
#include "Hand.h"

#include <memory>
#include <string>

namespace CBJGame {

	static const int PLAYER_NAME_MAX_LENGTH = 12;

	class Player {
	public:
		typedef std::unique_ptr<CBJCards::Card> CardPointer;
		typedef std::vector<CardPointer> CardPointerVector;

		Player();
		Player(std::string playerName);

		std::string name() const { return m_name; }
		const CBJCards::Hand& hand() const { return m_hand; }
		int chips() const { return m_chips; }
		
		void setName(std::string name);
		void drawCard(CardPointer card);
		CardPointerVector discardHand();

	private:
		std::string m_name;
		CBJCards::Hand m_hand;
		int m_chips;
	};
}