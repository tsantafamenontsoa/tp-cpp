#include "Personnage.h"
#include <iostream>

using namespace std;

Personnage::Personnage(){
    nomPersonnage = "Jean";
    hobby = "Lire";
    std::cout << "Bonjour,je suis " +nomPersonnage+ " et je viens d'arriver en ville" << endl;
}

Personnage::Personnage(string mon_nom,string mon_hobby){
    nomPersonnage = mon_nom;
    hobby = mon_hobby;

    std::cout << "Bonjour,je suis " +nomPersonnage+ " et je viens d'arriver en ville" << endl;
}

void Personnage::parle(const string texte){
    std::cout << nomPersonnage+ " : " +texte << endl;
}

void Personnage::setnom(string le_nom){
    nomPersonnage = le_nom;
}

string Personnage::getnom(){
    return nomPersonnage;
}

Personnage::~Personnage(){
    std::cout << "Il n'y a plus rien à faire ici pour moi," +nomPersonnage+ "Adieu" << endl;
}

