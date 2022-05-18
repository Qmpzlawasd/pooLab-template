#pragma once
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include "Statie.h"

using namespace std;
class StatieExtraurbana : public virtual Statie
{
public:
StatieExtraurbana()=default;
    StatieExtraurbana(size_t codStatie, const std::string &strada, const std::string &nume, int numar, int sector,
                       const std::string &codIntern);
    const std::string &getCodIntern() const;
    void setCodIntern(const std::string &codIntern);
    friend std::ostream &operator<<(std::ostream &os, const StatieExtraurbana &extraurbana);
private:
    std::string codIntern; 
};
const std::string &StatieExtraurbana::getCodIntern() const
{
    return codIntern;
}

void StatieExtraurbana::setCodIntern(const std::string &codIntern)
{
    StatieExtraurbana::codIntern = codIntern;
}

StatieExtraurbana::StatieExtraurbana(size_t codStatie, const std::string &strada, const std::string &nume, int numar,
                                     int sector, const std::string &codIntern) : Statie(codStatie, strada, nume, numar, sector), codIntern(codIntern) {}

std::ostream &operator<<(std::ostream &os, const StatieExtraurbana &extraurbana)
{
    os << static_cast<const Statie &>(extraurbana) << " codIntern: " << extraurbana.codIntern;
    return os;
}