/********
 Fichier: Multiplication_de_deux_matrices.c
 Auteur: Jérémy Cusson cusj3102
 Date: 02 octobre 2020
 Description: Calcul d'une multiplication de deux matrices carrées
              et tests du limitage du codage
********/

#include <stdio.h>
#define N 4

void MultiplicationMatrices(double matrice1[N][N], double matrice2[N][N], double matriceResultat[N][N]);
void AfficherMatrice(double matriceResultat[N][N]);
void InitialisationZero(double matrice3[N][N]);

// Description: Test pour l'opération de la multiplication de deux matrices
int main(void)
{	
	//Test pour vérifier l'aboutissement du code avec des valeurs extrèmes dans la matrice
	double matriceTest1[N][N] = {{100,200,300,400},{600,700,800,900},{110,120,130,140},{160,170,180,190}};
	double matriceTest2[N][N] = {{500,500,500,500},{400,400,400,400},{300,300,300,300},{200,200,200,200}};
	double matriceResultat1[N][N] = {0};
	
	printf("Test avec des valeurs extremes : \n");
	printf("Matrice A:\n");
	AfficherMatrice(matriceTest1);
	printf("Matrice B:\n");
	AfficherMatrice(matriceTest2);
	printf("Resultat :\n");
	MultiplicationMatrices(matriceTest1, matriceTest2, matriceResultat1);
	AfficherMatrice(matriceResultat1);
	
	printf("-------------------------------------------\n");
	
	//Test pour vérifier l'aboutissement du code avec des valeurs à virgul dans la matrice
	double matriceTest3[N][N] = {{0.0000001,0.0000001,0.0000001,0.0000001},{0.0000001,0.0000001,0.0000001,0.0000001},
		                         {0.0000001,0.0000001,0.0000001,0.0000001},{0.0000001,0.0000001,0.0000001,0.0000001}};
	double matriceTest4[N][N] = {{0.0000001,0.0000001,0.0000001,0.0000001},{0.0000001,0.0000001,0.0000001,0.0000001},
		                         {0.0000001,0.0000001,0.0000001,0.0000001},{0.0000001,0.0000001,0.0000001,0.0000001}};
	double matriceResultat2[N][N] = {0};
	
	printf("Test avec des valeurs positionnees six chiffres apres la virgule : \n");
	printf("Matrice A:\n");
	AfficherMatrice(matriceTest3);
	printf("Matrice B:\n");
	AfficherMatrice(matriceTest4);
	printf("Resultat :\n");
	MultiplicationMatrices(matriceTest3, matriceTest4, matriceResultat2);
	AfficherMatrice(matriceResultat2);
	
	printf("-------------------------------------------\n");
	
	//Test pour vérifier que le programme affiche des chiffres en mettant des lettres
	double matriceTest5[N][N] = {{1,'a',1,'a'},{'a','a',1,'a'},{'a','a',1,'a'},{'a',1,'a','a'}};
	double matriceTest6[N][N] = {{'a',1,'a','a'},{'a',1,'a','a'},{'a',1,'a','a'},{'a','a',1,'a'}};
	double matriceResultat3[N][N] = {0};
	
	printf("Test avec des valeurs correspondant a des caracteres : \n");
	printf("Matrice A:\n");
	AfficherMatrice(matriceTest5);
	printf("Matrice B:\n");
	AfficherMatrice(matriceTest6);
	printf("Resultat :\n");
	MultiplicationMatrices(matriceTest5, matriceTest6, matriceResultat3);
	AfficherMatrice(matriceResultat3);
	
	printf("-------------------------------------------\n");
	
	//Test pour vérifier que le programme affiche le résultat si les valeurs des matrices sont négatives et élevées
	double matriceTest7[N][N] = {{-1343,-2324,-332432,-4434},{-632432,-74324,-832423,-9432},{-114324,-126565,-13435,-14432},
		                         {-1654,-1732,-183432,-19432}};
	double matriceTest8[N][N] = {{-1343,-2324,-332432,-4434},{-632432,-74324,-832423,-9432},{-114324,-126565,-13435,-14432},
		                         {-1654,-1732,-183432,-19432}};
	double matriceResultat4[N][N]= {0};
	
	printf("Test avec des valeurs negatives elevees : \n");
	printf("Matrice A:\n");
	AfficherMatrice(matriceTest7);
	printf("Matrice B:\n");
	AfficherMatrice(matriceTest8);
	printf("Resultat :\n");
	MultiplicationMatrices(matriceTest7, matriceTest8, matriceResultat4);
	AfficherMatrice(matriceResultat4);
	
	return 0;
}

//Description: Multiplication de deux matrices paramétrées
//Précondition: Les matrices multipliées sont initialisées et la matrice résultante est initialisée à zéro
void MultiplicationMatrices(double matrice1[N][N], double matrice2[N][N], double matrice3[N][N])
{
	InitialisationZero(matrice3);
	
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			for(int k = 0; k < N; k++)
			{	
				matrice3[i][j] = matrice3[i][j] + matrice1[i][k] * matrice2[k][j];
			}
		}
	}
}

void AfficherMatrice(double matriceResultat[N][N])
{
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			printf("%f  ", matriceResultat[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void InitialisationZero(double matrice3[N][N])
{
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			matrice3[i][j] = 0;
		}
	}
}
