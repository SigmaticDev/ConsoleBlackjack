// ConsoleBlackjack.cpp : Defines the entry point for the application.
//

#include "Main.h"

#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "ScorerInterface.h"
#include "StyledChar.h"

#include <vector>
#include <Windows.h>

#include <string>

using namespace std;
using namespace CBJCards;
using namespace CBJDisplay;

int main()
{
	/*SetConsoleOutputCP(65001);

	setvbuf(stdout, nullptr, _IOFBF, 1000);*/

	const char* suits = "\x06\x05\x04\x03";

	cout << "huh" << endl;

	cout << "Hello CMake." << suits << endl;

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(
		hConsole,
		FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | 
		FOREGROUND_INTENSITY);

	cout << "TESTING" << endl;

	auto fgRed = ConsoleColor("RED", true);
    auto fgGreen = ConsoleColor("GREEN", true);
    auto fgBlue = ConsoleColor("BLUE", true);

    auto bgRed = ConsoleColor("RED", false);
    auto bgGreen = ConsoleColor("GREEN", false);
    auto bgBlue = ConsoleColor("BLUE", false);

	vector<StyledChar> styledChars;

    styledChars.push_back(StyledChar('A', fgRed, bgBlue));
    styledChars.push_back(StyledChar('B', fgGreen, bgRed));
    styledChars.push_back(StyledChar('C', fgBlue, bgGreen));
    styledChars.push_back(StyledChar('D', fgRed, bgBlue));
    styledChars.push_back(StyledChar('E', fgGreen, bgRed));
    styledChars.push_back(StyledChar('F', fgBlue, bgGreen));

    for (auto& sc : styledChars) {
        cout << sc;
        cout << "X";
    }
    cout << endl;

    Hand hand;

    hand.addCard(std::make_unique<Card>(Card(Suit::SPADES, Rank::ACE)));
    hand.addCard(std::make_unique<Card>(Card(Suit::DIAMONDS, Rank::TWO)));
    hand.addCard(std::make_unique<Card>(Card(Suit::DIAMONDS, Rank::ACE)));

    auto& handCards = hand.cards();

    cout << handCards[0]->toString() << endl;
    cout << handCards[1]->toString() << endl;
    cout << handCards[2]->toString() << endl;

    auto scorer = CBJGame::ScorerInterface::getScorer();

    auto score = scorer->score(hand);

    cout << "Score = " << score << endl << endl;

    auto deck = Deck();

    deck.addCardTop(std::make_unique<Card>(Card(Suit::CLUBS, Rank::TEN)));
    deck.addCardTop(std::make_unique<Card>(Card(Suit::CLUBS, Rank::NINE)));
    deck.addCardTop(std::make_unique<Card>(Card(Suit::CLUBS, Rank::EIGHT)));
    deck.addCardTop(std::make_unique<Card>(Card(Suit::SPADES, Rank::ACE)));

    deck.shuffle();

    cout << "First card off deck: " << deck.draw()->toString() << endl;
    cout << "Second card off deck: " << deck.draw()->toString() << endl;
    cout << "Third card off deck: " << deck.draw()->toString() << endl;
    cout << "Fourth card off deck: " << deck.draw()->toString() << endl;

	return 0;
}
