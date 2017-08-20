#ifndef GAMEBOT_H
#define GAMEBOT_H

#include <iostream>
#include <set>
#include <algorithm>

#include "GameCreator.h"
#include "lipaboyLibrary/src/intervals/interval.h"
#include "lipaboyLibrary/src/intervals/cutoffborders.h"
#include "lipaboyLibrary/src/common_interfaces/comparable.h"

namespace PikiFamsGameBot {

	using PikiFamsGame::GameCreator;
	using PikiFamsGame::DigitType;
	using PikiFamsGame::Array4Digits;
	using PikiFamsGame::GameStepInfo;
	using std::set;
	using LipaboyLib::CloseInterval;
	using LipaboyLib::cutOffLeftBorder;
	using LipaboyLib::Comparable;

	typedef CloseInterval<int> PossibleResultInterval;
	constexpr uint32_t stepLength = 4u;
	//Special sets

	//TODO: implement from Comparable
	class GameSet : public Comparable {
	public:
		GameSet(set<DigitType> _plenty = set<DigitType>(), uint32_t _value = 0)
			: plenty(_plenty), value(_value) {}

		bool operator<(const Comparable& other) const {
			return (value < dynamic_cast<const GameSet&>(other).value);
		}
		bool operator==(const Comparable& other) const {
			return (value == dynamic_cast<const GameSet&>(other).value);
		}

	public:
		set<DigitType> plenty;
		uint32_t value;		//count digits that precense into that set
	};

	//PossibleResultInterval isn't a real set
	inline PossibleResultInterval calculatePossibleResultSet(const GameSet& set1, const uint32_t subsetLength) { 
		return PossibleResultInterval(
			std::max<signed int>(0, static_cast<signed int>(set1.value - (set1.plenty.size() - subsetLength))),
			std::min<signed int>(set1.value, subsetLength)
		);
	}		// Using signed int is justified by correct calculation

	//return game step count
	uint32_t solveTheGame(GameCreator game);

}

#endif //GAMEBOT_H
