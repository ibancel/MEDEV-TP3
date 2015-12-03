#include <vector>
#include <iostream>
#include <cstdlib>


class Goban {

private:

    int taille;
    vector <vector<Groupe*> > plateau;

public :

    int get_taille(){return taille;};
    void affichage ();
    Goban (int t);

};


class Groupe {


private :

    int couleur; //0 vide; 1 blanc, 2 noir
    int nb_liberte;
    vector <coord> pierres;

public:


    int get_couleur () {return couleur;};
    int get_nb_liberte(){return nb_liberte;};
    vector <coord> get_pierres(){return pierres;}

};



class Joueur {
    private:
        int couleur;
        int nb_captures;
        bool passe;

    public:
        void passer();
        void poser();

        int get_couleur(){return couleur;};
        int get_nb_captures(){return nb_capture;};
        bool get_passe(){return passe;};

        Joueur(int c);



}

struct coord {
    int x;
    int y;

}




