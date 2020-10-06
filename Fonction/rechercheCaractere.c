/********
Fichier: cos.c
Auteurs: Samuel Bouchard bous1938	
Jérémy Cusson cusj3102
Date: 04 octobre 2000
Description: Fonction permettant de calculer le cos d'un angle en radiant. Contient egalement une fonction pour de test automatise.
********/

#include <stdio.h>


int main(void)
{
	void validation();
	void planTest();
	printf("Validation: \n");
	validation();
//	printf("\n\nPlan de test: \n");
//	planTest();
}


void validation()
{
	int indexCaractere(char str[],char c);
	printf("Recherche : n dans [anticonstitutionnellement] index attendu : 1, index trouve: %d\n",indexCaractere("anticonstitutionnellement",'n'));
	printf("Recherche : e dans [bonjour] index attendu : -1, index trouve: %d\n",indexCaractere("bonjour",'e'));
	printf("Recherche : r dans [bonjour] index attendu : 6, index trouve: %d\n",indexCaractere("bonjour",'r'));
	printf("Recherche : a dans [allocommentcava] index attendu : 0, index trouve: %d\n",indexCaractere("allocommentcava",'a'));
}

void planTest()
{
	int indexCaractere(char str[],char c);
	printf("Recherche : 0 dans [012345678910] index attendu : 0, index trouve: %d\n",indexCaractere("012345678910",'0'));
	printf("Recherche : @ dans [] index attendu : -1, index trouve: %d\n",indexCaractere("",'@'));
	printf("Recherche : _ dans [allo_comment_cava] index attendu : 4, index trouve: %d\n",indexCaractere("allo_comment_cava",'_'));
	printf("Recherche : [espace] dans [allo comment cava] index attendu : 4, index trouve: %d\n",indexCaractere("allo comment cava",' '));
}

//Pre-condition: n/a
//Post-Condition: retourne -1 si le caractere est introuvable sinon retourn l'index
int indexCaractere(char str[],char c)
{
	//Si str[i] = 0 alors caractere null donc fin tableau
	for (int i = 0; str[i] != 0; i++)
	{
		if (str[i]==c) 
		{
			return i;
		}
	}
	return -1;
}
