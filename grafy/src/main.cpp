#include "Algorithm.hpp"

int main() {
    
    int IloscWierzcholkow[5] { 10, 50, 100, 500, 1000 };
    int GestoscGrafu[4]      { 25, 50,  75, 100 };
    int IloscGrafow = 100;
    
    std::clock_t Start;
    int          Droga = 0;
    
    AdjacencyMatrix Mac[IloscGrafow];

    
    std::cout <<" Wierzchołki = " << IloscWierzcholkow[1] << std:: endl;
    std::cout <<" Gęstości = " << GestoscGrafu[1] << std:: endl << std:: endl;
    
    for (int i = 0; i < IloscGrafow; ++i)
        Mac[i].Create(IloscWierzcholkow[2],GestoscGrafu[1]);
    
    
    Start = std::clock();
    for (int i = 0; i < IloscGrafow; ++i){
        Droga = DijkstraM(Mac[0], 0, IloscWierzcholkow[2]);
        
    }
    double Czas = ( std::clock() - Start ) / (double) CLOCKS_PER_SEC;
    
    std::cout << " Droga: " << Droga << std:: endl;
    std::cout << " Czas: "  << Czas  << std:: endl << std:: endl;

    
    //    AdjacencyList List(IloscWierzcholkow[0],GestoscGrafu[0]);
    //    List.WyswietlListe(std::cout);
    //    List.WyswietlListeEdge(std::cout);
    
    //    for (int j = 0; j < 5; ++j) {       // Po wierzchołkach
    //        for (int k = 0; k < 4; ++k) {   // Po gęstościach
    //    std::fstream PlikLista;
    //    PlikLista.open("OutputList.txt", std::ios::in);
    //    std::fstream PlikMacierz;
    //    PlikMacierz.open("OutputMatrix.txt", std::ios::in);
    //    PlikLista.close();
    //    PlikMacierz.close();
    
    return 0;
}
