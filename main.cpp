#include <iostream>
#include "gtest/gtest.h"
#include "Goban.h"

using namespace std;


int main(int argc, char **argv)
{

	Goban* jeu = new Goban(5);

	::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
