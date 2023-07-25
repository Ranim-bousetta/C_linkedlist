#include<stdio.h>
#include<conio.h>

#include<stdlib.h>
typedef struct
{
   int val;
   struct list * nxt; //definir la structure
} liste;
liste * AjoutEnTete(liste * L,int x)
{
    liste * P;
P=(liste *)malloc(sizeof(liste));
    if(P==NULL)
    {
      printf("problem allocation memoire");
      exit(0);

    }else
    {
        P->val=x;
        P->nxt=L;
    }
}
liste * AjoutEnFin(liste * L,int x)
{
    liste * new1,*pt=L;
new1=(liste *)malloc(sizeof(liste));
    if(new1==NULL)
    {
      printf("problem allocation memoire");
      exit(0);

    }else
    {
        new1->val=x;
        new1->nxt=NULL;
        if(L==NULL)
        {
            return(new1);
        }else
        {
            while(pt->nxt!=NULL)
            {
                pt=pt->nxt;
            }
            pt->nxt=new1;
            return(L);
        }
    }
}
void AfficherList(liste * L)
{
    liste * pt=L;
    if(!L)
    {
        printf("la liste est vide");
    }
    else
    {
        while(pt!=NULL)
        {
            printf("%d\t",pt->val);
            pt=pt->nxt;
        }
    }
}
void saisir(int *a)
{
    printf("saisir un entier: ");
    scanf("%d",a);
}
liste * Recherche(liste * L,int x)
{
    liste * P=L;
    int pos=0;
    while((P!=NULL)&&(P->val!=x))
    {

        P=P->nxt;
        pos++;
    }
    if(P==NULL)
    {
        printf("%d n'existe pas");
    }else
    {
        printf("%d se trouve dans la position %d",x,pos);
    }
    return(P);
}
liste * supprimEnTete(liste * L)
{
    liste * aSup;
    if(L!=NULL)
    {
        aSup=L->nxt;
        free(L);
        return(aSup);
    }else
    {
        return (NULL);
    }

}
liste *supprimEnFin(liste *L)
{
    liste *p1,*p2;
    p1 = L;
    if(!L)
    {
       return(NULL);
    }

    else if(L->nxt==NULL)
    {
        L=L->nxt;
        free(p1);
    }
    else
    {
        p2=p1->nxt;
        while(p2->nxt!=NULL)
        {
            p1=p1->nxt;
            p2=p2->nxt;
        }
        p1->nxt=NULL;
        free(p2);
        return(L);
    }
}
liste *supprimeElem(liste *L,int n)
{
    liste *pos,*pt;
    pos=Recherche(L,n);
    if(L!=pos)
    {
        return(L);
    }else
    {
    if (pos=L)
    {
     return(supprimEnTete(L));}
    }if(pos->nxt==NULL)
    {
        return(supprimEnFin(L));
    }
    else
    {
        pt=L;
        while (pt->nxt != pos)
        {
            pt=pt->nxt;
        }
        pt->nxt=pos ->nxt;
        free(pos);


        return (L);
    }

}
int nbrocc(liste *L,int n)
{
    int cpt=0;
    liste *P=L;
    while(P)
    {
        if (P->val==n)
        {
            cpt++;
        }
        P=P->nxt;
    }
    return(cpt);
}


liste * supprimerocc(liste *L,int n)
{
    int nbr=nbrocc(L,n),i;
    for(i=0;i<nbr;i++)
    {
        L=supprimeElem(L,n);
    }
    return(L);
}
int taille(liste *L)
{
    liste *p=L;
    int i=0;
    while (p!=NULL)
    {
        i++;
        p=p->nxt;
    }
}
liste * ajoutpos(liste*L, int n)
{
    int t=taille(L),pos=n,i;
    liste *nouv,*p;
    if(pos>t+1)
    {
        return(L);
    }
    else if(pos==1)
    {
        return(AjoutEnTete(L,n));
    }
    else if(pos==t+1)
    {
        return(AjoutEnFin(L,n));
    }
    else
    {
        nouv=(liste*)malloc(sizeof(liste));
        nouv->val=n;
        p=L;
        for(i=1;i<pos;i++)
        {
            p=p->nxt;
        }
        nouv->nxt=p->nxt;
        p->nxt=nouv;
        return(L);
    }

}


main()
{
    liste * L=NULL;
    int x,y,choix,n;

do
{
    system("cls");
    AfficherList(L);
    printf("\nmenu\n 1.AjoutEntete\n 2.AjoutEnFin \n 3.afficher liste\n 4.rechercher element\n 5.SupprimerEnTete\n 6.Supprimer element\n 7.nombre occurence\n 0.quitter \n faire votre choix: " );
    scanf("%d",&choix);
    if(choix==1)
    {
    saisir(&x);
    L=AjoutEnTete(L,x);
    }
    else if (choix==2)
    {
        saisir(&x);
        L=AjoutEnFin(L,x);
    }
    else if (choix==3)
    {
     AfficherList(L);
     getch();
    }
    else if (choix==4)
    {
       saisir(&y);
       Recherche(L,y);
       getch();
    }
    else if (choix==5)
    {
        supprimEnTete(L);
    }
    else if (choix==6)
    {
        saisir(&x);
        supprimeElem(L,x);
    }
     else if (choix==7)
     {
         saisir(&x);
         n=nbrocc(L,x);
         printf("%d",n);
         getch();
     }

}while(choix!=0);
}



