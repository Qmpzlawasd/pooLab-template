#include <ostream>
#include <fstream>
// #include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include "Proces/Proces.h"
#include "Proces/Proces_civil.h"
#include "Proces/Proces_penal.h"
using namespace std;
ifstream cin("date.txt");
int main()
{
    vector<Proces *> v;
    int n;
    Proces_civil a, b;
    cout << "\n";
    ::cin >> a >> b;
    cout << "\n";
    cout << b;
    cout << "\n";
    cout << a;
  

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