#pragma once
#include <iostream>
#include "InvalidData.h"
class Proces
{
protected:
    int nrProces;
    std::string reclamant;
    std::string reclamat;

public:
    Proces(int nrProces = -1, const std::string &reclamant = "", const std::string &reclamat = "") : nrProces{nrProces}, reclamant{reclamant}, reclamat{reclamat} {};
    Proces(const Proces &x) : nrProces{x.nrProces}, reclamant{x.reclamant}, reclamat{x.reclamat} {}
    friend std::ostream &operator<<(std::ostream &, const Proces &);
    friend std::istream &operator>>(std::istream &, Proces &);
    virtual std::ostream &afis(std::ostream &) const;
    int getNrProces() const { return nrProces; };
    virtual std::istream &citi(std::istream &);
    bool eNumar(const std::string &) const;
    void setReclamant(const std::string &);
    void setReclamat(const std::string &);
    virtual bool getStadiu() const = 0;
    const std::string &getReclamant();
    Proces &operator=(const Proces &);
    void setNrProces(const int &);
    virtual ~Proces(){};
};
const std::string &Proces::getReclamant()
{
    return reclamant;
}
Proces &Proces::operator=(const Proces &x)
{
    nrProces = x.nrProces;
    reclamant = x.reclamant;
    reclamat = x.reclamat;
    return *this;
}
std::istream &Proces::citi(std::istream &os)
{
    try
    {
        std::cout << "NrProces: ";
        std::string a;
        os >> a;
        if (eNumar(a))
        {
            nrProces = atoi(a.c_str());
        }
        else
            throw InvalidData{};
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        exit(0);
    }

    std::cout << "Reclamant: ";
    os >> reclamant;
    std::cout << "Reclamat: ";
    os >> reclamat;

    return os;
}
void Proces::setNrProces(const int &nrProcesx)
{
    Proces::nrProces = nrProcesx;
}
bool Proces::eNumar(const std::string &str)const
{
    for (const char &c : str)
    {
        if (std::isdigit(c) == 0)
            return false;
    }
    return true;
}
std::ostream &Proces::afis(std::ostream &os) const
{
    os << "NrProces: " << nrProces << "\nReclamant: " << reclamant << "\nReclamat: " << reclamat << '\n';
    return os;
}
void Proces::setReclamat(const std::string &reclamatx)
{
    Proces::reclamat = reclamatx;
}
void Proces::setReclamant(const std::string &reclamantx)
{
    Proces::reclamant = reclamantx;
}
std::istream &operator>>(std::istream &os, Proces &proces)
{
    proces.Proces::citi(os);
    return proces.citi(os);
}
std::ostream &operator<<(std::ostream &os, const Proces &proces)
{
    proces.Proces::afis(os);
    return proces.afis(os);
}
