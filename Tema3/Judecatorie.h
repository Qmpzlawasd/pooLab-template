#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include "Proces.h"
#include "Proces_civil.h"
#include "Proces_penal.h"
#include "Avocat.h"

using namespace std;

class Factory
{
public:
    static Proces *manufactureProces(std::string opti)
    {
        if (opti == "Proces_penal")
            return new Proces_penal;

        if (opti == "Proces_civil")
            return new Proces_civil;

        return nullptr;
    }
};
class Judecatorie
{
private:
    vector<Proces *> judecatorie;
    vector<Avocat<Proces_civil> *> barouCivil;
    vector<Avocat<Proces_penal> *> barouPenal;
    Judecatorie(){};

public:
    static Judecatorie &getInstance()
    {
        static Judecatorie asd;
        return asd;
    }
    void run()
    {
        unsigned long n{4}, acas{1};
        int coma{-12};
        while (acas)
        {
            std::cout
                << "\n------------------Meniu------------------\nTasta 1: Citeste Procese \nTasta 2: Afiseaza toate procesele \nTasta 3: Zi care e cel mai scump proces \nTasta 4: Da stadiul unui proces \nTasta 5: exit\n Tasta : ";

            cin >> coma;
            switch (coma)
            {
            case 1:
                cout << "cate lucruri? ";
                cin >> n;
                for (int i = 0; i < n; i++)
                {
                    Proces *pp{nullptr};
                    Avocat<Proces_civil> *c;
                    Avocat<Proces_penal> *p;

                    switch (i)
                    {
                    case 0:

                        cout << "\nProces civil::\n";
                        pp = Factory::manufactureProces("Proces_penal");
                        break;
                    case 1:

                        cout << "\nProces civil::\n";
                        pp = Factory::manufactureProces("Proces_civil");

                        break;
                    case 2:
                    {
                        cout << "\nAvocat Civil ::\n";

                        Avocat<Proces_civil> *c = new Avocat<Proces_civil>;
                        cin >> *c;
                        barouCivil.push_back(c);
                        break;
                    }
                    case 3:
                    {
                        cout << "\nAvocat Penal::\n";
                        Avocat<Proces_penal> *p = new Avocat<Proces_penal>;
                        cin >> *p;
                        barouPenal.push_back(p);
                        break;
                    }
                    }
                    if (pp != nullptr)
                    {
                        cin >> *pp;
                        std::cout << "\n";
                        judecatorie.push_back(pp);
                    }
                }

                break;
            case 2:
                for (size_t i = 0; i < judecatorie.size(); i++)
                {
                    std::cout << "\n"
                              << (*judecatorie[i]);
                }
                cout << "\n-------Barou\n";
                for (auto &&i : barouCivil)
                {
                    cout << *i << "\n\n";
                }
                cout << "\n-------Barou\n";
                for (auto &&i : barouPenal)
                {
                    cout << *i << "\n\n";
                }

                break;
            case 3:

                Proces_civil::printScumpProces();
                cout << "\n";

                break;
            case 4:
            {
                cout << "Care proces? ";
                cin >> coma;

                auto rez = std::find_if(judecatorie.begin(), judecatorie.end(), [&](const auto &c)
                                        { return c->getNrProces() == coma; });

                if (rez != judecatorie.end())
                {
                    cout << "Stadiul este ";
                    cout << (*rez)->getStadiu();
                    cout << '\n';
                }
                else
                    cout << "nu s-a gasit";

                break;
            }
            case 5:

                acas = 0;
                break;
            default:

                acas = 0;

                break;
            }
        }
    }
    ~Judecatorie()
    {
        for (size_t i = 0; i < judecatorie.size(); i++)
        {
            delete judecatorie[i];
        }
        judecatorie.clear();
        for (auto &&i : barouCivil)
            delete i;
        for (auto &&i : barouPenal)
            delete i;
        barouCivil.clear();
        barouPenal.clear();
    };
};
