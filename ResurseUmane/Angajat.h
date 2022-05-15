#pragma once
#include <iostream>

class Angajat
{
private:
    std::string dataAngajare;
    double salariuBrut;
    bool esteSef;
    Angajat *manager;
    std::string nume;

public:
    const std::string &getNume() const { return nume; }
    double getSalariu() const { return salariuBrut; }
    void setEsteSef(const bool &x)
    {
        esteSef = x;
    }
    void setManager(Angajat *x)
    {

        manager = x;
    }


    Angajat() = default;
    Angajat(const Angajat &x) : dataAngajare(x.dataAngajare), salariuBrut(x.salariuBrut), esteSef{x.esteSef}, manager(x.manager), nume(x.nume){};
    Angajat(const std::string &dataAngajare, double salariuBrut, Angajat *manager, const std::string &nume)
        : dataAngajare(dataAngajare), salariuBrut(salariuBrut), manager(manager), nume(nume){};

    friend std::istream &operator>>(std::istream &os, Angajat &angajat)
    {
        angajat.citi(os);
        return os;
    }
    void afis(std::ostream &) const;
    void citi(std::istream &);
    bool operator==(const Angajat &rhs) const
    {
        return dataAngajare == rhs.dataAngajare &&
               salariuBrut == rhs.salariuBrut &&
               manager == rhs.manager &&
               nume == rhs.nume;
    }
    friend std::ostream &operator<<(std::ostream &os, const Angajat &angajat)
    {
        angajat.afis(os);
        return os;
    }
    ~Angajat()
    {
        manager = nullptr;
    }
};
void Angajat::afis(std::ostream &os) const
{

    os << "\n\t|dataAngajare: " << dataAngajare << "\n\t|salariuBrut: " << salariuBrut << "\n\t|manager: ";
    if (manager != nullptr)
    {
        os << manager->nume;
    }
    else if (!esteSef)
    {
        os << " nu am ";
    }
    else
    {
        os << " eu sunt managerul ";
    }
    os << "\n\t|nume: " << nume << "\n\t|";
}
void Angajat::citi(std::istream &os)
{

    std::cout << "\ndataAngajare: ";
    os >> dataAngajare;
    std::cout << "\nsalariuBrut: ";
    os >> salariuBrut;
    std::cout << "\nnume: ";
    os >> nume;
}