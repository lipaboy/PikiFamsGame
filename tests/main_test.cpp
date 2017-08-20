#include "Test_hd.h"
#include <iostream>

using namespace std;
int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	return 0;
}