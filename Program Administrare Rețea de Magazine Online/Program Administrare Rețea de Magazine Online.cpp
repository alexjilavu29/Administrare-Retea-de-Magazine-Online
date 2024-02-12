#include<iostream>
#include<string>
#include <fstream>
#include<stdlib.h>
#include <map>
using namespace std;

class Interfata {
public:
    virtual void adaugareProduse() = 0;
    virtual void selectareProduse() = 0;
};

class Utilizator
{
protected:
    string numeUtilizator;
    string email;
    string tipUtilizator;
    string parola;
    static int nrUtilizatori;

public:
    // GETTERI
    string getNumeUtilizator()
    {
        return numeUtilizator;
    }
    string getEmail()
    {
        return email;
    }
    string getTipUtilizator()
    {
        return tipUtilizator;
    }
    string getParola()
    {
        return parola;
    }
    static int getNrUtilizatori() {
        return nrUtilizatori;
    }

    // SETTERI
    void setNumeUtilizator(string numeUtilizator)
    {
        if (numeUtilizator.size() > 0)
            this->numeUtilizator = numeUtilizator;
    }
    void setEmail(string email)
    {
        if (email.size() > 0)
            this->email = email;
    }
    void setTipUtilizator(string tipUtilizator)
    {
        int ok = 0;
        if (tipUtilizator == "Magazin" || tipUtilizator == "Client")
            ok = 1;
        if (ok == 0)
            cout << "Utilizatorul introdus trebuie sa fie Magazin sau Client." << endl;
        else
            this->tipUtilizator = tipUtilizator;
    }
    void setParola(string parola)
    {
        int ok = 1;
        // Verificam daca parola are cel putin 8 caractere
        if (parola.length() < 8)
        {
            cout << "Parola introdusa are mai putin de 8 caractere" << endl;
            ok = 0;
        }
        // Verificam daca parola are cel putin o litera mare
        bool hasMajuscula = false;
        for (int i = 0; i < parola.length(); i++)
        {
            if (isupper(parola[i]))
            {
                hasMajuscula = true;
                break;
            }
        }
        if (!hasMajuscula)
        {
            cout << "Parola introdusa trebuie sa contina minim o majuscula." << endl;
            ok = 0;
        }
        // Verificam daca parola are cel putin un numar
        bool hasNumar = false;
        for (int i = 0; i < parola.length(); i++)
        {
            if (isdigit(parola[i]))
            {
                hasNumar = true;
                break;
            }
        }
        if (!hasNumar)
        {
            cout << "Parola trebuie sa contina cel putin un numar." << endl;
            ok = 0;
        }

        if (ok == 1)
            this->parola = parola;
        else
        {
            cout << "Parola introdusa este incompleta";
            return;
        }
    }
    static int setNrUtilizatori(int nrUtilizatori) {
        if (nrUtilizatori >= 0)
            Utilizator::nrUtilizatori = nrUtilizatori;
    }
    // Constructor fara parametri
    Utilizator() { //lista de initializare (este necesara pentru atributele constante)
        this->numeUtilizator = "N/A";
        this->email = "N/A";
        this->tipUtilizator = "Neselectat";
        this->parola = "Parola123";
        nrUtilizatori++;

        //cout << "APEL -- CONSTRUCTOR FARA PARAMETRI -- " << endl;
    }
    // Constructor cu parametri
    Utilizator(string numeUtilizator, string email, string tipUtilizator, string parola)
    {
        // numeUtilizator
        if (numeUtilizator.size() > 0)
            this->numeUtilizator = numeUtilizator;
        else
            this->numeUtilizator = "N/A";

        // email
        if (email.size() > 0)
            this->email = email;
        else
            this->email = "N/A";

        // tipUtilizator
        int ok = 0;
        if (tipUtilizator == "Magazin" || tipUtilizator == "Client")
            ok = 1;
        if (ok == 0)
        {
            cout << "Utilizatorul introdus trebuie sa fie Magazin sau Client." << endl;
            this->tipUtilizator = "Neselectat";
        }
        else
            this->tipUtilizator = tipUtilizator;

        // parola
        ok = 1;
        if (parola.length() < 8)
        {
            cout << "Parola introdusa are mai putin de 8 caractere" << endl;
            ok = 0;
        }
        bool hasMajuscula = false;
        for (int i = 0; i < parola.length(); i++)
        {
            if (isupper(parola[i]))
            {
                hasMajuscula = true;
                break;
            }
        }
        if (!hasMajuscula)
        {
            cout << "Parola introdusa trebuie sa contina minim o majuscula." << endl;
            ok = 0;
        }
        bool hasNumar = false;
        for (int i = 0; i < parola.length(); i++)
        {
            if (isdigit(parola[i]))
            {
                hasNumar = true;
                break;
            }
        }
        if (!hasNumar)
        {
            cout << "Parola trebuie sa contina cel putin un numar." << endl;
            ok = 0;
        }

        if (ok == 1)
            this->parola = parola;
        else
        {
            cout << "Parola introdusa este incompleta. Parola se va completa automat cu 'Parola123'.";
            this->parola = "Parola123";
            return;
        }

        nrUtilizatori++;

        //cout << "APEL -- CONSTRUCTOR CU PARAMETRI -- " << endl;
    }
    // Constructor de copiere
    Utilizator(const Utilizator& u)
    {
        this->numeUtilizator = u.numeUtilizator;
        this->email = u.email;
        this->tipUtilizator = u.tipUtilizator;
        this->parola = u.parola;
        nrUtilizatori++;
        // cout << "APEL -- CONSTRUCTOR DE COPIERE -- " << endl;
    }
    // Supraincarcare Operator =
    Utilizator operator=(const Utilizator& u) {

        this->numeUtilizator = u.numeUtilizator;
        this->email = u.email;
        this->tipUtilizator = u.tipUtilizator;
        this->parola = u.parola;
        return *this;
    }
    // Destructor
    ~Utilizator() {
        nrUtilizatori--;
        //cout << "APEL -- DESTRUCTOR -- " << endl;
    }
};



class Produs
{
private:
    string numeProdus;
    float pret;
    int cantDisponibila;
public:
    //getteri
    string getNumeProdus()
    {
        return numeProdus;
    }
    float getPret()
    {
        return pret;
    }
    int getCantDisponibila()
    {
        return cantDisponibila;
    }
    //setteri
    void setNumeProdus(string numeProdus)
    {
        if (numeProdus.size() > 0)
            this->numeProdus = numeProdus;
        else
            this->numeProdus = "Nedefinit";
    }
    void setPret(float pret)
    {
        if (pret >= 0)
            this->pret = pret;
        else
            cout << "Pretul trebuie sa fie un numar pozitiv" << endl;
    }
    void setCantDisponibila(int cantDisponibila)
    {
        if (cantDisponibila >= 0)
            this->cantDisponibila = cantDisponibila;
        else
            cout << "Nu pot exista cantitati negative" << endl;
    }
    //constructor fara parametri
    Produs()
    {
        this->numeProdus = "Nedefinit";
        this->pret = 0;
        this->cantDisponibila = 0;

        // cout << "APEL- CONSTRUCTOR FARA PARAMETRII -- " << endl;
    }
    //constructor cu parametri
    Produs(string numeProdus, float pret, int cantDisponibila)
    {
        if (numeProdus.size() > 0)
            this->numeProdus = numeProdus;
        else
            this->numeProdus = "Nedefinit";

        if (pret >= 0)
            this->pret = pret;
        else
            cout << "Pretul trebuie sa fie un numar pozitiv" << endl;

        if (cantDisponibila >= 0)
            this->cantDisponibila = cantDisponibila;
        else
            cout << "Nu pot exista cantitati negative" << endl;
    }
    //constructor de copiere
    Produs(const Produs& pr)
    {
        this->numeProdus = pr.numeProdus;
        this->pret = pr.pret;
        this->cantDisponibila = pr.cantDisponibila;
    }
    //supraincarcare operator =
    Produs operator=(const Produs& pr)
    {
        this->numeProdus = pr.numeProdus;
        this->pret = pr.pret;
        this->cantDisponibila = pr.cantDisponibila;
        return *this;
    }
    //destructor
    ~Produs()
    {
        //cout << "APEL -- DESTRUCTOR --" << endl;
    }

    friend istream& operator>>(istream& in, Produs& p);
    //friend Magazin& operator^(string nume, Magazin &p);
};
class Comanda //produse, pret total, date client
{
private:
    string numeClient;
    string adresaClient;
    Produs* produseComandate;
    int nrProduseComandate;
    float pretTotal;
    static int nrComenzi;

public:
    //getteri
    string getNumeClient()
    {
        return numeClient;
    }
    string getAdresaClient()
    {
        return adresaClient;
    }
    Produs* getProduseComandate()
    {
        return produseComandate;
    }

    float getPretTotal()
    {
        return pretTotal;
    }
    int getNrProduseComandate()
    {
        return nrProduseComandate;
    }

    static int getNrComenzi()
    {
        return nrComenzi;
    }
    //setteri
    void setNumeClient(string numeClient)
    {
        if (numeClient.size() > 0)
            this->numeClient = numeClient;
        else
            this->numeClient = "Necompletat";
    }

    void setAdresaClient(string adresaClient)
    {
        if (adresaClient.size() > 0)
            this->adresaClient = adresaClient;
    }

    void setProduseComandate(Produs* produseComandate)
    {
        this->produseComandate = new Produs[this->nrProduseComandate];
        for (int i = 0; i < this->nrProduseComandate; i++)
            this->produseComandate[i] = produseComandate[i];


    }
    void setNrProduseComandate(int nrProduseComandate)
    {
        if (nrProduseComandate > 0)
            this->nrProduseComandate = nrProduseComandate;
        else
            cout << "Niciun produs comandat" << endl;
    }

    void setPretTotal(float pretTotal)
    {
        if (pretTotal >= 0)
            this->pretTotal = pretTotal;
        else
            cout << "Pretul trebuie sa fie un numar pozitiv" << endl;

    }
    static int setNrComenzi(int nrComenzi) {
        if (nrComenzi >= 0)
            Comanda::nrComenzi = nrComenzi;
    }
    //constructor fara parametri
    Comanda() {
        this->numeClient = "N/A";
        this->adresaClient = "N/A";
        this->nrProduseComandate = 0;
        this->produseComandate = nullptr;
        this->pretTotal = 0;
        nrComenzi++;
        //cout << "APEL- CONSTRUCTOR FARA PARAMETRII -- " << endl;

    }
    //constructor cu parametri
    Comanda(string numeClient, string adresaClient, int nrProduseComandate, Produs* produseComandate, float pretTotal)
    {
        //nume
        if (numeClient.size() > 0)
            this->numeClient = numeClient;
        else
            this->numeClient = "Nu ati completat numele";
        //adresa
        if (adresaClient.size() > 0)
            this->adresaClient = adresaClient;
        else
            this->adresaClient = "Nu ati completat adresa";

        //nr de produse comandate
        if (nrProduseComandate >= 0)
            this->nrProduseComandate = nrProduseComandate;
        else this->nrProduseComandate = 0;

        //produsele comandate
        if (produseComandate != nullptr)
        {
            this->produseComandate = new Produs[this->nrProduseComandate];

            for (int i = 0; i < this->nrProduseComandate; i++)
                this->produseComandate[i] = produseComandate[i];
        }
        else
            this->produseComandate = nullptr;

        //pretul total
        if (pretTotal >= 0)
            this->pretTotal = pretTotal;
        else
            cout << "Pretul trebuie sa fie un numar pozitiv" << endl;
        nrComenzi++;
        // cout << "APEL -- CONSTRUCTOR CU PARAMETRI -- " << endl;
    }


    //constructorul de copiere
    Comanda(const Comanda& sursa)
    {
        this->numeClient = sursa.numeClient;
        this->adresaClient = sursa.adresaClient;
        this->nrProduseComandate = sursa.nrProduseComandate;
        this->produseComandate = new Produs[this->nrProduseComandate];
        for (int i = 0; i < this->nrProduseComandate; i++)
            this->produseComandate[i] = sursa.produseComandate[i];
        this->pretTotal = sursa.pretTotal;
        nrComenzi++;
        //cout << "APEL -- CONSTRUCTOR DE COPIERE -- " << endl;
    }
    //supreaincarcare operator =
    Comanda operator=(const Comanda& co) {
        this->numeClient = co.numeClient;
        this->adresaClient = co.adresaClient;
        this->pretTotal = co.pretTotal;
        this->nrProduseComandate = co.nrProduseComandate;
        if (this->produseComandate != nullptr)
            delete[] this->produseComandate;
        this->produseComandate = new Produs[this->nrProduseComandate];
        for (int i = 0; i < this->nrProduseComandate; i++)
            this->produseComandate[i] = produseComandate[i];
        return *this;

    }
    //destructor
    ~Comanda()
    {
        nrComenzi--;
        //cout << "APEL -- DESTRUCTOR --" << endl;
    }

    void raportComanda(ofstream& outTxtComanda) {
        outTxtComanda << " ----  COMANDA NO. " << this->getNrComenzi << " ";
        for (int i = 0; i < this->getNrProduseComandate(); i++) {
            outTxtComanda << "Produsul nr. " << i + 1 << ": " << endl;
            outTxtComanda << "    -> Nume: " << this->getProduseComandate()[i].getNumeProdus() << endl;
            outTxtComanda << "    -> Pret: " << this->getProduseComandate()[i].getPret() << endl;
        }
        outTxtComanda << "     --------------------- TOTAL: " << this->getPretTotal() << " LEI " << endl;
        outTxtComanda << endl;
        outTxtComanda << " --- DATE PERSONALE ---" << endl;
        outTxtComanda << " -> Nume client: " << this->getNumeClient();
        outTxtComanda << " -> Adresa Client: " << this->getAdresaClient();
        outTxtComanda << endl;
    }
    void serializare(ofstream& out)
    {
        out.write((char*)this, sizeof(Comanda));
    }

    void deserializare(ifstream& in)
    {
        in.read((char*)this, sizeof(Comanda));
    }

    friend ofstream& operator<<(ofstream& out, Comanda c)
    {
        out << "  " << c.getNrProduseComandate() << endl;

        for (int i = 0; i < c.getNrProduseComandate(); i++)
            out << c.getProduseComandate()[i].getNumeProdus() << " ";

        return out;
    }

    friend ostream& operator<<(ostream& out, Comanda c) {
        out << "  " << c.getNrProduseComandate() << endl;

        for (int i = 0; i < c.getNrProduseComandate(); i++)
            out << c.getProduseComandate()[i].getNumeProdus() << " ";
        cout << endl;
        return out;
    }

    friend class Produs;
};

class Magazin :
    public Utilizator

{
protected:
    int idMagazin;
    string numeMagazin;
    int nrProduseDisponibile;
    Produs* produseDisponibile;
    int nrComenziPrimite;
    Comanda* comenziPrimite;
    string adresaMagazin;
    static int nrMagazine;

public:
    // GETTERI
    int getIdMagazin()
    {
        return idMagazin;
    }
    string getNumeMagazin()
    {
        return numeMagazin;
    }
    int getNrProduseDisponibile()
    {
        return nrProduseDisponibile;
    }
    Produs* getProduseDisponibile()
    {
        return produseDisponibile;
    }
    int getNrComenziPrimite()
    {
        return nrComenziPrimite;
    }
    Comanda* getComenziPrimite()
    {
        return comenziPrimite;
    }
    string getAdresa()
    {
        return adresaMagazin;
    }
    static int getNrMagazine() {
        return nrMagazine;
    }

    // SETTERI
    void setIdMagazin(int idMagazin)
    {
        if (idMagazin >= 0)
            this->idMagazin = idMagazin;
    }
    void setNumeMagazin(string numeMagazin)
    {
        if (numeMagazin.size() > 0)
            this->numeMagazin = numeMagazin;
    }

    void setProduseDisponibile(int nrProduseDisponibile, Produs* produseDisponibile) {
        if (nrProduseDisponibile >= 0 && produseDisponibile != nullptr) {
            this->nrProduseDisponibile = nrProduseDisponibile;

            if (this->produseDisponibile != nullptr)
                delete[] this->produseDisponibile;

            this->produseDisponibile = new Produs[this->nrProduseDisponibile];

            for (int i = 0; i < this->nrProduseDisponibile; i++)
                this->produseDisponibile[i] = produseDisponibile[i];
        }
    }

    void setComenziPrimite(int nrComenziPrimite, Comanda* comenziPrimite) {
        if (nrComenziPrimite >= 0 && comenziPrimite != nullptr) {
            this->nrComenziPrimite = nrComenziPrimite;

            if (this->comenziPrimite != nullptr)
                delete[] this->comenziPrimite;

            this->comenziPrimite = new Comanda[this->nrComenziPrimite];

            for (int i = 0; i < this->nrComenziPrimite; i++)
                this->comenziPrimite[i] = comenziPrimite[i];
        }
    }

    void setAdresa(string adresa)
    {
        if (adresa.size() > 0)
            this->adresaMagazin = adresaMagazin;
    }

    static int setNrMagazine(int nrMagazine) {
        if (nrMagazine >= 0)
            Magazin::nrMagazine = nrMagazine;
    }

    // CONSTRUCTOR FARA PARAMETRI
    Magazin() : Utilizator()
    {
        this->idMagazin = 0;
        this->numeMagazin = "N/A";
        this->nrProduseDisponibile = 0;
        this->produseDisponibile = nullptr;
        this->nrComenziPrimite = 0;
        this->comenziPrimite = nullptr;
        this->adresaMagazin = "N/A";
        nrMagazine++;
    }

    // CONSTRUCTOR CU PARAMETRI
    Magazin(int idMagazin, string numeUtilizator, string email, string tipUtilizator, string parola, string numeMagazin, int nrProduseDisponibile, Produs* produseDisponibile, int nrComenziPrimite, Comanda* comenziPrimite, string adresaMagazin) : Utilizator(numeUtilizator, email, tipUtilizator, parola)
    {
        if (idMagazin >= 0)
            this->idMagazin = idMagazin;
        if (numeMagazin.size() > 0)
            this->numeMagazin = numeMagazin;
        if (nrProduseDisponibile >= 0 && produseDisponibile != nullptr) {
            this->nrProduseDisponibile = nrProduseDisponibile;

            if (this->produseDisponibile != nullptr)
                delete[] this->produseDisponibile;

            this->produseDisponibile = new Produs[this->nrProduseDisponibile];

            for (int i = 0; i < this->nrProduseDisponibile; i++)
                this->produseDisponibile[i] = produseDisponibile[i];
        }
        else
        {
            this->produseDisponibile = nullptr;
        }
        if (nrComenziPrimite >= 0 && comenziPrimite != nullptr) {
            this->nrComenziPrimite = nrComenziPrimite;

            if (this->comenziPrimite != nullptr)
                delete[] this->comenziPrimite;

            this->comenziPrimite = new Comanda[this->nrComenziPrimite];

            for (int i = 0; i < this->nrComenziPrimite; i++)
                this->comenziPrimite[i] = comenziPrimite[i];
        }
        else
        {
            this->comenziPrimite = nullptr;
        }
        if (adresaMagazin.size() > 0)
            this->adresaMagazin = adresaMagazin;
        nrMagazine++;
        // cout << "APEL -- CONSTRUCTOR CU PARAMETRI -- " << endl;
    }

    // CONSTRUCTOR DE COPIERE
    Magazin(const Magazin& ma)
    {
        this->numeUtilizator = ma.numeUtilizator;
        this->parola = ma.parola;
        this->idMagazin = ma.idMagazin;
        this->numeMagazin = ma.numeMagazin;
        this->nrProduseDisponibile = ma.nrProduseDisponibile;
        this->produseDisponibile = new Produs[this->nrProduseDisponibile];
        for (int i = 0; i < this->nrProduseDisponibile; i++)
            this->produseDisponibile[i] = ma.produseDisponibile[i];
        this->nrComenziPrimite = ma.nrComenziPrimite;
        this->comenziPrimite = new Comanda[this->nrComenziPrimite];
        for (int i = 0; i < this->nrComenziPrimite; i++)
        {
            this->comenziPrimite[i] = ma.comenziPrimite[i];
            this->comenziPrimite[i].setProduseComandate(ma.comenziPrimite[i].getProduseComandate());
        }
        this->adresaMagazin = ma.adresaMagazin;
        nrMagazine++;
    }

    Magazin operator=(const Magazin& mag) {
        this->numeUtilizator = mag.numeUtilizator;
        this->parola = mag.parola;
        this->idMagazin = mag.idMagazin;
        this->numeMagazin = mag.numeMagazin;
        this->nrProduseDisponibile = mag.nrProduseDisponibile;
        this->produseDisponibile = new Produs[this->nrProduseDisponibile];
        for (int i = 0; i < this->nrProduseDisponibile; i++)
            this->produseDisponibile[i] = mag.produseDisponibile[i];
        this->nrComenziPrimite = mag.nrComenziPrimite;
        this->comenziPrimite = new Comanda[this->nrComenziPrimite];
        for (int i = 0; i < this->nrComenziPrimite; i++)
            this->comenziPrimite[i] = mag.comenziPrimite[i];
        this->adresaMagazin = mag.adresaMagazin;
        return *this;
    }

    // DESTRUCTOR
    ~Magazin() {
        nrMagazine--;
        if (this->produseDisponibile != nullptr)
            delete[] this->produseDisponibile;
        if (this->comenziPrimite != nullptr)
            delete[] this->comenziPrimite;
        //cout << "APEL -- DESTRUCTOR -- " << endl;
    }

    void adaugareProduse() {
        int aux;
        cout << endl << "ADAUGARE PRODUSE IN MAGAZINUL " << this->numeMagazin << " " << endl;
        cout << "Introduceti numarul de produse pe care doriti sa le adaugati: ";
        cin >> aux;
        Produs* pd;
        pd = new Produs[this->nrProduseDisponibile];
        for (int i = 0; i < this->nrProduseDisponibile; i++)
            pd[i] = this->produseDisponibile[i];
        if (aux > 0)
        {
            this->nrProduseDisponibile = this->nrProduseDisponibile + aux;
            cout << "Numarul total de produse a fost actualizat la " << this->nrProduseDisponibile << "." << endl;
            cout << endl;
        }
        delete[] this->produseDisponibile;
        this->produseDisponibile = new Produs[this->nrProduseDisponibile];
        for (int i = 0; i < this->nrProduseDisponibile; i++)
        {
            if (i < (this->nrProduseDisponibile - aux))
                this->produseDisponibile[i] = pd[i];
            else
            {
                cout << "Introduceti numele produsului cu numarul " << i + 1 << ": " << endl;
                cin >> this->produseDisponibile[i];
            }
        }
    }

    void stergereProduse()
    {
        string nume;
        int poz = 0;
        cout << "Introduceti numele produsului pe care doriti sa il stergeti:";
        cin >> nume;
        for (int i = 0; i < this->nrProduseDisponibile; i++)
            if (this->getProduseDisponibile()[i].getNumeProdus() == nume)
            {
                poz = i;
                break;
            }
        for (int i = poz - 1; i < this->nrProduseDisponibile - 1; i++)
            produseDisponibile[i] = produseDisponibile[i + 1];
        Produs* tmp = new Produs[--this->nrProduseDisponibile];
        int j = 0;
        for (int i = 0; i < nrProduseDisponibile; i++)
        {
            tmp[j] = this->produseDisponibile[i];
            j++;
        }
        delete[] this->produseDisponibile;
        this->produseDisponibile = tmp;
        cout << "Produsul cu numele " << nume << " a fost sters." << endl;
    }

    void adaugareComanda(Comanda co)
    {
        Comanda* tmp;
        tmp = new Comanda[this->nrComenziPrimite];
        for (int i = 0; i < this->nrComenziPrimite; i++)
            tmp[i] = this->comenziPrimite[i];
        this->nrComenziPrimite = this->nrComenziPrimite + 1;
        delete[] this->comenziPrimite;
        this->comenziPrimite = new Comanda[this->nrComenziPrimite];
        for (int i = 0; i < this->nrComenziPrimite; i++)
        {
            if (i < (this->nrComenziPrimite - 1))
                this->comenziPrimite[i] = tmp[i];
            else
            {
                this->comenziPrimite[i].setNumeClient(co.getNumeClient());
                this->comenziPrimite[i].setAdresaClient(co.getAdresaClient());
                this->comenziPrimite[i].setNrProduseComandate(co.getNrProduseComandate());
                this->comenziPrimite[i].setPretTotal(co.getPretTotal());
            }
        }
    }

    Magazin& operator +() //operator care adauga produse in magazin
    {
        int aux, cantitate;
        string nume;
        float pret;
        cout << " -------------------------------" << "ADAUGARE PRODUSE IN MAGAZINUL " << this->numeMagazin << "------------------------" << endl;
        cout << "|                                                                                        |" << endl;
        cout << "|  -- Introduceti numarul de produse pe care doriti sa le adaugati: ";
        cin >> aux;
        cout << "|                                                                                        " << endl;
        Produs* pd;
        pd = new Produs[this->nrProduseDisponibile];
        for (int i = 0; i < this->nrProduseDisponibile; i++)
            pd[i] = this->produseDisponibile[i];
        if (aux > 0)
        {
            this->nrProduseDisponibile = this->nrProduseDisponibile + aux;
            cout << "|      #Numarul total de produse a fost actualizat la " << this->nrProduseDisponibile << "." << endl;
        }
        delete[] this->produseDisponibile;
        this->produseDisponibile = new Produs[this->nrProduseDisponibile];
        for (int i = 0; i < this->nrProduseDisponibile; i++)
        {
            if (i < (this->nrProduseDisponibile - aux))
                this->produseDisponibile[i] = pd[i];
            else
            {
                cout << "|            == Introduceti numele produsului cu numarul " << i + 1 << ": ";
                cin >> nume;
                cout << "|    -> Introduceti cantitatea disponibila pentru produsul introdus: ";
                cin >> cantitate;
                cout << "|    -> Introduceti pretul produsului " << nume << ": ";
                cin >> pret;
                Produs p(nume, pret, cantitate);
                this->produseDisponibile[i] = p;

            }
        }
        cout << "|       " << endl;
        cout << " ---------------------------------------------------------------------------" << endl;
        return *this;
    }

    Magazin& operator-() //operator - in loc de stergere produse
    {
        string nume;
        int poz = 0;
        cout << " -------------------------------" << "STERGERE PRODUSE DIN MAGAZINUL " << this->numeMagazin << "------------------------" << endl;
        cout << "|                                                                                                                      |" << endl;
        cout << "|      PRODUSE DISPONIBILE:                                                                                            |" << endl;
        cout << "|   ";
        for (int i = 0; i < this->getNrProduseDisponibile(); i++)
            cout << this->getProduseDisponibile()[i].getNumeProdus() << "   |   ";
        cout << endl;
        cout << "|  " << endl;
        cout << "|  -- Introduceti numele produsului pe care doriti sa il stergeti: ";
        cin >> nume;
        for (int i = 0; i < this->nrProduseDisponibile; i++)
            if (this->getProduseDisponibile()[i].getNumeProdus() == nume)
            {
                poz = i;
                break;
            }
        for (int i = poz; i < this->nrProduseDisponibile - 1; i++)
            produseDisponibile[i] = produseDisponibile[i + 1];
        Produs* tmp = new Produs[--this->nrProduseDisponibile];
        int j = 0;
        for (int i = 0; i < nrProduseDisponibile; i++)
        {
            tmp[j] = this->produseDisponibile[i];
            j++;
        }
        delete[] this->produseDisponibile;
        this->produseDisponibile = tmp;
        cout << "|       " << endl;
        cout << "|  #Produsul cu numele " << nume << " a fost sters." << endl;
        cout << "|       " << endl;
        cout << " ---------------------------------------------------------------------------------------------------------------------" << endl;
        return *this;
    }

    Magazin operator~() //op editare nume magazin
    {
        string nume2, nume;
        int cant2, poz = 0;
        float pret2;
        cout << " --------------------------------" << "EDITARE PRODUS DIN MAGAZINUL " << this->numeMagazin << "------------------------" << endl;
        cout << "|                                                                                                                      |" << endl;
        cout << "|      PRODUSE DISPONIBILE:                                                                                            |" << endl;
        cout << "|   ";
        for (int i = 0; i < this->getNrProduseDisponibile(); i++)
            cout << this->getProduseDisponibile()[i].getNumeProdus() << "   |   ";
        cout << endl;
        cout << "|  " << endl;
        cout << "|  -- Introduceti numele produsului pe care doriti sa il editati: ";
        cin >> nume;
        for (int i = 0; i < this->nrProduseDisponibile; i++)
            if (this->getProduseDisponibile()[i].getNumeProdus() == nume)
            {
                poz = i;
                break;
            }
        cout << "|  -- Introduceti un alt nume pentru produsul cu numele " << this->getProduseDisponibile()[poz].getNumeProdus() << ": ";
        cin >> nume2;
        cout << "|  -- Introduceti o noua cantitate pentru produsul cu cantitatea " << this->getProduseDisponibile()[poz].getCantDisponibila() << ": ";
        cin >> cant2;
        cout << "|  -- Introduceti un pret nou pentru produsul cu pretul " << this->getProduseDisponibile()[poz].getPret() << ": ";
        cin >> pret2;
        cout << "|  # Nume modificat din " << this->getProduseDisponibile()[poz].getNumeProdus() << " in " << nume2 << "." << endl;
        cout << "|  # Cantitate modificata din " << this->getProduseDisponibile()[poz].getCantDisponibila() << " in " << cant2 << "." << endl;
        cout << "|  # Pret modificat din " << this->getProduseDisponibile()[poz].getPret() << " in " << pret2 << "." << endl;
        cout << "|                                                                                                                     |" << endl;
        cout << " ---------------------------------------------------------------------------------------------------------------------" << endl;
        this->produseDisponibile[poz].setNumeProdus(nume2);
        this->produseDisponibile[poz].setCantDisponibila(cant2);
        this->produseDisponibile[poz].setPret(pret2);
        return *this;
    }

    friend class Produs;
    friend class Comanda;
    friend istream& operator>>(istream& in, Produs& p);

    void afisareProduse() {
        cout << "Produsele disponibile in magazin sunt: " << endl;
        for (int i = 0; i < this->getNrProduseDisponibile(); i++)
            cout << "  --  " << this->getProduseDisponibile()[i].getNumeProdus() << endl;
    }

    void rapComenziPrimite(ofstream& outTxt) {
        outTxt << " ----" << this->getNrComenziPrimite() << " ";
        for (int i = 0; i < this->getNrComenziPrimite(); i++) {
            outTxt << "Comanda numarul " << i + 1 << " are " << this->getComenziPrimite()[i].getNrProduseComandate() << "produse. " << endl;
            for (int j = 0; j < this->getComenziPrimite()[i].getNrProduseComandate(); j++)
                outTxt << "  ---" << this->getComenziPrimite()[i].getProduseComandate()[j].getNumeProdus() << endl;

        }
        outTxt << endl;
    }
    void serializare(ofstream& out)
    {
        out.write((char*)this, sizeof(Magazin));
    }

    void deserializare(ifstream& in)
    {
        in.read((char*)this, sizeof(Magazin));
    }

    friend ofstream& operator<<(ofstream& out, Magazin m)
    {
        out << "  " << m.getNrComenziPrimite() << endl;

        for (int i = 0; i < m.getNrComenziPrimite(); i++)
            out << m.getComenziPrimite()[i].getNrProduseComandate() << " ";

        return out;
    }

    friend ostream& operator<<(ostream& out, Magazin m) {
        out << "  " << m.getNrComenziPrimite() << endl;

        for (int i = 0; i < m.getNrComenziPrimite(); i++)
            out << m.getComenziPrimite()[i].getNrProduseComandate() << " ";
        cout << endl;
        return out;
    }
};

class Client : public Utilizator
{
protected:
    string numeClient;
    string adresaClient;
    int nrProduseSelectate;
    Produs* cosElectronic;
    static int nrClienti;
public:
    string getNumeClient()
    {
        return numeClient;
    }
    string getAdresaClient()
    {
        return adresaClient;
    }
    int getNrProduseSelectate() {
        return nrProduseSelectate;
    }
    Produs* getCosElectronic() {
        return cosElectronic;
    }
    static int getNrClienti() {
        return nrClienti;
    }

    void setNumeClient(string numeClient)
    {
        if (numeClient.size() > 0)
            this->numeClient = numeClient;
    }

    void setaAdresaClient(string adresaClient)
    {
        if (adresaClient.size() > 0)
            this->adresaClient = adresaClient;
    }

    void setNrProduseSelectate(int nrProduseSelectate) {
        if (nrProduseSelectate > 0)
            this->nrProduseSelectate = nrProduseSelectate;
        else cout << "Nici un produs selectat !" << endl;
    }
    void setCosElectronic(Produs* cosElectronic) {
        if (cosElectronic != nullptr) {
            if (this->cosElectronic != nullptr)
                delete[] this->cosElectronic;
            this->cosElectronic = new Produs[this->nrProduseSelectate];
            for (int i = 0; i < this->nrProduseSelectate; i++)
                this->cosElectronic[i] = cosElectronic[i];
        }
    }
    static int setNrClienti(int nrClienti) {
        if (nrClienti >= 0)
            Client::nrClienti = nrClienti;
    }

    Client() :Utilizator() {
        this->numeClient = "N/A";
        this->adresaClient = "N/A";
        this->nrProduseSelectate = 0;
        this->cosElectronic = nullptr;
        nrClienti++;
        //cout << "APEL -- CONSTRUCTOR FARA PARAMETRI -- " << endl;
    }
    Client(string numeUtilizator, string email, string tipUtilizator, string parola, string numeClient, string adresaClient, int nrProduseSelectate, Produs* cosElectronic) : Utilizator(numeUtilizator, email, tipUtilizator, parola)
    {
        if (numeClient.size() > 0)
            this->numeClient = numeClient;
        if (adresaClient.size() > 0)
            this->adresaClient = adresaClient;

        if (nrProduseSelectate >= 0)
            this->nrProduseSelectate = nrProduseSelectate;
        else this->nrProduseSelectate = 0;
        if (cosElectronic != nullptr) {
            this->cosElectronic = new Produs[this->nrProduseSelectate];
            for (int i = 0; i < this->nrProduseSelectate; i++)
                this->cosElectronic[i] = cosElectronic[i];
        }
        else {
            this->cosElectronic = nullptr;
        }
        nrClienti++;
        //cout << "APEL -- CONSTRUCTOR CU PARAMETRI -- " << endl;

    }

    Client(const Client& cl) : Utilizator(cl) {
        this->numeClient = cl.numeClient;
        this->adresaClient = cl.adresaClient;
        this->nrProduseSelectate = cl.nrProduseSelectate;
        this->cosElectronic = new Produs[this->nrProduseSelectate];
        for (int i = 0; i < this->nrProduseSelectate; i++)
            this->cosElectronic[i] = cl.cosElectronic[i];
        nrClienti++;
    }
    Client operator=(const Client& cl) {
        this->numeClient = cl.numeClient;
        this->adresaClient = cl.adresaClient;
        this->nrProduseSelectate = cl.nrProduseSelectate;
        if (this->cosElectronic != nullptr)
            delete[] this->cosElectronic;
        this->cosElectronic = new Produs[this->nrProduseSelectate];
        for (int i = 0; i < this->nrProduseSelectate; i++)
            this->cosElectronic[i] = cosElectronic[i];
        return *this;
    }

    ~Client() {
        nrClienti--;
        if (this->cosElectronic != nullptr)
            delete[] this->cosElectronic;
        //cout << "APEL -- DESTRUCTOR -- " << endl;
    }

    void selectareProduse(Magazin m) {
        string aux;
        int j = 0, nr;
        cout << endl;
        //cout << "SELECTARE PRODUSE PENTRU CLIENTUL " << this->numeClient << " " << endl;
        /*if (this->cosElectronic != nullptr)
            delete[] this->cosElectronic;*/
        cout << "Introduceti numarul de produse pe care doriti sa le selectati: ";
        cin >> nr;
        cout << endl;
        Produs* cos = new Produs[this->nrProduseSelectate];
        for (int i = 0; i < this->nrProduseSelectate; i++)
            cos[i] = this->cosElectronic[i];
        delete[] this->cosElectronic;
        this->cosElectronic = new Produs[this->nrProduseSelectate + nr];
        for (int i = 0; i < this->nrProduseSelectate + nr; i++)
        {
            if (i < this->nrProduseSelectate)
                this->cosElectronic[i] = cos[i];
            else
            {
                cout << "Introduceti produsul cu numarul " << i + 1 << ": ";
                cin >> aux;
                j = 0;
                while (m.getProduseDisponibile()[j].getNumeProdus() != aux && j <= m.getNrProduseDisponibile())
                    j++;
                if (j < m.getNrProduseDisponibile())
                    this->cosElectronic[i] = m.getProduseDisponibile()[j];
                else
                    cout << "EROARE la introducere produsului cu numele " << aux << ". Acesta nu se afla in lista de produse disponibile pentru magazinul " << m.getNumeMagazin();
            }
        } this->nrProduseSelectate = this->nrProduseSelectate + nr;
    }

    friend class Produs;
    friend class Comanda;

    friend ostream& operator<<(ostream& out, Client cl);

    void afisareProduse1(Client& cl) {
        cout << "Produsele selectate sunt: " << endl;
        for (int i = 0; i < cl.getNrProduseSelectate(); i++)
            cout << "  --  " << cl.getCosElectronic()[i].getNumeProdus() << endl;
    }

    void scoateProduse()
    {
        string produsScos;
        cout << " -------------------------------" << "SCOATERE PRODUSE DIN COS ELECTRONIC" << "------------------------|" << this->getNumeClient() << "|" << endl;
        cout << "|                                                                                                                      |" << endl;
        cout << "|      PRODUSE IN COSUL ELECTRONIC:                                                                                    |" << endl;
        cout << "|   ";
        for (int i = 0; i < this->getNrProduseSelectate(); i++)
            cout << this->getCosElectronic()[i].getNumeProdus() << "   |   ";
        cout << endl;
        cout << "|  " << endl;
        cout << "|  -- Introduceti numele produsului pe care doriti sa il scoateti din cos: ";
        cin >> produsScos;

        for (int i = 0; i < this->nrProduseSelectate; i++)
        {
            if (produsScos == this->cosElectronic[i].getNumeProdus())
            {
                for (int j = i; j < this->nrProduseSelectate - 1; j++)
                {
                    this->cosElectronic[j] = this->cosElectronic[j + 1];
                }
                this->nrProduseSelectate--;
                break;

            }
        }
        cout << "|  Produsul " << produsScos << " a fost scos cu succes." << endl;
    }

    void inregistrareClient() {

        string numeUt;
        system("cls");
        cout << " ---------------------------------------------ECRAN INREGISTRARE CLIENT-----------------------------------------------" << endl;
        cout << "|                                                                                                                     |" << endl;
        cout << "|                        NUME DE UTILIZATOR: ";
        cin >> numeUt;
        this->numeUtilizator = numeUt;
        int ok = 1;
        cout << "|                        " << endl;
        cout << "|           | Parola trebuie sa contina: " << endl;
        cout << "|                 - cel putin 8 caractere" << endl;
        cout << "|                 - cel putin o majuscula" << endl;
        cout << "|                 - cel putin un numar" << endl;
        cout << "|                        PAROLA: ";
        string parola1;
        cin >> parola1;
        // Verificam daca parola are cel putin 8 caractere
        if (parola1.length() < 8)
        {
            cout << "Parola introdusa are mai putin de 8 caractere" << endl;
            ok = 0;
        }
        // Verificam daca parola are cel putin o litera mare
        bool hasMajuscula = false;
        for (int i = 0; i < parola1.length(); i++)
        {
            if (isupper(parola[i]))
            {
                hasMajuscula = true;
                break;
            }
        }
        if (!hasMajuscula)
        {
            cout << "Parola introdusa trebuie sa contina minim o majuscula." << endl;
            ok = 0;
        }
        // Verificam daca parola are cel putin un numar
        bool hasNumar = false;
        for (int i = 0; i < parola1.length(); i++)
        {
            if (isdigit(parola1[i]))
            {
                hasNumar = true;
                break;
            }
        }
        if (!hasNumar)
        {
            cout << "Parola trebuie sa contina cel putin un numar." << endl;
            ok = 0;
        }
        if (ok == 1) {
            cout << "|                        RESCRIE PAROLA: ";
            string parola2;
            cin >> parola2;
            if (parola1 == parola2)
            {
                this->parola = parola1;
                cout << "|                           " << endl;
                cout << "|                        NUME CLIENT: ";
                string numeCl;
                cin >> numeCl;
                this->numeClient = numeCl;
                cout << "|                        " << endl;
                cout << "|                        EMAIL: ";
                string emailCl;
                cin >> emailCl;
                this->email = emailCl;
                cout << "|                        " << endl;
                cout << "|                        ADRESA: ";
                string adresaCl;
                cin >> adresaCl;
                this->adresaClient = adresaCl;
                cout << "|                        " << endl;
            }
            else
                cout << "Parola introdusa este diferita de cea initiala.";
        }
        else
        {

            return;
        }
        cout << "Inregistrare realizata cu succes!" << endl;
    }

    friend class Utilizator;
};


void afisareProduse(Magazin& m) {
    cout << "Produsele disponibile in magazin sunt: " << endl;
    for (int i = 0; i < m.getNrProduseDisponibile(); i++)
        cout << "  --  " << m.getProduseDisponibile()[i].getNumeProdus() << endl;
}


int Utilizator::nrUtilizatori = 0;
int Magazin::nrMagazine = 0;
int Client::nrClienti = 0;
int Comanda::nrComenzi = 0;

int main()
{

    Produs p1("laptop", 4000, 4);
    Produs p2("PC", 8000, 3);
    Produs p3("TV", 2000, 10);
    Produs p4("mouse", 4000, 5);
    Produs p5("tigaie", 200, 20);
    Produs p6("frigider", 2500, 10);
    Produs p7("casti", 200, 50);
    Produs p8("boxa", 300, 100);

    map<string, Client> mapClient;

    Client c1("Ion", "ion@gmail.com", "Client", "Ion12345", "Ion", "Str. Lacului, Nr.15", 2, new Produs[2]{ p1,p5 });
    Client c2("Andrei", "andrei@gmail.com", "Client", "Andrei123", "Andrei", "Str. Morii, Nr.201", 3, new Produs[3]{ p1,p2,p3 });
    Client c3("Rares", "rares@gmail.com", "Client", "Rares123", "Rares", "Str. Lebedelor, Nr. 3", 0, nullptr);
    Client c4("Diana", "diana@gmail.com", "Client", "Diana123", "Diana", "Str. Noptii, Nr. 10", 0, nullptr);

    mapClient.insert(pair<string, Client>(c1.getNumeUtilizator(), c1));
    mapClient.insert(pair<string, Client>(c2.getNumeUtilizator(), c2));
    mapClient.insert(pair<string, Client>(c3.getNumeUtilizator(), c3));
    mapClient.insert(pair<string, Client>(c4.getNumeUtilizator(), c4));

    map<string, Client>::iterator itMap;

    Comanda co1("Ion", "Str. Lacului, Nr.15", 2, new Produs[2]{ p3,p5 }, 2200);
    Comanda co2("Diana", "Str. Noptii. Nr. 10", 3, new Produs[3]{ p1,p3,p4 }, 10000);
    Comanda co3("Rares", "Str. Lebedelor, Nr. 3", 1, new Produs[1]{ p7 }, 200);


    map<int, Magazin> mapMagazin;

    //Magazin m0;
    Magazin m1(1, "Maria", "maria@gmail.com", "Magazin", "Maria123", "Flanco", 4, new Produs[4]{ p1,p6,p7,p8 }, 1, new Comanda{ co3 }, "Str. Lalelelor, Nr. 58");
    Magazin m2(2, "Violeta", "violeta@gmail.com", "Magazin", "Violeta123", "Emag", 3, new Produs[4]{ p1,p3,p4,p5 }, 2, new Comanda[2]{ co1,co2 }, "Str. Cainelui, Nr. 9");
    Magazin m3(3, "Cornel", "cornel@gmail.com", "Magazin", "Cornel123", "Altex", 6, new Produs[6]{ p1,p2,p3,p6,p7,p8 }, 0, nullptr, "Str. Pisicilor, Nr. 351");

    mapMagazin.insert(pair<int, Magazin>(m1.getIdMagazin(), m1));
    mapMagazin.insert(pair<int, Magazin>(m2.getIdMagazin(), m2));
    mapMagazin.insert(pair<int, Magazin>(m3.getIdMagazin(), m3));

    map<int, Magazin>::iterator itMapMagazine;


    string inceput;
start:
    system("cls");
    cout << " --------------------------------------------------ECRAN DE PORNIRE---------------------------------------------------" << endl;
    cout << "|                                                                                                                     |" << endl;
    cout << "|                                            Alegeti tipul de UTILIZATOR:                                             |" << endl;
    cout << "|                                                                                                                     |" << endl;
    cout << "|                                                                                                                     |" << endl;
    cout << "|             TASTATI 1 PENTRU                                       TASTATI 2 PENTRU                                 |" << endl;
    cout << "|                   CLIENT                                                MAGAZIN                                     |" << endl;
    cout << "|                                                                                                                     |" << endl;
    cout << "|                                                                                                                     |" << endl;
    cout << "|                                                                                                                     |" << endl;
    cout << "|                                                                                                                     |" << endl;
    cout << " ---------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "                                                      -->  ";
    int tipUtilizator;
    cin >> tipUtilizator;
    system("cls");
    if (tipUtilizator == 1)
    {
    inceputClient:
        cout << " ----------------------------------------------ECRAN INREGISTRARE CLIENT----------------------------------------------" << endl;
        cout << "|                                                                                                                     |" << endl;
        cout << "|                                                                                                                     |" << endl;
        cout << "|                                                                                                                     |" << endl;
        cout << "|                                                                                                                     |" << endl;
        cout << "|             TASTATI 1 PENTRU                                       TASTATI 2 PENTRU                                 |" << endl;
        cout << "|                 A VA LOGA                                           A VA INREGISTRA                                 |" << endl;
        cout << "|          IN CONTUL DUMNEAVOASTRA                                   CA SI UN CLIENT NOU                              |" << endl;
        cout << "|                                                                                                                     |" << endl;
        cout << "|                                                                                                                     |" << endl;
        cout << "|                                                                                                                     |" << endl;
        cout << " ---------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "                                                      -->  ";
        int tipClient;
        cin >> tipClient;
        if (tipClient == 1)
        {
            cout << endl;
            cout << "                                      INTRODUCETI NUMELE DE UTILIZATOR " << endl;
            cout << "                                             -->  ";
            string utilizatorClient;
            cin >> utilizatorClient;
            itMap = mapClient.find(utilizatorClient);
            if (itMap != mapClient.end())
            {
                cout << "                                      INTRODUCETI PAROLA " << endl;
                cout << "                                             -->  ";
                string parolaClient;
                cin >> parolaClient;
                if (parolaClient == itMap->second.getParola())
                {
                    system("cls");
                    cout << " ------------------------------------------------BINE ATI VENIT " << itMap->second.getNumeClient() << "----------------------------------------------" << endl;
                    cout << "|                                                                                                                     " << endl;
                    cout << "|               DATE PERSONALE:                                                               " << endl;
                    cout << "|                     -- Nume: " << itMap->second.getNumeClient() << endl;
                    cout << "|                     -- Email: " << itMap->second.getEmail() << endl;
                    cout << "|                     -- Adresa: " << itMap->second.getAdresaClient() << endl;
                    cout << "|               # La momentul de fata, in cosul dumneavoastra se afla " << itMap->second.getNrProduseSelectate() << " produse." << endl;
                    cout << "|                " << endl;
                    cout << "|      PENTRU A NAVIGA MAGAZINELE DISPONIBILE                                          PENTRU A FACE O COMANDA     " << endl;
                    cout << "|                APASATI TASTA 1                                                           APASATI TASTA 2" << endl;
                    cout << "|                                                                                                                     " << endl;
                    cout << " ---------------------------------------------------------------------------------------------------------------------" << endl;
                    cout << "                                             -->  ";
                    int alegereClient;
                    cin >> alegereClient;
                    if (alegereClient == 1)
                    {

                        system("cls");
                        cout << " ----------------------------------------------ECRAN MAGAZINE DISPONIBILE--------------------------------------|" << itMap->second.getNumeClient() << "|" << endl;
                        cout << "|" << endl;
                        for (int i = 0; i < mapMagazin.size(); i++)
                        {
                            itMapMagazine = mapMagazin.find(i + 1);
                            cout << "|            | " << i + 1 << ". " << itMapMagazine->second.getNumeMagazin() << endl;
                            cout << "|" << endl;
                        }
                        cout << "|    #Pentru a accesa unul din magazine scrieti numarul acestuia din lista de mai sus: ";
                        int alegereMagazin;
                        cin >> alegereMagazin;
                        itMapMagazine = mapMagazin.find(alegereMagazin);
                        if (itMapMagazine != mapMagazin.end())
                        {
                            system("cls");
                            cout << " --------------------------------------------------" << itMapMagazine->second.getNumeMagazin() << "--------------------------------------------------|" << itMap->second.getNumeClient() << "|" << endl;
                            cout << "|                                                                                                                     " << endl;
                            cout << "|       -- PRODUSE DISPONIBILE --                                                  " << endl;
                            cout << "|                                                                                                                     " << endl;
                            for (int i = 0; i < itMapMagazine->second.getNrProduseDisponibile(); i++)
                            {
                                cout << "|" << endl;
                                cout << "|       -- " << itMapMagazine->second.getProduseDisponibile()[i].getNumeProdus() << endl;
                                cout << "|                  -" << itMapMagazine->second.getProduseDisponibile()[i].getPret() << " LEI" << endl;
                                cout << "|                  -" << itMapMagazine->second.getProduseDisponibile()[i].getCantDisponibila() << " bucati pe stoc" << endl;
                            }
                            cout << "|" << endl;
                            Client& cl = mapClient.at(utilizatorClient);
                            Magazin& ma = mapMagazin.at(alegereMagazin);
                            cl.selectareProduse(ma);

                            system("cls");
                            cout << " ------------------------------------------------CASA DE MARCAT----------------------------------------------|" << itMap->second.getNumeClient() << "|" << endl;
                            cout << "|                                                                                                                     " << endl;
                            cout << "|                     -- Adresa de livrare: " << itMap->second.getAdresaClient() << endl;
                            cout << "|               # La momentul de fata, in cosul dumneavoastra se afla " << itMap->second.getNrProduseSelectate() << " produse." << endl;
                            cout << "|               Acestea sunt: ";
                            for (int i = 0; i < itMap->second.getNrProduseSelectate(); i++)
                                cout << itMap->second.getCosElectronic()[i].getNumeProdus() << " " << itMap->second.getCosElectronic()[i].getPret() << "LEI" << "  ";
                            cout << endl;
                            cout << "|                         PENTRU A SCOATE UN PRODUS DIN COS APASATI TASTA 1.     " << endl;
                            cout << "|                         PENTRU A CONFIRMA CA DORITI SA CUMPARATI PRODUSELE SELECTATE     " << endl;
                            cout << "|                         SCRIETI CUVANTUL 'DA'. IN CAZ CONTRAR, COMANDA VA FI ANULATA." << endl;
                            cout << "|                                                                                                                     " << endl;
                            cout << " ---------------------------------------------------------------------------------------------------------------------" << endl;
                            cout << "                                             -->  ";
                            string confirmareComanda;
                            cin >> confirmareComanda;
                            if (confirmareComanda == "DA")
                            {
                                Comanda coNou;
                                coNou.setNumeClient(itMap->second.getNumeClient());
                                coNou.setAdresaClient(itMap->second.getAdresaClient());
                                coNou.setNrProduseComandate(itMap->second.getNrProduseSelectate());
                                coNou.setProduseComandate(itMap->second.getCosElectronic());
                                int valTotala = 0;
                                for (int i = 0; i < itMap->second.getNrProduseSelectate(); i++)
                                    valTotala = valTotala + itMap->second.getCosElectronic()[i].getPret();
                                coNou.setPretTotal(valTotala);
                                ma.adaugareComanda(coNou);
                                system("cls");
                                cout << " ------------------------------------------------ECRAN FACTURA-------------------------------------------------------" << endl;
                                cout << "|                                                                                                                 " << endl;
                                cout << "|               --- Comanda No. " << coNou.getNrComenzi << endl;
                                cout << "|                                                                                                                 " << endl;
                                cout << "|         -- Nume Client:" << coNou.getNumeClient() << endl;
                                cout << "|         -- Adresa Client: " << coNou.getAdresaClient() << endl;
                                cout << "|         -- Numar Produse comandate: " << coNou.getNrProduseComandate() << endl;
                                cout << "|             " << endl;
                                for (int i = 0; i < coNou.getNrProduseComandate(); i++)
                                    cout << "|                | " << i + 1 << ". " << coNou.getProduseComandate()[i].getNumeProdus() << " " << coNou.getProduseComandate()[i].getPret() << " LEI" << endl;
                                cout << "|             ----------------------- TOTAL: " << coNou.getPretTotal() << endl;
                                cout << "|                                                                                                                 " << endl;
                                try {
                                    ofstream outTxtComanda("raportComanda.txt", ios::out);
                                    if (!outTxtComanda) {
                                        throw   "|                                          Nu s-a putut genera fisierul text!                                         |";
                                    }
                                    else {
                                        outTxtComanda << coNou;
                                        outTxtComanda.close();
                                        cout << "|                                                RAPORTUL A FOST GENERAT.                                             |" << endl;
                                    }
                                }
                                catch (const char* ex) {
                                    cout << "Nu s-a putut lucra cu fisierul text. " << ex << endl;
                                }
                                catch (...) {
                                    cout << "Nu s-a putut lucra cu fisierul text." << endl;
                                }
                                cout << "|                                                                                                                " << endl;
                                cout << " --------------------------------------------------------------------------------------------------------------------" << endl;
                                cout << "                     Pentru a reveni la ecranul principal introduceti 'Y' de la tastatura:" << endl;
                                cin >> inceput;
                                if (inceput == "Y")
                                    goto start;
                            }
                            if (confirmareComanda == "1")
                            {
                                system("cls");
                                cl.scoateProduse();
                                cout << "                     Pentru a reveni la ecranul de inceput pentru client apasati 'C' de la tastatura." << endl;
                                cout << "                          Pentru a reveni la ecranul principal introduceti 'Y' de la tastatura." << endl;
                                cin >> inceput;
                                if (inceput == "Y")
                                    goto start;
                                else if (inceput == "C")
                                    goto inceputClient;
                            }
                            else
                                cout << "Comanda anulata.";
                        }
                        else
                            cout << "Alegere invalida.";
                    }
                    else
                    {
                        if (itMap->second.getNrProduseSelectate())
                        {
                            if (itMap->second.getNumeUtilizator() == "Andrei")
                            {
                                system("cls");
                                cout << " ------------------------------------------------CASA DE MARCAT----------------------------------------------|" << itMap->second.getNumeClient() << "|" << endl;
                                cout << "|                                                                                                                     " << endl;
                                cout << "|                     -- Adresa de livrare: " << itMap->second.getAdresaClient() << endl;
                                cout << "|               # La momentul de fata, in cosul dumneavoastra se afla " << itMap->second.getNrProduseSelectate() << " produse." << endl;
                                cout << "|               Acestea sunt: ";
                                for (int i = 0; i < itMap->second.getNrProduseSelectate(); i++)
                                    cout << itMap->second.getCosElectronic()[i].getNumeProdus() << " " << itMap->second.getCosElectronic()[i].getPret() << "LEI" << "  ";
                                cout << endl;
                                cout << "|                         PENTRU A SCOATE UN PRODUS DIN COS APASATI TASTA 1.     " << endl;
                                cout << "|                         PENTRU A CONFIRMA CA DORITI SA CUMPARATI PRODUSELE SELECTATE     " << endl;
                                cout << "|                         SCRIETI CUVANTUL 'DA'. IN CAZ CONTRAR, COMANDA VA FI ANULATA." << endl;
                                cout << "|                                                                                                                     " << endl;
                                cout << " ---------------------------------------------------------------------------------------------------------------------" << endl;
                                cout << "                                             -->  ";
                                string confirmareComanda;
                                cin >> confirmareComanda;
                                if (confirmareComanda == "DA")
                                {
                                    Comanda coNou;
                                    coNou.setNumeClient(itMap->second.getNumeClient());
                                    coNou.setAdresaClient(itMap->second.getAdresaClient());
                                    coNou.setNrProduseComandate(itMap->second.getNrProduseSelectate());
                                    coNou.setProduseComandate(itMap->second.getCosElectronic());
                                    int valTotala = 0;
                                    for (int i = 0; i < itMap->second.getNrProduseSelectate(); i++)
                                        valTotala = valTotala + itMap->second.getCosElectronic()[i].getPret();
                                    coNou.setPretTotal(valTotala);
                                    m3.adaugareComanda(coNou);
                                    system("cls");
                                    cout << " ------------------------------------------------ECRAN FACTURA-------------------------------------------------------" << endl;
                                    cout << "|                                                                                                                 " << endl;
                                    cout << "|               --- Comanda No. " << coNou.getNrComenzi() << endl;
                                    cout << "|                                                                                                                 " << endl;
                                    cout << "|         -- Nume Client:" << coNou.getNumeClient() << endl;
                                    cout << "|         -- Adresa Client: " << coNou.getAdresaClient() << endl;
                                    cout << "|         -- Numar Produse comandate: " << coNou.getNrProduseComandate() << endl;
                                    cout << "|             " << endl;
                                    for (int i = 0; i < coNou.getNrProduseComandate(); i++)
                                        cout << "|                | " << i + 1 << ". " << coNou.getProduseComandate()[i].getNumeProdus() << " " << coNou.getProduseComandate()[i].getPret() << " LEI" << endl;
                                    cout << "|             ----------------------- TOTAL: " << coNou.getPretTotal() << endl;
                                    cout << "|                                                                                                                 " << endl;
                                    try {
                                        ofstream outTxtComanda("raportComanda.txt", ios::out);
                                        if (!outTxtComanda) {
                                            throw   "|                                          Nu s-a putut genera fisierul text!                                         |";
                                        }
                                        else {
                                            outTxtComanda << coNou;
                                            outTxtComanda.close();
                                            cout << "|                                                RAPORTUL A FOST GENERAT.                                             |" << endl;
                                        }
                                    }
                                    catch (const char* ex) {
                                        cout << "Nu s-a putut lucra cu fisierul text. " << ex << endl;
                                    }
                                    catch (...) {
                                        cout << "Nu s-a putut lucra cu fisierul text." << endl;
                                    }
                                    cout << "|                                                                                                                " << endl;
                                    cout << " --------------------------------------------------------------------------------------------------------------------" << endl;
                                    cout << "                     Pentru a reveni la ecranul principal introduceti 'Y' de la tastatura:" << endl;
                                    cin >> inceput;
                                    if (inceput == "Y")
                                        goto start;
                                }
                                if (confirmareComanda == "1")
                                {
                                    c2.scoateProduse();
                                    cout << "                     Pentru a reveni la ecranul de inceput pentru client apasati 'C' de la tastatura." << endl;
                                    cout << "                          Pentru a reveni la ecranul principal introduceti 'Y' de la tastatura." << endl;
                                    cin >> inceput;
                                    if (inceput == "Y")
                                        goto start;
                                    else if (inceput == "C")
                                        goto inceputClient;
                                }
                                else
                                {
                                    cout << "                               Comanda anulata." << endl;
                                    cout << "     Pentru a reveni la ecranul principal introduceti 'Y' de la tastatura." << endl;
                                    string inceput;
                                    cin >> inceput;
                                    if (inceput == "Y")
                                        goto start;
                                }
                            }
                            else
                            {
                                system("cls");
                                cout << " ------------------------------------------------CASA DE MARCAT----------------------------------------------|" << itMap->second.getNumeClient() << "|" << endl;
                                cout << "|                                                                                                                     " << endl;
                                cout << "|                     -- Adresa de livrare: " << itMap->second.getAdresaClient() << endl;
                                cout << "|               # La momentul de fata, in cosul dumneavoastra se afla " << itMap->second.getNrProduseSelectate() << " produse." << endl;
                                cout << "|               Acestea sunt: ";
                                for (int i = 0; i < itMap->second.getNrProduseSelectate(); i++)
                                    cout << itMap->second.getCosElectronic()[i].getNumeProdus() << " " << itMap->second.getCosElectronic()[i].getPret() << "LEI" << "  ";
                                cout << endl;
                                cout << "|                         PENTRU A SCOATE UN PRODUS DIN COS APASATI TASTA 1.     " << endl;
                                cout << "|                         PENTRU A CONFIRMA CA DORITI SA CUMPARATI PRODUSELE SELECTATE     " << endl;
                                cout << "|                         SCRIETI CUVANTUL 'DA'. IN CAZ CONTRAR, COMANDA VA FI ANULATA." << endl;
                                cout << "|                                                                                                                     " << endl;
                                cout << " ---------------------------------------------------------------------------------------------------------------------" << endl;
                                cout << "                                             -->  ";
                                string confirmareComanda;
                                cin >> confirmareComanda;
                                if (confirmareComanda == "DA")
                                {
                                    Comanda coNou;
                                    coNou.setNumeClient(itMap->second.getNumeClient());
                                    coNou.setAdresaClient(itMap->second.getAdresaClient());
                                    coNou.setNrProduseComandate(itMap->second.getNrProduseSelectate());
                                    coNou.setProduseComandate(itMap->second.getCosElectronic());
                                    int valTotala = 0;
                                    for (int i = 0; i < itMap->second.getNrProduseSelectate(); i++)
                                        valTotala = valTotala + itMap->second.getCosElectronic()[i].getPret();
                                    coNou.setPretTotal(valTotala);
                                    m2.adaugareComanda(coNou);
                                    system("cls");
                                    cout << " ------------------------------------------------ECRAN FACTURA-------------------------------------------------------" << endl;
                                    cout << "|                                                                                                                 " << endl;
                                    cout << "|               --- Comanda No. " << coNou.getNrComenzi() << endl;
                                    cout << "|                                                                                                                 " << endl;
                                    cout << "|         -- Nume Client:" << coNou.getNumeClient() << endl;
                                    cout << "|         -- Adresa Client: " << coNou.getAdresaClient() << endl;
                                    cout << "|         -- Numar Produse comandate: " << coNou.getNrProduseComandate() << endl;
                                    cout << "|             " << endl;
                                    for (int i = 0; i < coNou.getNrProduseComandate(); i++)
                                        cout << "|                | " << i + 1 << ". " << coNou.getProduseComandate()[i].getNumeProdus() << " " << coNou.getProduseComandate()[i].getPret() << " LEI" << endl;
                                    cout << "|             ----------------------- TOTAL: " << coNou.getPretTotal() << endl;
                                    cout << "|                                                                                                                 " << endl;
                                    try {
                                        ofstream outTxtComanda("raportComanda.txt", ios::out);
                                        if (!outTxtComanda) {
                                            throw   "|                                          Nu s-a putut genera fisierul text!                                         |";
                                        }
                                        else {
                                            outTxtComanda << coNou;
                                            outTxtComanda.close();
                                            cout << "|                                                RAPORTUL A FOST GENERAT.                                             |" << endl;
                                        }
                                    }
                                    catch (const char* ex) {
                                        cout << "Nu s-a putut lucra cu fisierul text. " << ex << endl;
                                    }
                                    catch (...) {
                                        cout << "Nu s-a putut lucra cu fisierul text." << endl;
                                    }
                                    cout << "|                                                                                                                " << endl;
                                    cout << " --------------------------------------------------------------------------------------------------------------------" << endl;
                                    cout << "                     Pentru a reveni la ecranul principal introduceti 'Y' de la tastatura:" << endl;
                                    cin >> inceput;
                                    if (inceput == "Y")
                                        goto start;
                                }
                                if (confirmareComanda == "1")
                                {
                                    c2.scoateProduse();
                                    cout << "                     Pentru a reveni la ecranul de inceput pentru client apasati 'C' de la tastatura." << endl;
                                    cout << "                          Pentru a reveni la ecranul principal introduceti 'Y' de la tastatura." << endl;
                                    cin >> inceput;
                                    if (inceput == "Y")
                                        goto start;
                                    else if (inceput == "C")
                                        goto inceputClient;
                                }
                                else
                                {
                                    cout << "                             Comanda anulata." << endl;
                                    cout << "     Pentru a reveni la ecranul principal introduceti 'Y' de la tastatura." << endl;
                                    string inceput;
                                    cin >> inceput;
                                    if (inceput == "Y")
                                        goto start;
                                }
                            }
                        }
                        else
                        {
                            cout << "                EROARE! Nu aveti produse in cosul electronic." << endl;
                            cout << "     Pentru a reveni la ecranul principal introduceti 'Y' de la tastatura." << endl;
                            string inceput;
                            cin >> inceput;
                            if (inceput == "Y")
                                goto start;
                        }
                    }
                }
                else
                {
                    cout << "                     Parola introdusa este gresita." << endl;
                    cout << "     Pentru a reveni la ecranul principal introduceti 'Y' de la tastatura." << endl;
                    string inceput;
                    cin >> inceput;
                    if (inceput == "Y")
                        goto start;
                }
            }
            else
            {
                cout << "         Nu s-a gasit niciun client cu numele de utilizator introdus!" << endl;
                cout << "     Pentru a reveni la ecranul principal introduceti 'Y' de la tastatura." << endl;
                string inceput;
                cin >> inceput;
                if (inceput == "Y")
                    goto start;
            }


        }
        else
            if (tipClient == 2) {

                Client clientNou;
                clientNou.inregistrareClient();
                if (clientNou.getAdresaClient() != "N/A")
                {

                    system("cls");
                    cout << " ------------------------------------------------BINE ATI VENIT " << clientNou.getNumeClient() << "----------------------------------------------" << endl;
                    cout << "|                                                                                                                     " << endl;
                    cout << "|               DATE PERSONALE:                                                               " << endl;
                    cout << "|                     -- Nume: " << clientNou.getNumeClient() << endl;
                    cout << "|                     -- Email: " << clientNou.getEmail() << endl;
                    cout << "|                     -- Adresa: " << clientNou.getAdresaClient() << endl;
                    cout << "|               # La momentul de fata, in cosul dumneavoastra se afla " << clientNou.getNrProduseSelectate() << " produse." << endl;
                    cout << "|                " << endl;
                    cout << "|      PENTRU A NAVIGA MAGAZINELE DISPONIBILE                                          PENTRU A FACE O COMANDA     " << endl;
                    cout << "|                APASATI TASTA 1                                                           APASATI TASTA 2" << endl;
                    cout << "|                                                                                                                     " << endl;
                    cout << " ---------------------------------------------------------------------------------------------------------------------" << endl;
                    cout << "                                             -->  ";
                    int alegereClient;
                    cin >> alegereClient;
                    if (alegereClient == 1)
                    {

                        system("cls");
                        cout << " ----------------------------------------------ECRAN MAGAZINE DISPONIBILE--------------------------------------|" << clientNou.getNumeClient() << "|" << endl;
                        cout << "|" << endl;
                        for (int i = 0; i < mapMagazin.size(); i++)
                        {
                            itMapMagazine = mapMagazin.find(i + 1);
                            cout << "|            | " << i + 1 << ". " << itMapMagazine->second.getNumeMagazin() << endl;
                            cout << "|" << endl;
                        }
                        cout << "|    #Pentru a accesa unul din magazine scrieti numarul acestuia din lista de mai sus: ";
                        int alegereMagazin;
                        cin >> alegereMagazin;
                        itMapMagazine = mapMagazin.find(alegereMagazin);
                        if (itMapMagazine != mapMagazin.end())
                        {
                            system("cls");
                            cout << " --------------------------------------------------" << itMapMagazine->second.getNumeMagazin() << "--------------------------------------------------|" << clientNou.getNumeClient() << "|" << endl;
                            cout << "|                                                                                                                     " << endl;
                            cout << "|       -- PRODUSE DISPONIBILE --                                                  " << endl;
                            cout << "|                                                                                                                     " << endl;
                            for (int i = 0; i < itMapMagazine->second.getNrProduseDisponibile(); i++)
                            {
                                cout << "|" << endl;
                                cout << "|       -- " << itMapMagazine->second.getProduseDisponibile()[i].getNumeProdus() << endl;
                                cout << "|                  -" << itMapMagazine->second.getProduseDisponibile()[i].getPret() << " LEI" << endl;
                                cout << "|                  -" << itMapMagazine->second.getProduseDisponibile()[i].getCantDisponibila() << " bucati pe stoc" << endl;
                            }
                            cout << "|" << endl;
                            Magazin& ma = mapMagazin.at(alegereMagazin);
                            clientNou.selectareProduse(ma);
                            mapClient.insert(pair<string, Client>(clientNou.getNumeUtilizator(), clientNou));

                            system("cls");
                            cout << " ------------------------------------------------CASA DE MARCAT----------------------------------------------|" << clientNou.getNumeClient() << "|" << endl;
                            cout << "|                                                                                                                     " << endl;
                            cout << "|                     -- Adresa de livrare: " << clientNou.getAdresaClient() << endl;
                            cout << "|               # La momentul de fata, in cosul dumneavoastra se afla " << clientNou.getNrProduseSelectate() << " produse." << endl;
                            cout << "|               Acestea sunt: ";
                            for (int i = 0; i < clientNou.getNrProduseSelectate(); i++)
                                cout << clientNou.getCosElectronic()[i].getNumeProdus() << " " << clientNou.getCosElectronic()[i].getPret() << "LEI" << "  ";
                            cout << endl;
                            cout << "|                         PENTRU A CONFIRMA CA DORITI SA CUMPARATI PRODUSELE SELECTATE     " << endl;
                            cout << "|                         PENTRU A SCOATE UN PRODUS DIN COS APASATI TASTA 1.     " << endl;
                            cout << "|                         SCRIETI CUVANTUL 'DA'. IN CAZ CONTRAR, COMANDA VA FI ANULATA." << endl;
                            cout << "|                                                                                                                     " << endl;
                            cout << " ---------------------------------------------------------------------------------------------------------------------" << endl;
                            cout << "                                             -->  ";
                            string confirmareComanda;
                            cin >> confirmareComanda;
                            if (confirmareComanda == "DA")
                            {
                                Comanda coNou;
                                coNou.setNumeClient(clientNou.getNumeClient());
                                coNou.setAdresaClient(clientNou.getAdresaClient());
                                coNou.setNrProduseComandate(clientNou.getNrProduseSelectate());
                                coNou.setProduseComandate(clientNou.getCosElectronic());
                                int valTotala = 0;
                                for (int i = 0; i < clientNou.getNrProduseSelectate(); i++)
                                    valTotala = valTotala + clientNou.getCosElectronic()[i].getPret();
                                coNou.setPretTotal(valTotala);
                                ma.adaugareComanda(coNou);
                                system("cls");
                                cout << " ------------------------------------------------ECRAN FACTURA-------------------------------------------------------" << endl;
                                cout << "|                                                                                                                 " << endl;
                                cout << "|               --- Comanda No. " << coNou.getNrComenzi << endl;
                                cout << "|                                                                                                                 " << endl;
                                cout << "|         -- Nume Client:" << coNou.getNumeClient() << endl;
                                cout << "|         -- Adresa Client: " << coNou.getAdresaClient() << endl;
                                cout << "|         -- Numar Produse comandate: " << coNou.getNrProduseComandate() << endl;
                                cout << "|             " << endl;
                                for (int i = 0; i < coNou.getNrProduseComandate(); i++)
                                    cout << "|                | " << i + 1 << ". " << coNou.getProduseComandate()[i].getNumeProdus() << " " << coNou.getProduseComandate()[i].getPret() << " LEI" << endl;
                                cout << "|             ----------------------- TOTAL: " << coNou.getPretTotal() << endl;
                                cout << "|                                                                                                                 " << endl;
                                cout << "|                                          RAPORTUL A FOST GENERAT. " << endl;
                                cout << "|                                                                                                                " << endl;
                                cout << " --------------------------------------------------------------------------------------------------------------------" << endl;
                                cout << "                     Pentru a reveni la ecranul principal introduceti 'Y' de la tastatura:" << endl;
                                cin >> inceput;
                                if (inceput == "Y")
                                    goto start;
                            }
                            if (confirmareComanda == "1")
                            {
                                system("cls");
                                clientNou.scoateProduse();
                                cout << "                     Pentru a reveni la ecranul de inceput pentru client apasati 'C' de la tastatura." << endl;
                                cout << "                          Pentru a reveni la ecranul principal introduceti 'Y' de la tastatura." << endl;
                                cin >> inceput;
                                if (inceput == "Y")
                                    goto start;
                                else if (inceput == "C")
                                    goto inceputClient;
                            }
                            else
                            {
                                cout << "                                         Comanda anulata." << endl;
                                cout << "                     Pentru a reveni la ecranul principal introduceti 'Y' de la tastatura:" << endl;
                                cin >> inceput;
                                if (inceput == "Y")
                                    goto start;
                            }
                        }
                        else
                        {
                            cout << "                                            Optiune invalida!" << endl;
                            cout << "                     Pentru a reveni la ecranul principal introduceti 'Y' de la tastatura:" << endl;
                            cin >> inceput;
                            if (inceput == "Y")
                                goto start;
                        }
                    }
                    else
                    {
                        cout << "                                  EROARE! Nu aveti produse in cosul electronic." << endl;
                        cout << "                     Pentru a reveni la ecranul de inceput pentru client apasati 'C' de la tastatura." << endl;
                        cout << "                          Pentru a reveni la ecranul principal introduceti 'Y' de la tastatura." << endl;
                        cin >> inceput;
                        if (inceput == "Y")
                            goto start;
                        else if (inceput == "C")
                            goto inceputClient;
                    }
                }
            }
            else
            {
                cout << "                                    EROARE! Nu aveti produse in cosul electronic." << endl;
                cout << "                     Pentru a reveni la ecranul de inceput pentru client apasati 'C' de la tastatura." << endl;
                cout << "                          Pentru a reveni la ecranul principal introduceti 'Y' de la tastatura." << endl;
                cin >> inceput;
                if (inceput == "Y")
                    goto start;
                else if (inceput == "C")
                    goto inceputClient;
            }
    }
    else
        if (tipUtilizator == 2)
        {

            cout << " ----------------------------------------------ECRAN INREGISTRARE MAGAZIN---------------------------------------------" << endl;
            cout << "|                                                                                                                     |" << endl;
            cout << "|                                                                                                                     |" << endl;
            cout << "|                                                                                                                     |" << endl;
            cout << "|                                                                                                                     |" << endl;
            cout << "|             TASTATI 1 PENTRU                                           TASTATI 2 PENTRU                             |" << endl;
            cout << "|                 A VA LOGA                                               A FACE CERERE                               |" << endl;
            cout << "|          IN CONTUL DUMNEAVOASTRA                               PENTRU A INREGISTRA UN MAGAZIN                       |" << endl;
            cout << "|                                                                       PE SITE-UL NOSTRU                             |" << endl;
            cout << "|                                                                                                                     |" << endl;
            cout << "|                                                                                                                     |" << endl;
            cout << " ---------------------------------------------------------------------------------------------------------------------" << endl;
            cout << "                                                      -->  ";
            int alegereMagazin;
            cin >> alegereMagazin;
            if (alegereMagazin == 1)
            {
                cout << endl;
                cout << "                                      INTRODUCETI ID-UL MAGAZINULUI " << endl;
                cout << "                                             -->  ";
                int idMagazin;
                cin >> idMagazin;
                itMapMagazine = mapMagazin.find(idMagazin);
                Magazin& ma = mapMagazin.at(idMagazin);
                if (itMapMagazine != mapMagazin.end())
                {
                    cout << "                                 ---------------- " << ma.getNumeMagazin() << " ----------------" << endl;
                    cout << "                                    INTRODUCETI NUMELE DE UTILIZATOR " << endl;
                    cout << "                                             -->  ";
                    string utilizatorMagazin;
                    cin >> utilizatorMagazin;
                    if (utilizatorMagazin == ma.getNumeUtilizator())
                    {
                        cout << "                                            INTRODUCETI PAROLA " << endl;
                        cout << "                                             -->  ";
                        string parolaMagazin;
                        cin >> parolaMagazin;
                        if (parolaMagazin == ma.getParola())
                        {
                        inceputMagazin:
                            system("cls");
                            cout << " ------------------------------------------------BINE ATI VENIT " << ma.getNumeUtilizator() << "----------------------------------------------" << endl;
                            cout << "|                                        --------- " << ma.getNumeMagazin() << " ---------" << endl;
                            cout << "|               DATE PERSONALE:                                                               " << endl;
                            cout << "|                     -- Nume de utilizator: " << ma.getNumeUtilizator() << endl;
                            cout << "|                     -- Parola: ";
                            for (int i = 0; i < ma.getParola().size(); i++)
                                cout << "*";
                            cout << endl;
                            cout << "|               DATE INSTITUTIONALE:" << endl;
                            cout << "|                     -- Nume magazin: " << ma.getNumeMagazin() << endl;
                            cout << "|                     -- Adresa: " << ma.getAdresa() << endl;
                            cout << "|                     -- Email: " << ma.getEmail() << endl;
                            cout << "|                     -- Numar produse disponibile: " << ma.getNrProduseDisponibile() << endl;
                            cout << "|            |   ";
                            for (int i = 0; i < ma.getNrProduseDisponibile(); i++)
                                cout << ma.getProduseDisponibile()[i].getNumeProdus() << " - " << ma.getProduseDisponibile()[i].getPret() << " LEI   |   ";
                            cout << endl;
                            cout << "|                     -- Numar comenzi primite: " << ma.getNrComenziPrimite() << endl;
                            cout << "|            |   ";
                            for (int i = 0; i < ma.getNrComenziPrimite(); i++)
                                cout << i + 1 << ". " << ma.getComenziPrimite()[i].getNrProduseComandate() << " produse - " << ma.getComenziPrimite()[i].getPretTotal() << " LEI   |   ";
                            cout << endl;
                            cout << "|                                                                                                                     " << endl;
                            cout << "|    PENTRU A ADAUGA PRODUSE            PENTRU A EDITA UN PRODUS            PENTRU A STERGE UN PRODUS                 " << endl;
                            cout << "|        APASATI TASTA 1                     APASATI TASTA 2                       APASATI TASTA 3                 " << endl;
                            cout << "|                                                                                                                     " << endl;
                            cout << "|                        PENTRU A PRELUCRA COMENZILE DIN MAGAZIN APASATI TASTA 4                                 " << endl;
                            cout << "|                                                                                                                     " << endl;
                            cout << " ---------------------------------------------------------------------------------------------------------------------" << endl;
                            cout << "                                             -->  ";
                            int alegereProduse;
                            cin >> alegereProduse;
                            if (alegereProduse == 1)
                            {
                                system("cls");
                                +ma;
                                cout << "       => Pentru a reveni la ecranul de primire pentru magazin apasati 'S' de la tastatura." << endl;
                                cout << "       => Pentru a reveni la ecranul principal introduceti 'Y' de la tastatura." << endl;
                                string inceput;
                                cin >> inceput;
                                if (inceput == "Y")
                                    goto start;
                                else
                                    if (inceput == "S")
                                        goto inceputMagazin;
                            }
                            else
                                if (alegereProduse == 2)
                                {
                                    system("cls");
                                    ~ma;
                                    cout << "       => Pentru a reveni la ecranul de primire pentru magazin apasati 'S' de la tastatura." << endl;
                                    cout << "       => Pentru a reveni la ecranul principal introduceti 'Y' de la tastatura." << endl;
                                    string inceput;
                                    cin >> inceput;
                                    if (inceput == "Y")
                                        goto start;
                                    else
                                        if (inceput == "S")
                                            goto inceputMagazin;
                                }
                                else
                                    if (alegereProduse == 3)
                                    {
                                        system("cls");
                                        -ma;
                                        cout << "       => Pentru a reveni la ecranul de primire pentru magazin apasati 'S' de la tastatura." << endl;
                                        cout << "       => Pentru a reveni la ecranul principal introduceti 'Y' de la tastatura." << endl;
                                        string inceput;
                                        cin >> inceput;
                                        if (inceput == "Y")
                                            goto start;
                                        else
                                            if (inceput == "S")
                                                goto inceputMagazin;
                                    }
                                    else
                                        if (alegereProduse == 4)
                                        {
                                            system("cls");
                                            cout << " -----------------------------------------------ECRAN PRELUCRARE COMENZI----------------------------------------------" << endl;
                                            cout << "|                                                                                                                     |" << endl;
                                            cout << "|                                                                                                                     |" << endl;
                                            cout << "|                     -- Numar comenzi primite: " << ma.getNrComenziPrimite() << endl;
                                            cout << "| " << endl;
                                            for (int i = 0; i < ma.getNrComenziPrimite(); i++)
                                            {
                                                cout << "|       | Comanda No. " << i + 1 << ". " << ma.getComenziPrimite()[i].getNrProduseComandate() << " produse -  Valoare totala = " << ma.getComenziPrimite()[i].getPretTotal() << " LEI   |   " << endl;
                                                /*cout << "|  Produsele care fac parte din aceasta comanda sunt:";
                                                for (int j = 0; j < ma.getComenziPrimite()[i].getNrProduseComandate(); j++)
                                                    cout << "|  -> " << ma.getComenziPrimite()[i].getProduseComandate()[j].getNumeProdus()<<endl;*/
                                            }
                                            cout << "|                                                                                                                     |" << endl;

                                            try {
                                                ofstream outTxt("raportComenziPrimite.txt", ios::out);
                                                if (!outTxt) {
                                                    throw   "|                                          Nu s-a putut genera fisierul text!                                         |";
                                                }
                                                else {
                                                    outTxt << ma;
                                                    outTxt.close();
                                                    cout << "|                                                RAPORTUL A FOST GENERAT.                                             |" << endl;
                                                }
                                            }
                                            catch (const char* ex) {
                                                cout << "Nu s-a putut lucra cu fisierul text. " << ex << endl;
                                            }
                                            catch (...) {
                                                cout << "Nu s-a putut lucra cu fisierul text." << endl;
                                            }
                                            cout << "|                                                                                                                     |" << endl;
                                            cout << " ---------------------------------------------------------------------------------------------------------------------" << endl;
                                            cout << "       => Pentru a reveni la ecranul de primire pentru magazin apasati 'S' de la tastatura." << endl;
                                            cout << "       => Pentru a reveni la ecranul principal introduceti 'Y' de la tastatura." << endl;
                                            string inceput;
                                            cin >> inceput;
                                            if (inceput == "Y")
                                                goto start;
                                            else
                                                if (inceput == "S")
                                                    goto inceputMagazin;
                                        }
                                        else
                                        {
                                            cout << "                 EROARE! Singurele optiuni sunt 1, 2, 3 si 4." << endl;
                                            cout << "     Pentru a reveni la ecranul principal introduceti 'Y' de la tastatura." << endl;
                                            string inceput;
                                            cin >> inceput;
                                            if (inceput == "Y")
                                                goto start;
                                        }
                        }
                        else
                        {
                            cout << "                      Parola introdusa este gresita." << endl;
                            cout << "     Pentru a reveni la ecranul principal introduceti 'Y' de la tastatura." << endl;
                            string inceput;
                            cin >> inceput;
                            if (inceput == "Y")
                                goto start;
                        }
                    }
                    else
                    {
                        cout << "      Numele de utilizator nu a fost gasit in baza de date pentru magazinul introdus." << endl;
                        cout << "          Pentru a reveni la ecranul principal introduceti 'Y' de la tastatura." << endl;
                        string inceput;
                        cin >> inceput;
                        if (inceput == "Y")
                            goto start;
                    }
                }
                else
                {
                    cout << "              ID-ul introdus nu a fost gasit in baza de date. Ne pare rau." << endl;
                    cout << "        Pentru a reveni la ecranul principal introduceti 'Y' de la tastatura." << endl;
                    string inceput;
                    cin >> inceput;
                    if (inceput == "Y")
                        goto start;
                }
            }
            else
                if (alegereMagazin == 2)
                {
                    cout << endl;
                    cout << "    INTRODUCETI MAIL-UL PERSONAL: ";
                    string mail;
                    cin >> mail;
                    cout << "                  -----------------" << endl;
                    cout << "             Va vom contacta in 3-5 zile lucratoare" << endl;
                    cout << "              cu legatura la cerinta dumneavoasta! :)" << endl;
                    cout << "Pentru a reveni la ecranul principal introduceti 'Y' de la tastatura." << endl;
                    string inceput;
                    cin >> inceput;
                    if (inceput == "Y")
                        goto start;
                }
                else
                {
                    cout << "                     EROARE! Singurele optiuni sunt 1 si 2." << endl;
                    cout << "        Pentru a reveni la ecranul principal introduceti 'Y' de la tastatura." << endl;
                    string inceput;
                    cin >> inceput;
                    if (inceput == "Y")
                        goto start;
                }
        }
        else
        {
            cout << "                          EROARE! Singurele optiuni sunt 1 si 2." << endl;
            cout << "        Pentru a reveni la ecranul principal introduceti 'Y' de la tastatura." << endl;
            string inceput;
            cin >> inceput;
            if (inceput == "Y")
                goto start;
        }

    return 0;
}



