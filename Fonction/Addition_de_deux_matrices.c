/********
 Fichier: Addition_de_deux_matrices.c
 Auteur: Jérémy Cusson cusj3102
 Date: 04 octobre 2020
 Description: Calcul d'une addition de deux matrices carrées
              et tests du limitage du codage
********/

#include <stdio.h>

#define M 3
#define N 2

void AdditionMatrice(double matriceA[M][N], double matriceB[M][N], double matriceResultat[M][N]);
void AfficherMatrice(double matrice[M][N]);

// Description: Test pour l'opération de l'addition de deux matrices
int main(void)
{
	//Test pour la validation pour avoir un résultat de {{7,7},{7,7},{7,7}}
	double matriceTest1[M][N] = {{1,2},{3,4},{5,6}};
	double matriceTest2[M][N] = {{6,5},{4,3},{2,1}};
	double matriceTest3[M][N];
	
	printf("Validation : \n");
	printf("Matrice A : \n");
	AfficherMatrice(matriceTest1);
	printf("Matrice B : \n");
	AfficherMatrice(matriceTest2);
	printf("Resultat : \n");
	AdditionMatrice(matriceTest1, matriceTest2, matriceTest3);
	AfficherMatrice(matriceTest3);
	
	printf("-------------------------------------------\n");
	
	//Test pour voir si l'opération est capable de calcul des valeurs élevées
	double matriceTest4[M][N] = {{10000000011, 20000000022},{30000000033, 40000000044},{50000000055, 60000000066}};
	double matriceTest5[M][N] = {{60000000066, 50000000055},{40000000044, 30000000033},{20000000022, 10000000011}};
	double matriceTest6[M][N];
	
	printf("Test avec des valeurs elevees : \n");
	printf("Matrice A : \n");
	AfficherMatrice(matriceTest4);
	printf("Matrice B : \n");
	AfficherMatrice(matriceTest5);
	printf("Resultat : \n");
	AdditionMatrice(matriceTest4, matriceTest5, matriceTest6);
	AfficherMatrice(matriceTest6);
	
	printf("-------------------------------------------\n");
	
	//Test pour voir si l'opération est capable de calcul des valeurs négatives élevées
	double matriceTest7[M][N] = {{-10000000011, -20000000022},{-30000000033, -40000000044},{-50000000055, -60000000066}};
	double matriceTest8[M][N] = {{-60000000066, -50000000055},{-40000000044, -30000000033},{-20000000022, -10000000011}};
	double matriceTest9[M][N];
	
	printf("Test avec des valeurs negatives elevees : \n");
	printf("Matrice A : \n");
	AfficherMatrice(matriceTest7);
	printf("Matrice B : \n");
	AfficherMatrice(matriceTest8);
	printf("Resultat : \n");
	AdditionMatrice(matriceTest7, matriceTest8, matriceTest9);
	AfficherMatrice(matriceTest9);
	
	printf("-------------------------------------------\n");
	
	//Test pour Test pour vérifier l'aboutissement du code avec des valeurs à virgul dans la matrice
	double matriceTest10[M][N] = {{0.0000001,0.0000001},{0.0000001,0.0000001},{0.0000001,0.0000001}};
	double matriceTest11[M][N] = {{0.0000001,0.0000001},{0.0000001,0.0000001},{0.0000001,0.0000001}};
	double matriceTest12[M][N];
	
	printf("Test avec des valeurs six chiffres apres la virgule : \n");
	printf("Matrice A : \n");
	AfficherMatrice(matriceTest10);
	printf("Matrice B : \n");
	AfficherMatrice(matriceTest11);
	printf("Resultat : \n");
	AdditionMatrice(matriceTest10, matriceTest11, matriceTest12);
	AfficherMatrice(matriceTest12);
	
	return 0;
}

//Description: Addition de deux matrices paramétrées
//Précondition: Les matrices additionnées doivents être initialisées
void AdditionMatrice(double matriceA[M][N], double matriceB[M][N], double matriceResultat[M][N])
{	
	for(int i = 0; i < M; i++)
	{
		for(int j = 0; j < N; j++)
		{
			matriceResultat[i][j] = matriceA[i][j] + matriceB[i][j];
		}
	}
}

void AfficherMatrice(double matrice[M][N])
{
	for(int i = 0; i < M; i++)
	{
		for(int j = 0; j < N; j++)
		{
			printf("%f  ", matrice[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
