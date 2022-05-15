#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "Companie.h"
using namespace std;

class HRManager
{
    std::vector<Companie *> catalog;
    HRManager(){};
    void mergeCompany(const Companie &, const Companie &);
    void deleteCompany(const Companie &);
    void addCompany(const Companie &);
    void citesteCompanie();
    void afisareCompanie();
    void numarDeAngajatiDinCompanie(const std::string &);
    void numarDeAngajatiDinDepartament(const std::string &);
    void costuriDinCompanie();
    void setManager(const std::string &, const std::string &, const std::string &);
    void departamenteCuMin(const size_t &);

public:
    static HRManager &getInstance()
    {
        static HRManager theInstance;
        return theInstance;
    }
    void runPrompt()
    {
        int aleg{3}, acas{1};
        string comp, depp, ang;
        while (acas)
        {
            std::cout << "\n-------------MENIU-------------\n1: citestecompanii\n2:Exit\n3:Seteza manager\n4:Care e numarul de angajati din departament\n5:Care e numarul de angajati din companie\n6:Afisare tot\n------------- END -------------\n";
            std::cin >> aleg;
            switch (aleg)
            {
            case 1:
                citesteCompanie();
                break;
            case 3:
                cout << "\nIn ce companie > ";
                cin >> comp;
                cout << "\nIn ce departament > ";
                cin >> depp;
                cout << "\nCare ii e numele > ";
                cin >> ang;
                setManager(comp, depp, ang);
                break;
            case 6:
                afisareCompanie();
                break;
            case 4:
                cout << "\nIn ce companie > ";
                cin >> comp;
                cout << "\nIn ce departament > ";
                cin >> depp;

                // numarDeAngajatiDinDepartament(comp, depp);
                break;
            case 5:
                cout << "\nIn ce companie > ";
                cin >> comp;

                numarDeAngajatiDinCompanie(comp);

                break;
            default:
                acas = 0;
                break;
            }
        }
    }
    // o Numarul de angajati ai unui companie/departament dat
    // o Cheltuielile salariale lunare totale existente la nivelul unei companii
    // o Numele, data de angajare si salariul angajatilor care au functia de manageri
    // pecum si lista de angajati care le sunt subordonati, la nivelul unei companii
    // o Lista departamentelor care au minim n angajati (n transmis ca parametru).

    ~HRManager()
    {
        for (auto &x : catalog)
        {
            delete x;
        }
        catalog.clear();
    }
};
void HRManager::setManager(const std::string &numeCompanie, const std::string &numeDepartament, const std::string &numeAngajat)
{

    for (auto &&i : catalog)
    {
        if (i->getNume() == numeCompanie)
        {
            i->setManager(numeDepartament, numeAngajat);
            break;
        }
    }
}

void HRManager::citesteCompanie()
{
    int marime{0};
    std::cout << "\nCate companii citim? ... ";
    std::cin >> marime;
    for (int i = 0; i < marime; i++)
    {
        Companie *heap = new Companie;
        std::cin >> *heap;
        catalog.push_back(heap);
    }
}
void HRManager::afisareCompanie()
{
    for (const auto &i : catalog)
    {
        cout << endl;
        cout << *i;
        cout << endl;
    }
}
