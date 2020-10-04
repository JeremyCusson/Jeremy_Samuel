/********
 Fichier: Multiplication_de_deux_matrices.c
 Auteur: Jérémy Cusson cusj3102
 Date: 02 octobre 2020
 Description: Calcul d'une multiplication de deux matrices carrées
              et tests du limitage du codage
********/

#include <stdio.h>
#define n 5

void MultiplicationMatrices(double matrice1[n][n], double matrice2[n][n], double matrice3[n][n]);

// Description: Test pour l'opération de la multiplication de deux matrices
int main(void)
{	
	//Test pour vérifier l'aboutissement du code avec des valeurs extrèmes dans la matrice
	double matrice1[n][n] = {{10000.5,20000,30000,40000,50000},{60000,70000,80000,90000,100000},{110000,120000,130000,140000,150000},
		                   {160000,170000,180000,190000,200000},{210000,220000,230000,240000,250000}};
	double matrice2[n][n] = {{50000,50000,50000,50000},{40000,400000,40000,40000,40000},{30000,30000,30000,30000,300000},
		                   {20000,20000,20000,20000,20000},{10000,10000,10000,10000,10000}};
	
	double matrice3[n][n];
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			matrice3[i][j] = (matrice1[i][j]*matrice2[i][j] + matrice1[i][1+j]*matrice2[1+i][j] + matrice1[i][2+j]*matrice2[2+i][j]);
		}
	}
	
	MultiplicationMatrices(matrice1, matrice2, matrice3);
	
	printf("-------------------------------------------\n");
	
	//Test pour vérifier l'aboutissement du code avec des valeurs à virgul dans la matrice
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			matrice1[i][j] = 0.000001;
			matrice2[i][j] = 0.000001;
		}
	}
		
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			matrice3[i][j] = (matrice1[i][j]*matrice2[i][j] + matrice1[i][1+j]*matrice2[1+i][j] + matrice1[i][2+j]*matrice2[2+i][j]);
		}
	}
	
	MultiplicationMatrices(matrice1, matrice2, matrice3);
	printf("-------------------------------------------\n");
	
	//Test pour vérifier que le programme affiche des chiffres en mettant des lettres
	double matriceTest1[n][n] = {{'q','z','a','n','m'},{'h','l','a','r','d'},{'v','x','a','v','x'},{'g','f','t','a','o'},{'k','j','a','h','j'}};
	double matriceTest2[n][n] = {{'q','z','a','n','m'},{'h','l','a','r','d'},{'v','x','a','v','x'},{'g','f','t','a','o'},{'k','j','a','h','j'}};
	MultiplicationMatrices(matriceTest1, matriceTest2, matrice3);
	printf("-------------------------------------------\n");
	
	//Test pour vérifier que le programme affiche des valeurs avec des chiffres négatifs élevés
	double matriceTest3[n][n] = {{-1343,-2324,-332432,-4434,-5324234},{-632432,-74324,-832423,-9432,-1043242},{-114324,-126565,-13435,-14432,-1532},
		                         {-1654,-1732,-183432,-19432,-2033},{-21423,-22432,-23432,-2432,-25432}};
	double matriceTest4[n][n] = {{-1343,-2324,-332432,-4434,-5324234},{-632432,-74324,-832423,-9432,-1043242},{-114324,-126565,-13435,-14432,-1532},
		                         {-1654,-1732,-183432,-19432,-2033},{-21423,-22432,-23432,-2432,-25432}};
	
	MultiplicationMatrices(matriceTest3, matriceTest4, matrice3);
	printf("-------------------------------------------\n");
	
	return 0;
}

//Description: Multiplication de deux matrices paramétrées
//Précondition: Matrice carré avec le même nombre de colonnes et de lignes
//Postecondition: Matrice résultante possède le même nombre de colonnes et de lignes
void MultiplicationMatrices(double matrice1[n][n], double matrice2[n][n], double matrice3[n][n])
{
	int nombreColonne = 0;
	int nombreLigne = 0;
	
	//Fait la multiplication de deux matrices
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			for(int k = 0; k < n; k++)
			{
				matrice3[i][j] = matrice3[i][j] + (matrice1[i][k]*matrice2[k][j]);
			}
			printf("%f  ", matrice3[i][j]);
			nombreColonne++;
		}
		printf("\n");
		nombreLigne++;
	}
	
	if (nombreColonne != nombreLigne)
	{
		printf("Erreur");
		matrice3 = 0;
	}
}
