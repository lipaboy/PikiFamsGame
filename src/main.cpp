#include <iostream>

#include "GameCreator.h"
#include "gamebot.h"

using namespace PikiFamsGame;
using namespace PikiFamsGameBot;

int main(void) {
	using std::cout;
	using std::endl;

	GameCreator game({ 1, 2, 3, 4 });
	GameCreator game2;

    //--------------------Game Bot Try----------------------------//

    //solveTheGame(game);

	//cout << info.piki << "piki " << info.fams << "fams" << endl;

    //--------------------User mode----------------------------//

    DigitArray userStep;
    for ( ; ; ) {
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

	return 0;
}
