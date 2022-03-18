#pragma once
class Car
{
    int vitezaTeoretica;

public:
    virtual int getSpeed() { return vitezaTeoretica; }
    template <class T>
    Car &operator=(const T *d)
    {
        vitezaTeoretica = d->getSpeed();
        return *this;
    }
    void setSpeed(const int &c)
    {
        vitezaTeoretica = c;
    }
    template <class T>
    bool operator>(T &d)
    {
        return (vitezaTeoretica > d.getSpeed()) ? 1 : 0;
    }
    template <class T>
    bool operator==(T &d)
    {
        return (vitezaTeoretica ==d.getSpeed()) ? 1 : 0;
    }
    template <class T>
    bool operator<(T &d)
    {
        return (vitezaTeoretica < d.getSpeed()) ? 1 : 0;
    }
    template <class T>
    bool operator<=(T &d)
    {
        return (vitezaTeoretica <= d.getSpeed()) ? 1 : 0;
    }
    template <class T>
    bool operator>=(T &d)
    {
        return (vitezaTeoretica >= d.getSpeed()) ? 1 : 0;
    }
    explicit Car(const Car &x) : vitezaTeoretica{x.vitezaTeoretica} {}
    explicit Car() : vitezaTeoretica{123} {}
    virtual ~Car(){};
};
