#include <vector>
#include <iostream>
#include <cstdlib>
#include "Go.h"
using namespace std;

//Méthode d'affichage du plateau de jeu
void Goban :: affichage(){

    int i,j;

    /*On parcourt le plateau et on affiche pour chaque case la couleur présente dessus
    0 pour une case vide, 1 pour un pion blanc et 2 pour un noir*/
    for (i=0; i<taille;i++){
        for (j=0; j<taille;j++){
            cout<<plateau[i][j]->get_couleur()<<'\t';

        }
        cout<<endl;
    }


}

//Méthode de fusion de plusieurs groupes
void Groupe::fusion(vector<Groupe*> environ, vector<vector<Groupe*> > plateau){
    int s;
    s=environ.size(); //Nombre de groupes environnant le piçon qui vient d'être posé
    int taille_gpe;
    int i,j;

    if (s>0){ //Au moins un groupe à fusionner
        for (i=0; i<s;i++){ //Pour chaque groupe environnant
            nb_liberte=nb_liberte+environ[i]->get_nb_liberte(); //On met à jour le nombre de libertés

            taille_gpe=environ[i]->get_pierres().size();

            for(j=0;j<taille_gpe;j++){ //On ajoute les pierres dans le premier groupe
                pierres.push_back(environ[i]->get_pierres()[j]);
            }

        }

    //On enlève des ddl pour les pierres adjacentes (et de même couleur) à la nouvelle pierre
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

//Constructeur d'un groupe
Groupe::Groupe(int c, int ddlib, coord position){

    couleur=c;
    nb_liberte=ddlib;
    pierres.push_back(position);


}

//Constructeur du Goban (le plateau de jeu)
Goban::Goban(int t){

    taille=t;
    int i, j;
    coord pos;
    pos.x=0;
    pos.y=0;

    //On construit et remplit le plateau de groupes de couleur 0 (vide)
    /*Par défault on instancie les positions contenues dans les groupes à (0,0),
    car ces groupes ne sont que provisoires, ils vont être écrasés dèq qu'on pose un pion de couleur 1 ou 2*/
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

//Surchage de l'opérateur == pour coord
bool operator==(coord c1, coord c2)
{
	if(c1.x == c2.x && c1.y == c2.y)
		return true;

	return false;
}


int nombre_ddl (Groupe bob, vector<vector<Groupe*> > go){

    int nombre_pier=0;
    nombre_pier=bob.get_pierres().size();
    vector<coord> case_comptee;
    int i;
    int j;
    bool deja_present=false;
    coord case_ajoutee;

    for(i=0; i<nombre_pier; i++){

        coord case_active=bob.get_pierres()[i];

//-------------------------------------------------------------------------------------------
//Check la case du dessus

        if (go[case_active.x+1][case_active.y]->get_couleur()==0 && case_active.x+1<go.size()){
                for (j=0; j<case_comptee.size() ; j++){
                    if (case_active.x+1==case_comptee[j].x && case_active.y==case_comptee[j].y){
                        deja_present=true;
                    }

                }
                if (!deja_present){
                    case_ajoutee.x= case_active.x+1;
                    case_ajoutee.y=case_active.y;
                    case_comptee.push_back(case_ajoutee);
                }

        }

        deja_present=false;




//-------------------------------------------------------------------------------------------
//Check la case du dessous
        if (go[case_active.x-1][case_active.y]->get_couleur()==0 && case_active.x-1>=0){
                for (j=0; j<case_comptee.size() ; j++){
                    if (case_active.x-1==case_comptee[j].x && case_active.y==case_comptee[j].y){
                        deja_present=true;
                    }

                }
                if (!deja_present){
                    case_ajoutee.x= case_active.x-1;
                    case_ajoutee.y=case_active.y;
                    case_comptee.push_back(case_ajoutee);
                }

        }

        deja_present=false;



//-------------------------------------------------------------------------------------------
//Check la case de droite
        if (go[case_active.x][case_active.y+1]->get_couleur()==0 && case_active.y+1<go.size()){
                for (j=0; j<case_comptee.size() ; j++){
                    if (case_active.x==case_comptee[j].x && case_active.y+1==case_comptee[j].y){
                        deja_present=true;
                    }

                }
                if (!deja_present){
                    case_ajoutee.x= case_active.x;
                    case_ajoutee.y=case_active.y+1;
                    case_comptee.push_back(case_ajoutee);
                }

        }

        deja_present=false;




//-------------------------------------------------------------------------------------------
//Check la case de gauche
        if (go[case_active.x][case_active.y-1]->get_couleur()==0 && case_active.y-1>=0){
                for (j=0; j<case_comptee.size() ; j++){
                    if (case_active.x==case_comptee[j].x && case_active.y-1==case_comptee[j].y){
                        deja_present=true;
                    }

                }
                if (!deja_present){
                    case_ajoutee.x= case_active.x;
                    case_ajoutee.y=case_active.y-1;
                    case_comptee.push_back(case_ajoutee);
                }

        }

        deja_present=false;


    }

    return case_comptee.size();

};
