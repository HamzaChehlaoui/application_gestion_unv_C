#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_RESET "\x1b[0m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_CAYAN "\x1b[36m"

struct informations{
    
    int numero_unique;
    char nom[100];
    char prenom[100];
    int departement;
    float note_generale; 
}infor[1000];

struct date_de_naissance{
    int jour;
    int mois;
    int anne;
}date[1000];

// initializer le tableau d'etudiant
struct informations infor[1000]={
    {1,"Chehlaoui","Hamza",1,20},
    {2,"Adnan","Mohamed",2,10},
    {3,"Sofian","Yasin",1,15},
    {4,"Daraoui","Saad",2,9},
    {6,"Rachid","karim",4,15},
    {7,"Badr","Barada",5,17},
    {8,"Jalal","Daraoui",3,15}
};
struct date_de_naissance date[1000]={

    {13,1,2003},
    {16,5,2000},
    {30,6,1999},
    {3,5,1994},
    {30,6,1997},
    {30,7,1995},
    {30,8,1989},
    {10,6,2001}
};
int c=8;

//entrer et verifier date
void date_naissanse(int i){
    int x;
    do
    {
        x=0;
    printf("Entrer le jour : ");
    scanf("%d",&date[i].jour);
    printf("Entrer le mois : ");
    scanf("%d",&date[i].mois);
    printf("Entrer le anne : ");
    scanf("%d",&date[i].anne);
    if(date[i].jour>31||date[i].jour<1||date[i].mois>12||date[i].mois<1){
        printf("La date que vous aves saisie est incorrecte \n");
        x=1;
    }
    else if(date[i].jour>30 && (date[i].mois==4||date[i].mois==6||date[i].mois==9||date[i].mois==11)){
        printf("La date que vous aves saisie est incorrecte \n");
        x=1;
    }
    else if(date[i].mois==2)
    {
            if((date[i].anne%4==0&&date[i].anne%100!=0)||(date[i].anne%400==0))
            {
                    if(date[i].jour>29)
                    {
                        printf("La date que vous aves saisie est incorrecte \n");
                        x=1;
                    }
            }
            else
            {
                if(date[i].jour>28){
                     printf("La date que vous aves saisie est incorrecte \n");
                     x=1;
                }
            }
    }

    } while (x==1);

}

void menu_depart(){
    printf("1 : Physique .\n");
    printf("2 : Informatique .\n");
    printf("3 : Sciences .\n");
    printf("4 : Mathematiques.\n");
    printf("5 : Economie .\n");
}

//entrer et verifier departement
void departement(int i){
  do
  {
     menu_depart();
    printf("Entrer votre numero de departement : ");
    scanf("%d",&infor[i].departement);
    if(infor[i].departement<1||infor[i].departement>5){
        printf("Votre numero de departement n'existe pas .\n");
    }
  } while (infor[i].departement<1||infor[i].departement>5);
  
}
//entrer et verifier note general
void note_general(int i){
    do
    {
        
        printf("Entrer Note generale note/20 : ");
        scanf("%f",&infor[i].note_generale);
        if(infor[i].note_generale<1||infor[i].note_generale>20){
                printf("Il ya une erreur, veuillez la saisir a nouveau \n");
        }
    } while (infor[i].note_generale<0||infor[i].note_generale>20);
}

void Ajouter_etudiant(){

    int numero,i,x;
    do
    {
         printf("Veuillez entrer le nombre d'etudiants que vous souhaitez ajouter : ");
        scanf("%d",&numero);
        if(numero>1000){
             printf("Ce numero n'ast pas disponible \n");
        }
    } while (numero>1000);
    for(i=0;i<numero;i++){
        printf("\nSaisir les informations sur l'etudiant %d : \n",i+1);
        do
        {
            x=0;
            printf("Entrer Numero unique : ");
            scanf("%d",&infor[c].numero_unique);
            for(i=0;i<c;i++){
                if(infor[i].numero_unique==infor[c].numero_unique){
                    printf("Numero unique existe avant\n");
                    x=1;

                }
            }
        } while (x==1);
        
        printf("Entrer le Nome : ");
        scanf(" %[^\n]s",infor[c].nom);
        printf("Entrer le Prenom : ");
        scanf(" %[^\n]s",infor[c].prenom);
        printf("Entrer Date de nissance (jour / mois / anne) : \n");
        date_naissanse(c);
        printf("Entrer Departement : \n");
        departement(c);
        note_general(c);
        c++;
        printf("\n[ L'etudiant a ete ajoute avec succes ! ]\n");

    }
    
}

void  Modifier(int i){
        printf("\nSaisir les informations sur l'etudiant %d : \n",i+1);
        printf("Entrer Numero unique : ");
        scanf("%d",&infor[i].numero_unique);
        printf("Entrer le Nome : ");
        scanf(" %[^\n]s",infor[i].nom);
        printf("Entrer le Prenom : ");
        scanf(" %[^\n]s",infor[i].prenom);
        printf("Entrer Date de nissance (jour / mois / anne) : \n");
        date_naissanse(i);
        printf("Entrer Departement : \n");
        departement(i);
        note_general(i);
        printf("\n[ Modifie avec succes ]\n");
}

void Supprimer(int i){
    char yes_non;
    printf("Il sera supprime veuillez confirmer (oui = y) (non = n or ) : ");
    scanf(" %c",&yes_non);
    if(yes_non=='y' || yes_non=='Y'){
        for(int j=i+1;j<c;j++){

                strcpy(infor[i].nom,infor[j].nom);
                strcpy(infor[i].prenom,infor[j].prenom);
                infor[i].departement=infor[j].departement;
                infor[i].note_generale=infor[j].note_generale;
                infor[i].numero_unique=infor[j].numero_unique;
        }
        printf("[ Supprime avec succes ]\n");
        c--;
    }
}

void Modifier_supprimer(){
        int choix,num_uniq,i,x=0;
        printf("Veuillez entrer le numero unique de l'etudiant : ");
        scanf("%d",&num_uniq);
        for(i=0;i<c;i++){
            if(num_uniq==infor[i].numero_unique){
                x=1;
                 
        do{
            printf("\n1 : Modifier .\n");
            printf("2 : Supprimer .\n");
            printf("Entrer Votre choix : ");
            scanf("%d",&choix);
            switch (choix)
            {
            case 1:
                Modifier(i);
                break;

            case 2:
                {
                     Supprimer(i);
                     
                }
               
                break;

            default:
            printf("Il ya une erreur, veuillez la saisir a nouveau \n");
                break;
            }

        } while (choix<1||choix>2);

            }
        }
       if(x==0){
        printf("Numiro unique incorrect \n");
       }

}
//fonction 
void affiche(int i){
     printf(ANSI_COLOR_CAYAN"\nInformations sur les etudiants %d : \n",i+1);
     printf(""ANSI_COLOR_RESET);
    printf("Nome : %s \n",infor[i].nom);
    printf("Prenom : %s \n",infor[i].prenom);
    printf("Note general : %.2f\n",infor[i].note_generale);
    printf("Numero unique : %d\n",infor[i].numero_unique);
    printf("Departement  %d : \n",infor[i].departement);
    switch (infor[i].departement)
    {
    case 1:
        printf("Physique\n");
        break;
    case 2:
        printf("Informatique\n");
        break;
    case 3:
        printf("Sciences\n");
        break;
     case 4:
        printf("Mathematiques\n");
        break;
     case 5:
        printf("Economie\n");
        break;

    default:
        break;
    }
    printf("Date de naisence : %d / %d / %d\n",date[i].jour,date[i].mois,date[i].anne);
}

//afficher les details d'un etudiant 
void Afficher(){
for(int i=0;i<c;i++){
   affiche(i);
}



}
//calculer la moyenne generale 
void Calculer(){
     menu_depart();
    float som=0,moy=0;
    float some[5]={0,0,0,0,0};
    int numbre[1000];//numbre etudiant
    float moyen[5]={0,0,0,0,0};
        for(int i=0;i<5;i++){
            for(int j=0;j<c;j++){
                if(infor[j].departement==i+1){
                    some[i]+=infor[j].note_generale;
                    numbre[i]++;
                }
            }
            if(some[i]==0)
            {
                continue;
            }
            moyen[i]=some[i]/numbre[i];
        }
        for(int i=0;i<5;i++){
            if(moyen[i]==0)
                continue;
            printf("Moyen de departement %d : %.2f \n",i+1,moyen[i]);
            som+=moyen[i];
            moy++;
            
        }
        printf("Moyenne de l'noversite : %.2f\n",som/moy);
}

void Statistique(){
     float moiyen_sup;
     int i,j,num_etu[5]={0,0,0,0,0};
     int opr;
    printf("1 : Noubre totale de etudiant\n");
    printf("2 : Nombre etudiant de departement\n");
    printf("3 : Les 3 etudians ayant les meilleurs\n");
    printf("4 : Nombre d'etudiants ayant reussi de departement\n");
    printf("5 : la moiyene superieure\n");
    printf("Entrer le choix : ");
    scanf("%d",&opr);
    switch (opr)
    {
    case 1:
        {
             printf("Noubre totale de etudiant est : %d \n",c);
             break;
        }
    case 2:
        {
              menu_depart();
            int numbre[1000];
            for(i=0;i<5;i++){
            for(j=0;j<c;j++){
                if(infor[j].departement==i+1){
                    numbre[i]++;
                }
            }

            printf("Nombre etudiant de departement %d est : %d \n",i+1,numbre[i]);

}
             break;
        }
    case 3:
    {
        printf("\nLes 3 etudians ayant les meilleurs : \n");
        int tmp,i,j;
         char tm[100];
         float tmp2;
        for(i=0;i<c;i++){
        for(j=i+1;j<c;j++){
            if(infor[i].note_generale<infor[j].note_generale){
                strcpy(tm,infor[i].nom);
                strcpy(infor[i].nom,infor[j].nom);
                strcpy(infor[j].nom,tm);
                strcpy(tm,infor[i].prenom);
                strcpy(infor[i].prenom,infor[j].prenom);
                strcpy(infor[j].prenom,tm);
                tmp=infor[i].numero_unique;
                infor[i].numero_unique=infor[j].numero_unique;
                infor[j].numero_unique=tmp;
                tmp=infor[i].departement;
                infor[i].departement=infor[j].departement;
                infor[j].departement=tmp;
                tmp2=infor[i].note_generale;
                infor[i].note_generale=infor[j].note_generale;
                infor[j].note_generale=tmp2;
                tmp=date[i].jour;
                date[i].jour=date[j].jour;
                date[j].jour=tmp;
                tmp=date[i].mois;
                date[i].mois=date[j].mois;
                date[j].mois=tmp;
                tmp=date[i].anne;
                date[i].anne=date[j].anne;
                date[j].anne=tmp;

            }
        }
    }
        for(i=0;i<3;i++){
         affiche(i);
    }
         break;
    }
    case 4:
    {
        menu_depart();
     for(int i=0;i<5;i++){
            for(int j=0;j<c;j++){
                if(infor[j].departement==i+1){
                    if(infor[j].note_generale>=10){
                       num_etu[i]++;
                    }
                }
            }
            printf("Nombre d'etudiants ayant reussi de departement %d : %d \n",i+1,num_etu[i]);
           
        }
        break;
    }
    case 5: 
    {
         printf("Entrer la moiyene superieure : ");
    scanf("%f",&moiyen_sup);
    for(i=0;i<c;i++){
        if(infor[i].note_generale>moiyen_sup){
            affiche(i);
        }
    }
        break;
    }
    default:
                printf("Selection incorrecte :(\n");
        break;
    }
   
    
}
//recherche un etudiant 
void Rechercher(){
    char nome[100];
    int n;//nombre de departement
    int i,opr;
    printf("1 : Rechercher un etudiant par son nom.\n");
    printf("2 : Afficher la liste des etudiants inscrits dans un departement specifique : \n");
    printf("Entrer le choix : ");
    scanf("%d",&opr);
    switch (opr)
    {
    case 1:
       {
             printf("Entrer nome etudiant a recherche : ");
             scanf(" %[^\n]s",nome);
            for(i=0;i<c;i++){
            if(strcmp(nome,infor[i].nom)==0){
                 affiche(i);
            }

            }
        break;
       }
       case 2:
       {
            menu_depart();
            printf("Entrer nombre de departoment : ");
            scanf("%d",&n);
           
            for(int j=0;j<c;j++){
                if(infor[j].departement==n){
                    affiche(j);
                }
            }  
            
            break;
       }
    default:
    {
             printf("Le numero que vous avez entre est incorrect \n");
            break;
    }
    }

}
//tri a bulles
void trier_a_z(){
    int tmp,i,j;
    char tm[100];
    float tmp2;
    for(i=0;i<c;i++){

        for(j=i+1;j<c;j++){
            if(strcmp(infor[i].nom,infor[j].nom)>0){
                strcpy(tm,infor[i].nom);
                strcpy(infor[i].nom,infor[j].nom);
                strcpy(infor[j].nom,tm);
                strcpy(tm,infor[i].prenom);
                strcpy(infor[i].prenom,infor[j].prenom);
                strcpy(infor[j].prenom,tm);
                tmp=infor[i].numero_unique;
                infor[i].numero_unique=infor[j].numero_unique;
                infor[j].numero_unique=tmp;
                tmp=infor[i].departement;
                infor[i].departement=infor[j].departement;
                infor[j].departement=tmp;
                tmp2=infor[i].note_generale;
                infor[i].note_generale=infor[j].note_generale;
                infor[j].note_generale=tmp2;
                tmp=date[i].jour;
                date[i].jour=date[j].jour;
                date[j].jour=tmp;
                tmp=date[i].mois;
                date[i].mois=date[j].mois;
                date[j].mois=tmp;
                tmp=date[i].anne;
                date[i].anne=date[j].anne;
                date[j].anne=tmp;

            }
        }
        affiche(i);
    }
}

void  trier_z_a(){
      int tmp,i,j;
    char tm[100];
    float tmp2;
    for(i=0;i<c;i++){

        for(j=i+1;j<c;j++){
            if(strcmp(infor[i].nom,infor[j].nom)<0){
                strcpy(tm,infor[i].nom);
                strcpy(infor[i].nom,infor[j].nom);
                strcpy(infor[j].nom,tm);
                strcpy(tm,infor[i].prenom);
                strcpy(infor[i].prenom,infor[j].prenom);
                strcpy(infor[j].prenom,tm);
                tmp=infor[i].numero_unique;
                infor[i].numero_unique=infor[j].numero_unique;
                infor[j].numero_unique=tmp;
                tmp=infor[i].departement;
                infor[i].departement=infor[j].departement;
                infor[j].departement=tmp;
                tmp2=infor[i].note_generale;
                infor[i].note_generale=infor[j].note_generale;
                infor[j].note_generale=tmp2;
                tmp=date[i].jour;
                date[i].jour=date[j].jour;
                date[j].jour=tmp;
                tmp=date[i].mois;
                date[i].mois=date[j].mois;
                date[j].mois=tmp;
                tmp=date[i].anne;
                date[i].anne=date[j].anne;
                date[j].anne=tmp;

            }
        }
        affiche(i);
    }
 }
 
 void trier_10_20(){
       int tmp,i,j;
    char tm[100];
    float tmp2;
    for(i=0;i<c;i++){

        for(j=i+1;j<c;j++){
            if(infor[i].note_generale<infor[j].note_generale){
                strcpy(tm,infor[i].nom);
                strcpy(infor[i].nom,infor[j].nom);
                strcpy(infor[j].nom,tm);
                strcpy(tm,infor[i].prenom);
                strcpy(infor[i].prenom,infor[j].prenom);
                strcpy(infor[j].prenom,tm);
                tmp=infor[i].numero_unique;
                infor[i].numero_unique=infor[j].numero_unique;
                infor[j].numero_unique=tmp;
                tmp=infor[i].departement;
                infor[i].departement=infor[j].departement;
                infor[j].departement=tmp;
                tmp2=infor[i].note_generale;
                infor[i].note_generale=infor[j].note_generale;
                infor[j].note_generale=tmp2;
                tmp=date[i].jour;
                date[i].jour=date[j].jour;
                date[j].jour=tmp;
                tmp=date[i].mois;
                date[i].mois=date[j].mois;
                date[j].mois=tmp;
                tmp=date[i].anne;
                date[i].anne=date[j].anne;
                date[j].anne=tmp;

            }
        }
        if(infor[i].note_generale>=10)
        affiche(i);
    }
 }
// trier un etudient 
void Trier(){
    int opr;
        printf("Tri alphabetique des etudiants en fonction de leur nom : \n");
        printf("1 : de A a Z .\n");
        printf("2 : de Z a A .\n");
        printf("3 : Tri de etudiens slon leur statut de reussite (ceux ayant une moyenne superieure ou egale a 10 / 20)\n");
         printf("Entrer le choix : ");
        scanf("%d",&opr);
        switch (opr)
        {
        case 1:
           trier_a_z();
            break;
        case 2:
           trier_z_a();
            break;
         case 3:
           trier_10_20();
            break;
        
        default:
        {
            printf("Le choix que vous avez saisi n'est pas valide\n");
            break;
           
        }
        }
}
//menu de programme
void menu(){
   
    printf("1 : Ajouter un etudiant .\n");
    printf("2 : Modifier ou supprimer un etudiant .\n");
    printf("3 : Afficher les details d'un etudiant .\n");
    printf("4 : Calculer la moyenne generale .\n");
    printf("5 : Statistiques .\n");
    printf("6 : Rechercher un etudiant .\n");
    printf("7 : Trier les etudiants .\n");
    printf("8 : Quitter .\n");
}

void print(){
    printf(ANSI_COLOR_RED"\n      === [ Bienvenue dans l'application de gestion des etudiants de l'unversite !] ===       \n\n"ANSI_COLOR_RESET);
    int opr;
    char yes_no;
    do
    {
       printf( ANSI_COLOR_YELLOW"") ;
       menu();       
    printf(ANSI_COLOR_RESET"");
       printf("Choisissez un numero dans la liste des options ( 1 / 8 ): ");
       scanf("%d",&opr);
       switch (opr)
       {
       case 1:
            Ajouter_etudiant();
        break;
       case 2:
            Modifier_supprimer();
        break;
       case 3:
            Afficher();
        break;
       case 4:
            Calculer();
        break;
       case 5:
            Statistique();
        break;
       case 6:
            Rechercher();
        break;
       case 7:
            Trier();
        break;
       case 8:
           printf("\n[ Au revoir, le programme est termine :) ]\n");
        return;
       
       
       default:
       printf("Le numero que vous avez choisi n'exsite pas :( \n");
        break;
       }
       printf("Voulez vous repeter le processus ? ( oui = y ) ( non = n ) : ");
       scanf(" %c",&yes_no);

    } while (yes_no=='y'||yes_no=='Y');
    

}

int main(){

  system("color 2");
   print();
  
    return 0;
}