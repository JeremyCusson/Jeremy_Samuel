/********
 Fichier: Détection_D'un_palinfrome.c
 Auteur: Jérémy Cusson cusj3102
 Date: 04 octobre 2020
 Description: Vérifie si un mot est un palindrome
********/

#include <stdio.h>

int DetectionPalindrome(char []);

int main(void)
{
	char mot1[] = "laval";
	//Validation
	printf("Validation que le code fonctionne : \n");
	printf("Mot evalue : %s \n",mot1);
	if(DetectionPalindrome(mot1))
	{
		printf("%s est un palindrome \n", mot1);
	}
	else
	{
		printf("%s n'est pas un palindrome \n", mot1);
	}
	
	printf("-------------------------------------------\n");
	
	//Palindrome dans une chaine de caratères de grandeur neuf
	char mot2[] = "ressasser";
	printf("Test d'un palindrome de neuf caracteres : \n");
	printf("Mot evalue : %s \n",mot2);
	if(DetectionPalindrome(mot2))
	{
		printf("%s est un palindrome \n", mot2);
	}
	else
	{
		printf("%s n'est pas un palindrome \n", mot2);
	}
	
	printf("-------------------------------------------\n");
	
	//Pour vérification de la fonctionnalité, detection pour une chaine de caractères d'une grosseur de cent
	char mot3[] = "lalalalalalalalalalalalalalalalalalalalalalalalalalalalalalalalalalalalalalalalalalalalalalalalalala";
	printf("Test d'un palindrome de cent caracteres : \n");
	printf("Mot evalue : %s \n",mot3);
	if(DetectionPalindrome(mot3))
	{
		printf("%s est un palindrome \n", mot3);
	}
	else
	{
		printf("%s n'est pas un palindrome \n", mot3);
	}
	
	printf("-------------------------------------------\n");
	
	//Pour vérification de la fonctionnalité, detection pour un palindrome d'une grosseur de cent un
	char mot4[] = "lalalalalalalalalalalalalalalalalalalalalalalalalalalalalalalalalalalalalalalalalalalalalalalalalalal";
	printf("Test d'un palindrome de cent caracteres : \n");
	printf("Mot evalue : %s \n",mot4);
	if(DetectionPalindrome(mot4))
	{
		printf("%s est un palindrome \n", mot4);
	}
	else
	{
		printf("%s n'est pas un palindrome \n", mot4);
	}
	return 0;
}

int DetectionPalindrome(char mot[])
{
	int nombreLettre = 0;
	
	for(int i = 0; mot[i] != '\0'; i++)
	{
		nombreLettre++;
	}
	
	for (int j=0;j<nombreLettre;j++)
	{
		if (mot[j]!=mot[(nombreLettre - 1) - j])
		{
		   return 0;
		}
	}
	
	return 1;
}
