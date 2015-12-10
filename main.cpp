#include <iostream>
#include "gtest/gtest.h"

using namespace std;

int main(int argc, char **argv)
{

	::testing::InitGoogleTest(&argc, argv);


    return RUN_ALL_TESTS();
}

TEST(initialisation_test, plateau5_vide)
{
	Goban go = new Goban(5);
	EXPECT_EQ(5, go->get_taille());
	vector< vector<Groupe*> > plateau = go->get_plateau();

	for(int i = 0 ; i < 5 ; i++)
	{
		for(int j = 0 ; j < 5 ; j++)
		{
			SCOPED_TRACE(i << "x" << j);
			EXPECT_EQ(0, plateau[i][j].size());
		}
	}
}

TEST(initialisation_test, plateau9_vide)
{
	Goban go = new Goban(9);
	EXPECT_EQ(9, go->get_taille());
	vector< vector<Groupe*> > plateau = go->get_plateau();

	for(int i = 0 ; i < 9 ; i++)
	{
		for(int j = 0 ; j < 9 ; j++)
		{
			SCOPED_TRACE(i << "x" << j);
			EXPECT_EQ(0, plateau[i][j].size());
		}
	}
}
