#ifndef _H_GOBAN
#define _H_GOBAN

#include <vector>

#include "Pierre.h"

using namespace std;

class Goban
{
public:
	Goban(int taille);

	void init(int taille);
	void jouer();

	vector< vector<Pierre*> > getCases() const { return cases; };

private:
	vector< vector<Pierre*> > cases;

};

#endif
