#include <iostream>
#include "Car.h"
#include "Dacia.h"
#include "Renaut.h"
#include "Toyota.h"
#include "Circuit.h"
using namespace std;

int main()
{
    Circuit a{7};
    Dacia d{13};
    Renault r{14};
    Toyota t{17};
    a.addCar(new Dacia{13});
    a.addCar(new Dacia{13});
    cout << endl;
    a.addCar(new Renault{14});
    cout << endl;
    a.addCar(new Toyota{10});
    a.addCar(new Renault{10});
    cout << endl;
    a.showFinalRanks();
    cout << endl;
}
