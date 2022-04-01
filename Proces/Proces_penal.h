#pragma once
#include <iostream>
#include "Proces.h"
class Proces_penal : protected Proces
{
private:
    int dovezi;
    bool stadiu;

public:
    ~Proces_penal(){};
    Proces_penal() : dovezi{0}, stadiu{0} {}
    Proces_penal(int dovezi, bool stadiu) : dovezi{dovezi}, stadiu{(dovezi > 25) ? true : false} {};
    void setStadiu(const bool &a)
    {
        stadiu = a;
    }
    Proces_penal(const Proces_penal &x)
    {
        dovezi = x.dovezi;
        stadiu = x.stadiu;
    }
    Proces_penal &operator=(const Proces_penal &x)
    {
        dovezi = x.dovezi;
        stadiu = x.stadiu;
        return *this;
    }
    friend std::istream &operator>>(std::istream &os, Proces_penal &penal)
    {
        std::cout << "NrDovezi: ";
        os >> penal.dovezi;
        std::cout << "Stadiu: ";
        os >> penal.stadiu;
        penal.stadiu = (penal.dovezi > 25) ? 1 : 0; // altfel??/
        return os;
    };
    friend std::ostream &operator<<(std::ostream &os, const Proces_penal &penal)
    {
        os << "Dovezi: " << penal.dovezi << "\nStadiu: " << penal.stadiu << '\n';
        return os;
    };
};
