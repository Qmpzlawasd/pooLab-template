#pragma once
#include <iostream>
#include <vector>
#include "Departament.h"
using namespace std;

class Companie
{
    std::string nume;
    std::vector<Departament *> dept;

public:
    size_t numarDeAngajati(const std::string &numeDepartament) const
    {
        size_t count = 0;
        for (auto &&i : dept)
        {
            if (i->getNume() == numeDepartament)
            {
                count += i->nrAngajati();

            }
        }
        return count;
    }
    Companie() =default;
    Companie(const std::string &nume, int scutireDeImpozit) : nume(nume){};
    Companie(const Companie &x) : nume(x.nume)
    {
        std::cout << "companie CC" << std::endl;
        this->~Companie();
        for (const auto &c : x.dept)
        {
            Departament *n = new Departament(*c);
            this->dept.push_back(n);
        }
    };
    void setManager(const std::string &numeDepartament, const std::string &numeAngajat)
    {

        for (auto &&i : dept)
        {
            if (i->getNume() == numeDepartament)
            {
                i->setManager(numeAngajat);
            }
        }
    }
    friend std::ostream &operator<<(std::ostream &os, const Companie &c)
    {
        c.afis(os);
        return os;
    }
    friend std::istream &operator>>(std::istream &os, Companie &c)
    {
        c.citi(os);
        return os;
    }
    Companie &operator=(const Companie &);
    Companie &operator+(const Companie &);
    void deleteDepartament(const Departament &);
    void addDepartament(const Departament &);
    void deleteAngajat(const Angajat &);
    void addAngajat(const Angajat &);
    void afis(std::ostream &) const;
    const std::string &getNume() const { return nume; }
    void citi(std::istream &);
    bool operator==(const Companie &rhs) const
    {
        return nume == rhs.nume &&
               dept == rhs.dept ;
    }
    ~Companie()
    {
        for (auto &x : dept)
        {
            delete x;
        }
        dept.clear();
    }
};

void Companie::afis(std::ostream &os) const
{
    os << "\n**************Companie**************";
    os << "\nnume: " << nume;
    for (const auto &x : dept)
    {

        os << *x;
    }
    os << "\n**************/Companie*************\n\n";
}
void Companie::citi(std::istream &os)
{
    int marime{0};
    std::cout << "\nnume: ";
    os >> nume;
    std::cout << "\nCate departamente citim? ... ";
    os >> marime;
    for (int i = 0; i < marime; i++)
    {
        Departament *heap = new Departament;
        os >> *heap;
        this->dept.push_back(heap);
    }
}