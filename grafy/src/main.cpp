#include "Algorithm.hpp"
#include <cstdlib>
#include <chrono>
#include <ctime>

int main() {
    
    int IloscWierzcholkow[5] {10,50,100,500,1000};
    int GestoscGrafu[4]      {25,50, 75,100};
    //    int IloscGrafow = 100;
    
    
    
    
    std::fstream PlikLista;
    PlikLista.open("OutputList.txt", std::ios::in);
    std::fstream PlikMacierz;
    PlikMacierz.open("OutputMatrix.txt", std::ios::in);
    
    
    
    AdjacencyMatrix Mac(IloscWierzcholkow[0],GestoscGrafu[0]);
    
//    Mac.WyswietlMacierz(std::cout);
    

    
    AdjacencyList List(IloscWierzcholkow[0],GestoscGrafu[0]);
    
    List.WyswietlListe(std::cout);
    
    PlikLista.close();
    PlikMacierz.close();
    
    
    return 0;
}
