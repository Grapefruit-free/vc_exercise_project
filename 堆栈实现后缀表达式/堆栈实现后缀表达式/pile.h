#pragma once

typedef int T;

typedef struct noeud {
	T val;
	struct noeud* suiv;
}*Pile;

extern const Pile pilevide;
extern int estVide(const Pile);
extern T sommet(const Pile);
extern void empiler(Pile*, const T);
extern void depiler(Pile*);