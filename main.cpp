#include <iostream>

//#define TEST_MODE
//#define LIPABOY_MODE

#ifdef TEST_MODE
#include "tests\Test_hd.h"
#else

#ifdef LIPABOY_MODE
#include "src\lipaboyLibrary\src\lipaboy_test.h"
#else
#include "src\GameCreator.h"
#include "src\gamebot.h"

using namespace PikiFamsGame;
using namespace PikiFamsGameBot;
using namespace std;
std::vector<int> getVect() { std::vector<int> vec({ 1, 2, 3 }); return std::move(vec); }

class DumbArray {
public:
	DumbArray(size_t _size = 0) : array1( (!_size) ? nullptr : new int[_size] ), size(_size) {}
	DumbArray(DumbArray && other) : DumbArray() { swap(*this, other); }
	DumbArray(const DumbArray & other) 
		: size(other.size), array1(other.size ? new int[other.size] : nullptr) 
	{ 
		memcpy(array1, other.array1, other.size * sizeof(array1));
		
	}

	DumbArray & operator= (DumbArray other) {
		swap(*this, other);
		return *this;
	}

	friend void swap(DumbArray & first, DumbArray & second) {
		using std::swap;
		swap(first.size, second.size);
		swap(first.array1, second.array1);
		std::cout << "Right swap" << std::endl;
	}

	~DumbArray() { if (size > 0) delete array1; }
private:
	int * array1;
	size_t size;
};

#endif

#endif


int main(int argc, char *argv[])
{
#ifdef TEST_MODE
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
#else

#ifdef LIPABOY_MODE
	LipaboyLib::lipaboyMain();
#else
	using std::cout;
	using std::endl;

	GameCreator game({ 1, 2, 3, 4 });
	GameCreator game2;

	DumbArray dumb(3);
	DumbArray dumb2;
	dumb2 = dumb;


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