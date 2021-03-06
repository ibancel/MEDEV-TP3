#include <iostream>
#include <vector>
#include <cstdlib>
#include "gtest/gtest.h"
#include "Go.h"

using namespace std;

//Méthode pour passer
void Joueur::passer(){//permet de savoir que le joueur passe
    passe = true;
}

//Constructeur de la classe Joueur
Joueur::Joueur(int c){//initialisation d'un joueur
    couleur = c;
    nb_captures=0;
    passe=false;
}

//Méthode pour poser un pion
bool Joueur::poser(vector<vector<Groupe*> > *plateau, int c){
    int i,j;//coordonnée de pose
    bool aJoue=false;
    do{
        cout<<"Entrer les coordonnees ou vous voulez poser la pierre"<<endl;
        cout<< "x =";
        cin>>i;
        cout<<endl<<"y =";
        cin>>j;
        cout<<endl;
    }while ((i<0)||(j<0)||(i>=plateau->size())||(j>=plateau->size())); //Si les coordonnées entrées ne sont pas correctes, on redemande des coordonnées


    if ((*plateau)[i][j]->get_couleur() ==0){//la case est vide

        coord a;
        a.x=i;
        a.y=j;
        /*On compte les degrés de liberté de la nouvelle pierre :
        on regarde si les cases qui l'entoure sont occupées.*/
        int lib=4;
        if (i <= 0 || (*plateau)[i-1][j]-> get_couleur()!=0)
            lib--;
        if (j <= 0 || (*plateau)[i][j-1]->get_couleur()!=0)
            lib --;
        if (j >= (*plateau).size()-1 || (*plateau)[i][j+1]->get_couleur()!=0)
            lib--;
        if (i >= (*plateau).size()-1 || (*plateau)[i+1][j]->get_couleur()!=0)
            lib--;

        int cpt=lib; // cpt va compter les degrés de liberté de la pierre + groupes de pieces de la même couleur pour determiner si la pose est possible (il faut cpt>0)
        bool id= false;
        vector<Groupe*> liste;
        //on regarde les groupes que l'on va devoir fusionner
        if (i > 0 && (*plateau)[i-1][j]->get_couleur()==c)
            liste.push_back((*plateau)[i-1][j]);

        if (i < (*plateau).size()-1 && (*plateau)[i+1][j]->get_couleur()==c){
            id = false;

            //On vérifie que ce groupe n'a pas déjà été pris en compte
            for (int k=0;k<liste.size();k++)
            {
                id = id&&((*plateau)[i+1][j]==liste[k]);
            }
            if (!id){ // Si le groupe n'est pas encore dans la liste, on l'y ajoute
                liste.push_back((*plateau)[i+1][j]);
            }
        }

        if (j > 0 && (*plateau)[i][j-1]->get_couleur()==c){
            id =false;

            for (int k=0;k<liste.size();k++)
            {
                id = id&&((*plateau)[i][j-1]==liste[k]);
            }
            if (!id){
                liste.push_back((*plateau)[i][j-1]);

            }
        }
        if (j < (*plateau).size()-1 && (*plateau)[i][j+1]->get_couleur()==c){
            id = false;

            for (int k=0;k<liste.size();k++)
            {
                id = id&&((*plateau)[i][j+1]==liste[k]);
            }
            if (!id){
                liste.push_back((*plateau)[i][j+1]);

            }
        }


        //On compte le nombre de ddl global du groupe après fusion

        for (int k=0;k<liste.size();k++){
            cpt=cpt+liste[k]->get_nb_liberte()-1; //ne représente pas le nombre de liberté du groupe fusionné ! permet juste de savoir si on se suicide ou pas
            //si on se suicide ça veut dire que la pierre posée a 0 liberté et que les autres groupes de la meme couleur autour en ont 1 -> celui de la pierre posée. Donc cpt = 0 dans le cas suicide
            //comme c'est le seul cas qu'on veut testr c'est bon !
        }
        /*Remarque : cas du suicide.
        cpt fonctionne, car la pierre posée a 0 ddl, et les groupes aux alenours en ont chacun 1, qui est la case où l'on pose la nouvelle pierre.*/

       if(cpt!=0){//on peut poser la pierre


            (*plateau)[i][j]=(new Groupe (c,lib,a)); //On créé un nouveau groupe, celui de la nouvelle pierre
            (*plateau)[i][j]->fusion(liste,*plateau); //On fusionne les groupes de la même couleur qui sont autour (s'il y en a)
            aJoue=true;
        }


    }
    else
        cout<<"coup impossible!"<<endl;

    return aJoue;
}

void Joueur::capture(vector<vector<Groupe*> > *plateau, coord a){//fonction qui vérifie si on capture des pieces et si oui, les supprimes et met a jour le nombre de pieces capturées

    vector<Groupe*> liste;
    bool id;

    //on ajoute les gorupes de couleur opposée à la liste des groupes à tester
    if ((a.x>0)&&((*plateau)[a.x-1][a.y]->get_couleur()!=couleur)&&(*plateau)[a.x-1][a.y]->get_couleur()!=0)
        liste.push_back((*plateau)[a.x-1][a.y]);

    if (a.x < (*plateau).size()-1 && (*plateau)[a.x+1][a.y]->get_couleur()!=couleur &&(*plateau)[a.x+1][a.y]->get_couleur()!=0){
        id = false;

        for (int k=0;k<liste.size();k++)
        {
            id = id&&((*plateau)[a.x+1][a.y]==liste[k]);
        }
        if (!id){
            liste.push_back((*plateau)[a.x+1][a.y]);
        }
    }
    if (a.y > 0 && (*plateau)[a.x][a.y-1]->get_couleur()!=couleur&&(*plateau)[a.x][a.y-1]->get_couleur()!=0){
        id =false;

        for (int k=0;k<liste.size();k++)
        {
            id = id&&((*plateau)[a.x][a.y-1]==liste[k]);
        }
        if (!id){
            liste.push_back((*plateau)[a.x][a.y-1]);

        }
    }
    if (a.y < (*plateau).size()-1 && (*plateau)[a.x][a.y+1]->get_couleur()!=couleur&&(*plateau)[a.x][a.y+1]->get_couleur()!=0){
        id = false;

        for (int k=0;k<liste.size();k++)
        {
            id = id&&((*plateau)[a.x][a.y+1]==liste[k]);
        }
        if (!id){
            liste.push_back((*plateau)[a.x][a.y+1]);

        }
    }

    vector<coord> pierres;
    for (int i=0;i<liste.size();i++)
    {
        if(liste[i]->get_nb_liberte() <= 1){//le groupe est capturé !

            pierres=liste[i]->get_pierres();
            nb_captures+=pierres.size();

            for (int k=0;k<pierres.size();k++){
                coord a = pierres[k];
                (*plateau)[a.x][a.y]=new Groupe (0,0,a);
            }


        }

    }



}
