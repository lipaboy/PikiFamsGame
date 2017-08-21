#ifndef GAMEBOT_H
#define GAMEBOT_H

#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>
#include <algorithm>

#include "GameCreator.h"
#include "lipaboyLibrary/src/intervals/interval.h"
#include "lipaboyLibrary/src/intervals/cutoffborders.h"
#include "lipaboyLibrary/src/common_interfaces/comparable.h"

namespace PikiFamsGameBot {

	using PikiFamsGame::GameCreator;
	using PikiFamsGame::DigitType;
	using PikiFamsGame::DigitArray;
	using PikiFamsGame::GameStepInfo;
	using PikiFamsGame::stepLength;

	using std::set;
	using std::vector;
	using std::unordered_set;

	using LipaboyLib::CloseInterval;
	using LipaboyLib::Comparable;

	typedef CloseInterval<int> PossibleResultInterval;
	
	//Special sets

	struct GameSet
	{
		GameSet(set<DigitType> _plenty = set<DigitType>(), uint32_t _value = 0)
			: plenty(_plenty), value(_value) {}
		set<DigitType> plenty;		//using set instead of unordered_set because in my program plenty has small size. It means the access is better than unordered_set's
		uint32_t value;		//count digits that precense into that set
	};

	//TODO: or may be use unordered_set??
	typedef vector<GameSet> WorldSet;

	struct GameSubSet {
		WorldSet::iterator baseIt;
		uint32_t size;
	};

	typedef vector<GameSubSet> StepStructure;

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
