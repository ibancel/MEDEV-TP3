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

bool poser(vector<vector<Groupe*> > plateau, int c){
    int i,j;//coordonnée de pose
    bool aJoue=false;

    cout<<"Entrer les coordonnees ou vous voulez poser la pierre"<<endl;
    cout<< "x =";
    cin>>i;
    cout<<endl<<"y =";
    cin>>j;
    cout<<endl;

    if (plateau[i][j]->get_couleur() ==0){//la case est vide

        coord a;
        a.x=i;
        a.y=j;
        //on compte les degrés de liberté de la nouvelle pierre
        int lib=4;
        if (plateau[i-1][j]-> get_couleur()!=0)
            lib--;
        if (plateau[i][j-1]->get_couleur()!=0)
            lib --;
        if (plateau[i][j+1]->get_couleur()!=0)
            lib--;
        if (plateau[i+1][j]->get_couleur()!=0)
            lib--;

        int cpt=lib; // cpt va compter les degrés de liberté de la pierre + groupes de pieces dce la même couleur pour determiner si la pose est possible
        bool id= false;
        vector<Groupe*> liste;
        //on regarde les groupes que l'on va devoir fusionner
        if (plateau[i-1][j]->get_couleur()==c)
            liste.push_back(plateau[i-1][j]);
        if (plateau[i+1][j]->get_couleur()==c){
            id = false;

            for (int k=0;k<liste.size();k++)
            {
                id = (plateau[i+1][j]==liste[k]);
            }
            if (!id){
                liste.push_back(plateau[i+1][j]);
            }
        }

        if (plateau[i][j-1]->get_couleur()==c){
            id =false;

            for (int k=0;k<liste.size();k++)
            {
                id = (plateau[i][j-1]==liste[k]);
            }
            if (!id){
                liste.push_back(plateau[i-1][j]);

            }
        }
        if (plateau[i][j+1]->get_couleur()==c){
            id = false;

            for (int k=0;k<liste.size();k++)
            {
                id = (plateau[i][j+1]==liste[k]);
            }
            if (!id){
                liste.push_back(plateau[i][j+1]);

            }
        }
        //on compte le nombre de liberté de la pierre considérée comme fusionnée avec les groupes alentours
        for (int k=0;k<liste.size();k++){
            cpt=cpt+liste[k]->get_nb_liberte()-1;
        }


       if(cpt!=0){//on peut poser la pierre

            plateau[i][j]=(new Groupe (c,lib,a));
          //  plateau[i][j]->fusion(lib,liste,plateau);
            aJoue=true;
        }


    }
    else
        cout<<"coup impossible!"<<endl;

    return aJoue;
}
