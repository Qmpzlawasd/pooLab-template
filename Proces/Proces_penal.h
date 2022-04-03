#pragma once
using namespace std;
#include <iostream>
#include "Proces.h"
class Proces_penal : public Proces
{
private:
    int dovezi;
    bool stadiu;

public:
    Proces_penal(int dovezi = 0, bool stadiu = 0) : dovezi{dovezi}, stadiu{(dovezi > 25) ? true : false} {};
    Proces_penal(const Proces_penal &x) : dovezi{x.dovezi}, stadiu{x.stadiu} {};
    friend std::istream &operator>>(std::istream &, Proces_penal &);
    friend std::ostream &operator<<(std::ostream &, const Proces_penal &);
    Proces_penal &operator=(const Proces_penal &);
    bool getStadiu() const { return stadiu; };
    virtual ostream &afis(ostream &) const;
    virtual istream &citi(istream &);
    void setStadiu(const bool &);
    ~Proces_penal(){};
};
void Proces_penal::setStadiu(const bool &a)

{
    stadiu = a;
}
ostream &Proces_penal::afis(ostream &os) const
{
    os << "Dovezi: " << dovezi << "\nStadiu: " << stadiu << '\n';
    return os;
}

std::ostream &operator<<(std::ostream &os, const Proces_penal &penal)
{
    penal.Proces::afis(os);
    return penal.afis(os);
}
istream &Proces_penal::citi(istream &os)
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
        exit(1);
    }

    dovezi = x.dovezi;
    stadiu = x.stadiu;
    return *this;
}