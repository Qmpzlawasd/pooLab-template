#pragma once
#include "InvalidData.h"

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
    Proces_penal(int nrProces, std::string reclamant, std::string reclamat, int dovezi = 0) : Proces{nrProces, std::move(reclamant), std::move(reclamat)}, dovezi{dovezi}, stadiu{(dovezi > 25) ? true : false} {};
    Proces_penal(int dovezi = 0) : Proces{}, dovezi{dovezi}, stadiu{(dovezi > 25) ? true : false} {};
    Proces_penal(const Proces_penal &x) : Proces{x}, dovezi{x.dovezi}, stadiu{x.stadiu} {};
    friend std::ostream &operator<<(std::ostream &, const Proces_penal &);
    friend std::istream &operator>>(std::istream &, Proces_penal &);
    virtual std::ostream &afis(std::ostream &) const override;
    virtual std::istream &citi(std::istream &) override;
    bool getStadiu() const override { return stadiu; };
    Proces_penal &operator=(const Proces_penal &);
    void setStadiu(const bool &);
    void setDovezi(const int &);
    int getDovezi() const;
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
    try
    {
        std::string a;
        os >> a;
        if (eNumar(a))
        {
            dovezi = atoi(a.c_str());
        }else throw InvalidData{};
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        exit(0);
    }

    stadiu = (dovezi > 25) ? true : false;
    return os;
}
std::istream &operator>>(std::istream &os, Proces_penal &penal)
{
    penal.Proces::citi(os);
    return penal.citi(os);
}
Proces_penal &Proces_penal::operator=(const Proces_penal &x)
{
    if (this != &x)
    {
        return *this;
    }
    try
    {
        Proces &rb = (*this); // upcast
        rb = x;
    }
    catch (std::bad_cast &)
    {
        std::exit(1);
    }
    dovezi = x.dovezi;
    stadiu = x.stadiu;
    return *this;
}
int Proces_penal::getDovezi() const
{
    return dovezi;
}
void Proces_penal::setDovezi(const int &dovezix)
{
    Proces_penal::dovezi = dovezix;
}
