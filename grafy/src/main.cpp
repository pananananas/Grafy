#include "Algorithm.hpp"

int main() {
    
    int IloscWierzcholkow[5] { 10, 50, 100, 500, 1000 };
    int GestoscGrafu[4]      { 25, 50,  75, 100 };
    int IloscGrafow = 100;
    
    std::clock_t Start;
    int          Droga;
    
    AdjacencyMatrix Mac(IloscWierzcholkow[2],GestoscGrafu[2]);
    
//    Mac.WyswietlMacierz(std::cout);
//    Mac.WyswietlWage(std::cout);
    
    

    Start = std::clock();
    Droga = DijkstraM(Mac, 0,IloscWierzcholkow[0]);
    double Czas = ( std::clock() - Start ) / (double) CLOCKS_PER_SEC;
    
    std::cout << " Droga: " << Droga << std:: endl
              << " Czas: "  << Czas  << std:: endl;
    
    
    


    
//    AdjacencyList List(IloscWierzcholkow[0],GestoscGrafu[0]);
//    List.WyswietlListe(std::cout);
//    List.WyswietlListeEdge(std::cout);
    
    
    
    
    
    
    
//    std::fstream PlikLista;
//    PlikLista.open("OutputList.txt", std::ios::in);
//    std::fstream PlikMacierz;
//    PlikMacierz.open("OutputMatrix.txt", std::ios::in);
//    PlikLista.close();
//    PlikMacierz.close();
    return 0;
}
