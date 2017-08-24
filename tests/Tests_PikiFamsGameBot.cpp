#include "Test_hd.h"

#include "..\src\gamebot.h"
#include "..\src\lipaboyLibrary\src\intervals\interval.h"

#include <set>

using std::set;

using PikiFamsGameBot::GameSet;

using PikiFamsGameBot::calculatePossibleResultSet;
using PikiFamsGameBot::PossibleResultInterval;

using namespace LipaboyLib;

//TODO: add TEST_VALUE

//TODO: add class for these tests

class TestCalculatePossibleResultSet_QuatroSet : public ::testing::Test {
protected:
	bool check_QuatroSet(int subsetLength, const PossibleResultInterval& interval) {
		return (calculatePossibleResultSet(quatroSet, subsetLength) == interval);
	}

protected:
	GameSet quatroSet = GameSet(set<uint32_t>({ 1, 2, 3, 4 }), 2);
};

TEST_F(TestCalculatePossibleResultSet_QuatroSet, first) {
	ASSERT_TRUE(check_QuatroSet(1, PossibleResultInterval(0, 1)));
}

TEST_F(TestCalculatePossibleResultSet_QuatroSet, second) {
	ASSERT_TRUE(check_QuatroSet(2, PossibleResultInterval(0, 2)));
}

TEST_F(TestCalculatePossibleResultSet_QuatroSet, third) {
	ASSERT_TRUE(check_QuatroSet(3, PossibleResultInterval(1, 2)));
}

TEST_F(TestCalculatePossibleResultSet_QuatroSet, fourth) {
	ASSERT_TRUE(check_QuatroSet(4, PossibleResultInterval(2, 2)));
}


/*---For intervals---*/

TEST(TestInterval, operatorEqual) {
	Interval<int, std::less<int>, std::less<int> > interval1(0, 1);
	Interval<int, std::less<int>, std::less<int> > interval2(0, 1);
	ASSERT_EQ(interval1 == interval2, true);
}
