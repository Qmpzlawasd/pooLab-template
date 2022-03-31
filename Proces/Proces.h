#pragma once
#include <string>
 static size_t asd{0};
class Proces
{
protected:
    int nrProces;
    std::string reclamant;
    std::string reclamat;

public:
    Proces() : nrProces{-1}, reclamant{""}, reclamat{""} {asd++;}
    Proces(const Proces &x)
    {

        nrProces = x.nrProces;
        reclamant = x.reclamant;
        reclamat = x.reclamat;
    }
    Proces(int nrProces, std::string reclamant, std::string reclamat) : nrProces{nrProces}, reclamant{reclamant}, reclamat{reclamat} {asd++;};
   virtual ~Proces(){};
    Proces &operator=(const Proces &x)
    {
        nrProces = x.nrProces;
        reclamant = x.reclamant;
        reclamat = x.reclamat;
        return *this;
    }
    friend ostream &operator<<(ostream &os, const Proces &proces)
    {
        os << "NrProces: " << proces.nrProces << "\nReclamant: " << proces.reclamant << "\nReclamat: " << proces.reclamat << '\n';
        return os;
    };
    friend istream &operator>>(istream &os,  Proces &proces)
    {
        os >> proces.nrProces >> proces.reclamant >> proces.reclamat;

        return os;
    };
};