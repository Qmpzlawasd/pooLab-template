#pragma once
class Car
{
    int vitezaTeoretica;

public:
    virtual ~Car(){};
    explicit Car() : vitezaTeoretica{123} {}
    virtual int getSpeed() const
    {
        return vitezaTeoretica;
    }
    explicit Car(const Car &x) : vitezaTeoretica{x.vitezaTeoretica} {}
    Car &operator=(const Car *);
    void setSpeed(const int &);
    bool operator>(const Car &)const;
    bool operator==(const Car &)const;
    bool operator<(const Car &)const;
    bool operator<=(const Car &)const;
    bool operator>=(const Car &)const;
};
Car &Car::operator=(const Car *d)
{
    vitezaTeoretica = d->getSpeed();
    return *this;
}
void Car::setSpeed(const int &c)
{
    vitezaTeoretica = c;
}
bool Car::operator>(const Car &d)const
{
    return (vitezaTeoretica > d.getSpeed()) ? 1 : 0;
}
bool Car::operator==(const Car &d)const
{
    return (vitezaTeoretica == d.getSpeed()) ? 1 : 0;
}
bool Car::operator<(const Car &d)const
{
    return (vitezaTeoretica < d.getSpeed()) ? 1 : 0;
}
bool Car::operator>=(const Car &d)const
{
    return (vitezaTeoretica >= d.getSpeed()) ? 1 : 0;
}
bool Car::operator<=(const Car &d)const
{
    return (vitezaTeoretica <= d.getSpeed()) ? 1 : 0;
}