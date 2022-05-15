#pragma once
#include <vector>
#include <iostream>
#include "Angajat.h"
using namespace std;
class Departament
{
    std::vector<Angajat *> angaj;
    std::string nume;
    bool scutireDeImpozit;

public:
    const std::string &getNume() const { return nume; };
    size_t nrAngajati() const { return angaj.size(); };
    void setManager(const std::string &numeAngajat)
    {
        Angajat *manag;

        for (auto &&i : angaj)
        {
            if (i->getNume() == numeAngajat)
            {
                manag = i;
                i->setEsteSef(1);
                break;
            }
        }
        for (auto &&i : angaj)
        {
            if (i->getNume() != numeAngajat)
            {
                i->setManager(manag);
            }
        }
    }
    size_t auditSalariu() const
    {
        size_t count = 0;
        for (auto &&i : angaj)
        {
            count += i->getSalariu();
        }

        return count - count * (scutireDeImpozit) ? .16 : 0;
    }
    Departament() =default;
    Departament(const std::string &x, const bool &t) : scutireDeImpozit(t), nume{x} {};
    Departament(const Departament &x) : scutireDeImpozit(x.scutireDeImpozit), nume{x.nume}
    {
        this->~Departament();
        for (const auto &c : x.angaj)
        {
            Angajat *n = new Angajat(*c);
            this->angaj.push_back(n);
        }
    }
    friend std::ostream &operator<<(std::ostream &os, const Departament &d)
    {
        d.afis(os);
        return os;
    }
    friend std::istream &operator>>(std::istream &os, Departament &d)
    {
        d.citi(os);
        return os;
    }
    void afis(std::ostream &) const;
    void citi(std::istream &);
    ~Departament()
    {
        for (auto &x : angaj)
        {
            delete x;
        }
        angaj.clear();
    }
};

void Departament::afis(std::ostream &os) const
{
    os << "\n    xxxxxxxxxxxxxx Departamente xxxxxxxxxxxxxx";

    os << "\n    Nume: " << nume;
    os << "\n    reducere impozit: " << ((scutireDeImpozit) ? " 16% " : " 0% ") << '\n';

    os << "\n\t|+++++++++++Angajati+++++++++++\n\t|";

    for (const auto &x : angaj)
    {
        os << *x;
    }
    os << "\n\t|+++++++++++/Angajati++++++++++\n\n";

    os << "\n    xxxxxxxxxxxxxx /Departamente xxxxxxxxxxxxx\n\n";
}
void Departament::citi(std::istream &os)
{
    int z{0};
    std::cout << "\nNume: ";
    os >> nume;
    std::cout << "\nE scutit de impozit? ... ";
    os >> scutireDeImpozit;
    std::cout << "\nCati angajati citim? ... ";
    os >> z;
    for (int i = 0; i < z; i++)
    {
        Angajat *heap = new Angajat;
        os >> *heap;
        angaj.push_back(heap);
    }
}