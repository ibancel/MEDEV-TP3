#include <iostream>
#include <vector>
#include <cstdlib>
#include "gtest/gtest.h"
#include "Go.h"

#ifdef __unix__
#define CLEAR "clear"
#endif
#ifdef __windows__
#define CLEAR "cls"
#endif

using namespace std;



int main(int argc, char **argv)
{

	::testing::InitGoogleTest(&argc, argv);

	int choix;
	cout << "Bienvenue dans le jeu de GO !" << endl << "1- Plateau 5x5" << endl << "2- Plateau 9x9" << endl << "> ";
	cin >> choix;

	// uniquement plateau 5x5 ou 9x9
	choix = (choix==1?5:9);
	system(CLEAR);

	Goban go(choix);

	Joueur jb(1); // joueur blanc
	Joueur jn(2); // joueur noir

	go.affichage();

	while(!jb.get_passe() && !jn.get_passe())
	{
		cout << "Joueur blanc : ";
		jb.poser(go.get_plateau(), jb.get_couleur());
		system(CLEAR);
		go.affichage();

		cout << "Joueur noir : ";
		jn.poser(go.get_plateau(), jn.get_couleur());
		system(CLEAR);
		go.affichage();
	}

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




TEST(capture,capture)
{

    Goban go(5);
    vector<vector<Groupe*> > *plateau= go.get_plateau();
    coord a;
    a.x=1;
    a.y=0;
    coord b;
    b.x=0;
    b.y=1;
    coord c;
    c.x=0;
    c.y=0;
    Joueur P(1);
    (*plateau)[1][0]=new Groupe (1,3,a);
    (*plateau)[0][0]= new Groupe (2,1,c);
    (*plateau)[0][1]=new Groupe (1,2,b);

    P.capture(plateau,b);
    EXPECT_EQ(1,P.get_nb_captures());
    EXPECT_EQ(0,(*plateau)[0][0]->get_couleur());


}

