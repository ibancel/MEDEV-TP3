#include <vector>
#include <iostream>
#include <cstdlib>
#include "Go.h"
using namespace std;

// Classes cpp

void Goban :: affichage(){

    int i,j;

    for (i=0; i<taille;i++){
        for (j=0; j<taille;j++){
            cout<<plateau[i][j]->get_couleur()<<'\t';

        }
        cout<<endl;
    }


}


Groupe::Groupe(int c, int ddlib, coord position){

    couleur=c;
    nb_liberte=ddlib;
    pierres.push_back(position);


}


Goban::Goban(int t){

    taille=t;
    int i, j;
    coord pos;

    cout<<"bob";
    for (i=0; i<taille;i++){
        for (j=0; j<taille;j++){

            pos.x=i;
            pos.y=j;
            plateau[i][j]= new Groupe(0,4,pos);
            cout<<plateau[0][0]->get_couleur()<<endl;

        }

    }


}
