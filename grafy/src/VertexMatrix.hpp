#ifndef VertexMatrix_hpp
#define VertexMatrix_hpp
#include <stdio.h>
#include <fstream>
#include <iostream>

class VertexMatrix {            // Wierzchołek do macierzy sąsiedztwa

public:
    int           ID;
    int           Wartosc;
    VertexMatrix *Adress;
    
    
    
    
    VertexMatrix(){};
    VertexMatrix(int x);
    void SetAdress(VertexMatrix *ad);
    
    
    
    
    
    ~VertexMatrix(){};
    

};
//std::ostream& operator * (std::ostream &strm){ strm << Wartosc; return strm; };

#endif /* VertexMatrix_hpp */
