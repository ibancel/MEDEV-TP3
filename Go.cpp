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

void Groupe::fusion(vector<Groupe*> environ, vector<vector<Groupe*> > plateau){
    int s;
    s=environ.size();
    int taille_gpe;
    int i,j;

    if (s>0){ //Au moins un groupe à fusionner
        for (i=0; i<s;i++){ //Pour chaque groupe environnant
            nb_liberte=nb_liberte+environ[i]->get_nb_liberte();

            taille_gpe=environ[i]->get_pierres().size();

            for(j=0;j<taille_gpe;j++){ //On ajoute les pierres dans le premier groupe
                pierres.push_back(environ[i]->get_pierres()[j]);
            }

        }

    //On enlève des ddl pour les pierres adjacentes (et de mêm couleur) à la nouvelle pierre
    //Coordonnées de la pierre posée (nouvelle)
    int coox=pierres[0].x;
    int cooy=pierres[0].y;
    //On compte le nbe de ddl à retirer
    if (plateau[coox-1][cooy]-> get_couleur()==couleur)
            nb_liberte--;
    if (plateau[coox][cooy-1]->get_couleur()==couleur)
            nb_liberte--;
    if (plateau[coox][cooy+1]->get_couleur()==couleur)
            nb_liberte--;
    if (plateau[coox+1][cooy]->get_couleur()==couleur)
            nb_liberte--;
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
    pos.x=0;
    pos.y=0;


    Groupe* gp= new Groupe(0,4,pos);
    vector <Groupe*> liste(t, gp);
    vector < vector<Groupe*> > bob(t, liste);
    plateau= bob;

    /*for (i=0; i<taille;i++){ //Mise à jour des positions des pierres
        for (j=0; j<taille;j++){

            pos.x=i;
            pos.y=j;
            plateau[i][j]->get_pierres[0].x=i;
            plateau[i][j]->get_pierres[0].y=i;
        }

    }*/


}
