#include<stdio.h>
typedef struct
{
    char nom[20],prenom[20];
    float moy;
}etudiant;
typedef struct
{
 char nomc[20];
 int nbre ;
 etudiant etd[50];
}classe;
void saisie_etudiant(etudiant *e)
{
    printf("\ndonner le nom de l'etudiant: ");
    scanf("%s",e->nom);
    printf("\ndonner le prenom de l'etudiant: ");
    scanf("%s",e->prenom);
    printf("\ndonner la moyenne de l'etudiant: ");
    scanf("%f",&e->moy);

}
void saisie_classe(classe *c)
{
    printf("\ndonner le nom de la classe: ");
    scanf("%s",c->nomc);
    printf("\ndonner le nombre d'etudiants : ");
    scanf("%d",&c->nbre);
    for(int i=0;i<c->nbre;i++)
    {
        saisie_etudiant(&c->etd[i]);
    }

}
void affiche_classe(classe c)
{
    int i;
    printf("la classe %s contient les etudiants suivant",c.nomc);
    for (i=0;i<c.nbre;i++)
    {
        printf("\nl'etudiant %s %s a une moyenne egale a %.2f",c.etd[i].nom,c.etd[i].prenom,c.etd[i].moy);
    }
}
float moyenne(classe c)
{
    float total=0;
    int i;
    for(i=0;i<c.nbre;i++)
    {
        total+=c.etd[i].moy;
    }
    return(total/c.nbre);

}
main()
{
    classe c;
    saisie_classe(&c);
    printf("la moyenne de la classe =%.2f",moyenne(c));
    return(0);
}

