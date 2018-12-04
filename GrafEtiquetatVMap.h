//
// Created by Marc Grau on 02/12/2018.
//

#ifndef EDA_S8_GRAFETIQUETATVMAP_H
#define EDA_S8_GRAFETIQUETATVMAP_H

#include <vector>
#include <map>
#include <fstream>
#include <list>
#include <vector>

typedef float etiqueta;
//typedef string etiqueta;
const float etiqNula = -1;
//const string etiqNula ="";
class GrafEtiquetatVMap {
public:
    GrafEtiquetatVMap(int nVertexs, bool dirigit = false);
    GrafEtiquetatVMap(const char *nomFitxerTGF, bool dirigit = false);
    int nVertexs() const;
    bool esDirigit() const;
    void AfegirAresta(int v1, int v2, etiqueta e);
    bool ExisteixAresta(int v1, int v2) const;
    void EsborrarAresta(int v1, int v2);
    etiqueta EtiquetaAresta(int v1, int v2);
    void escriureGraf(const char * nomFitxerTGF) const;
    std::list<int> Hamiltonian_Cycle_NNA();
    int totsM (std::vector<int> m);

private:
    int _nVertexs; // =_arestes.size()-1 (vèrtexs comencen a 1)
    bool _dirigit;
    std::vector< std::map<int, etiqueta> > _arestes; // veïns o successors (depenent si dirigit)

    bool esValid(int v) const;
};

#endif //EDA_S8_GRAFETIQUETATVMAP_H
