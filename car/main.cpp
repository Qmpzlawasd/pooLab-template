#include <iostream>
#include "Car.h"
#include "Dacia.h"
#include "Renaut.h"
#include "Toyota.h"
#include "Circuit.h"
using namespace std;
int main()
{   
    
           
          
     Circuit a{61};
    a.addCar(new Dacia{13});
    a.addCar(new Toyota{14});
    a.addCar(new Renault{12});
    a.addCar(new Renault{10});
    a.addCar(new Renault{10});
   Circuit b{a};
    b.addCar(new Renault{10});
    b.addCar(new Renault{10});
    b.addCar(new Renault{14});
    b.addCar(new Renault{10});
    b.addCar(new Dacia{12});
    b.addCar(new Toyota{14});
    b.showFinalRanks();




}
