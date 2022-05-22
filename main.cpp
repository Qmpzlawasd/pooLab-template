#include <iostream>
#include <algorithm>
#include <vector>
#include "Tema3/Proces.h"
#include "Tema3/Judecatorie.h"
#include "Tema3/Proces_civil.h"
#include "Tema3/Proces_penal.h"
#include "Tema3/Avocat.h"
using namespace std;

int main()
{
    Judecatorie &piataUnirii = Judecatorie::getInstance();
    piataUnirii.run();
}