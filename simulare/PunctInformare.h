#pragma once
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include "StatieExtraurbana.h"
#include "StatieUrbana.h"
using namespace std;
class PunctInformare : public StatieUrbana, public StatieExtraurbana
{
public:
    PunctInformare(size_t codStatie, const std::string &strada, const std::string &nume, int numar, int sector,
                   bool legitimatie, const std::string &codIntern, size_t codStatie1,
                   const std::string &strada1, const std::string &nume1, int numar1, int sector1,
                   const std::string &codIntern1) : StatieUrbana(codStatie, strada, nume, numar, sector, legitimatie, codIntern), StatieExtraurbana(codStatie1, strada1, nume1, numar1, sector1, codIntern1) {}
    virtual void afis(std::ostream &) const;
    virtual void citi(std::istream &);
    friend std::ostream &operator<<(std::ostream &os, const PunctInformare &informare)
    {
        os << static_cast<const StatieUrbana &>(informare) << ' ' << static_cast<const StatieExtraurbana &>(informare);
        return os;
    }

private:
    int estimare(const Statie *, const Statie *) const;
};
 void PunctInformare::afis(std::ostream &os) const{ }
     void PunctInformare::citi(std::istream &os){


         
     }