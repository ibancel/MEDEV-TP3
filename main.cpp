#include <iostream>
#include <vector>
#include <cstdlib>
#include "gtest/gtest.h"
#include "Go.h"

using namespace std;

int main(int argc, char **argv)
{

	::testing::InitGoogleTest(&argc, argv);
    coord coo;
    coo.x=2;
    coo.y=2;
    Goban go(5);
    go.affichage();
    Joueur P1(2);
    bool test = P1.poser(go.get_plateau(),2);
    go.get_plateau()[2][2]=new Groupe(4, 4, coo);
    go.affichage();

    return RUN_ALL_TESTS();
}

TEST(initialisation_test, plateau5_vide)
{
	Goban go(5);
	EXPECT_EQ(5, go.get_taille());
	vector< vector<Groupe*> > *plateau = go.get_plateau();

	for(int i = 0 ; i < 5 ; i++)
	{
		for(int j = 0 ; j < 5 ; j++)
		{
			string str = i + "x" + j;

			SCOPED_TRACE(str);
			EXPECT_EQ(0, (*plateau)[i][j]->get_couleur());
		}
	}
}

TEST(initialisation_test, plateau9_vide)
{
	Goban go(9);
	EXPECT_EQ(9, go.get_taille());
	vector< vector<Groupe*> > *plateau = go.get_plateau();

	for(int i = 0 ; i < 9 ; i++)
	{
		for(int j = 0 ; j < 9 ; j++)
		{
			string str = i + "x" + j;
			SCOPED_TRACE(str);
			EXPECT_EQ(0, (*plateau)[i][j]->get_couleur());
		}
	}
}
/*
TEST (methode_fusion, fusion_de_groupe){

    Goban go(5);
    Joueur joe(1);
    Joueur mary(2);

    joe.poser(go.get_plateau(),1); //1, 1
    mary.poser(go.get_plateau(),2);//0,1
    joe.poser(go.get_plateau(),1); //1,2
    mary.poser(go.get_plateau(),2); //4,4
    joe.poser(go.get_plateau(),1); //2,1
    mary.poser(go.get_plateau(),2); //4,5

    EXPECT_EQ(6,(*go.get_plateau())[1][1]->get_nb_liberte());


}
*/
