#ifndef VertexMatrix_hpp
#define VertexMatrix_hpp
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <chrono>    // Do liczenia czasu
#include <ctime>
#include <cmath>


class VertexMatrix {            // Wierzchołek do macierzy sąsiedztwa

public:
    int           ID;
    int           Wartosc;
    VertexMatrix *Adres;
    
    
    
    
    VertexMatrix(){};
    VertexMatrix(int x);
    void SetAdress(VertexMatrix *ad);
    
    
    
    
    
    ~VertexMatrix(){};
    

};




//std::ostream& operator * (std::ostream &strm){ strm << Wartosc; return strm; };

#endif /* VertexMatrix_hpp */
