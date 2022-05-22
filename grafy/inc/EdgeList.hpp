#ifndef EdgeList_hpp
#define EdgeList_hpp
#include "VertexList.hpp"

class EdgeList {

public:
    int          Wartosc;
    EdgeList    *Adres;
    VertexList   Start;
    VertexList   Koniec;
    
    
    
    
    EdgeList(){};
    EdgeList(EdgeList *ad, int **W, VertexList w, VertexList v);
    
    ~EdgeList(){};
};








#endif /* EdgeList_hpp */
