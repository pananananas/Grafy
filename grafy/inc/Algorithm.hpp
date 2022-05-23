#ifndef Algorytmy_hpp
#define Algorytmy_hpp
#include "IncidentList.hpp"
#include "Matrix.hpp"

const int INF = 2147483647;

int MinDist(int Dist[], bool SptSet[], int Size) {

    int min       = INF;
    int min_index = 0;

    for (int v = 0; v < Size; ++v)
        if (!SptSet[v] && Dist[v] <= min) {
            min = Dist[v];
            min_index = v;
        }
    return min_index;
}

int DijkstraM(AdjacencyMatrix M, int Start, int Koniec) {
    
    int   MSize  =  M.GetSize();        // Rozmiar Macierzy
    int  *Dist   =  new int [MSize];    // Tablica z odległościami pomiędzy wierzchołkami
    bool *SptSet =  new bool [MSize];   // sptSet[i] will be true if vertex i is included in shortest
                                        // path tree or shortest distance from src to i is finalized
    
    for (int i = 0; i < MSize; ++i) {   // Wypełnienie Dist = 'inf', SptSet = false
        Dist[i] = INF;
        SptSet[i] = false;
    }
    
    Dist[Start] = 0;

    for (int i = 0; i < MSize - 1; ++i) {
        int u = MinDist(Dist, SptSet, MSize);
        SptSet[u] = true;
        for (int v = 0; v < MSize; ++v)
            if (!SptSet[v] && M.AreAdjacent(u,v) && Dist[u] != INT_MAX && Dist[u] + M.GetEdgeLength(u,v) < Dist[v])
                Dist[v] = Dist[u] + M.GetEdgeLength(u,v);
    }
    return Dist[Koniec];
}


#endif
