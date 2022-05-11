#ifndef VertexMatrix_hpp
#define VertexMatrix_hpp
#include <stdio.h>
#include <fstream>
#include <iostream>

class VertexMatrix {            // Wierzchołek do macierzy sąsiedztwa

public:
    int ID;
    VertexMatrix *adress;
    int **Wartosc;
    
    
    
    VertexMatrix(){};
    VertexMatrix(int x);
    void SetAdress(VertexMatrix *ad);
    ~VertexMatrix(){};
    

};


#endif /* VertexMatrix_hpp */
