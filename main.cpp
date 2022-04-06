#include <iostream>
#include <fstream>
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
            for (const auto &c : judecatorie)
            {
                std::cout << "\n";
                std::cout << *c;
            }
            break;
        case 3:
            Proces_civil::printScumpProces();
            cout << "\n";

            break;
        case 4:
            cout << "Care proces? ";
            cin >> coma;
            for (const auto &c : judecatorie)
            {
                if (c->getNrProces() == coma)
                {
                    cout << "Stadiul este ";
                    cout << c->getStadiu();
                    cout << '\n';
                    break;
                }
            }

            break;
        case 5:

            for (size_t i = 0; i < n; i++)
            {
                delete judecatorie[i];
            }
            exit(0);
        default:

            for (size_t i = 0; i < n; i++)
            {
                delete judecatorie[i];
            }
            exit(0);
        }
    }

    // Proces_civil *b = new Proces_civil;
    // ::cin >> *b;
    // std::cout << "\n";
    // std::cout << *b;
    // std::cout << "\n";
    // Proces_penal *c = new Proces_penal;
    // ::cin >> *c;
    // std::cout << "\n";
    // std::cout << *c;
    // std::cout << "\n";
    // Proces_civil x{12, 'a', 'a'};
    // // Proces_civil x{12, "asd", 'a'};//aeroere
    // std::cout << x;
    // delete c;
    // delete b;
    // ema 14. Se dau clasele:
    // - Proces (int nrProces, string reclamant, string reclamat)
    // - Proces_civil (double dauneMorale, double dauneMateriale, int nrMartori, bool
    // stadiu)
    // - Proces_penal (int dovezi, bool stadiu).
    // Sa se faca verificarile in constructori si la citire astfel: daca nrMartori > 5 automat
    // stadiul este 1, altfel este 0. Daca la un proces penal numarul dovezilor > 25 atunci
    // stadiul este 1.
    // Sa se poata modifica stadiul unui proces si sa se creeze o metoda de calculare a taxei
    // de timbru pentru fiecare proces civil. Taxa de timbru = 10/100 * dauneMorale + 10% *
    // dauneMateriale.
    // Sa se afle procesul care are taxa de timbru cea mai mare.
}