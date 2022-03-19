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
    a.addCar(new Dacia{13});
    a.addCar(new Dacia{13});
    a.addCar(new Renault{14});
    a.addCar(new Toyota{10});
    a.addCar(new Renault{10});
    a.showFinalRanks();
}
