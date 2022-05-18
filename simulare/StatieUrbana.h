#pragma once
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include "Statie.h"

using namespace std;
class StatieUrbana : public virtual Statie
{
public:
    StatieUrbana() = default;
    StatieUrbana(size_t codStatie, const std::string &strada, const std::string &nume, int numar, int sector,
                 bool legitimatie, const std::string &codIntern);

    bool isLegitimatie() const;
    void setLegitimatie(bool legitimatie);
    const std::string &getCodIntern() const;
    void setCodIntern(const std::string &codIntern);
    friend std::ostream &operator<<(std::ostream &os, const StatieUrbana &urbana);
    friend std::istream &operator<<(std::istream &os, StatieUrbana &urbana);

private:
    bool legitimatie;
    std::string codIntern; // su
};

bool StatieUrbana::isLegitimatie() const
{
    return legitimatie;
}

void StatieUrbana::setLegitimatie(bool legitimatie)
{
    StatieUrbana::legitimatie = legitimatie;
}

const std::string &StatieUrbana::getCodIntern() const
{
    return codIntern;
}

void StatieUrbana::setCodIntern(const std::string &codIntern)
{
    StatieUrbana::codIntern = codIntern;
}

StatieUrbana::StatieUrbana(size_t codStatie, const std::string &strada, const std::string &nume, int numar, int sector,
                           bool legitimatie, const std::string &codIntern) : Statie(codStatie, strada, nume, numar, sector), legitimatie(legitimatie), codIntern(codIntern) {}

std::ostream &operator<<(std::ostream &os, const StatieUrbana &urbana)
{
    os << static_cast<const Statie &>(urbana) << " legitimatie: " << urbana.legitimatie << " codIntern: "
       << urbana.codIntern;
    return os;
}

std::istream &operator<<(std::istream &os, StatieUrbana &urbana)
{
 return os;   
}
