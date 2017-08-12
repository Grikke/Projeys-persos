// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "targetver.h"
#include <stdlib.h>
#include <string>
#include <iostream>
//#include <io>
using namespace std;

// variables globales
int nombreVies;
string motADeviner;
string motCourant;
string listeLettreProp;

int essaiJoueur() //fonction d'essai du joueur 
{
	bool test; // variable pour le test de la récurrence de la lettre proposée
	char lettreProp;
	do {
		cout << "Choisis une lettre :";
		cin >> lettreProp;
		test = true;
		for (int i = 0; i < listeLettreProp.length(); i++) {
			if (lettreProp == listeLettreProp[i]) {
				test = false;
				cout << "Lettre deja choisie \n";
			}
		}
	} while (!test);
	listeLettreProp += lettreProp;
	bool propEstDansMot = false;
	for (int i = 0; i < motADeviner.length(); i++) {
		if (lettreProp == motADeviner[i]) {
			propEstDansMot = true;
			motCourant[i] = lettreProp; // ajout de la lettre devinée au mot en construction
		}
	}
	if (!propEstDansMot) {
		cout << "Dommage, la lettre n'est pas dans le mot.\n";
		nombreVies--;
		cout << "Il te reste " << nombreVies << " vies.\n";
	}
	else {
		cout << "Bien joue ! \n";
		cout << "Il te reste " << nombreVies << " vies.\n";
	}
	return 0;
}

int initialisation(int vies) // fonction d'initialisation du jeu
{
	nombreVies = vies;
	cout << "Entrez le mot a deviner :";
	cin >> motADeviner;
	system("cls");
	motCourant = "";
	for (int i = 0;i < motADeviner.length();i++) {
		motCourant += "_";
	}
	listeLettreProp = "";
	return 0;
}

int main()
{
	int vies;
	cout << "Entrez le nombre de vie de la partie :";
	cin >> vies;
	initialisation(vies);
	while (nombreVies > 0 && motADeviner != motCourant) {
		essaiJoueur();
		cout << motCourant << "\n";
	}
	if (nombreVies > 0) {
		cout << "C'est gagne ! Bravo ! \n Entre un nombre";
		cin >> vies;
	}
	else
	{
		cout << "Game over ! \n Mot qu'il fallait deviner etais \"" << motADeviner << "\"\nEntre un nombre ";
		cin >> vies;
	}
    return 0;
}




