#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLEMAX 25 //On d�finit une constante afin de conditionner la taille de la cha�ne � entrer (�tant donn� que le mot le plus long de la langue fran�aise est compos�  de 25 lettres)

int main()
{
    //D�claration des variables
    char mot_entre[TAILLEMAX];
    char mot_masque[TAILLEMAX];
    char caractere;
    int essais=10,longueur_mot=0,i=0,recommencer=0;

    do
    {
    printf("Bienvenue dans le jeu du pendu !\n");
    printf("Veuillez entrer votre mot a deviner!\n"); // On demande le mot � deviner
    scanf("%s",mot_entre); // On lit le mot entr�
    system("cls");
    longueur_mot=strlen(mot_entre);
    for (i=0;i<longueur_mot;i++)
        mot_masque[i]='-'; // On r�cup�re la longueur du mot et on remplace la chaine par des tirets afin de masquer le contenu
    mot_masque[longueur_mot+1]='\0'; //Fin de la chaine
    do
    {
        printf("Veuillez entrer un caractere\n");
        fflush(stdin);
        scanf("%c",&caractere);
        for (i=0;i<longueur_mot;i++)
        {
            if (mot_entre[i]==caractere) // On test si le caract�re rentr� correspond � une lettre de la chaine
                mot_masque[i]=caractere;    //On remplace le caract�re si il correspond
        }
        essais--;
        printf("%s\n",mot_masque);
        printf("Nombre d'essais: %d\n",essais); //Affichage du nombre d'essais
    }while (essais>0 || strcmp(mot_entre,mot_masque)!=0); //Le programme continue tant que le nombre d'essais est sup�rieur � 0 et que les chaine ne correspondent pas
    if (strcmp(mot_entre,mot_masque)==0)
        printf("Bravo, vous avez gagn�\n");
    else printf("Dommage, vous y arriverez peut-etre la prochaine fois\n");
    printf("Voulez-vous recommencer ? (1 pour OUI et 2 pour NON)\n"); //Boucle afin de recommencer le jeu
    scanf("%d",&recommencer);
    }while (recommencer==1);
    system("pause");
    return 0;
}
