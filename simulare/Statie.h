#pragma once
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include "Statie.h"

using namespace std;
static size_t coduri = 0;

class Statie
{
private:
    size_t codStatie;
    std::string strada;
    std::string nume;
    int numar, sector;
    std::vector<int> opresc;

public:
    Statie() = default;
    Statie(size_t codStatie, const std::string &strada, const std::string &nume, int numar, int sector);
    size_t getCodStatie() const;
    const std::string &getStrada() const;
    const std::string &getNume() const;
    int getNumar() const;
    int getSector() const;
    const std::vector<int> &getOpresc() const;
    void setCodStatie(size_t codStatie);
    void setStrada(const std::string &strada);
    void setNume(const std::string &nume);
    void setNumar(int numar);
    void setSector(int sector);
    void setOpresc(const std::vector<int> &opresc);
    friend std::ostream &operator<<(std::ostream &, const Statie &);
    friend std::istream &operator>>(std::istream &, Statie &);
    Statie &operator=(const Statie &rhs);
    void afis(std::ostream &) const;
    void citi(std::istream &);
};
void Statie::afis(std::ostream &os) const
{
    os << "codStatie: " << codStatie << " strada: " << strada << " nume: " << nume << " numar: "
       << numar << " sector: " << sector << " opresc: ";
    for (auto &&i : opresc)
    {
        cout << i << ' ';
    }
    cout << '\n';
}
void Statie::citi(std::istream &os)
{
    cout << "codStatie: ";
    os >> codStatie;
    cout << " strada: ";
    os >> strada;
    cout << " nume: ";
    os >> nume;
    cout << " numar: ";
    os >> numar;
    cout << " sector: ";
    os >> sector;
    cout << " cate autobuze ";
    int x, c;
    os >> x;
    for (size_t i = 0; i < x; i++)
    {
        os >> c;
        opresc.push_back(c);
    }
    cout << '\n';
}

std::istream &operator>>(std::istream &os, Statie &statie)
{
    statie.citi(os);
    return os;
}
Statie::Statie(size_t codStatie, const std::string &strada, const std::string &nume, int numar, int sector) : codStatie(codStatie), strada(strada), nume(nume), numar(numar),
                                                                                                              sector(sector) {}

std::ostream &operator<<(std::ostream &os, const Statie &statie)
{
    statie.afis(os);
    return os;
}

Statie &Statie::operator=(const Statie &rhs)
{
    codStatie = rhs.codStatie;
    strada = rhs.strada;
    nume = rhs.nume;
    numar = rhs.numar;
    sector = rhs.sector;
    opresc = rhs.opresc;
    return *this;
}
