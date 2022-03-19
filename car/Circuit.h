#pragma once
#include <iostream>
#include <algorithm>
#include <map>
#include "Car.h"
class Circuit
{
    Car *cars;
    int len, j;

public:
    explicit Circuit(const int &);
    explicit Circuit(const Circuit &);
    explicit Circuit() : Circuit(20){};
    void showFinalRanks() const;
    template <class T>
    void addCar(T *c);
    ~Circuit();

};
template <class T>
void Circuit::addCar(T *c)
{
    if (j == len)
    {
        std::cerr << "NO SPACE FOR RACE" << std::endl;
        std::exit(-1);
    }

    cars[j++] = c;
}

Circuit::Circuit(const int &nr)
{
    j = 0;
    len = nr;
    cars = new Car[nr];
}

Circuit::Circuit(const Circuit &x)
{
    len = x.len;
    j = 0;
    cars = new Car[x.len];
    for (size_t i = 0; i < len; i++)
    {
        cars[i] = x.cars[i];
    }
}

Circuit::~Circuit()
{
    delete[] cars;
}

void Circuit::showFinalRanks() const
{
    std::cout << std::endl;
    srand(time(0));

    int minn;
    short corruptionIndex;
    int *sort_pls = new int[j];

    std::map<int, int> v;
    for (size_t i = 0; i < j; i++)
    {

        corruptionIndex = rand() % 9;

        sort_pls[i] = cars[i].getSpeed() + corruptionIndex;

        v[i] = sort_pls[i];
    }
    std::sort(sort_pls, sort_pls + j);
    std::cout << "\n*******------------RANKS-----------------****\n";
    for (size_t i = 0; i < j; i++)
    {

        for (size_t b = 0; b < v.size(); b++)

            if (v[b] == sort_pls[i])
            {

                std::cout << "Locul " << i + 1 << "  masina cu numarul " << 1 + b << " cu viteza de " << sort_pls[i] << " "
                          << "\n---------------------------------------------\n";
                v.erase(b);
                break;
            }
    }
    delete[] sort_pls;
    std::cout << std::endl;
}