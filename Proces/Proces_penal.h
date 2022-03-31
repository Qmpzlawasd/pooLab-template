#pragma once
#include "Proces.h"
class Proces_penal : protected Proces
{
private:
    int dovezi;
    bool stadiu;

public:
    Proces_penal(int dovezi, bool stadiu) : dovezi{0}, stadiu{0} {}
    Proces_penal(int dovezi, bool stadiu) : dovezi{dovezi}, stadiu{(dovezi > 25) ? 1 : 0} {};
    void setStadiu(const bool &a)
    {
        stadiu = a;
        
    }
    friend istream &operator>>(istream &os, Proces_penal &penal)
    {
        os >> penal.dovezi >> penal.stadiu;
        penal.stadiu=(penal.dovezi > 25) ? 1 : 0;
        return os;
    };
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
    ~Proces_penal(){};
    friend ostream &operator<<(ostream &os, const Proces_penal &penal)
    {
        os << "Dovezi: " << penal.dovezi << "\nStadiu: " << penal.stadiu << '\n';
        return os;
    };
};
