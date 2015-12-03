#ifndef _H_PIERRE
#define _H_PIERRE

enum Couleur{NOIR, BLANC};

class Pierre
{

public:
	Pierre(Couleur couleur);

	Couleur getCouleur() const { return couleur; };

private:
	Couleur couleur;
};

#endif
