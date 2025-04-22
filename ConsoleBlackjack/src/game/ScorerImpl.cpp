#include "ScorerImpl.h"

#include "Card.h"

using namespace CBJGame;

CBJGame::Scorer::Scorer(const ScoringStyle& style)
	: ScorerInterface{style}
{}

int CBJGame::Scorer::styledScore(const CBJCards::Hand& hand) const
{
	int score = 0;

	if (style() == ScoringStyle::TRADITIONAL_BLACKJACK)
	{
		int numAces = 0;

		for (int i = 0; i < hand.size(); ++i) {
			switch (hand.cards().at(i)->rank())
			{
			case CBJCards::Rank::ACE:
				numAces++;
				score++;
				break;
			case CBJCards::Rank::TWO:
				score += 2;
				break;
			case CBJCards::Rank::THREE:
				score += 3;
				break;
			case CBJCards::Rank::FOUR:
				score += 4;
				break;
			case CBJCards::Rank::FIVE:
				score += 5;
				break;
			case CBJCards::Rank::SIX:
				score += 6;
				break;
			case CBJCards::Rank::SEVEN:
				score += 7;
				break;
			case CBJCards::Rank::EIGHT:
				score += 8;
				break;
			case CBJCards::Rank::NINE:
				score += 9;
				break;
			case CBJCards::Rank::TEN:
				score += 10;
				break;
			case CBJCards::Rank::JACK:
				score += 10;
				break;
			case CBJCards::Rank::QUEEN:
				score += 10;
				break;
			case CBJCards::Rank::KING:
				score += 10;
				break;
			default:
				break;
			}
		}

		while (numAces > 0) {
			if (score <= 11) score += 10;
			numAces--;
		}
	} // Other ScoringStyle cases here

	return score;
}
