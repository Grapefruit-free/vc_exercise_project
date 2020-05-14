#include<stdio.h>
#include<stdlib.h>

#define USAGE "Usage: calc int op int"

int estUnEntier(char* s) {
	return 1;
}
int estUnOperateur(char* s) {
	return 1;
}
int main(int argc, char* argv[]) {
	if (argc != 4) {
		fprintf(stderr, "%s\n", USAGE);
		return EXIT_FAILURE;
	}
	if (!estUnEntier(argv[1])) {
		fprintf(stderr, "%s: entier attendu\n", argv[1]);
		return EXIT_FAILURE;
	}
	if (!estUnEntier(argv[3])) {
		fprintf(stderr, "%s: entier attendu\n", argv[3]);
	}
	if (!estUnOperateur(argv[2])) {
		fprintf(stderr, "%s: op¨¦rateur + - * / attendu \n", argv[2]);
		return EXIT_FAILURE;
	}
	int res = 0, opG = atoi(argv[1]), opD = atoi(argv[3]);
	switch (*argv[2]) {
	case'+':res = opG + opD; break;
	case'-':res = opG - opD; break;
	case'*':res = opG * opD; break;
	case'/':if (opD == 0) {
		fprintf(stderr, "division par 0\n");
		return EXIT_FAILURE;
	}
		   res = opG / opD;
		   break;
	}
	printf("%d %c %d = %d", opG, *argv[2], opD, res);
	return EXIT_SUCCESS;
}