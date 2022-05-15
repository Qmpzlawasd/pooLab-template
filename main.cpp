#include <iostream>
#include <fstream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include "ResurseUmane/HRManager.h"
#include "ResurseUmane/InvalidAction.h"
using namespace std;

int main()
{
    HRManager &x = HRManager::getInstance();
    x.runPrompt();
}
