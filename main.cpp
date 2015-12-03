#include <iostream>
#include <pthread.h>
#include "gtest/gtest.h"

using namespace std;

int factorielle(int n)
{
	if(n < 0)
		return -1;

	if(n<=0)
		return -1;

	return n*factorielle(n-1);
}

int main(int argc, char **argv)
{
    cout << factorielle(3) << endl;
	::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

TEST(factorielle, GereLeZero)
{
	EXPECT_EQ(1, factorielle(0));
}

TEST(factorielle_test , GereLesValeursPositives)
{
	EXPECT_EQ(1, factorielle (1));
	EXPECT_EQ(2, factorielle (2));
	EXPECT_EQ(6, factorielle (3));
	EXPECT_EQ (40320 , factorielle (8));
}
