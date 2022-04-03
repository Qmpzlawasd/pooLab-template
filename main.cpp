#include <ostream>
#include <fstream>
#include <memory>
#include <vector>
#include "Proces/Proces.h"
#include "Proces/Proces_civil.h"
#include "Proces/Proces_penal.h"
using namespace std;
// #include <iostream>
ifstream cin("date.txt");
int main()
{
    // Proces_civil *d=  new Proces;
    vector<Proces *> judecatorie;
    unsigned long n{4};
    for (size_t i = 0; i < n; i++)
    {
        Proces *a;
        if (i & 1)
        {
            a = new Proces_civil;
        }
        else
            a = new Proces_penal;

        ::cin >> *a;
        cout << "\n";
        judecatorie.push_back(a);
    }
    for (size_t i = 0; i < n; i++)
    {
        cout << "\n";
        cout << *judecatorie[i];
        delete judecatorie[i];
    }
    Proces_civil *b = new Proces_civil;
    ::cin >> *b;
    cout << "\n";
    cout << *b;
    cout << "\n";
    Proces_penal *c = new Proces_penal;
    ::cin >> *c;
    cout << "\n";
    cout << *c;
    cout << "\n";
    Proces_civil x{12, 'a', 'a'};
    // Proces_civil x{12, "asd", 'a'};//aeroere
    cout << x;
    delete c;
    delete b;
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