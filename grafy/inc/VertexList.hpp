#ifndef VertexList_hpp
#define VertexList_hpp
#include <stdio.h>
#include <fstream>
#include <iostream>


class VertexList {              // Wierzchołek do listy sąsiedztwa

public:
    VertexList *adress;
    int **Wartosc;
    
    
    
    VertexList(){};
    VertexList(int **x){ Wartosc = x; };
    void SetAdress(VertexList *ad){ adress = ad; };
    ~VertexList(){};
};







#endif /* VertexList_hpp */
