#pragma once
#include <iostream>
#include <vector>
#include <map>
// using namespace std;
#include "Car.h"
class Circuit
{
    Car *cars;
    int len, j;

public:
    explicit Circuit(const int &);
    explicit Circuit(const Circuit &);
    ~Circuit();
    template <class T>
    void addCar(T *c)
    {
        if (j == len)
        {
            std::cerr << "OUT OF SPACE POUR LE ARRAY" << std::endl;
            std::exit(-1);
        }

        cars[j++] = c;
    // for (size_t i = 0; i < j; i++)
    // {
    //     cout<<cars[i].getSpeed()<<
    //      ' '<<j<<' ';
    // }
    // cout<<endl;
    }
    
    void showFinalRanks() const;
};

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

    std::map<int, int> v;
    for (size_t i = 0; i < j; i++)
    {

        corruptionIndex = rand() % 9;
        cars[i].setSpeed(cars[i].getSpeed() + corruptionIndex);
        v[i] = (cars[i].getSpeed());
    }

    for (size_t i = 0; i < j; i++)
    {
        minn = i;
        for (size_t k = i + 1; k < j; k++)
        {
            if (cars[minn] < cars[k])
                minn = k;
        }
        Car p{cars[minn]};
        cars[minn] = cars[i];
        cars[i] = p;
    }
    std::cout << "\n*******------------RANKS-----------------****\n";
    for (size_t i = 0; i < j; i++)
    {

        for (size_t b = 0; b < v.size(); b++)

            if (v[b] == cars[i].getSpeed())
            {

                std::cout << "Locul " << i + 1 << "  masina cu numarul " << 1 + b << " cu viteza de " << cars[i].getSpeed() << " "
                     << "\n---------------------------------------------\n";
                v.erase(b);break;
            }
    }

    std::cout << std::endl;
}