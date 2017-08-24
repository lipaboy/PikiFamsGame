#ifndef GAMEBOT_H
#define GAMEBOT_H

#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <iterator>

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
	
	//--------------------------Special structs---------------------------//

	typedef CloseInterval<int> PossibleResultInterval;

	inline PossibleResultInterval operator+(const PossibleResultInterval& first,
											const PossibleResultInterval& second) {
		return PossibleResultInterval(first.left() + second.left(), first.right() + second.right());
	}

	//using set instead of unordered_set because in my program plenty has small size. 
	//It means the access is better than unordered_set's
	typedef set<DigitType> DigitSet;

	//TODO: may be add typedef for set<DigitType>
	struct GameSet
	{
		GameSet(const DigitSet& _plenty = DigitSet(), uint32_t _value = 0)
			: plenty(_plenty), value(_value) {}
		DigitSet plenty;
		uint32_t value;		//count digits that precense into that set
	};

	//TODO: or may be use unordered_set??
	typedef vector<GameSet> WorldSet;

	struct GameSubSet {
		WorldSet::const_iterator baseIt;
		uint32_t size;
	};

	typedef vector<GameSubSet> StepStructure;

	struct SolvingInfo {
		DigitSet guessedNumber;
		uint32_t stepCount;
	};

	//--------------------------Functions---------------------------//

	//PossibleResultInterval isn't a real set
	inline PossibleResultInterval calculatePossibleResultSet(const GameSet& set1, 
															 const uint32_t subsetLength) { 
		return PossibleResultInterval(
			std::max<signed int>(0, static_cast<signed int>(set1.value - (set1.plenty.size() - subsetLength))),
			std::min<signed int>(set1.value, subsetLength)
		);
	}		// Using signed int is justified by correct calculation

	template <class... Args>
	inline PossibleResultInterval calculatePossibleResultSet(const GameSet& set1,
															 const uint32_t subsetLength, Args... args) {
		return calculatePossibleResultSet(set1, subsetLength) + calculatePossibleResultSet2(args...);
	}

	//template <class... Args>
	//bool containsAll(T element, Args... args) { return contains(element) && containsAll(args...); }

	void combineTheBestStep(const WorldSet& world, StepStructure & stepStructure);

	GameSet calculateResidue(const WorldSet& world, const GameSet& step, 
		const StepStructure& stepStructure);

	void updateWorld(WorldSet& world, const GameSet& step, 
		const StepStructure& stepStructure, const GameSet& residue);

	//return game step count
	SolvingInfo solveTheGame(GameCreator game);

}

#endif //GAMEBOT_H
