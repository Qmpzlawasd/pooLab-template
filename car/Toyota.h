#pragma once
class Toyota : public Car
{
private:
    int vitezaTeoretica;

public:
    ~Toyota(){};
    Toyota(const int &nr) : vitezaTeoretica{nr} {}
    int getSpeed() const { return vitezaTeoretica; }
};
