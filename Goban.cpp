#include <iostream>

#include "Goban.h"

using namespace std;


Goban::Goban(int taille)
{
	init(taille);
}

void Goban::init(int taille)
{
	cases.resize(taille);
	for(int i = 0 ; i < taille ; i++)
		cases[i].resize(taille, NULL);
}


void Goban::jouer()
{

}
