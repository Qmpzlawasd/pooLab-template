#include <cmath>
#include <iostream>
using namespace std;

class Complex
{
    double i, r;

public:
    Complex();
    Complex(double, double);
    ~Complex();
    void set(double, double);
    void setImag(double);
    void setReal(double);
    double modul();
    double GetImag();
    double GetReal();
    friend ostream &operator<<(ostream &, const Complex &);
    Complex(const Complex &);
    Complex operator*(Complex &);
    Complex operator/(Complex &);
    Complex operator+(Complex &);
};


Complex::Complex() : i{0}, r{0} {}
Complex::~Complex()
{
    i = 0;
    r = 0;
}
Complex::Complex(double pr, double pi) : i{pi}, r{pr} {}
void Complex::set(double pr, double pi) { i = pi, r = pr; }
void Complex::setReal(double x) { r = x; }
void Complex::setImag(double x) { i = x; }
Complex::Complex(const Complex &b) : i{b.i}, r{b.r} {}
double Complex::modul()
{
    return sqrt(r * r + i * i);
}
ostream &operator<<(ostream &os, const Complex &a)
{
    bool ok = 0;
    if (a.r == 0 and a.i > 0)
    {
        os << a.i << 'i';
        return os;
    }

    if (a.i == 0 and a.r == 0)
    {
        os << 0;
        return os;
    }
    if (a.r != 0)
    {
        ok = 1;
        os << a.r;
    }
    if (a.i > 0 and ok)
        os << "+" << a.i;
    else if (a.i < 0)
        os << a.i;
    else if (a.i == 0)
    {
        // os << 0;
        return os;
    }
    cout << "i";
    return os;
}
Complex Complex::operator+(Complex &a)
{
    double s = r + a.r, b = i + a.i;
    Complex rr(s, b);
    return rr;
}
Complex Complex::operator*(Complex &a)
{

    Complex d(a.r * r - a.i * i, a.i * r + a.r * i);

    return d;
}
double Complex::GetReal()
{
    return r;
}
double Complex::GetImag()
{
    return i;
}
Complex Complex::operator/(Complex &x)
{
    double a = this->r;
    double b = this->i;
    double c = x.r;
    double d = x.i;
    Complex z((a * c + b * d) / (c * c + d * d), (b * c - a * d) / (c * c + d * d));
    return z;
}
int main()
{
    Complex a(34, 0);
    cout << a << endl;
    Complex b(0, 3);
    cout << b << endl;
    Complex c(0, -3);
    cout << c << endl;
    Complex d(23, 2);
    cout << d << endl;
    Complex e(3, -9);
    cout << e << endl;
    cout << e * d << endl;
}