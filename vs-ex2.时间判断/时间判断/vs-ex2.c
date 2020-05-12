#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define ANNEEMIN 1583

typedef struct {
    int jour, mois, annee;
    char nomDuMois[10];
}Date;

typedef struct {
    char nomDuMois[10];
    int nbJours;
}Mois;

Mois lesMois[12] = { {"janvier",31},{"fevrier",28},{"mars",31},{"avril",30},{"mai",31},{"juin",30},{"juillet",31},{"aout",31},{"septembre",30},{"octobre",31},{"novembre",30},{"decembre",31}
};

int nbJoursMois[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

char nomsDesMois[][10] = { "janvier","fevrier","mars","avril","juin","juillet","aout","septembre","octobre","nomvembre","decembre" };

//role:revoir si l'annee a est bissextile,0 sinon
int bissextile(const int a) {
    return (a % 4 == 0 && a % 100 != 0 || a % 400 == 0);
}

//role:revoie le nobre du jours du mois m de l'annee a
int nbJoursDansMois(const int m, const int a) {
    if (m == 2) return bissextile(a) ? 29 : 28;
    return lesMois[m - 1].nbJours;
}

int DateValide(const Date d) {
    if (d.annee < ANNEEMIN) return 0;
    if (d.mois < 1 || d.mois>12) return 0;
    if (strcmp(lesMois[d.mois - 1].nomDuMois, d.nomDuMois) != 0) return 0;
    return d.jour >= 1 && d.jour <= nbJoursDansMois(d.mois, d.annee);
}

int main(void) {
    Date d1 = { 18,4,2017,"mars" };
    Date d2 = { 8,5,2020,"mai" };
    Date d3 = { 29,2,2019,"fevrier" };

    printf("%d\n", DateValide(d1));
    printf("%d\n", DateValide(d2));
    printf("%d\n", DateValide(d3));

    return EXIT_SUCCESS;
}