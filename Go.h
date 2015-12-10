#ifndef _H_GO
#define _H_GO

#include <vector>
#include <iostream>
#include <cstdlib>

using namespace std;

struct coord {
    int x;
    int y;

};

class Groupe {


private :

    int couleur; //0 vide; 1 blanc, 2 noir
    int nb_liberte;
    vector <coord> pierres;

public:


    int get_couleur () {return couleur;}
    int get_nb_liberte(){return nb_liberte;}
    vector <coord> get_pierres(){return pierres;}
    void add_coord(coord position){pierres.push_back(position);}

    //Fusion des Groupes
    void fusion(vector<Groupe*> environ, vector<vector<Groupe*> > plateau);

    //Constructeur
    Groupe(int c, int ddlib, coord position);


    };


class Goban {

private:

    int taille;
    vector<vector<Groupe*> >  plateau;

public :


    int get_taille(){return taille;};
    void affichage ();
    Goban (int t);
    vector<vector<Groupe*> > get_plateau(){return plateau;};

};



class Joueur {
    private:
        int couleur;//1 blanc, 2 noir
        int nb_captures;
        bool passe;

    public:
        void passer();
        void poser(vector<vector<Groupe*> >, int);

        int get_couleur(){return couleur;};
        int get_nb_captures(){return nb_captures;};
        bool get_passe(){return passe;};

        Joueur(int c);



};

#endif
