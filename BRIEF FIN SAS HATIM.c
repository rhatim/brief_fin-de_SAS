#include<stdio.h>

#include<stdlib.h>

#include<stdbool.h>

#include<string.h>

 

 

// cree type varriables comptes bancaires

 

struct compte_b{

                char cin[10];

                char Nom[15];

                char Prenom[15];

                double montant;

};

 

// cree un tableaux de type comptes bancaires

 

struct compte_b tableaux[100];

 

int compteur=0;

 

 

// fonction d introduire un compte bancaire

int introduction1_c(){

               

    printf("entrez cin : ");

                scanf("%s", &tableaux[compteur].cin);

                printf("entrez le nom : ");

                scanf("%s", &tableaux[compteur].Nom);

                printf("entrez le prenom : ");

                scanf("%s", &tableaux[compteur].Prenom);

                printf("entrez montant : ");

                scanf("%lf", &tableaux[compteur].montant);     

               

                compteur++;

                return 0;

               

}

// fonction d introduire plusieurs comptes bancaires

int introductionplusieurs_c(){

                printf(" entrez le nombre du comptes: ");

                int nombre_du_comptes;

                scanf("%d", &nombre_du_comptes);

               

                int index;

                for( index=0;index<nombre_du_comptes;index++){

                                printf("---------------------------------------------- \n");

                                printf("entrez cin : ");

                                scanf("%s", &tableaux[compteur].cin);

                                printf("entrez le nom : ");

                                scanf("%s", &tableaux[compteur].Nom);

                                printf("entrez le prenom : ");

                                scanf("%s", &tableaux[compteur].Prenom);

                                printf("entrez montant : ");

                                scanf("%lf", &tableaux[compteur].montant);

                                               

               

               compteur++;

                }

               

                return 0;

               

}

// fonction operation pour le retrait et depot

int operations(){

                char cin[10];

                int index;

                bool existe=false;

                printf("entrez cin : ");

                scanf("%s", &cin);

               

                for( index=0;index<compteur;index++){

                                if( strcmp(tableaux[index].cin,cin) ==0 ){

                                                existe=true;break;

                                               

                                }

                }

               

                if ( existe==true){

                                printf("1 - retrait \n2 - depot \n");

                                printf("entrez votre choix: ");

                                int operations;

                                scanf("%d", &operations);

                               

                                double montant;

                                printf("entrez le montant : ");

                                scanf("%lf", &montant);

                               

                                switch(operations){

                                                case 1: tableaux[index].montant=tableaux[index].montant-montant;break;

                                                case 2: tableaux[index].montant=tableaux[index].montant+montant;break;

                                }

                               

                                               

                }else{

                                printf("compte introuvable \n");

                }

               

               

                //////////

 

                return 0;

}

// fonction d'affichage les comptes bancaires

int affichage(){

                char cin[10];

                int index;

                bool existe=false;

 

                printf("1- tous les on order ascendant \n");

                printf("2- tous les on order descendant \n");

                printf("3- tous les on order ascendant ayant un montant superieur a un chiffre introduit \n");

                printf("4- tous les on order descendant ayant un montant superieur a un chiffre introduit \n");

                printf("5- recherche par cin \n");

               

                int choix;

                printf("entrez votre choix : ");

                scanf("%d",&choix);

               

                int i,j,index_min,index_max;

                struct compte_b tmpr;

               

                double montant;

               

               

                switch (choix){

                               

                                case 1:

                                                //  Par Ordre Ascendant

                                               

                                                // algorithme de tri par selection

                                               

                                                for(i=0;i<compteur-1;i++){

                                                                index_min=i;

                                                                for(j=i+1;j<compteur;j++){

                                                                                if(tableaux[index_min].montant>tableaux[j].montant) index_min=j;

                                                                               

                                                                }

                                                                if(i!=index_min){

                                                                                tmpr=tableaux[index_min];

                                                                                tableaux[index_min]=tableaux[i];

                                                                                tableaux[i]=tmpr;

                                                               

                                                                }

                                                               

                                                }

                                               

                                                //boucle d'affichage

                                               

                                                for(i=0;i<compteur;i++)

                                                {

                                                                printf("cin : %s | " , tableaux[i].cin );

                                                                printf("nom : %s  | "   , tableaux[i].Nom);

                                                                printf("prenom : %s  | ", tableaux[i].Prenom);

                                                                printf("montant : %lf  \n", tableaux[i].montant);

                                                }

                                               

                                                break;

                               

                                case 2:

                                                // Par Ordre Descendant

                                               

                                                for(i=0;i<compteur-1;i++){

                                                                index_max=i;

                                                                for(j=i+1;j<compteur;j++){

                                                                                if(tableaux[index_max].montant<tableaux[j].montant) index_max=j;

                                                                               

                                                                }

                                                                if(i!=index_max){

                                                                                tmpr=tableaux[index_max];

                                                                                tableaux[index_max]=tableaux[i];

                                                                                tableaux[i]=tmpr;

                                                               

                                                                }

                                                               

                                                }

                                                for(i=0;i<compteur;i++)

                                                {

                                                                                printf("cin : %s | " , tableaux[i].cin );

                                                                                printf("nom : %s  | "   , tableaux[i].Nom);

                                                                                printf("prenom : %s  | ", tableaux[i].Prenom);

                                                                                printf("montant : %lf  \n", tableaux[i].montant);

                                                               

                                                               

                                                                               

                                                }

                                               

                                                break;

                                               

                                case 3:

                                                // Par Ordre Ascendant (les comptes bancaires ayant un montant supérieur à un chiffre introduit)

                                                printf("entrez le montant : ");

                                                scanf("%lf",&montant);

                                               

                                               

                                                for(i=0;i<compteur-1;i++){

                                                                index_min=i;

                                                                for(j=i+1;j<compteur;j++){

                                                                                if(tableaux[index_min].montant>tableaux[j].montant) index_min=j;

                                                                               

                                                                }

                                                                if(i!=index_min){

                                                                                tmpr=tableaux[index_min];

                                                                                tableaux[index_min]=tableaux[i];

                                                                                tableaux[i]=tmpr;

                                                               

                                                                }

                                                               

                                                }

                                               

                                                for(i=0;i<compteur;i++)

                                                {

                                                                if(tableaux[i].montant>=montant){

                                                                                printf("cin : %s | " , tableaux[i].cin );

                                                                                printf("nom : %s  | "   , tableaux[i].Nom);

                                                                                printf("prenom : %s  | ", tableaux[i].Prenom);

                                                                                printf("montant : %lf  \n", tableaux[i].montant);

                                                                }

                                                }

                                               

                                                break;

                                               

                               

                                case 4:

                                                // Par Ordre Descendant (les comptes bancaires ayant un montant supérieur à un chiffre introduit)

                                               

                                                printf("entrez le montant : ");

                                                scanf("%lf",&montant);

                                                for(i=0;i<compteur-1;i++){

                                                                index_max=i;

                                                                for(j=i+1;j<compteur;j++){

                                                                                if(tableaux[index_max].montant<tableaux[j].montant) index_max=j;

                                                                               

                                                                }

                                                                if(i!=index_max){

                                                                                tmpr=tableaux[index_max];

                                                                                tableaux[index_max]=tableaux[i];

                                                                                tableaux[i]=tmpr;

                                                               

                                                                }

                                                               

                                                }

                                                for(i=0;i<compteur;i++)

                                                {

                                                    if(tableaux[i].montant>=montant){

                                                                                printf("cin : %s | " , tableaux[i].cin );

                                                                                printf("nom : %s  | "   , tableaux[i].Nom);

                                                                                printf("prenom : %s  | ", tableaux[i].Prenom);

                                                                                printf("montant : %lf  \n", tableaux[i].montant);

                                                                }

                                                                               

                                                }             

                                                break;

                               

                                case 5:

                                                // recherche par cin

                               

                                     printf("entrez cin : ");

                                     scanf("%s", &cin);

               

                                                for( index=0;index<compteur;index++){

                                                                if( strcmp(tableaux[index].cin,cin) ==0 ){

                                                                                existe=true;break;

                                                                }

                                                }

                                                if(existe==true){

                                                                printf("cin : %s | " , tableaux[index].cin );

                                         printf("nom : %s  | "   , tableaux[index].Nom);

                             printf("prenom : %s  | ", tableaux[index].Prenom);

                             printf("montant : %lf  \n", tableaux[index].montant);

                            

                                                }else{

                                                                printf("compte no existe \n");

                                                               

                                                }

                                               

                                                break;

                                               

                }

 

                return 0;

               

}

 

int fidelisation(){

               

                // TRI DE TABLE

                int i,j,index_max;

                struct compte_b tmpr;

                for(i=0;i<compteur-1;i++){

                                                                index_max=i;

                                                                for(j=i+1;j<compteur;j++){

                                                                                if(tableaux[index_max].montant<tableaux[j].montant) index_max=j;

                                                                               

                                                                }

                                                                if(i!=index_max){

                                                                                tmpr=tableaux[index_max];

                                                                                tableaux[index_max]=tableaux[i];

                                                                                tableaux[i]=tmpr;

                                                               

                                                                }

                                                }

                                               

                // AUGMENT MONTANT DE 3 PREMIER

                tableaux[0].montant=tableaux[0].montant+( tableaux[0].montant *1.3/100 );

                tableaux[1].montant=tableaux[1].montant+( tableaux[1].montant *1.3/100 );

                tableaux[2].montant=tableaux[2].montant+( tableaux[2].montant *1.3/100 );
                
                
                for(i=0;i<3;i++)
				{
					printf("les comptes fidelises sont :\n % ");   
															printf("nom : %s  | "   , tableaux[i].Nom);

							                           		printf("prenom : %s  | ", tableaux[i].Prenom);
							
							                            	printf("montant : %lf  \n", tableaux[i].montant); 
				}

               

               

                return 0;

}

 

 

int main(){

                int choix;

 

               

               

               

               

               

do{

 

                printf("         menu principal      \n");

                printf(" 1- introduire un compte bancaire \n");

                printf(" 2- Introduire plusieurs comptes bancaires  \n");

                printf(" 3- operations \n");

                printf(" 4- affichage   \n");

                printf(" 5- Fidelisation  \n");

                printf(" 6- quitter  \n");

               

                printf(" tapez votre choix  \n");

   scanf("%d",&choix);

  

   switch(choix){

                case 1:  introduction1_c();break;

               

                case 2:  introductionplusieurs_c();break;

               

                case 3:  operations();break;

               

                case 4:  affichage();break;

               

                case 5:  fidelisation(); getch();break;

               

                case 6: printf("quitter... \n");break;

               

                default : printf("entrez valeur entre 1 et 6 \n");

               

               

               

   }

   printf("--------------------------------------- \n");

  

               

}while(choix !=6);

 

 

 

 

}
