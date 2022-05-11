#ifndef VertexList_hpp
#define VertexList_hpp
#include <stdio.h>
#include <fstream>
#include <iostream>


class VertexList {              // Wierzchołek do listy sąsiedztwa

public:
    VertexList *adress;
    int Wartosc;
    
    
    
    VertexList(){};
    VertexList(int **x){ Wartosc = x; };
    void SetAdress(VertexList *ad){ adress = ad; };
//    EdgeList IncidentEdges();  // return an edge list of the edges
    bool IsAdjancent(VertexList v); // test whether v and u are adjencent
    ~VertexList(){};
};







#endif /* VertexList_hpp */
