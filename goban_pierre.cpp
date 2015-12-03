#include <vector>
#include <iostream>
#include <cstdlib>
#include "Go.h"
// Classes cpp

void Goban :: affichage(){

    int i,j;

    for (i=0; i<taille;i++){
        for (j=0; j<taille;j++){
            cout<<Goban[i][j]->get_couleur()<<\t;

        }
        cout<<endl;
    }


}


Goban::Goban(int t){

    taille=t;

    for (i=0; i<taille;i++){
        for (j=0; j<taille;j++){
            Goban[i][j]=new Groupe(0);

        }

    }


}
