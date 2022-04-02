#pragma once
using namespace std;
#include <iostream>
#include <string>
#include "Proces.h"
class Proces_penal : public Proces
{
private:
    int dovezi;
    bool stadiu;

public:
    ~Proces_penal(){};
    Proces_penal(int dovezi = 0, bool stadiu = 0) : dovezi{dovezi}, stadiu{(dovezi > 25) ? true : false} {};
    void setStadiu(const bool &a)
    {
        stadiu = a;
    }
    bool getStadiu() const { return stadiu; };
    Proces_penal(const Proces_penal &x) : dovezi{x.dovezi}, stadiu{x.stadiu}
    {
    }
    Proces_penal &operator=(const Proces_penal &x)
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
    friend std::istream &operator>>(std::istream &os, Proces_penal &penal)
    {

        penal.Proces::citi(os);
        return penal.citi(os);
    }
    virtual istream &citi(istream &os)
    {
        std::cout << "NrDovezi: ";
        os >> dovezi;
        std::cout << "Stadiu: ";
        os >> stadiu;
        stadiu = (dovezi > 25) ? true : false; // altfel??

        return os;
    }
    virtual ostream &afis(ostream &os) const
    {
        os << "Dovezi: " << dovezi << "\nStadiu: " << stadiu << '\n';
        return os;
    }

    friend std::ostream &operator<<(std::ostream &os, const Proces_penal &penal)
    {
        penal.Proces::afis(os);
        return penal.afis(os);
    };
};
