#ifndef EdgeMatrix_hpp
#define EdgeMatrix_hpp
#include "VertexMatrix.hpp"

template <class Typ>
class EdgeMatrix {

public:
    Typ          **Wartosc;
    EdgeMatrix    *Adress;
    VertexMatrix   Start;
    VertexMatrix   Koniec;
    
    
    
    
    EdgeMatrix(){};
    EdgeMatrix(EdgeMatrix *ad, int **W, VertexMatrix w, VertexMatrix v);
    ~EdgeMatrix(){}
};

#endif /* EdgeMatrix_hpp */
