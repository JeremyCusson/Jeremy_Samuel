/********
Fichier: sin.c
Auteurs: Samuel Bouchard bous1938	
Jérémy Cusson cusj3102
Date: 04 octobre 2000
Description: Fonction permettant de calculer le sin d'un angle en radiant. Contient egalement une fonction pour de test automatise.
********/

#include <stdio.h>


// Declaration constante
const int NB_SERIE = 5;


int main(void)
{
	void validation();
	void planTest();
	printf("Validation: \n");
	validation();
	//printf("\n\nPlan de test: \n");
	//planTest();
}

void validation()
{
	const long double pi = 3.14159265358979323846264338327950288419716939937510582;
	float sinRad(long double);
	printf("sin(1), valeur attendu = 0.8415, valeur calcule = %f\n",sinRad(1));
	printf("sin(0), valeur attendu = 0, valeur calcule = %f\n",sinRad(0));
	printf("sin(pi/4), valeur attendu = 0.7071, valeur calcule = %f\n",sinRad(pi/4.0));
	printf("sin(pi/2), valeur attendu = 1, valeur calcule = %f\n",sinRad(pi/2.0));
}

void planTest()
{
	const long double pi = 3.14159265358979323846264338327950288419716939937510582;
	float sinRad(long double);
	printf("sin(2*pi), valeur attendu = 0, valeur calcule = %f\n",sinRad(2*pi));
	printf("sin(0), valeur attendu = 0, valeur calcule = %f\n",sinRad(0));
	printf("sin(300.5*pi), valeur attendu = 1, valeur calcule = %f\n",sinRad(300.5*pi));
	printf("sin(-300*pi), valeur attendu = 0, valeur calcule = %f\n",sinRad(-300*pi));
}

//Pre-condition: x en radian, NB_SERIE ne devrait
//	pas depasser 10 a 15 pour eviter le risque de 
//	perte de precision
//Post-Condition: si x < ou > 0 et 2 pi,
//	x ramener entre 0 et 2 pi pour calcul.
float sinRad(long double x)
{
	long double puissance(float,int);
	long long int factoriel(int);
	long double ramenerRadInterieurLimite(long double);
	x = ramenerRadInterieurLimite(x);

	//Represente la valeur prise au exposant
	// et a la factoriel pour le calcul du terme.
	int expoFacto = 1; 
	float total = 0;
	
	//Calcul du cos
	for (int i=0;i<NB_SERIE;i++)
	{
		//On calcul le therme de la series 
		float terme = puissance(x,expoFacto)/factoriel(expoFacto); 
		
		//On alterne l'addition et la soustraction 
		//du terme en debutant avec une addition
		if (i%2 == 0)
		{
			total += terme;
		}
		else
		{
			total -= terme;
		}
		expoFacto += 2;
	}	
	return total;
}


//Pre-condition: Valeur de n plus grande que 0
//Post-Condition: Si n plus grand que 0 retour de la factoriel sinon retourne 0
long double ramenerRadInterieurLimite(long double x)
{
	const long double pi = 3.14159265358979323846264338327950288419716939937510582;
	
	//Tant que x pas entre 0 et 2pi on continue a tourner dans le cercle
	while (x < 0 || x >= (2*pi))
	{
		 if (x < 0)
		 {
			 x += (2*pi);
		 }
		 else
		 {
			  x -= (2*pi);
		 }
	}
	
	return x;
}

//Pre-condition: Valeur de n plus grande que 0
//Post-Condition: Si n plus grand que 0 retour de la factoriel sinon retourne 0
long long int factoriel(int n)
{
	if (n<0)
	{
		return 0;
	}
	long long int tot=1;
	for(int i = 1;i<=n;i++)
	{
		tot *= i;
	}
	return tot;
}


//Post-Condition: si exposant negatif, devrait calculer 1/base exposant
long double puissance(float base,int exposant)
{
	float tot=1;
	int maxFor= exposant;
		
	if (exposant < 0)
	{
		maxFor *= -1;
	}
	
	for (int i = 0;i<maxFor;i++)
	{
		tot*=base;
	}
	
	if (exposant < 0)
	{
		tot = 1.0/tot;
		
	}
	
	return tot;
}
