#ifndef Algorytmy_hpp
#define Algorytmy_hpp
#include "IncidentList.hpp"
#include "Matrix.hpp"

const int INF = 2147483647;

int MinDist(int Dist[], bool SptSet[], int Size) {

    int min = INF;
    int tmp = 0;                            // Indeks na najkrótszą drogę w tablicy SptSet
    
    for (int v = 0; v < Size; ++v)          // Idziemy po całej macierzy
        if (!SptSet[v] && Dist[v] <= min) { // Jeśli SptSet jest false oraz Dist mniejszy od min
            min = Dist[v];                  // Aktualizujemy wartości
            tmp = v;
        }
    return tmp;                             // Zwracam indeks na najkrótszą drogę
}

void WyswietlDrogi(int Dist[], int Rozmiar) {
    std::cout <<"W \t Długość" << std::endl;
    for (int i = 0; i < Rozmiar; i++)
        std:: cout << i << " \t\t" << Dist[i]<< std::endl;
}

int DijkstraM(AdjacencyMatrix M, int Start, int Koniec) {
    
    int   MSize  =  M.GetSize();            // Rozmiar Macierzy
    int  *Dist   =  new int [MSize];        // Tablica z odległościami pomiędzy wierzchołkami
    bool *SptSet =  new bool [MSize];       // Tablica wartości z wierzchołkami,
                                            // będzie true dla najkrótszego połączenia od Start
    
    for (int i = 0; i < MSize; ++i) {       // Wypełnienie Dist = 'inf', SptSet = false
        Dist[i] = INF;
        SptSet[i] = false;
    }
    Dist[Start] = 0;                        // Odległość od samego siebie to 0

    for (int i = 0; i < MSize - 1; ++i) {   // MSize - 1, bo tyle jest możliwych połączeń
        int u = MinDist(Dist, SptSet, MSize);
        SptSet[u] = true;                   // True dla najkrótszego połączenia od Start
        for (int v = 0; v < MSize; ++v)
      // Jeśli   false        u i v połączone       odległość != inf      odległość od u + długość (u,v) mniejsza od odległości od v
            if (!SptSet[v] && M.AreAdjacent(u,v) && Dist[u] != INT_MAX && Dist[u] + M.GetEdgeLength(u,v) < Dist[v])
                Dist[v] = Dist[u] + M.GetEdgeLength(u,v);  // Odl do v + waga kolejnego połączenia
    }
//    WyswietlDrogi(Dist, MSize);
    
    return Dist[Koniec-1];  // Zwracam odległość od Start do Koniec
}


#endif
