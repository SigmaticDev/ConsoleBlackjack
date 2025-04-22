#include "ScorerInterface.h"

#include "ScorerImpl.h"

using namespace CBJGame;

ScorerInterface* CBJGame::instance = nullptr;

ScorerInterface* CBJGame::ScorerInterface::getScorer(
	const ScoringStyle& style
)
{
	static bool init = [](ScoringStyle style) {
		if (!instance) {
			static Scorer scorer(style);
			instance = &scorer;
		}
		return true;
	}(style);

	return instance;
}

CBJGame::ScorerInterface::ScorerInterface(const ScoringStyle& style)
	: m_style(style)
{}
