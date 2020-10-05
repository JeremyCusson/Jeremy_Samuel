/********
 Fichier: Multiplication_de_deux_matrices.c
 Auteur: Jérémy Cusson cusj3102
 Date: 02 octobre 2020
 Description: Calcul d'une multiplication de deux matrices carrées
              et tests du limitage du codage
********/

#include <stdio.h>
#define n 4

void MultiplicationMatrices(double matrice1[n][n], double matrice2[n][n], double matriceResultat[n][n]);
void AfficherMatriceMult(double matriceResultat[n][n]);

// Description: Test pour l'opération de la multiplication de deux matrices
int main(void)
{	
	//Test pour vérifier l'aboutissement du code avec des valeurs extrèmes dans la matrice
	double matriceTest1[n][n] = {{100,200,300,400},{600,700,800,900},{110,120,130,140},
		                         {160,170,180,190}};
	double matriceTest2[n][n] = {{500,500,500,500},{400,400,400,400},{300,300,300,300},
		                         {200,200,200,200}};
	double matriceResultat1[n][n];
	
	printf("Test avec des valeurs extremes : \n");
	printf("Matrice A:\n");
	AfficherMatriceMult(matriceTest1);
	printf("Matrice B:\n");
	AfficherMatriceMult(matriceTest2);
	printf("Resultat :\n");
	MultiplicationMatrices(matriceTest1, matriceTest2, matriceResultat1);
	
	printf("-------------------------------------------\n");
	
	//Test pour vérifier l'aboutissement du code avec des valeurs à virgul dans la matrice
	double matriceTest3[n][n] = {{0.0000001,0.0000001,0.0000001,0.0000001},{0.0000001,0.0000001,0.0000001,0.0000001},
		                         {0.0000001,0.0000001,0.0000001,0.0000001},{0.0000001,0.0000001,0.0000001,0.0000001}};
	double matriceTest4[n][n] = {{0.0000001,0.0000001,0.0000001,0.0000001},{0.0000001,0.0000001,0.0000001,0.0000001},
		                         {0.0000001,0.0000001,0.0000001,0.0000001},{0.0000001,0.0000001,0.0000001,0.0000001}};
	double matriceResultat2[n][n];
	
	printf("Test avec des valeurs positionnees six chiffres apres la virgule : \n");
	printf("Matrice A:\n");
	AfficherMatriceMult(matriceTest3);
	printf("Matrice B:\n");
	AfficherMatriceMult(matriceTest4);
	printf("Resultat :\n");
	MultiplicationMatrices(matriceTest3, matriceTest4, matriceResultat2);
	
	printf("-------------------------------------------\n");
	
	//Test pour vérifier que le programme affiche des chiffres en mettant des lettres
	double matriceTest5[n][n] = {{1,'a',1,'a'},{'a','a',1,'a'},{'a','a',1,'a'},{'a',1,'a','a'}};
	double matriceTest6[n][n] = {{'a',1,'a','a'},{'a',1,'a','a'},{'a',1,'a','a'},{'a','a',1,'a'}};
	double matriceResultat3[n][n];
	
	printf("Test avec des valeurs correspondant a des caracteres : \n");
	printf("Matrice A:\n");
	AfficherMatriceMult(matriceTest5);
	printf("Matrice B:\n");
	AfficherMatriceMult(matriceTest6);
	printf("Resultat :\n");
	MultiplicationMatrices(matriceTest5, matriceTest6, matriceResultat3);
	
	printf("-------------------------------------------\n");
	
	//Test pour vérifier que le programme affiche le résultat si les valeurs des matrices sont négatives et élevées
	double matriceTest7[n][n] = {{-1343,-2324,-332432,-4434},{-632432,-74324,-832423,-9432},{-114324,-126565,-13435,-14432},
		                         {-1654,-1732,-183432,-19432}};
	double matriceTest8[n][n] = {{-1343,-2324,-332432,-4434},{-632432,-74324,-832423,-9432},{-114324,-126565,-13435,-14432},
		                         {-1654,-1732,-183432,-19432}};
	double matriceResultat4[n][n];
	
	printf("Test avec des valeurs negatives elevees : \n");
	printf("Matrice A:\n");
	AfficherMatriceMult(matriceTest7);
	printf("Matrice B:\n");
	AfficherMatriceMult(matriceTest8);
	printf("Resultat :\n");
	MultiplicationMatrices(matriceTest7, matriceTest8, matriceResultat4);
	
	return 0;
}

//Description: Multiplication de deux matrices paramétrées
//Précondition: Matrice carré avec le même nombre de colonnes et de lignes
//Postecondition: Matrice résultante possède le même nombre de colonnes et de lignes et le résultats est 0 si les valeurs sont cinq chiffres en-dessous de la virgule
void MultiplicationMatrices(double matrice1[n][n], double matrice2[n][n], double matrice3[n][n])
{
	int nombreLigne = 0;
	
	//Fait la multiplication de deux matrices
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			for(int k = 0; k < n; k++)
			{
				if(matrice1[i][k] < 0.00001 && matrice1[i][k] > -1)
					matrice1[i][k] = 0;
				if(matrice2[k][j] < 0.00001 && matrice2[k][j] > -1)
					matrice2[k][j] = 0;
				
				matrice3[i][j] = matrice3[i][j] + (matrice1[i][k] * matrice2[k][j]);
			}
		}
		nombreLigne++;
	}
	
	if (nombreLigne != n)
	{
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				matrice3[i][j] = 0;
			}
		}
	}
	else
		AfficherMatriceMult(matrice3);
}

void AfficherMatriceMult(double matriceResultat[n][n])
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			printf("%f  ", matriceResultat[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
