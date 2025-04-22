#pragma once

#include "Hand.h"

namespace CBJGame {

	enum class ScoringStyle {
		TRADITIONAL_BLACKJACK,
	};

	class ScorerInterface {
	public:
		virtual ~ScorerInterface() = default;

		static ScorerInterface* getScorer(
			const ScoringStyle& style = ScoringStyle::TRADITIONAL_BLACKJACK
		);

		int score(const CBJCards::Hand& hand) const {
			return styledScore(hand);
		}

	protected:
		ScorerInterface(const ScoringStyle& style);

		ScoringStyle style() const { return m_style; }
		void setStyle(const ScoringStyle& style) { m_style = style; }

	private:
		virtual int styledScore(const CBJCards::Hand& hand) const = 0;

		ScoringStyle m_style;
	};

	extern ScorerInterface* instance;
}