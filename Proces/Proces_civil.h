#pragma once
#include <iostream>
#include "Proces.h"
class Proces_civil : protected Proces
{
private:
    bool stadiu;
    int nrMartori;
    double dauneMorale;
    double dauneMateriale;
    static double taxaMaxima;

public:
    ~Proces_civil(){};
    Proces_civil(double dauneMorale, double dauneMateriale, int nrMartori, bool stadiu) : dauneMateriale{dauneMateriale}, dauneMorale{dauneMorale}, nrMartori{nrMartori}, stadiu{(nrMartori > 5) ? true : false} {};
    Proces_civil() : dauneMateriale{0}, dauneMorale{0}, nrMartori{0}, stadiu{0} {}
    void setStadiu(const bool &a)
    {
        stadiu = a;
    }
    static void setTaxa(const double &x)
    {
        taxaMaxima = x;
    }
    double taxaDeTimbru() const
    {
        return 10 / 100 * dauneMorale + 10 / 100 * dauneMateriale;
    }
    Proces_civil(const Proces_civil &x)
    {
        dauneMorale = x.dauneMorale;
        dauneMateriale = x.dauneMateriale;
        nrMartori = x.nrMartori;
        stadiu = x.stadiu;
    }
    Proces_civil &operator=(const Proces_civil &x)
    {
        dauneMorale = x.dauneMorale;
        dauneMateriale = x.dauneMateriale;
        nrMartori = x.nrMartori;
        stadiu = x.stadiu;
        return *this;
    }
    friend std::istream &operator>>(std::istream &os, Proces_civil &civil)
    {
        std::cout << "DauneMorale: ";
        os >> civil.dauneMorale;
        std::cout << "DauneMateriale: ";
        os >> civil.dauneMateriale;
        std::cout << "NrMartori: ";
        os >> civil.nrMartori;
        std::cout << "Stadiu: ";
        os >> civil.stadiu;
        civil.stadiu = (civil.nrMartori > 5) ? 1 : 0;

        return os;
    };
    friend std::ostream &operator<<(std::ostream &os, const Proces_civil &civil)
    {
        os << "DauneMorale: " << civil.dauneMorale << "\nDauneMateriale: " << civil.dauneMateriale << "\nNrMartori: "
           << civil.nrMartori << "\nStadiu: " << civil.stadiu << '\n';
        return os;
    };

};
double Proces_civil::taxaMaxima = -1;
