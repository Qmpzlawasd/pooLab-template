#pragma once
#include <string>
using namespace std;
#include <iostream>
class Proces
{
protected:
    std::string reclamant;
    std::string reclamat;
    int nrProces;

public:
    Proces(int nrProces = -1, std::string reclamant = "", std::string reclamat = "") : nrProces{nrProces}, reclamant{reclamant}, reclamat{reclamat} {};
    Proces(const Proces &x) : nrProces{x.nrProces}, reclamant{x.reclamant}, reclamat{x.reclamat} {}
    friend std::ostream &operator<<(std::ostream &, const Proces &);
    friend std::istream &operator>>(std::istream &, Proces &);
    virtual ostream &afis(ostream &) const;
    virtual bool getStadiu() const = 0;
    Proces &operator=(const Proces &);
    virtual istream &citi(istream &);
    virtual ~Proces(){};
};
Proces &Proces::operator=(const Proces &x)
{
    nrProces = x.nrProces;
    reclamant = x.reclamant;
    reclamat = x.reclamat;
    return *this;
}
istream &Proces::citi(istream &os)
{
    std::cout << "NrProces: ";
    os >> nrProces;
    std::cout << "Reclamant: ";
    os >> reclamant;
    std::cout << "Reclamat: ";
    os >> reclamat;

    return os;
}
std::ostream &operator<<(std::ostream &os, const Proces &proces)
{
    proces.Proces::afis(os);
    return proces.afis(os);
}
ostream &Proces::afis(ostream &os) const
{
    os << "NrProces: " << nrProces << "\nReclamant: " << reclamant << "\nReclamat: " << reclamat << '\n';
    return os;
}
std::istream &operator>>(std::istream &os, Proces &proces)
{
    proces.Proces::citi(os);
    return proces.citi(os);
}