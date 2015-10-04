#ifndef LIEU_H
#define LIEU_H
#include <string>

class Lieu{
    private:
        std::string nomLieu;
        bool estOuvert;

    public:
        Lieu();
        void ouvrir();
        void fermer();
        void setNom(std::string le_nom);
        std::string getNomLieu();
        ~Lieu();
};

#endif
