#pragma once
#include <iostream>
#include <algorithm>
#include "Proces_civil.h"
#include "Proces_penal.h"
#include <vector>
using namespace std;

template <class T>
class Avocat // nu exista in utopia nostra postbelica vreun avocat ce detine in custodie procese diferite de constiinta - de constiinta; Daca nu as spune adevarul teoretic as minti.
{
private:
    string nume;
    vector<T *> carte;

public:
    Avocat<T>(){};
    ~Avocat<T>()
    {

        for (auto &&i : carte)
            delete i;
        carte.clear();
    };

    const string getType() const;
    std::istream &citi(std::istream &);
    std::ostream &afis(std::ostream &) const;
    Avocat<T>(const string &nume) : nume{nume} {};
    template <class K>
    friend std::istream &operator>>(std::istream &, Avocat<K> &);
    template <class K>
    friend std::ostream &operator<<(std::ostream &, const Avocat<K> &);
};
template <typename T>
const string Avocat<T>::getType() const { return "-1"; };
template <>
const string Avocat<Proces_civil>::getType() const { return "Civil"; };
template <>
const string Avocat<Proces_penal>::getType() const { return "Penal"; };
template <class T>
std::istream &Avocat<T>::citi(std::istream &os)
{
    cout << "nume ";
    os >> nume;
    cout << "cate procese veri sa citesti ? ";
    int x{0};
    os >> x;
    for (size_t i = 0; i < x; i++)
    {
        T *procesAmbiguu = new T;
        os >> *procesAmbiguu;
        carte.push_back(procesAmbiguu);
    }
    return os;
}
template <class T>
std::ostream &Avocat<T>::afis(std::ostream &os) const
{
    os << "Avocat ce se ocupa cu procese " << this->getType() << "e\n";
    os << "nume " << nume << '\n';
    for (auto &&i : carte)
    {
        os << *i;
        os << '\n';
    }

    return os;
}
template <class T>
std::istream &operator>>(std::istream &os, Avocat<T> &avoc)
{
    return avoc.citi(os);
}
template <class T>
std::ostream &operator<<(std::ostream &os, const Avocat<T> &avoc)
{
    return avoc.afis(os);
}