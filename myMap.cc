#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
template <class T, class Q>
class MyMap
{
private:
    vector<pair<T, Q>> v;

public:
    MyMap() = default;
    virtual ~MyMap() = default;
    Q &operator[](const T &x)
    {
        for (auto &z : v)
        {
            if (z.first == x)
            {
                return z.second;
            }
        }
        v.push_back({x, 0});
        return v.back().second;
    }
    void print() const
    {
        for (const auto &c : v)
            cout << c.first << " : " << c.second << "\n";
    }
};
int main()
{
    MyMap<string, int> catalog;
    catalog["catto"] = 1;
    catalog["capybara"] = 99;
    catalog.print();
    cout << catalog["capybara"];
}