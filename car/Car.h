#pragma once
class Car
{
    int vitezaTeoretica;

public:
    virtual ~Car(){};
    virtual int getSpeed() const;
    explicit Car() : vitezaTeoretica{123} {}
    explicit Car(const Car &x) : vitezaTeoretica{x.vitezaTeoretica} {}
    bool operator>(const Car &) const;
    bool operator==(const Car &) const;
    bool operator<(const Car &) const;
    bool operator<=(const Car &) const;
    bool operator>=(const Car &) const;
    Car &operator=(const Car *);
    void setSpeed(const int &);
};
 int Car::getSpeed() const
{
    return vitezaTeoretica;
}

Car &Car::operator=(const Car *d)
{
    vitezaTeoretica = d->getSpeed();
    return *this;
}
void Car::setSpeed(const int &c)
{
    vitezaTeoretica = c;
}
bool Car::operator>(const Car &d) const
{
    return (vitezaTeoretica > d.getSpeed()) ? 1 : 0;
}
bool Car::operator==(const Car &d) const
{
    return (vitezaTeoretica == d.getSpeed()) ? 1 : 0;
}
bool Car::operator<(const Car &d) const
{
    return (vitezaTeoretica < d.getSpeed()) ? 1 : 0;
}
bool Car::operator>=(const Car &d) const
{
    return (vitezaTeoretica >= d.getSpeed()) ? 1 : 0;
}
bool Car::operator<=(const Car &d) const
{
    return (vitezaTeoretica <= d.getSpeed()) ? 1 : 0;
}