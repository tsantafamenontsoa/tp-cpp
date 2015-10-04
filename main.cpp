#include "Personnage.h"
#include "Lieu.h"
#include <iostream>

using namespace std;

int main(){
    cout << "Bonjour,je suis  et je viens d'arriver en ville" << endl;

    Personnage Jean;
    string nom = Jean.getnom();
    cout << nom << endl;
    return 0;
}
