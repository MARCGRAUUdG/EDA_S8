//
// Created by Marc Grau on 02/12/2018.
//

#include "GrafEtiquetatVMap.h"

GrafEtiquetatVMap::GrafEtiquetatVMap(int nVertexs, bool dirigit) {
    _nVertexs = nVertexs;
    _dirigit = dirigit;
}

GrafEtiquetatVMap::GrafEtiquetatVMap(const char *nomFitxerTGF, bool dirigit) {
    std::ifstream f_ent;
    std::string n;
    int v1, v2;
    float e;

    f_ent.open(nomFitxerTGF, std::ifstream::in);
    if (!f_ent.is_open())
    {
        throw ("No s'ha obert el fitxer!");
    }
    f_ent >> n;
    while (n != "#")
    {
        _nVertexs++;
        std::getline(f_ent, n);
    }
    while (!f_ent.eof())
    {
        f_ent >> v1 >> v2 >> e;
        AfegirAresta(v1, v2, e);
    }
    f_ent.close();
}

int GrafEtiquetatVMap::nVertexs() const {
    return _nVertexs;
}

bool GrafEtiquetatVMap::esDirigit() const {
    return _dirigit;
}

void GrafEtiquetatVMap::AfegirAresta(int v1, int v2, etiqueta e) {
    if (not esValid(v1) or not esValid(v2)) throw("No és vàlid!");
    else if (not ExisteixAresta(v1,v2)) {
        _arestes[v1][v2] = e;
        if (not _dirigit) _arestes[v2][v1] = e;
    }
}

bool GrafEtiquetatVMap::ExisteixAresta(int v1, int v2) const {
    if (not esValid(v1) or not esValid(v2)) return false;
    else return (_arestes[v1].count(v2) == 1);
}

void GrafEtiquetatVMap::EsborrarAresta(int v1, int v2) {
    _arestes[v1].erase(v2);
}

etiqueta GrafEtiquetatVMap::EtiquetaAresta(int v1, int v2) {
    return _arestes[v1][v2];
}

void GrafEtiquetatVMap::escriureGraf(const char *nomFitxerTGF) const {

}

bool GrafEtiquetatVMap::esValid(int v) const {
    return v > _nVertexs;
}

std::list<int> GrafEtiquetatVMap::Hamiltonian_Cycle_NNA() {
    std::list<int> resultat;

    return resultat;
}