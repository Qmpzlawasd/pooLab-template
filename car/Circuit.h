#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include "Car.h"
class Circuit
{
    Car **cars; //////////////////conflict
    int len, j;

public:
    explicit Circuit(const int &);
    explicit Circuit(const Circuit &);
    explicit Circuit() : Circuit(20){};
    void showFinalRanks() const;
    void addCar(Car *c);
    ~Circuit();
};
void Circuit::addCar(Car *c)
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
    cars = new Car *[nr];
}

Circuit::Circuit(const Circuit &x)
{
    len = x.len;
    j = x.j;
    cars = new Car *[x.len];
    for (size_t i = 0; i < j; i++)
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
    srand(time(0));
    std::cout << std::endl;
    short corruptionIndex, loc{0};
    std::map<int, std::vector<int>, std::greater<int>> v;
    for (size_t i = 0; i < j; i++)
    {
        corruptionIndex = rand() % 9;
        v[cars[i]->getSpeed() + corruptionIndex].push_back(i);
    }
    std::cout << "\n*******------------RANKS-----------------****\n";

    for (const auto &i : v)
    {
        for (const auto &j : i.second)
        {
            loc++;
            std::cout << "Locul " << loc << "  masina cu numarul " << j + 1 << " cu viteza de " << i.first << " "
                      << "\n---------------------------------------------\n";
        }
    }
    std::cout << std::endl;
}