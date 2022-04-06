#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "Proces/Proces.h"
#include "Proces/Proces_civil.h"
#include "Proces/Proces_penal.h"
using namespace std;
int main()
{
    std::ifstream cin("date.txt");
    vector<Proces *> judecatorie;
    unsigned long n{4};
    int coma{-12};
    while (coma)
    {
        std::cout
            << "\n------------------Meniu------------------\nTasta 1: Citeste Procese \nTasta 2: Afiseaza toate procesele \nTasta 3: Zi care e cel mai scump proces \nTasta 4: Da stadiul unui proces \nTasta 5: exit\n Tasta : ";

        cin >> coma;
        switch (coma)
        {
        case 1:
            cin >> n;
            for (size_t i = 0; i < n; i++)
            {
                Proces *a;
                if (i & 1)
                {
                    cout << "\nProces civil::\n";
                    a = new Proces_civil;
                }
                else
                {
                    cout << "\nProces penal::\n";
                    a = new Proces_penal;
                }
                cin >> *a;
                std::cout << "\n";
                judecatorie.push_back(a);
            }

            break;
        case 2:
            for (const auto  &c : judecatorie)
            {
                std::cout <<"\n"<< (*c);
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

            // auto rez = std::find_if(judecatorie.begin(), judecatorie.end(), [&](const auto &c)
            //                         { return c->getNrProces() == coma; });

            // if (rez != judecatorie.end())
            // {
            //     cout << "Stadiul este ";
            //     cout << (*rez)->getStadiu();
            //     cout << '\n';
            // }

            break;
        }
        case 5:

            for (size_t i = 0; i < n; i++)
            {
                delete judecatorie[i];
            }
            exit(0);
            break;
        default:

            for (size_t i = 0; i < n; i++)
            {
                delete judecatorie[i];
            }
            exit(0);
        }
    }
}