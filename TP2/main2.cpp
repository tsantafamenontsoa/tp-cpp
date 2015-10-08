#include <iostream>

using namespace std;
class Lieu{
    private:
        std::string nomLieu;
        bool estOuvert;
        Lieu** accessible[];
        long nbAccessible;

    public:
        Lieu();
        Lieu(std::string nom,bool etat);
        bool getEtat();
        void ouvrir();
        void fermer();
        void setNomLieu(std::string le_nom);
        std::string getNomLieu();
        long getNbAccessible();
        void setNbAccessible(long n);
        Lieu* getAccessible(long n);
        void addAccessible(Lieu* l);
        void removeAccessible(Lieu* l);
        long distance(const Lieu* l);
        ~Lieu();
};

class Transport{
    std::string mode;
    Lieu* desserte;

}

class Personnage{
    private:
        std::string nomPersonnage;
        std::string hobby;
        Lieu* lieu;

    public:
            Personnage(){
            nomPersonnage = "Jean";
            hobby = "Lire";
            std::cout << "Bonjour,je suis " +nomPersonnage+ " et je viens d'arriver en ville" << endl;
            lieu = NULL;
        }

        Personnage(string mon_nom,string mon_hobby){
            nomPersonnage = mon_nom;
            hobby = mon_hobby;
            lieu = NULL;
            std::cout << "Bonjour,je suis " +nomPersonnage+ " et je viens d'arriver en ville" << endl;
        }

        void parle(const string texte){
            std::cout << nomPersonnage+ " : " +texte << endl;
        }

        void setnom(string le_nom){
            nomPersonnage = le_nom;
        }

        string getnom(){
            return nomPersonnage;
        }

        Lieu* getLieu(){
            return lieu;
        }

        void setLieu(Lieu* l){
            lieu = l;
        }

        void deplace(Lieu* l,Transport* t){
            setLieu(l);
            string destination = l.getNomLieu();
            long dist = distance(l);
            std::cout << "Je vais à" +destination+ "en faisant" +dist+ "pas" << endl;
        }

        ~Personnage(){
            std::cout << "Il n'y a plus rien à faire ici pour moi," +nomPersonnage+ " Adieu" << endl;
        }

};


        Lieu::Lieu(){
        }

        Lieu::Lieu(string nom,bool etat): nomLieu(nom), estOuvert(etat), nbAccessible(0){
            *accessible = 0;
        }

        bool Lieu::getEtat(){
            return estOuvert;
        }

        void Lieu::ouvrir(){
            estOuvert = true;
        }

        void Lieu::fermer(){
            estOuvert = false;
        }

        void Lieu::setNomLieu(string le_nom){
            nomLieu = le_nom;
        }

        long Lieu::getNbAccessible(){
            return nbAccessible;
        }

        void Lieu::setNbAccessible(long n){
            nbAccessible = n;
        }

        string Lieu::getNomLieu(){
            return nomLieu;
        }

        Lieu* Lieu::getAccessible(long n){
            return *accessible[n];
        }

        void Lieu::addAccessible(Lieu* l){
            int n = getNbAccessible();
            accessible[n] = &l;
            setNbAccessible(n+1);
        }

        void Lieu::removeAccessible(Lieu* l){
            int n = getNbAccessible();
            for(int i=0;i<n;i++){
                if(*accessible[i] == l){
                    for(int j=i;j<n;j++)
                        *accessible[j] = *accessible[j+1];
                }
            }
            *accessible[n] = NULL;
            setNbAccessible(n-1);
        }

        long Lieu::distance(const Lieu* l){
            int n = getNbAccessible();
            for(long i=0;i<n;i++){
                if(*accessible[i] == l){
                    return i;
                }
                }
        }


        Lieu::~Lieu(){

        }


int main(){
    //cout << "Bonjour,je suis  et je viens d'arriver en ville" << endl;
    Personnage Jean("Joseph","Ecrire");
    Lieu ici("st maur",false);
    Lieu labas("paris13",false);
    string nom = Jean.getnom();
    Lieu* ptr = Jean.getLieu();
    string lieu = ici.getNomLieu();
    std::cout << nom << endl;
    ici.addAccessible(ptr);
    long nbr = ici.getNbAccessible();
    std::cout << nbr << endl;
    Lieu* endroit = ici.getAccessible(0);
    std::cout << (*endroit).getNomLieu() << endl;
    ici.removeAccessible(ptr);
    std::cout << ici.getNbAccessible() << endl;
    return 0;
}
