#pragma once
class Dacia : public Car
{
private:
    int vitezaTeoretica;

public:
    ~Dacia(){}
    Dacia(const int &nr) : vitezaTeoretica{nr} {}
    int getSpeed() const { return vitezaTeoretica; }
};
