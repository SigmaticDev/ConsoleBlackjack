#pragma once

#include "ScorerInterface.h"

namespace CBJGame {

	class Scorer : public CBJGame::ScorerInterface {
	public:
		Scorer(const ScoringStyle& style = ScoringStyle::TRADITIONAL_BLACKJACK);

		Scorer(const Scorer&) = delete;
		Scorer& operator=(const Scorer&) = delete;
		Scorer(Scorer&&) = delete;
		Scorer& operator=(Scorer&&) = delete;

	private:
		int styledScore(const CBJCards::Hand& hand) const override;
	};
}