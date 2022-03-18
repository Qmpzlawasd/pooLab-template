#pragma once
class Renault : public Car
{
private:
    int vitezaTeoretica;

public:
    Renault(const int &nr) : vitezaTeoretica{nr} {}
    ~Renault(){};
    int getSpeed() const { return vitezaTeoretica; }
};
