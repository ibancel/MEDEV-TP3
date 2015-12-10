#include <iostream>
#include <vector>
#include <cstdlib>
#include "gtest/gtest.h"
#include "Go.h"

using namespace std;

void Joueur::passer(){//permet de savoir que le joueur passe
    passe = true;
}

Joueur::Joueur(int c){//initialisation d'un joueur
    couleur = c;
    nb_captures=0;
    passe=false;
}

/*void poser(vector<vector<Groupe*> > plateau, int c){
    int i,j;//coordonnée de pose

    cout<<"Entrer les coordonnees ou vous voulez poser la pierre"<<endl;
    cout<< "x =";
    cin>>i;
    cout<<endl<<"y =";
    cin>>j;
    cout<<endl;

    if (plateau[i][j]->get_couleur() ==0){//la case est vide
        plateau[i][j]=(new )


    }


}*/
