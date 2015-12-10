#include <iostream>
#include <vector>
#include <cstdlib>
#include "gtest/gtest.h"
#include "Go.h"

using namespace std;

int main(int argc, char **argv)
{

	::testing::InitGoogleTest(&argc, argv);

    Goban go(5);
    go.affichage();
    Joueur P1(1);
    bool test = P1.poser(go.get_plateau(),1);
    go.affichage();

    return RUN_ALL_TESTS();
}

TEST(initialisation_test, plateau5_vide)
{
	Goban go(5);
	EXPECT_EQ(5, go.get_taille());
	vector< vector<Groupe*> > plateau = go.get_plateau();

	for(int i = 0 ; i < 5 ; i++)
	{
		for(int j = 0 ; j < 5 ; j++)
		{
			string str = i + "x" + j;

			SCOPED_TRACE(str);
			EXPECT_EQ(0, plateau[i][j]->get_couleur());
		}
	}
}

TEST(initialisation_test, plateau9_vide)
{
	Goban go(9);
	EXPECT_EQ(9, go.get_taille());
	vector< vector<Groupe*> > plateau = go.get_plateau();

	for(int i = 0 ; i < 9 ; i++)
	{
		for(int j = 0 ; j < 9 ; j++)
		{
			string str = i + "x" + j;
			SCOPED_TRACE(str);
			EXPECT_EQ(0, plateau[i][j]->get_couleur());
		}
	}
}
