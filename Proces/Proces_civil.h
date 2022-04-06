#pragma once
#include <iostream>
#include "Proces.h"
#include <string>
// using namespace std;

class Proces_civil : public Proces
{
private:
    int nrMartori;
    bool stadiu;
    double dauneMorale;
    double dauneMateriale;
    static int procesScump;
    static double taxaMaxima;
    static void setTaxa(const Proces_civil &);

public:
    Proces_civil(const Proces_civil &x) : Proces{x}, nrMartori{x.nrMartori}, stadiu{x.stadiu}, dauneMorale{x.dauneMorale}, dauneMateriale{x.dauneMateriale} {};
    Proces_civil(double dauneMorale = 0, double dauneMateriale = 0, int nrMartori = 0, bool stadiu = 0) : Proces{}, nrMartori{nrMartori}, stadiu{(nrMartori > 5) ? true : false}, dauneMorale{dauneMorale}, dauneMateriale{dauneMateriale} { setTaxa(*this); }
    Proces_civil(int nrProces, std::string reclamant, std::string reclamat, double dauneMorale = 0, double dauneMateriale = 0, int nrMartori = 0, bool stadiu = 0) : Proces{nrProces, std::move(reclamant), std::move(reclamat)}, nrMartori{nrMartori}, stadiu{  (nrMartori > 5 ) ? true : false}, dauneMorale{dauneMorale}, dauneMateriale{dauneMateriale} { setTaxa(*this); };
    //////////////////////////////////////////////////////////////////////// 
    friend std::ostream &operator<<(std::ostream &, const Proces_civil &);
    friend std::istream &operator>>(std::istream &, Proces_civil &);
    Proces_civil &operator=(const Proces_civil &);
    bool getStadiu() const override { return stadiu; }
    virtual std::ostream &afis(std::ostream &) const override;
    virtual std::istream &citi(std::istream &) override;
    static void printScumpProces();
    void setStadiu(const bool &);
    double taxaDeTimbru() const;
    ~Proces_civil(){};
};
int Proces_civil::procesScump = -1;
double Proces_civil::taxaMaxima = -1;
void Proces_civil::setStadiu(const bool &a)
{
    stadiu = a;
}
std::istream &operator>>(std::istream &os, Proces_civil &civil)
{

    civil.Proces::citi(os);
    return civil.citi(os);
}
std::ostream &operator<<(std::ostream &os, const Proces_civil &civil)
{
    civil.Proces::afis(os);
    return civil.afis(os);
}
void Proces_civil::printScumpProces()
{
    std::cout << procesScump ;
}
std::ostream &Proces_civil::afis(std::ostream &os) const
{
    os << "DauneMorale: " << dauneMorale << "\nDauneMateriale: " << dauneMateriale << "\nNrMartori: "
       << nrMartori << "\nStadiu: " << stadiu << '\n';

    return os;
}
std::istream &Proces_civil::citi(std::istream &os)
{
    std::cout << "DauneMorale: ";
    os >> dauneMorale;
    std::cout << "DauneMateriale: ";
    os >> dauneMateriale;
    std::cout << "NrMartori: ";
    os >> nrMartori;
    std::cout << "Stadiu: ";
    os >> stadiu;
    stadiu = (nrMartori > 5) ? true : false;
    setTaxa(*this);

    return os;
}
double Proces_civil::taxaDeTimbru() const
{
    return .1 * dauneMorale + .1 * dauneMateriale;
}
Proces_civil &Proces_civil::operator=(const Proces_civil &x)
{
    try
    {
        Proces &rb = (*this); // upcast
        rb = x;
    }
    catch (std::bad_cast&)
    {
        std::exit(1);
    }

    dauneMorale = x.dauneMorale;
    dauneMateriale = x.dauneMateriale;
    nrMartori = x.nrMartori;
    stadiu = x.stadiu;
    setTaxa(*this);
    return *this;
}
void Proces_civil::setTaxa(const Proces_civil &x)
{
    if (taxaMaxima < x.taxaDeTimbru())
    {
        taxaMaxima = x.taxaDeTimbru();
        procesScump = x.nrProces;
    }
}
