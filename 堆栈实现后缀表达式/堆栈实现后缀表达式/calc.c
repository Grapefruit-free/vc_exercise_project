#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<ctype.h>
#include"pile.h"

int estUnEntier(const char* s) {
	if (*s == '\0') return 0;
	while (*s)
		if (!isdigit(*s++))return 0;
	return 1;
}
int estUnOperateur(const char* s) {
	return (*s == '+' || *s == '-' || *s == '*' || *s == '/');
}
void erreur(const char* s) {
	fprintf(stderr, "Erreur:%s\n", s);
	exit(EXIT_FAILURE);
}
int main(int argc , char* argv[]) {
	Pile p = pilevide;

	for (int i = 1; i < argc; i++) {
		if (estUnEntier(argv[i]))
			empiler(&p, atoi(argv[i]));
		else
			if (estUnOperateur(argv[i])) {
				int opD = sommet(p);depiler(&p);
				int opG = sommet(p);depiler(&p);
				switch (*argv[i]) {
				case'+':empiler(&p, opG + opD); break;
				case'-':empiler(&p, opG - opD); break;
				case'*':empiler(&p, opG * opD); break;
					if (opD == 0)erreur("Division par 0");
					empiler(&p, opG / opD); break;
				}
			}
			else
				erreur("Expression postfixee incorrecte");
	}
	if (!estVide(p)) {
		int res = sommet(p);
		depiler(&p);
		if (!estVide(p))erreur("Expression postfixee incorrecte");
		printf("res = %d\n", res);
		return EXIT_SUCCESS;
	}
}