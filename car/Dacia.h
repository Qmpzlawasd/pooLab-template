#pragma once
class Dacia : public Car
{
private:
    int vitezaTeoretica;

public:
    Dacia(const int &nr) : vitezaTeoretica{nr} {}
    Dacia():vitezaTeoretica{0} {}
    ~Dacia(){}
    int getSpeed() const { return vitezaTeoretica; }
};
