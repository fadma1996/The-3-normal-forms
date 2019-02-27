#include <stdio.h>
#include <stdlib.h>


struct Dependences
{
    char *cle;
    int nbr_cle;
    char attribut;
};

typedef struct Dependences *dependences;

struct Relation
{
    int nbr_cle;
    int nbr_attr;
    int nbr_dep;
    char* cle;
    char* attribut;
    dependences dep;
};

typedef struct Relation *relation;

void FN1(relation r)
{
    if(r->nbr_cle >0)
        printf("La relation est en forme normale 1\n");
    else
        printf("La relation n'est pas en forme normale 1\n");

}
void FN2(relation r)
{
    int i,j,k,l,temp;

    for( i=0 ; i< r->nbr_dep; i++)
    {
        for( j=0 ; j< r->nbr_dep; j++)
        {
            temp=0;
            for( k=0 ; k< r->dep[i].nbr_cle; k++)
            {
                for ( l=0 ; l< r->dep[j].nbr_cle; l++)
                {
                    if( r->dep[l].cle[k] == r->dep[j].cle[l])
                        temp++;
                }
            }
            if( temp != r->dep[j].nbr_cle && temp !=0)
            {
                exit(printf("La relation n'est pas en forme normale 2\n"));
            }

        }
    }
    printf("La relation est en forme normale 2\n");
}

void FN3(relation r)
{
    int i,j,k;
    for( i=0 ; i< r->nbr_dep; i++)
    {
        for( j=0 ; j< r->nbr_dep ; j++)
        {
            for( k=0 ; k< r->dep[j].nbr_cle ; k++)
            {
                if( r->dep[i].attribut == r->dep[j].cle[k])
                    exit(printf("La relation n'est pas en forme normale 3\n"));
            }
        }
    }
    printf("La relation est en forme normale 3\n");

}

int main()
{
    int nbr_cle, nbr_attr, nbr_dep;
    int i,j;

    do{
        printf("Entrer le nombre de clés!\n");
        scanf("%d",&nbr_cle);
    }while( nbr_attr<=0);

    relation R =(relation)malloc(sizeof(struct Relation));
    R->cle=(char*)malloc((nbr_cle*sizeof(char)));
    R->attribut=(char*)malloc((nbr_attr*sizeof(char)));
    R->nbr_cle= nbr_cle;
    R->nbr_attr= nbr_attr;

    printf("Remplir la relation par les clés!\n");
    for( i=0; i<nbr_cle; i++)
    {
        printf("Saisir la clé[%d]:",i+1);
        do{
            scanf("%c",&(R->cle[i]));
        }while(R->cle[i] == '\n');
    }
    do{
        printf("Saisir le nombre d'attribut:\n");
        scanf("%d",&nbr_attr);
    }while( nbr_attr<=0);

    printf("Remplir la relation par les attributs\n");
    for( i=0 ; i<nbr_attr ;i++)
    {
        printf("Saisir l'attribut[%d]:",i+1);
        do{
            scanf("%c",&(R->attribut[i]));
        }while(R->attribut[i] == '\n');
    }

    do{
        printf("Saisir le nombre de dependences qu'on a: \n");
        scanf("%d",&nbr_dep);
    }while(nbr_dep<=0);

    R->nbr_dep = nbr_dep;
    R->dep = (dependences)malloc(nbr_dep*sizeof(struct Dependences));

    for( i=0 ; i<nbr_dep ; i++)
    {
        printf("Entrer les infor de dependence numero %d\n",i+1);
        printf("Saisir le nombre de cle de cette dep:\n");
        scanf("%d",&nbr_cle);

        R->dep[i].cle=(char*)malloc(nbr_cle*sizeof(char));
        R->dep[i].nbr_cle=nbr_cle;

        for( j=0; j<nbr_cle ; j++)
        {
            printf("Saisir la cle[%d]:\n");
            do{
                scanf("%c",&R->dep[i].cle[j]);
            }while(R->dep[i].cle[j] == '\n');
        }

        printf("Saisir l'attribut asspcie :\n");
        do{
            scanf("%c",&R->dep[i].attribut);
        }while(R->dep[i].attribut == '\n');

        for( j=0 ; j<R->dep[i].nbr_cle ; j++)
        {
            printf("%c",R->dep[i].cle[j]);
        }
        printf("---------->");
        printf("%c\n",R->dep[i].attribut);
    }
    printf("\n/*************************\n");
    printf("* Affichage de dependences *\n");
    printf("*******************************/\n");

    for( i=0 ; i<nbr_dep ; i++)
    {
        for( j=0 ; j< R->dep[i].nbr_cle ; j++)
        {
            printf("%c",R->dep[i].cle[i]);
        }
        printf("------>");
        printf("%c\n", R->dep[i].attribut);
    }
    FN1(R);
    FN2(R);
    FN3(R);
    return 0;
}

