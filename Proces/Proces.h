#pragma once
#include <string>
// using namespace std;
#include <iostream>
class Proces
{
protected:
    std::string reclamant;
    std::string reclamat;
    int nrProces;

public:
    Proces(int nrProces = -1, std::string reclamant = "", std::string reclamat = "") : reclamant{reclamant}, reclamat{reclamat}, nrProces{nrProces} {};
    Proces(const Proces &x) : nrProces{x.nrProces}, reclamant{x.reclamant}, reclamat{x.reclamat} {}
    friend std::ostream &operator<<(std::ostream &, const Proces &);
    friend std::istream &operator>>(std::istream &, Proces &);
    virtual std::ostream &afis(std::ostream &) const;
    int getNrProces() const { return nrProces; };
    virtual bool getStadiu() const = 0;
    Proces &operator=(const Proces &);
    virtual std::istream &citi(std::istream &);
    virtual ~Proces(){};
};
Proces &Proces::operator=(const Proces &x)
{
    nrProces = x.nrProces;
    reclamant = x.reclamant;
    reclamat = x.reclamat;
    return *this;
}
std::istream &Proces::citi(std::istream &os)
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
std::ostream &Proces::afis(std::ostream &os) const
{
    os << "NrProces: " << nrProces << "\nReclamant: " << reclamant << "\nReclamat: " << reclamat << '\n';
    return os;
}
std::istream &operator>>(std::istream &os, Proces &proces)
{
    proces.Proces::citi(os);
    return proces.citi(os);
}