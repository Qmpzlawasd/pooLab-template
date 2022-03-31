#pragma once
#include "Proces.h"
class Proces_civil : protected Proces
{
private:
    double dauneMorale;
    double dauneMateriale;
    int nrMartori;
    bool stadiu;

public:
    Proces_civil(double dauneMorale, double dauneMateriale, int nrMartori, bool stadiu) : dauneMateriale{dauneMateriale}, dauneMorale{dauneMorale}, nrMartori{nrMartori}, stadiu{(nrMartori > 5) ? 1 : 0} {};
    Proces_civil(double dauneMorale, double dauneMateriale, int nrMartori, bool stadiu) : dauneMateriale{0}, dauneMorale{0}, nrMartori{0}, stadiu{0} {}
    void setStadiu(const bool &a)
    {
        stadiu = a;
    }
    double taxaDeTimbru() const
    {
        return 10 / 100 * dauneMorale + 10 / 100 * dauneMateriale;
    }
    Proces_civil &operator=(const Proces_civil &x)
    {
        dauneMorale = x.dauneMorale;
        dauneMateriale = x.dauneMateriale;
        nrMartori = x.nrMartori;
        stadiu = x.stadiu;
        return *this;
    }
    ~Proces_civil(){};
    Proces_civil(const Proces_civil &x)
    {
        dauneMorale = x.dauneMorale;
        dauneMateriale = x.dauneMateriale;
        nrMartori = x.nrMartori;
        stadiu = x.stadiu;
    }
    friend ostream &operator<<(ostream &os, const Proces_civil &civil)
    {
        os << "DauneMorale: " << civil.dauneMorale << "\nDauneMateriale: " << civil.dauneMateriale << "\nNrMartori: "
           << civil.nrMartori << "\nStadiu: " << civil.stadiu << '\n';
        return os;
    };
    friend istream &operator>>(istream &os, Proces_civil &civil)
    {
        os>>civil.dauneMorale >> civil.dauneMateriale >> civil.nrMartori >> civil.stadiu;
        civil.stadiu = (civil.nrMartori > 5) ? 1 : 0;
        return os;
    };
};