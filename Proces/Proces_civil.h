#pragma once
#include <iostream>
#include "Proces.h"
#include "InvalidData.h"
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
    Proces_civil(int nrProces, std::string reclamant, std::string reclamat, double dauneMorale = 0, double dauneMateriale = 0, int nrMartori = 0) : Proces{nrProces, std::move(reclamant), std::move(reclamat)}, nrMartori{nrMartori}, stadiu{(nrMartori > 5) ? true : false}, dauneMorale{dauneMorale}, dauneMateriale{dauneMateriale} { setTaxa(*this); };
    Proces_civil(double dauneMorale = 0, double dauneMateriale = 0, int nrMartori = 0) : Proces{}, nrMartori{nrMartori}, stadiu{(nrMartori > 5) ? true : false}, dauneMorale{dauneMorale}, dauneMateriale{dauneMateriale} { setTaxa(*this); };
    Proces_civil(const Proces_civil &x) : Proces{x}, nrMartori{x.nrMartori}, stadiu{x.stadiu}, dauneMorale{x.dauneMorale}, dauneMateriale{x.dauneMateriale} {};
    friend std::ostream &operator<<(std::ostream &, const Proces_civil &);
    friend std::istream &operator>>(std::istream &, Proces_civil &);
    virtual std::ostream &afis(std::ostream &) const override;
    virtual std::istream &citi(std::istream &) override;
    bool getStadiu() const override { return stadiu; };
    Proces_civil &operator=(const Proces_civil &);
    void setDauneMateriale(const double &);
    void setDauneMorale(const double &);
    double getDauneMateriale() const;
    static void printScumpProces();
    void setNrMartori(const int &);
    double getDauneMorale() const;
    void setStadiu(const bool &);
    double taxaDeTimbru() const;
    int getNrMartori() const;
    ~Proces_civil(){};
};
int Proces_civil::procesScump = -1;
double Proces_civil::taxaMaxima = -1;
void Proces_civil::setStadiu(const bool &st)
{
    stadiu = st;
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
    try
    {
        if (procesScump == -1)
        {
            throw -1;
        }
    }
    catch (const int &)
    {
        std::cout << " nu avem rocese civile in vizor";
        return;
    }
    std::cout << procesScump;
}
std::ostream &Proces_civil::afis(std::ostream &os) const
{
    os << "DauneMorale: " << dauneMorale << "\nDauneMateriale: " << dauneMateriale << "\nNrMartori: "
       << nrMartori << "\nStadiu: " << stadiu << '\n';

    return os;
}
std::istream &Proces_civil::citi(std::istream &os)
{
    try
    {
        std::string a, b, c;
        std::cout << "DauneMorale: ";
        os >> a;
        std::cout << "DauneMateriale: ";
        os >> b;
        std::cout << "NrMartori: ";
        os >> c;

        if (eNumar(a) and eNumar(b) and eNumar(c))
        {
            dauneMorale = atoi(a.c_str());
            dauneMateriale = atoi(b.c_str());
            nrMartori = atoi(c.c_str());
        }
        else
            throw InvalidData{};
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        exit(0);
    }

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
    if (this != &x)
    {
        return *this;
    }

    try
    {
        Proces &rb = (*this); // upcast
        rb = x;
    }
    catch (std::bad_cast &)
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
double Proces_civil::getDauneMorale() const
{
    return dauneMorale;
}
void Proces_civil::setDauneMorale(const double &dauneMoralex)
{
    Proces_civil::dauneMorale = dauneMoralex;
    setTaxa(*this);
}
double Proces_civil::getDauneMateriale() const
{
    return dauneMateriale;
}
void Proces_civil::setDauneMateriale(const double &dauneMaterialex)
{
    Proces_civil::dauneMateriale = dauneMaterialex;
    setTaxa(*this);
}
int Proces_civil::getNrMartori() const
{
    return nrMartori;
}
void Proces_civil::setNrMartori(const int &nrMartorix)
{
    Proces_civil::nrMartori = nrMartorix;
}
