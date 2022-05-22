#include "Algorithm.hpp"


int main() {
    
    int IloscWierzcholkow[5] {10,50,100,500,1000};
    int GestoscGrafu[4]      {25,50, 75,100};
    //    int IloscGrafow = 100;
    
    std::fstream PlikLista;
    PlikLista.open("OutputList.txt", std::ios::in);
    std::fstream PlikMacierz;
    PlikMacierz.open("OutputMatrix.txt", std::ios::in);
    
    
    AdjacencyMatrix Mac(IloscWierzcholkow[0],GestoscGrafu[0]);
//    AdjacencyMatrix Mac2(IloscWierzcholkow[0],GestoscGrafu[0]);
    Mac.WyswietlMacierz(std::cout);
    
    
    
    AdjacencyMatrix Mac2(IloscWierzcholkow[0],GestoscGrafu[0]);
    
    Mac2.WyswietlMacierz(std::cout);
    
    AdjacencyList List(IloscWierzcholkow[0],GestoscGrafu[0]);
    
    List.WyswietlListe(std::cout);
    
//    List.WyswietlListeEdge(std::cout);
    
    PlikLista.close();
    PlikMacierz.close();
    return 0;
}
