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
    virtual bool getStadiu() const = 0;
    virtual ~Proces(){};
    Proces(int nrProces = -1, std::string reclamant = "", std::string reclamat = "") : nrProces{nrProces}, reclamant{reclamant}, reclamat{reclamat} {};
    Proces(const Proces &x) : nrProces{x.nrProces}, reclamant{x.reclamant}, reclamat{x.reclamat} {}
    Proces &operator=(const Proces &x)
    {
        nrProces = x.nrProces;
        reclamant = x.reclamant;
        reclamat = x.reclamat;
        return *this;
    }
    friend std::istream &operator>>(std::istream &os, Proces &proces)
    {
        std::cout << "NrProces: ";
        os >> proces.nrProces;
        std::cout << "Reclamant: ";
        os >> proces.reclamant;
        std::cout << "Reclamat: ";
        os >> proces.reclamat;

        return os;
    };
    friend std::ostream &operator<<(std::ostream &os, const Proces &proces)
    {
        os << "NrProces: " << proces.nrProces << "\nReclamant: " << proces.reclamant << "\nReclamat: " << proces.reclamat << '\n';
        return os;
    };
};