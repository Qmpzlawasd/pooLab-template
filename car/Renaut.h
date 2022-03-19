#pragma once
class Renault : public Car
{
private:
    int vitezaTeoretica;

public:
    ~Renault(){};
    Renault(const int &nr) : vitezaTeoretica{nr} {}
    int getSpeed() const { return vitezaTeoretica; }
};
