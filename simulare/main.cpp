#include <iostream>
#include <fstream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include "Statie.h"
#include "StatieUrbana.h"
#include "StatieExtraurbana.h"
using namespace std;

int main()
{
    std::string x;
    int acas{1}, aleg{2};
    vector<Statie *> v;
    while (acas)
    {
        cout << "1:Citire statie\n2:afis date statii\n3:afis toate statiile prin care trece un autobuz\n4:estimare pret 2 statii\n5:exit\n\n";
        cin >> aleg;
        switch (aleg)
        {
        case 1:
            cout << "\nce tip de statie ?";
            cin >> x;
            Statie *ne;
            if (x == "urbana")
            {
                ne = new StatieUrbana{};
            }
            else
            {
                ne = new StatieExtraurbana{};
            }
            cin >> *ne;
            break;
        case 2:
            acas = 0;

            break;
        case 3:
            acas = 0;

            break;
        case 4:
            acas = 0;

            break;

        default:
            acas = 0;
            break;
        }
    }
}