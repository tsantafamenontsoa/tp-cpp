#ifndef PERSONNAGE_H
#define PERSONNAGE_H
#include <string>

class Personnage{
    private:
        std::string nomPersonnage;
        std::string hobby;

    public:
        Personnage();
        Personnage(std::string mon_nom,std::string mon_hobby);
        void parle(const std::string texte);
        void setnom(std::string nouveau_nom);
        std::string getnom();
        ~Personnage();
};

#endif
