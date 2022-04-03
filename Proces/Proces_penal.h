#pragma once
// using namespace std;
#include <iostream>
#include <string>
#include "Proces.h"
class Proces_penal : public Proces
{
private:
    int dovezi;
    bool stadiu;

public:
    Proces_penal(int dovezi = 0, bool stadiu = 0) : Proces{}, dovezi{dovezi}, stadiu{(dovezi > 25) ? true : false} {};
    Proces_penal(int nrProces, std::string reclamant, std::string reclamat, int dovezi = 0, bool stadiu = 0) : Proces{nrProces, reclamant, reclamat}, dovezi{dovezi}, stadiu{(dovezi > 25) ? true : false} {};
    Proces_penal(const Proces_penal &x) : Proces{x}, dovezi{x.dovezi}, stadiu{x.stadiu} {};
    friend std::istream &operator>>(std::istream &, Proces_penal &);
    friend std::ostream &operator<<(std::ostream &, const Proces_penal &);
    Proces_penal &operator=(const Proces_penal &);
    bool getStadiu()   const override { return stadiu; };
    virtual std::ostream &afis(std::ostream &) const override;
    virtual std::istream &citi(std::istream &)override;
    void setStadiu(const bool &);
    ~Proces_penal(){};
};
void Proces_penal::setStadiu(const bool &a)
{
    stadiu = a;
}
std::ostream &Proces_penal::afis(std::ostream &os) const
{
    os << "Dovezi: " << dovezi << "\nStadiu: " << stadiu << '\n';
    return os;
}

std::ostream &operator<<(std::ostream &os, const Proces_penal &penal)
{
    penal.Proces::afis(os);
    return penal.afis(os);
}
std::istream &Proces_penal::citi(std::istream &os)
{
    std::cout << "NrDovezi: ";
    os >> dovezi;
    std::cout << "Stadiu: ";
    os >> stadiu;
    stadiu = (dovezi > 25) ? true : false; // altfel??
    return os;
}
std::istream &operator>>(std::istream &os, Proces_penal &penal)
{
    penal.Proces::citi(os);
    return penal.citi(os);
}
Proces_penal &Proces_penal::operator=(const Proces_penal &x)
{
    try
    {
        Proces &rb = (*this); // upcast
        rb = x;
    }
    catch (std::bad_cast)
    {
        std::exit(1);
    }

    dovezi = x.dovezi;
    stadiu = x.stadiu;
    return *this;
}