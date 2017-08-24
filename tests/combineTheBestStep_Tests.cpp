#include "Test_hd.h"

#include "..\src\gamebot.h"

using PikiFamsGameBot::GameSet;
using PikiFamsGameBot::StepStructure;
using PikiFamsGameBot::WorldSet;

using PikiFamsGameBot::combineTheBestStep;

//--------------------Combine The Best Step Tests--------------------//

//These tests are separate on two groups : first group must be complete in the whole evolution of Game.
//Second one depends on only current algorithms for combining best step. It can be omit with new version.

TEST(TestCombineTheBestStep, first) {
	StepStructure stepStruct;
	//WorldSet - is vector
	WorldSet world({ 
		GameSet({1, 2, 3, 4}, 2),
		GameSet({ 5, 6, 7, 8 }, 1), 
		GameSet({ 0, 9 }, 1)
	});
	WorldSet::iterator it2 = world.begin() + 1;
	WorldSet::iterator it3 = world.begin() + 2;
	combineTheBestStep(world, stepStruct);
	//ASSERT_TRUE(set<WorldSet::iterator>({ stepStruct[0].baseIt, stepStruct[1].baseIt);
}


