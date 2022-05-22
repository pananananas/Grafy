#ifndef EdgeMatrix_hpp
#define EdgeMatrix_hpp
#include "VertexMatrix.hpp"


class EdgeMatrix {

public:
    int           Wartosc;
    EdgeMatrix   *Adres;
    VertexMatrix  Start;
    VertexMatrix  Koniec;
    
    
    
    
    EdgeMatrix(){};
    EdgeMatrix(EdgeMatrix *ad, int **W, VertexMatrix w, VertexMatrix v);
    ~EdgeMatrix(){}
};

#endif /* EdgeMatrix_hpp */
