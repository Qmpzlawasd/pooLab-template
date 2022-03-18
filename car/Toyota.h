#pragma once
class Toyota : public Car
{
private:
    int vitezaTeoretica;

public:
    Toyota(const int &nr) : vitezaTeoretica{nr} {}
    ~Toyota(){};
    int getSpeed() const { return vitezaTeoretica; }
};
