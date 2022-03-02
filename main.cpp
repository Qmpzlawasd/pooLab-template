#include <iostream>
#include <time.h>
#include <string.h>
using namespace std;

class Individ
{
    int i;
    char tip;
    int varsta;
    double energia;
    unsigned char viu;
    void inmulteste(Individ[]);
    void ataca(Individ[]);
    void imbatraneste();
    void hraneste();
    void moare();

public:
    Individ() :  i{0},tip{'+'} ,varsta{0}, energia{0}, viu{'0'} {}
    Individ(int poz, char tipp) : i{poz}, tip{tipp}, varsta{0}, energia{30}, viu{'1'} {}
    Individ(int poz, char tipp, int vars, double ener) : i{poz}, tip{tipp}, varsta{vars}, energia{ener}, viu{'1'} {}
    friend ostream &operator<<(ostream &, const Individ &);
    friend istream &operator>>(istream &, Individ &);
    void actualizare(Individ[]);
    bool esteviu() const;
    char gettip() const;
    int getI() const;
    ~Individ(){}
};


void Individ::imbatraneste()
{
    // no intiger overflow :)
    if (energia <= 6 or varsta > 80 - 1)
    {
        energia -= 6;
        varsta++;
        this->moare();
    }
    else
    {
        energia -= 6;
        varsta++;
    }
}
void Individ::inmulteste(Individ a[])
{
    if (i - 1 >= 0 and a[i - 1].esteviu() == 0)
    {
        Individ s{i - 1, tip, 0, energia * 2};

        a[i - 1] = s;
    }

    if (i + 1 < 30 and a[i + 1].esteviu() == 0)
    {
        Individ s{i + 1, tip, 0, energia * 2};

        a[i + 1] = s;
    }
}
void Individ::hraneste()
{
    energia += 1 + (rand() % 10);
}
void Individ::moare()
{
    viu = '0';
}
void Individ::ataca(Individ a[])
{
    if (i - 1 >= 0 and a[i - 1].esteviu() and a[i - 1].gettip() != tip and energia > a[i - 1].energia)
    {
        energia -= a[i - 1].energia;
        a[i - 1].moare();
    }

    if (i + 1 < 30 and a[i + 1].esteviu() and a[i + 1].gettip() != tip and energia > a[i + 1].energia)
    {
        energia -= a[i + 1].energia;
        a[i + 1].moare();
    }
}
ostream &operator<<(ostream &os, const Individ &x)
{
    os << "Individ:---->pozitie: " << x.i << '\n';
    os << "tip: " << x.tip << '\n';
    os << "varsta: " << x.varsta << " ani\n";
    os << "energia: " << x.energia << " mana\n";
    os << "viu: " << (x.esteviu() ? "DA \n" : "NU\n");
    os << "---------------------<\n\n";
    return os;
}
istream &operator>>(istream &os, Individ &x)
{

    cout << "Individ -> \nPozitia: ";
    os >> x.i;
    cout << "Tip: ";
    os >> x.tip;
    cout << '\n';
    x.varsta = 0, x.energia = 30, x.viu = '1';
    return os;
}
void Individ::actualizare(Individ a[])
{
    if (esteviu())
    {
        hraneste();
        inmulteste(a);
        ataca(a);
        imbatraneste();
    }
}
bool Individ::esteviu() const { return viu == '1' ? 1 : 0; }
char Individ::gettip() const { return tip; }
int Individ::getI() const { return i; }

int main() // exit(-1) ==> urmeaza eroare
{
    srand ( static_cast<unsigned int>(time(NULL)) );
    static Individ v[31];

    int choice{123132123};
    int aux{-1};
    int val{-1};
    while (1)
    {
        cout << "\n\n-----------------------\nMeniu:\n1: citire indivizi\n2: actualizeaza\n3: e viu??\n4: get tip\n5: exit \n-----------------------\n\n";
        // for (size_t j = 0; j < 10; j++)
        // {

        //     cout << v[j];
        // }

        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "1-->cati indivizi?? (max 30) ";

            cin >> aux;
            if (aux <= 30 and aux > 0)
                for (int i = 0; i < aux; i++)
                {
                    Individ a;
                    cin >> a;
                    v[a.getI()] = a;
                }
            else
                exit(-1);

            break;
            
        case 2:
            if (aux != -1)
            {
                for (int i = 0; i < 30; i++)
                {
                    v[i].actualizare(v);
                }
                cout << "\nGata!\n";
            }
            else
                exit(-1);
            break;

        case 3:
            cout << "3-->Cine ?!! ";

            cin >> val;
            if (aux != -1)
            {

                if (val < 30 and val >= 0)
                {
                    if (v[val].esteviu() == 1)
                        cout << "\nDa";
                    else
                        cout << "\nNup :(";
                }
                else
                    exit(-1);
            }
            else
                exit(-1);
            break;

        case 4:
            cout << "4-->Al cui ? ";

            cin >> val;
            if (aux != -1)

            {
                if (val < 30 and val >= 0)

                {
                    if (v[val].gettip() == '0')
                        cout << "\ntipul e 0";
                    else
                        cout << "\ntipul e +";
                }
                else
                    exit(-1);
            }
            else
                exit(-1);
            break;

        default:
            exit(0);
        }
    }
}
