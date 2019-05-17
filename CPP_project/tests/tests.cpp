#include <iostream>

#define TEST_MODE
//#define LIPABOY_MODE

#ifdef TEST_MODE
#include "Test_hd.h"
#else

#ifdef LIPABOY_MODE
#include "src\lipaboyLibrary\src\lipaboy_test.h"
#else
#include "src\GameCreator.h"
#include "src\gamebot.h"

using namespace PikiFamsGame;
using namespace PikiFamsGameBot;
#endif

#endif


//using namespace std;

int main(int argc, char *argv[])
{
#ifdef TEST_MODE
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	system("pause");
#else

#ifdef LIPABOY_MODE
	LipaboyLib::lipaboyMain();
#else
	using std::cout;
	using std::endl;

	GameCreator game({ 1, 2, 3, 4 });
	GameCreator game2;

	//--------------------Game Bot Try----------------------------//

	//solveTheGame(game);

	//cout << info.piki << "piki " << info.fams << "fams" << endl;

	//--------------------User mode----------------------------//

	DigitArray userStep;
	for (; ; ) {
		cout << "Enter the number: ";
		DigitArray::iterator it;
		for (it = userStep.begin(); it != userStep.end(); it++) {
			std::cin >> *it;
		}
		GameStepInfo info = game2.guess(userStep);
		cout << info.piki << "p " << info.fams << "f " << endl;
		if (info.piki >= 4 || userStep[0] == userStep[1])
			break;
	}

#endif

#endif

	return 0;
}