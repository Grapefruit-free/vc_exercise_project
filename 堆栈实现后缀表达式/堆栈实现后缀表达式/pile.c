#include<assert.h>
#include<stdlib.h>
#include"pile.h"

/*
typedef struct noeud {
	T val;
	struct noeud* suiv;
}*Pile;
*/

const Pile pilevide = NULL;

int estVide(const Pile p) {
	return p == pilevide;
}

T sommet(const Pile p) {
	assert(!estVide(p));
	return p->val;
}

void empiler(Pile* p, const T e) {
	struct noeud* n = malloc(sizeof(struct noeud));
	n->val = e;
	n->suiv = *p;
	*p = n;
}

void depiler(Pile* p) {
	assert(!estVide(*p));
	struct noeud* n = *p;
	*p = (*p)->suiv;
	free(n);
}

