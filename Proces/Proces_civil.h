#pragma once
#include <iostream>
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

public:
    ~Proces_civil(){};
    Proces_civil(double dauneMorale = 0, double dauneMateriale = 0, int nrMartori = 0, bool stadiu = 0) : dauneMateriale{dauneMateriale}, dauneMorale{dauneMorale}, nrMartori{nrMartori}, stadiu{(nrMartori > 5) ? true : false}
    {
        setTaxa(*this);
    }
    bool getStadiu() const { return stadiu; }
    void setStadiu(const bool &a)
    {
        stadiu = a;
    }
    static void setTaxa(const Proces_civil &x)
    {
        if (taxaMaxima < x.taxaDeTimbru())
        {
            taxaMaxima = x.taxaDeTimbru();
            procesScump = x.nrProces;
        }
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
        std::cout << "NrProces: ";
        os >> civil.nrProces;
        std::cout << "Reclamant: ";
        os >> civil.reclamant;
        std::cout << "Reclamat: ";
        os >> civil.reclamat;
        std::cout << "DauneMorale: ";
        os >> civil.dauneMorale;
        std::cout << "DauneMateriale: ";
        os >> civil.dauneMateriale;
        std::cout << "NrMartori: ";
        os >> civil.nrMartori;
        std::cout << "Stadiu: ";
        os >> civil.stadiu;
        civil.stadiu = (civil.nrMartori > 5) ? 1 : 0;
        setTaxa(civil);

        return os;
    }
    friend std::ostream &operator<<(std::ostream &os, const Proces_civil &civil)
    {
        os << "NrProces: " << civil.nrProces << "\nReclamant: " << civil.reclamant << "\nReclamat: " << civil.reclamat << '\n';
        os << "DauneMorale: " << civil.dauneMorale << "\nDauneMateriale: " << civil.dauneMateriale << "\nNrMartori: "
           << civil.nrMartori << "\nStadiu: " << civil.stadiu << '\n';
           os<<civil.taxaMaxima<<' '<<civil.procesScump<<'\n';
        return os;
    }
};
double Proces_civil::taxaMaxima = -1;
int Proces_civil::procesScump = -1;
