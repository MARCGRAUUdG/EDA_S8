#include <iostream>
#include <cstring>
#include "GrafEtiquetatVMap.h"

int main() {
    std::string str;
    std::cout << "Entra el fitxer: " << std::endl;
    std::cin >> str;
    char *cstr = new char[str.size()+1];
    strcpy(cstr, str.c_str());


    GrafEtiquetatVMap g(cstr, false);
    std::list<int> res = g.Hamiltonian_Cycle_NNA();
    for (auto &elem : res)
    {
        std::cout << elem << " ";
    }
    return 0;
}