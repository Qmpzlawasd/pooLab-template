#pragma once
#include <iostream>
#include <string>
#include "Proces.h"
using namespace std;

class Proces_civil : public Proces
{
private:
    bool stadiu;
    int nrMartori;
    double dauneMorale;
    double dauneMateriale;
    static int procesScump;
    static double taxaMaxima;
    static void setTaxa(const Proces_civil &x)
    {
        if (taxaMaxima < x.taxaDeTimbru())
        {
            taxaMaxima = x.taxaDeTimbru();
            procesScump = x.nrProces;
        }
    }

public:
    ~Proces_civil(){};
    static void printScumpProces() 
    {
        cout << procesScump << "\n";
    }
    Proces_civil(double dauneMorale = 0, double dauneMateriale = 0, int nrMartori = 0, bool stadiu = 0) : dauneMateriale{dauneMateriale}, dauneMorale{dauneMorale}, nrMartori{nrMartori}, stadiu{(nrMartori > 5) ? true : false}
    {
        setTaxa(*this);
    }

    virtual ostream &afis(ostream &os) const
    {
        os << "DauneMorale: " << dauneMorale << "\nDauneMateriale: " << dauneMateriale << "\nNrMartori: "
           << nrMartori << "\nStadiu: " << stadiu << '\n';

        return os;
    }
    bool getStadiu() const { return stadiu; }
    void setStadiu(const bool &a)
    {
        stadiu = a;
    }

    double taxaDeTimbru() const
    {
        return .1 * dauneMorale + .1 * dauneMateriale;
    }
    Proces_civil(const Proces_civil &x) : dauneMorale{x.dauneMorale}, dauneMateriale{x.dauneMateriale}, nrMartori{x.nrMartori}, stadiu{x.stadiu} {}
    Proces_civil &operator=(const Proces_civil &x)
    {
        Proces &rb = (*this);
        rb = x;
        dauneMorale = x.dauneMorale;
        dauneMateriale = x.dauneMateriale;
        nrMartori = x.nrMartori;
        stadiu = x.stadiu;
        setTaxa(*this);
        return *this;
    }
    friend std::istream &operator>>(std::istream &os, Proces_civil &civil)
    {

        civil.Proces::citi(os);
        return civil.citi(os);
    }
    virtual istream &citi(istream &os)
    {
        std::cout << "DauneMorale: ";
        os >> dauneMorale;
        std::cout << "DauneMateriale: ";
        os >> dauneMateriale;
        std::cout << "NrMartori: ";
        os >> nrMartori;
        std::cout << "Stadiu: ";
        os >> stadiu;
        stadiu = (nrMartori > 5) ? 1 : 0;
        setTaxa(*this);

        return os;
    }
    friend std::ostream &operator<<(std::ostream &os, const Proces_civil &civil)
    {
        civil.Proces::afis(os);
        return civil.afis(os);
    }
};
double Proces_civil::taxaMaxima = -1;
int Proces_civil::procesScump = -1;
